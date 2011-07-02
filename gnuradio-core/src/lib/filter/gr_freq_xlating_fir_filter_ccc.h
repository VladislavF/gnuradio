/* -*- c++ -*- */
/*
 * Copyright 2002,2004 Free Software Foundation, Inc.
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

/*
 * WARNING: This file is automatically generated by
 * generate_gr_freq_xlating_fir_filter_XXX.py  Any changes made to this file
 * will be overwritten.
 */

#ifndef INCLUDED_GR_FREQ_XLATING_FIR_FILTER_CCC_H
#define	INCLUDED_GR_FREQ_XLATING_FIR_FILTER_CCC_H

#include <gr_sync_decimator.h>
#include <gr_rotator.h>

class gr_freq_xlating_fir_filter_ccc;
typedef boost::shared_ptr<gr_freq_xlating_fir_filter_ccc> gr_freq_xlating_fir_filter_ccc_sptr;

/*!
 * Construct a FIR filter with the given taps and a composite frequency
 * translation that shifts center_freq down to zero Hz.  The frequency 
 * translation logically comes before the filtering operation.
 */
gr_freq_xlating_fir_filter_ccc_sptr 
gr_make_freq_xlating_fir_filter_ccc (int decimation, const std::vector<gr_complex> &taps,
		     double center_freq, double sampling_freq);


class gr_fir_ccc;

/*!
 * \brief FIR filter combined with frequency translation with gr_complex input, gr_complex output and gr_complex taps
 * \ingroup filter_blk
 *
 * This class efficiently combines a frequency translation
 * (typically "down conversion") with a FIR filter (typically low-pass)
 * and decimation.  It is ideally suited for a "channel selection filter"
 * and can be efficiently used to select and decimate a narrow band signal
 * out of wide bandwidth input.
 *
 * Uses a single input array to produce a single output array.
 * Additional inputs and/or outputs are ignored.
 */
class gr_freq_xlating_fir_filter_ccc : public gr_sync_decimator
{
 public:
  virtual ~gr_freq_xlating_fir_filter_ccc ();

  void set_center_freq (double center_freq);
  void set_taps (const std::vector<gr_complex> &taps);

  int work (int noutput_items,
	    gr_vector_const_void_star &input_items,
	    gr_vector_void_star &output_items);

 private:
  friend gr_freq_xlating_fir_filter_ccc_sptr 
  gr_make_freq_xlating_fir_filter_ccc (int decimation, const std::vector<gr_complex> &taps,
		       double center_freq, double sampling_freq);

 protected:
  std::vector<gr_complex>	d_proto_taps;
  gr_fir_ccc		       *d_composite_fir;
  gr_rotator			d_r;
  double			d_center_freq;
  double			d_sampling_freq;
  bool				d_updated;

  virtual void build_composite_fir ();

  /*!
   * Construct a FIR filter with the given taps and a composite frequency
   * translation that shifts center_freq down to zero Hz.  The frequency 
   * translation logically comes before the filtering operation.
   */
  gr_freq_xlating_fir_filter_ccc (int decimation,
			  const std::vector<gr_complex> &taps,
			  double center_freq, double sampling_freq);
};

#endif /* _gr_freq_xlating_fir_filter_ccc_H_ */
