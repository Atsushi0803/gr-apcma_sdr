#include "apcma_tx_impl.h"

#include <gnuradio/expj.h>
#include <gnuradio/io_signature.h>

namespace gr {
namespace apcma_sdr {

using output_type = gr_complex;
apcma_tx::sptr
    apcma_tx::make( uint32_t sf,
                    uint32_t bw,
                    uint32_t n_bit,
                    uint32_t n_pulse,
                    uint32_t start_var,
                    uint32_t end_var ) {
    return gnuradio::make_block_sptr<apcma_tx_impl>( sf, bw, n_bit, n_pulse, start_var, end_var );
}


/*
 * The private constructor
 */
apcma_tx_impl::apcma_tx_impl( uint32_t sf,
                              uint32_t bw,
                              uint32_t n_bit,
                              uint32_t n_pulse,
                              uint32_t start_var,
                              uint32_t end_var ):
    gr::sync_block( "apcma_tx",
                    gr::io_signature::make( 0, 0, 0 ),
                    gr::io_signature::make( 1, 1, sizeof( output_type ) ) ) {
    m_sf        = sf;
    m_bw        = bw;
    m_samp_rate = bw;
    m_nbit      = n_bit;
    m_npulse    = n_pulse;
    m_start_var = start_var;
    m_end_var   = end_var;

    m_send_index = 0;

    m_sample_per_slot = (uint32_t)( std::pow( 2, sf ) );
    if ( m_npulse == 4 ) {
        m_length_c = std::pow( 2, m_nbit + 1 ) + 5;
    }

    start_var = 1;
    end_var   = 8;
    m_l_send_data.resize( end_var - start_var + 1 );
    for ( uint32_t i = 0; i < ( end_var - start_var + 1 ); i++ ) {
        m_l_send_data[i] = start_var + i;
    }

    m_codeword.resize( m_length_c );
    m_l_interval.resize( m_npulse - 1 );

    m_upchirp.resize( m_sample_per_slot );
    m_zeros.resize( m_sample_per_slot );

    for ( uint32_t i = 0; i < m_sample_per_slot; i++ ) {    // upchirpの配列を生成
        m_upchirp[i] = gr_complex( 1.0, 0.0 ) * gr_expj( 2.0 * M_PI * ( i * i / ( 2 * m_sample_per_slot ) - 0.5 * i ) );
    }
    for ( uint32_t i = 0; i < m_sample_per_slot; i++ ) {    // 0+j0の配列zerosを定義(0スロット用)
        m_zeros[i] = gr_complex( 0.0, 0.0 );
    }
}


/*
 * Our virtual destructor.
 */
apcma_tx_impl::~apcma_tx_impl() {}

int
    apcma_tx_impl::work( int                        noutput_items,
                         gr_vector_const_void_star& input_items,
                         gr_vector_void_star&       output_items ) {
    auto out = static_cast<output_type*>( output_items[0] );

    for ( uint32_t i = 0; i < m_length_c; i++ ) {
        m_codeword[i] = 0;
    }
    m_send_data = m_l_send_data[m_send_index];
    std::cout << "send_data: " << m_send_data << std::endl;
    m_send_index = ( m_send_index + 1 ) % ( m_end_var - m_start_var + 1 );    //

    // 符号語の設定
    // x/c-2x/cの場合
    m_l_interval = { m_send_data, m_length_c - 2 * m_send_data - 4, m_send_data };
    for ( uint32_t i = 0; i < m_npulse; i++ ) {
        int tmp_index         = std::accumulate( m_l_interval.begin(), std::next( m_l_interval.begin(), i ), 0 ) + i;    // パルスがオンになるm_codewordのインデックスを作成
        m_codeword[tmp_index] = 1;
    }

    for ( uint32_t i = 0; i < m_length_c; i++ ) {
        if ( m_codeword[i] == 0 ) {
            memcpy( &out[noutput_items], &m_zeros[0], m_sample_per_slot * sizeof( gr_complex ) );
            //std::cout << "0";
        } else {
            memcpy( &out[noutput_items], &m_upchirp[0], m_sample_per_slot * sizeof( gr_complex ) );
            //std::cout << "1";
        }
        noutput_items += m_sample_per_slot;
    }
    return noutput_items;
}

} /* namespace apcma_sdr */
} /* namespace gr */
