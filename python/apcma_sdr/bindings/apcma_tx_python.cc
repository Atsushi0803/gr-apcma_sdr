/*
 * Copyright 2022 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(apcma_tx.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(049bd5882420d5b259184b0f7718f319)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/apcma_sdr/apcma_tx.h>
// pydoc.h is automatically generated in the build directory
#include <apcma_tx_pydoc.h>

void bind_apcma_tx(py::module& m)
{

    using apcma_tx    = gr::apcma_sdr::apcma_tx;


    py::class_<apcma_tx, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<apcma_tx>>(m, "apcma_tx", D(apcma_tx))

        .def(py::init(&apcma_tx::make),
           D(apcma_tx,make)
        )
        



        ;




}








