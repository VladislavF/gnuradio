/* -*- c++ -*- */
/*
 * Copyright 2004 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

// WARNING: this file is machine generated.  Edits will be over written

#ifndef INCLUDED_TRELLIS_PCCC_DECODER_B_H
#define INCLUDED_TRELLIS_PCCC_DECODER_B_H

#include "fsm.h"
#include "interleaver.h"
#include <gr_block.h>
#include <vector>
#include "siso_type.h"

class trellis_pccc_decoder_b;
typedef boost::shared_ptr<trellis_pccc_decoder_b> trellis_pccc_decoder_b_sptr;

trellis_pccc_decoder_b_sptr trellis_make_pccc_decoder_b (
  const fsm &FSM1, int ST10, int ST1K,
  const fsm &FSM2, int ST20, int ST2K,
  const interleaver &INTERLEAVER,
  int blocklength,
  int repetitions,
  trellis_siso_type_t SISO_TYPE // perform "min-sum" or "sum-product" combining 
);


/*!
 *  \ingroup coding_blk
 */
class trellis_pccc_decoder_b : public gr_block
{
  fsm d_FSM1;
  fsm d_FSM2;
  int d_ST10;
  int d_ST1K;
  int d_ST20;
  int d_ST2K;
  interleaver d_INTERLEAVER;
  int d_blocklength;
  int d_repetitions;
  trellis_siso_type_t d_SISO_TYPE;
  std::vector<float> d_buffer;

  friend trellis_pccc_decoder_b_sptr trellis_make_pccc_decoder_b (
    const fsm &FSM1, int ST10, int ST1K,
    const fsm &FSM2, int ST20, int ST2K,
    const interleaver &INTERLEAVER,
    int blocklength,
    int repetitions,
    trellis_siso_type_t SISO_TYPE
  );

  trellis_pccc_decoder_b (
    const fsm &FSM1, int ST10, int ST1K,
    const fsm &FSM2, int ST20, int ST2K,
    const interleaver &INTERLEAVER,
    int blocklength,
    int repetitions,
    trellis_siso_type_t SISO_TYPE 
  );

public:
  fsm FSM1 () const { return d_FSM1; }
  fsm FSM2 () const { return d_FSM2; }
  int ST10 () const { return d_ST10; }
  int ST1K () const { return d_ST1K; }
  int ST20 () const { return d_ST20; }
  int ST2K () const { return d_ST2K; }
  interleaver INTERLEAVER () const { return d_INTERLEAVER; }
  int blocklength () const { return d_blocklength; }
  int repetitions () const { return d_repetitions; }
  trellis_siso_type_t SISO_TYPE () const { return d_SISO_TYPE; }

  void forecast (int noutput_items,
                 gr_vector_int &ninput_items_required);
  int general_work (int noutput_items,
                    gr_vector_int &ninput_items,
                    gr_vector_const_void_star &input_items,
                    gr_vector_void_star &output_items);
};

#endif
