/* -*- c++ -*- */
/*
 * Copyright 2022 Atsushi Nakamura.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_APCMA_SDR_APCMA_TX_IMPL_H
#define INCLUDED_APCMA_SDR_APCMA_TX_IMPL_H

#include <fstream>
#include <gnuradio/apcma_sdr/apcma_tx.h>
#include <gnuradio/io_signature.h>
#include <iostream>
#include <numeric>
#include <vector>

namespace gr {
namespace apcma_sdr {

class apcma_tx_impl: public apcma_tx {
  private:
    uint32_t m_sf;
    uint32_t m_samp_rate;
    uint32_t m_bw;
    uint32_t m_nbit;
    uint32_t m_npulse;
    uint32_t m_start_var;
    uint32_t m_end_var;
    uint32_t m_sample_per_slot;
    uint32_t m_length_c;
    uint32_t m_send_index;
    uint32_t m_send_data;

    std::vector<gr_complex> m_upchirp;    ///< reference upchirp
    std::vector<gr_complex> m_zeros;      ///< reference zeros

    std::vector<uint32_t> m_l_send_data;
    std::vector<uint32_t> m_codeword;
    std::vector<uint32_t> m_l_interval;


  public:
    apcma_tx_impl( uint32_t sf, uint32_t bw, uint32_t n_bit, uint32_t n_pulse, uint32_t start_var, uint32_t end_var );
    ~apcma_tx_impl();

    // Where all the action really happens
    int work(
        int                        noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star       &output_items );
};

}    // namespace apcma_sdr
}    // namespace gr

#endif /* INCLUDED_APCMA_SDR_APCMA_TX_IMPL_H */
