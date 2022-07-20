/* -*- c++ -*- */
/*
 * Copyright 2022 Atsushi Nakamura.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_APCMA_SDR_APCMA_TX_H
#define INCLUDED_APCMA_SDR_APCMA_TX_H

#include <gnuradio/apcma_sdr/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace apcma_sdr {

    /*!
     * \brief <+description of block+>
     * \ingroup apcma_sdr
     *
     */
    class APCMA_SDR_API apcma_tx : virtual public gr::sync_block
    {
     public:
      typedef std::shared_ptr<apcma_tx> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of apcma_sdr::apcma_tx.
       *
       * To avoid accidental use of raw pointers, apcma_sdr::apcma_tx's
       * constructor is in a private implementation
       * class. apcma_sdr::apcma_tx::make is the public interface for
       * creating new instances.
       */
      static sptr make(uint32_t sf = 7, uint32_t bw = 250000, uint32_t n_bit = 4, uint32_t n_pulse = 4, uint32_t start_var = 1, uint32_t end_var = 8);
    };

  } // namespace apcma_sdr
} // namespace gr

#endif /* INCLUDED_APCMA_SDR_APCMA_TX_H */
