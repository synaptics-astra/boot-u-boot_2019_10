/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2016~2023 Synaptics Incorporated. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 or
 * later as published by the Free Software Foundation.
 *
 * INFORMATION CONTAINED IN THIS DOCUMENT IS PROVIDED "AS-IS," AND
 * SYNAPTICS EXPRESSLY DISCLAIMS ALL EXPRESS AND IMPLIED WARRANTIES,
 * INCLUDING ANY IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE, AND ANY WARRANTIES OF NON-INFRINGEMENT OF ANY
 * INTELLECTUAL PROPERTY RIGHTS. IN NO EVENT SHALL SYNAPTICS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, PUNITIVE, OR
 * CONSEQUENTIAL DAMAGES ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OF THE INFORMATION CONTAINED IN THIS DOCUMENT, HOWEVER CAUSED AND
 * BASED ON ANY THEORY OF LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, AND EVEN IF SYNAPTICS WAS
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. IF A TRIBUNAL OF
 * COMPETENT JURISDICTION DOES NOT PERMIT THE DISCLAIMER OF DIRECT
 * DAMAGES OR ANY OTHER DAMAGES, SYNAPTICS' TOTAL CUMULATIVE LIABILITY
 * TO ANY PARTY SHALL NOT EXCEED ONE HUNDRED U.S. DOLLARS.
 */

#ifndef mc_wrap_h
#define mc_wrap_h () {}

#include "ctypes.h"

#pragma pack(1)
#ifdef __cplusplus
  extern "C" {
#endif

#ifndef _DOCC_H_BITOPS_
#define _DOCC_H_BITOPS_ () {}

    #define _bSETMASK_(b)                                      ((b) < 32 ? (1 << ((b) & 31)) : 0)
    #define _NSETMASK_(msb, lsb)                                (_bSETMASK_((msb) + 1) - _bSETMASK_(lsb))
    #define _bCLRMASK_(b)                                      (~_bSETMASK_(b))
    #define _NCLRMASK_(msb, lsb)                                (~_NSETMASK_(msb, lsb))
    #define _BFGET_(r, msb, lsb)                                 (_NSETMASK_((msb) - (lsb), 0) & ((r) >> (lsb)))
    #define _BFSET_(r, msb, lsb, v)                               do { (r) &= _NCLRMASK_(msb, lsb); (r) |= _NSETMASK_(msb, lsb) & ((v) << (lsb)); } while (0)

#endif

//////
///
/// $INTERFACE abipll                  biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 ctrlA                (P-)
///               ###
///               * PLL Control
///               ###
///               %unsigned 1  RESET                     0x0
///                                    ###
///                                    * PLL Internal Reset Active High
///                                    ###
///               %unsigned 1  BYPASS                    0x0
///                                    ###
///                                    * PLL Bypass Enable Active High
///                                    ###
///               %unsigned 1  NEWDIV                    0x0
///                                    ###
///                                    * Fractional Divide Input Control
///                                    ###
///               %unsigned 3  RANGE                     0x2
///                                    ###
///                                    * PLL Filter Range
///                                    ###
///               %%        26         # Stuffing bits...
///     @ 0x00004 ctrlB                (P-)
///               %unsigned 4  SSMF                      0x0
///                                    ###
///                                    * Spread Spectrum Modulation Frequency
///                                    ###
///               %unsigned 3  SSMD                      0x0
///                                    ###
///                                    * Spread Spectrum Modulation Depth
///                                    ###
///               %unsigned 1  SSE_RSVD                  0x0
///                                    ###
///                                    * Spread Spectrum Reserve Bit
///                                    ###
///               %unsigned 1  SSE                       0x0
///                                    ###
///                                    * Enables Spread Spectrum Mode Active High
///                                    ###
///               %unsigned 1  SSDS                      0x0
///                                    ###
///                                    * Spread Spectrum Down Spread Center Spread
///                                    ###
///               %%        22         # Stuffing bits...
///     @ 0x00008 ctrlC                (P-)
///               %unsigned 6  DIVR                      0x1
///                                    ###
///                                    * Reference Divider
///                                    ###
///               %%        26         # Stuffing bits...
///     @ 0x0000C ctrlD                (P-)
///               %unsigned 9  DIVFI                     0x1F
///                                    ###
///                                    * Integer Divider
///                                    ###
///               %%        23         # Stuffing bits...
///     @ 0x00010 ctrlE                (P-)
///               %unsigned 24 DIVFF                     0x0
///                                    ###
///                                    * Fractional Divider Control
///                                    ###
///               %%        8          # Stuffing bits...
///     @ 0x00014 ctrlF                (P-)
///               %unsigned 5  DIVQ                      0x1
///                                    ###
///                                    * Output Divider Control for PLLOUT
///                                    ###
///               %%        27         # Stuffing bits...
///     @ 0x00018 ctrlG                (P-)
///               %unsigned 3  DIVQF                     0x3
///                                    ###
///                                    * Output Divider Control for PLLOUTF
///                                    ###
///               %%        29         # Stuffing bits...
///     @ 0x0001C status               (R-)
///               ###
///               * PLL status register
///               ###
///               %unsigned 1  LOCK
///                                    ###
///                                    * Output. Lock detection
///                                    ###
///               %unsigned 1  DIVACK
///                                    ###
///                                    * Fractional Divide Hand-shake signal
///                                    ###
///               %%        30         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      32B, bits:      65b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_abipll
#define h_abipll () {}

    #define     RA_abipll_ctrlA                                0x0000

    #define     BA_abipll_ctrlA_RESET                          0x0000
    #define     B16abipll_ctrlA_RESET                          0x0000
    #define   LSb32abipll_ctrlA_RESET                             0
    #define   LSb16abipll_ctrlA_RESET                             0
    #define       babipll_ctrlA_RESET                          1
    #define   MSK32abipll_ctrlA_RESET                             0x00000001

    #define     BA_abipll_ctrlA_BYPASS                         0x0000
    #define     B16abipll_ctrlA_BYPASS                         0x0000
    #define   LSb32abipll_ctrlA_BYPASS                            1
    #define   LSb16abipll_ctrlA_BYPASS                            1
    #define       babipll_ctrlA_BYPASS                         1
    #define   MSK32abipll_ctrlA_BYPASS                            0x00000002

    #define     BA_abipll_ctrlA_NEWDIV                         0x0000
    #define     B16abipll_ctrlA_NEWDIV                         0x0000
    #define   LSb32abipll_ctrlA_NEWDIV                            2
    #define   LSb16abipll_ctrlA_NEWDIV                            2
    #define       babipll_ctrlA_NEWDIV                         1
    #define   MSK32abipll_ctrlA_NEWDIV                            0x00000004

    #define     BA_abipll_ctrlA_RANGE                          0x0000
    #define     B16abipll_ctrlA_RANGE                          0x0000
    #define   LSb32abipll_ctrlA_RANGE                             3
    #define   LSb16abipll_ctrlA_RANGE                             3
    #define       babipll_ctrlA_RANGE                          3
    #define   MSK32abipll_ctrlA_RANGE                             0x00000038
    ///////////////////////////////////////////////////////////
    #define     RA_abipll_ctrlB                                0x0004

    #define     BA_abipll_ctrlB_SSMF                           0x0004
    #define     B16abipll_ctrlB_SSMF                           0x0004
    #define   LSb32abipll_ctrlB_SSMF                              0
    #define   LSb16abipll_ctrlB_SSMF                              0
    #define       babipll_ctrlB_SSMF                           4
    #define   MSK32abipll_ctrlB_SSMF                              0x0000000F

    #define     BA_abipll_ctrlB_SSMD                           0x0004
    #define     B16abipll_ctrlB_SSMD                           0x0004
    #define   LSb32abipll_ctrlB_SSMD                              4
    #define   LSb16abipll_ctrlB_SSMD                              4
    #define       babipll_ctrlB_SSMD                           3
    #define   MSK32abipll_ctrlB_SSMD                              0x00000070

    #define     BA_abipll_ctrlB_SSE_RSVD                       0x0004
    #define     B16abipll_ctrlB_SSE_RSVD                       0x0004
    #define   LSb32abipll_ctrlB_SSE_RSVD                          7
    #define   LSb16abipll_ctrlB_SSE_RSVD                          7
    #define       babipll_ctrlB_SSE_RSVD                       1
    #define   MSK32abipll_ctrlB_SSE_RSVD                          0x00000080

    #define     BA_abipll_ctrlB_SSE                            0x0005
    #define     B16abipll_ctrlB_SSE                            0x0004
    #define   LSb32abipll_ctrlB_SSE                               8
    #define   LSb16abipll_ctrlB_SSE                               8
    #define       babipll_ctrlB_SSE                            1
    #define   MSK32abipll_ctrlB_SSE                               0x00000100

    #define     BA_abipll_ctrlB_SSDS                           0x0005
    #define     B16abipll_ctrlB_SSDS                           0x0004
    #define   LSb32abipll_ctrlB_SSDS                              9
    #define   LSb16abipll_ctrlB_SSDS                              9
    #define       babipll_ctrlB_SSDS                           1
    #define   MSK32abipll_ctrlB_SSDS                              0x00000200
    ///////////////////////////////////////////////////////////
    #define     RA_abipll_ctrlC                                0x0008

    #define     BA_abipll_ctrlC_DIVR                           0x0008
    #define     B16abipll_ctrlC_DIVR                           0x0008
    #define   LSb32abipll_ctrlC_DIVR                              0
    #define   LSb16abipll_ctrlC_DIVR                              0
    #define       babipll_ctrlC_DIVR                           6
    #define   MSK32abipll_ctrlC_DIVR                              0x0000003F
    ///////////////////////////////////////////////////////////
    #define     RA_abipll_ctrlD                                0x000C

    #define     BA_abipll_ctrlD_DIVFI                          0x000C
    #define     B16abipll_ctrlD_DIVFI                          0x000C
    #define   LSb32abipll_ctrlD_DIVFI                             0
    #define   LSb16abipll_ctrlD_DIVFI                             0
    #define       babipll_ctrlD_DIVFI                          9
    #define   MSK32abipll_ctrlD_DIVFI                             0x000001FF
    ///////////////////////////////////////////////////////////
    #define     RA_abipll_ctrlE                                0x0010

    #define     BA_abipll_ctrlE_DIVFF                          0x0010
    #define     B16abipll_ctrlE_DIVFF                          0x0010
    #define   LSb32abipll_ctrlE_DIVFF                             0
    #define   LSb16abipll_ctrlE_DIVFF                             0
    #define       babipll_ctrlE_DIVFF                          24
    #define   MSK32abipll_ctrlE_DIVFF                             0x00FFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_abipll_ctrlF                                0x0014

    #define     BA_abipll_ctrlF_DIVQ                           0x0014
    #define     B16abipll_ctrlF_DIVQ                           0x0014
    #define   LSb32abipll_ctrlF_DIVQ                              0
    #define   LSb16abipll_ctrlF_DIVQ                              0
    #define       babipll_ctrlF_DIVQ                           5
    #define   MSK32abipll_ctrlF_DIVQ                              0x0000001F
    ///////////////////////////////////////////////////////////
    #define     RA_abipll_ctrlG                                0x0018

    #define     BA_abipll_ctrlG_DIVQF                          0x0018
    #define     B16abipll_ctrlG_DIVQF                          0x0018
    #define   LSb32abipll_ctrlG_DIVQF                             0
    #define   LSb16abipll_ctrlG_DIVQF                             0
    #define       babipll_ctrlG_DIVQF                          3
    #define   MSK32abipll_ctrlG_DIVQF                             0x00000007
    ///////////////////////////////////////////////////////////
    #define     RA_abipll_status                               0x001C

    #define     BA_abipll_status_LOCK                          0x001C
    #define     B16abipll_status_LOCK                          0x001C
    #define   LSb32abipll_status_LOCK                             0
    #define   LSb16abipll_status_LOCK                             0
    #define       babipll_status_LOCK                          1
    #define   MSK32abipll_status_LOCK                             0x00000001

    #define     BA_abipll_status_DIVACK                        0x001C
    #define     B16abipll_status_DIVACK                        0x001C
    #define   LSb32abipll_status_DIVACK                           1
    #define   LSb16abipll_status_DIVACK                           1
    #define       babipll_status_DIVACK                        1
    #define   MSK32abipll_status_DIVACK                           0x00000002
    ///////////////////////////////////////////////////////////

    typedef struct SIE_abipll {
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_ctrlA_RESET(r32)                     _BFGET_(r32, 0, 0)
    #define   SET32abipll_ctrlA_RESET(r32, v)                   _BFSET_(r32, 0, 0, v)
    #define   GET16abipll_ctrlA_RESET(r16)                     _BFGET_(r16, 0, 0)
    #define   SET16abipll_ctrlA_RESET(r16, v)                   _BFSET_(r16, 0, 0, v)

    #define   GET32abipll_ctrlA_BYPASS(r32)                    _BFGET_(r32, 1, 1)
    #define   SET32abipll_ctrlA_BYPASS(r32, v)                  _BFSET_(r32, 1, 1, v)
    #define   GET16abipll_ctrlA_BYPASS(r16)                    _BFGET_(r16, 1, 1)
    #define   SET16abipll_ctrlA_BYPASS(r16, v)                  _BFSET_(r16, 1, 1, v)

    #define   GET32abipll_ctrlA_NEWDIV(r32)                    _BFGET_(r32, 2, 2)
    #define   SET32abipll_ctrlA_NEWDIV(r32, v)                  _BFSET_(r32, 2, 2, v)
    #define   GET16abipll_ctrlA_NEWDIV(r16)                    _BFGET_(r16, 2, 2)
    #define   SET16abipll_ctrlA_NEWDIV(r16, v)                  _BFSET_(r16, 2, 2, v)

    #define   GET32abipll_ctrlA_RANGE(r32)                     _BFGET_(r32, 5, 3)
    #define   SET32abipll_ctrlA_RANGE(r32, v)                   _BFSET_(r32, 5, 3, v)
    #define   GET16abipll_ctrlA_RANGE(r16)                     _BFGET_(r16, 5, 3)
    #define   SET16abipll_ctrlA_RANGE(r16, v)                   _BFSET_(r16, 5, 3, v)

    #define     w32abipll_ctrlA                                {\
	    UNSG32 uctrlA_RESET                                :  1;\
	    UNSG32 uctrlA_BYPASS                               :  1;\
	    UNSG32 uctrlA_NEWDIV                               :  1;\
	    UNSG32 uctrlA_RANGE                                :  3;\
	    UNSG32 RSVDx0_b6                                   : 26;\
	}
    union { UNSG32 u32abipll_ctrlA;
	    struct w32abipll_ctrlA;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_ctrlB_SSMF(r32)                      _BFGET_(r32, 3, 0)
    #define   SET32abipll_ctrlB_SSMF(r32, v)                    _BFSET_(r32, 3, 0, v)
    #define   GET16abipll_ctrlB_SSMF(r16)                      _BFGET_(r16, 3, 0)
    #define   SET16abipll_ctrlB_SSMF(r16, v)                    _BFSET_(r16, 3, 0, v)

    #define   GET32abipll_ctrlB_SSMD(r32)                      _BFGET_(r32, 6, 4)
    #define   SET32abipll_ctrlB_SSMD(r32, v)                    _BFSET_(r32, 6, 4, v)
    #define   GET16abipll_ctrlB_SSMD(r16)                      _BFGET_(r16, 6, 4)
    #define   SET16abipll_ctrlB_SSMD(r16, v)                    _BFSET_(r16, 6, 4, v)

    #define   GET32abipll_ctrlB_SSE_RSVD(r32)                  _BFGET_(r32, 7, 7)
    #define   SET32abipll_ctrlB_SSE_RSVD(r32, v)                _BFSET_(r32, 7, 7, v)
    #define   GET16abipll_ctrlB_SSE_RSVD(r16)                  _BFGET_(r16, 7, 7)
    #define   SET16abipll_ctrlB_SSE_RSVD(r16, v)                _BFSET_(r16, 7, 7, v)

    #define   GET32abipll_ctrlB_SSE(r32)                       _BFGET_(r32, 8, 8)
    #define   SET32abipll_ctrlB_SSE(r32, v)                     _BFSET_(r32, 8, 8, v)
    #define   GET16abipll_ctrlB_SSE(r16)                       _BFGET_(r16, 8, 8)
    #define   SET16abipll_ctrlB_SSE(r16, v)                     _BFSET_(r16, 8, 8, v)

    #define   GET32abipll_ctrlB_SSDS(r32)                      _BFGET_(r32, 9, 9)
    #define   SET32abipll_ctrlB_SSDS(r32, v)                    _BFSET_(r32, 9, 9, v)
    #define   GET16abipll_ctrlB_SSDS(r16)                      _BFGET_(r16, 9, 9)
    #define   SET16abipll_ctrlB_SSDS(r16, v)                    _BFSET_(r16, 9, 9, v)

    #define     w32abipll_ctrlB                                {\
	    UNSG32 uctrlB_SSMF                                 :  4;\
	    UNSG32 uctrlB_SSMD                                 :  3;\
	    UNSG32 uctrlB_SSE_RSVD                             :  1;\
	    UNSG32 uctrlB_SSE                                  :  1;\
	    UNSG32 uctrlB_SSDS                                 :  1;\
	    UNSG32 RSVDx4_b10                                  : 22;\
	}
    union { UNSG32 u32abipll_ctrlB;
	    struct w32abipll_ctrlB;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_ctrlC_DIVR(r32)                      _BFGET_(r32, 5, 0)
    #define   SET32abipll_ctrlC_DIVR(r32, v)                    _BFSET_(r32, 5, 0, v)
    #define   GET16abipll_ctrlC_DIVR(r16)                      _BFGET_(r16, 5, 0)
    #define   SET16abipll_ctrlC_DIVR(r16, v)                    _BFSET_(r16, 5, 0, v)

    #define     w32abipll_ctrlC                                {\
	    UNSG32 uctrlC_DIVR                                 :  6;\
	    UNSG32 RSVDx8_b6                                   : 26;\
	}
    union { UNSG32 u32abipll_ctrlC;
	    struct w32abipll_ctrlC;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_ctrlD_DIVFI(r32)                     _BFGET_(r32, 8, 0)
    #define   SET32abipll_ctrlD_DIVFI(r32, v)                   _BFSET_(r32, 8, 0, v)
    #define   GET16abipll_ctrlD_DIVFI(r16)                     _BFGET_(r16, 8, 0)
    #define   SET16abipll_ctrlD_DIVFI(r16, v)                   _BFSET_(r16, 8, 0, v)

    #define     w32abipll_ctrlD                                {\
	    UNSG32 uctrlD_DIVFI                                :  9;\
	    UNSG32 RSVDxC_b9                                   : 23;\
	}
    union { UNSG32 u32abipll_ctrlD;
	    struct w32abipll_ctrlD;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_ctrlE_DIVFF(r32)                     _BFGET_(r32, 23, 0)
    #define   SET32abipll_ctrlE_DIVFF(r32, v)                   _BFSET_(r32, 23, 0, v)

    #define     w32abipll_ctrlE                                {\
	    UNSG32 uctrlE_DIVFF                                : 24;\
	    UNSG32 RSVDx10_b24                                 :  8;\
	}
    union { UNSG32 u32abipll_ctrlE;
	    struct w32abipll_ctrlE;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_ctrlF_DIVQ(r32)                      _BFGET_(r32, 4, 0)
    #define   SET32abipll_ctrlF_DIVQ(r32, v)                    _BFSET_(r32, 4, 0, v)
    #define   GET16abipll_ctrlF_DIVQ(r16)                      _BFGET_(r16, 4, 0)
    #define   SET16abipll_ctrlF_DIVQ(r16, v)                    _BFSET_(r16, 4, 0, v)

    #define     w32abipll_ctrlF                                {\
	    UNSG32 uctrlF_DIVQ                                 :  5;\
	    UNSG32 RSVDx14_b5                                  : 27;\
	}
    union { UNSG32 u32abipll_ctrlF;
	    struct w32abipll_ctrlF;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_ctrlG_DIVQF(r32)                     _BFGET_(r32, 2, 0)
    #define   SET32abipll_ctrlG_DIVQF(r32, v)                   _BFSET_(r32, 2, 0, v)
    #define   GET16abipll_ctrlG_DIVQF(r16)                     _BFGET_(r16, 2, 0)
    #define   SET16abipll_ctrlG_DIVQF(r16, v)                   _BFSET_(r16, 2, 0, v)

    #define     w32abipll_ctrlG                                {\
	    UNSG32 uctrlG_DIVQF                                :  3;\
	    UNSG32 RSVDx18_b3                                  : 29;\
	}
    union { UNSG32 u32abipll_ctrlG;
	    struct w32abipll_ctrlG;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_status_LOCK(r32)                     _BFGET_(r32, 0, 0)
    #define   SET32abipll_status_LOCK(r32, v)                   _BFSET_(r32, 0, 0, v)
    #define   GET16abipll_status_LOCK(r16)                     _BFGET_(r16, 0, 0)
    #define   SET16abipll_status_LOCK(r16, v)                   _BFSET_(r16, 0, 0, v)

    #define   GET32abipll_status_DIVACK(r32)                   _BFGET_(r32, 1, 1)
    #define   SET32abipll_status_DIVACK(r32, v)                 _BFSET_(r32, 1, 1, v)
    #define   GET16abipll_status_DIVACK(r16)                   _BFGET_(r16, 1, 1)
    #define   SET16abipll_status_DIVACK(r16, v)                 _BFSET_(r16, 1, 1, v)

    #define     w32abipll_status                               {\
	    UNSG32 ustatus_LOCK                                :  1;\
	    UNSG32 ustatus_DIVACK                              :  1;\
	    UNSG32 RSVDx1C_b2                                  : 30;\
	}
    union { UNSG32 u32abipll_status;
	    struct w32abipll_status;
	  };
    ///////////////////////////////////////////////////////////
    } SIE_abipll;

    typedef union  T32abipll_ctrlA {
		UNSG32 u32;
	    struct w32abipll_ctrlA;
		 } T32abipll_ctrlA;
    typedef union  T32abipll_ctrlB {
		UNSG32 u32;
	    struct w32abipll_ctrlB;
		 } T32abipll_ctrlB;
    typedef union  T32abipll_ctrlC {
		UNSG32 u32;
	    struct w32abipll_ctrlC;
		 } T32abipll_ctrlC;
    typedef union  T32abipll_ctrlD {
		UNSG32 u32;
	    struct w32abipll_ctrlD;
		 } T32abipll_ctrlD;
    typedef union  T32abipll_ctrlE {
		UNSG32 u32;
	    struct w32abipll_ctrlE;
		 } T32abipll_ctrlE;
    typedef union  T32abipll_ctrlF {
		UNSG32 u32;
	    struct w32abipll_ctrlF;
		 } T32abipll_ctrlF;
    typedef union  T32abipll_ctrlG {
		UNSG32 u32;
	    struct w32abipll_ctrlG;
		 } T32abipll_ctrlG;
    typedef union  T32abipll_status {
		UNSG32 u32;
	    struct w32abipll_status;
		 } T32abipll_status;
    ///////////////////////////////////////////////////////////

    typedef union  Tabipll_ctrlA {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_ctrlA;
		   };
		 } Tabipll_ctrlA;
    typedef union  Tabipll_ctrlB {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_ctrlB;
		   };
		 } Tabipll_ctrlB;
    typedef union  Tabipll_ctrlC {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_ctrlC;
		   };
		 } Tabipll_ctrlC;
    typedef union  Tabipll_ctrlD {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_ctrlD;
		   };
		 } Tabipll_ctrlD;
    typedef union  Tabipll_ctrlE {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_ctrlE;
		   };
		 } Tabipll_ctrlE;
    typedef union  Tabipll_ctrlF {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_ctrlF;
		   };
		 } Tabipll_ctrlF;
    typedef union  Tabipll_ctrlG {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_ctrlG;
		   };
		 } Tabipll_ctrlG;
    typedef union  Tabipll_status {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_status;
		   };
		 } Tabipll_status;

    ///////////////////////////////////////////////////////////
     SIGN32 abipll_drvrd(SIE_abipll *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 abipll_drvwr(SIE_abipll *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void abipll_reset(SIE_abipll *p);
     SIGN32 abipll_cmp(SIE_abipll *p, SIE_abipll *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define abipll_check(p, pie, pfx, hLOG) abipll_cmp(p, pie, pfx, (void *)(hLOG), 0, 0)
    #define abipll_print(p,    pfx, hLOG) abipll_cmp(p, 0,  pfx, (void *)(hLOG), 0, 0)

#endif
//////
/// ENDOFINTERFACE: abipll
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE abipll_rw               biu              (4,4)
///     # # ----------------------------------------------------------
///     @ 0x00000 ctrlA                (RW)
///               ###
///               * PLL Control
///               ###
///               %unsigned 1  RESET                     0x0
///                                    ###
///                                    * PLL Internal Reset Active High
///                                    ###
///               %unsigned 1  BYPASS                    0x0
///                                    ###
///                                    * PLL Bypass Enable Active High
///                                    ###
///               %unsigned 1  NEWDIV                    0x0
///                                    ###
///                                    * Fractional Divide Input Control
///                                    ###
///               %unsigned 3  RANGE                     0x2
///                                    ###
///                                    * PLL Filter Range
///                                    ###
///               %%        26         # Stuffing bits...
///     @ 0x00004 ctrlB                (RW)
///               %unsigned 4  SSMF                      0x0
///                                    ###
///                                    * Spread Spectrum Modulation Frequency
///                                    ###
///               %unsigned 3  SSMD                      0x0
///                                    ###
///                                    * Spread Spectrum Modulation Depth
///                                    ###
///               %unsigned 1  SSE_RSVD                  0x0
///                                    ###
///                                    *  Spread Spectrum Reserve Bit
///                                    ###
///               %unsigned 1  SSE                       0x0
///                                    ###
///                                    * Enables Spread Spectrum Mode Active High
///                                    ###
///               %unsigned 1  SSDS                      0x0
///                                    ###
///                                    * Spread Spectrum Down Spread Center Spread
///                                    ###
///               %%        22         # Stuffing bits...
///     @ 0x00008 ctrlC                (RW)
///               %unsigned 6  DIVR                      0x1
///                                    ###
///                                    * Reference Divider
///                                    ###
///               %%        26         # Stuffing bits...
///     @ 0x0000C ctrlD                (RW)
///               %unsigned 9  DIVFI                     0x1F
///                                    ###
///                                    * Integer Divider
///                                    ###
///               %%        23         # Stuffing bits...
///     @ 0x00010 ctrlE                (RW)
///               %unsigned 24 DIVFF                     0x0
///                                    ###
///                                    * Fractional Divider Control
///                                    ###
///               %%        8          # Stuffing bits...
///     @ 0x00014 ctrlF                (RW)
///               %unsigned 5  DIVQ                      0x1
///                                    ###
///                                    * Output Divider Control for PLLOUT
///                                    ###
///               %%        27         # Stuffing bits...
///     @ 0x00018 ctrlG                (RW)
///               %unsigned 3  DIVQF                     0x3
///                                    ###
///                                    * Output Divider Control for PLLOUTF
///                                    ###
///               %%        29         # Stuffing bits...
///     @ 0x0001C status               (R-)
///               ###
///               * PLL status register
///               ###
///               %unsigned 1  LOCK
///                                    ###
///                                    *  Output. Lock detection
///                                    ###
///               %unsigned 1  DIVACK
///                                    ###
///                                    * Fractional Divide Hand-shake signal
///                                    ###
///               %%        30         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      32B, bits:      65b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_abipll_rw
#define h_abipll_rw () {}

    #define     RA_abipll_rw_ctrlA                             0x0000

    #define     BA_abipll_rw_ctrlA_RESET                       0x0000
    #define     B16abipll_rw_ctrlA_RESET                       0x0000
    #define   LSb32abipll_rw_ctrlA_RESET                          0
    #define   LSb16abipll_rw_ctrlA_RESET                          0
    #define       babipll_rw_ctrlA_RESET                       1
    #define   MSK32abipll_rw_ctrlA_RESET                          0x00000001

    #define     BA_abipll_rw_ctrlA_BYPASS                      0x0000
    #define     B16abipll_rw_ctrlA_BYPASS                      0x0000
    #define   LSb32abipll_rw_ctrlA_BYPASS                         1
    #define   LSb16abipll_rw_ctrlA_BYPASS                         1
    #define       babipll_rw_ctrlA_BYPASS                      1
    #define   MSK32abipll_rw_ctrlA_BYPASS                         0x00000002

    #define     BA_abipll_rw_ctrlA_NEWDIV                      0x0000
    #define     B16abipll_rw_ctrlA_NEWDIV                      0x0000
    #define   LSb32abipll_rw_ctrlA_NEWDIV                         2
    #define   LSb16abipll_rw_ctrlA_NEWDIV                         2
    #define       babipll_rw_ctrlA_NEWDIV                      1
    #define   MSK32abipll_rw_ctrlA_NEWDIV                         0x00000004

    #define     BA_abipll_rw_ctrlA_RANGE                       0x0000
    #define     B16abipll_rw_ctrlA_RANGE                       0x0000
    #define   LSb32abipll_rw_ctrlA_RANGE                          3
    #define   LSb16abipll_rw_ctrlA_RANGE                          3
    #define       babipll_rw_ctrlA_RANGE                       3
    #define   MSK32abipll_rw_ctrlA_RANGE                          0x00000038
    ///////////////////////////////////////////////////////////
    #define     RA_abipll_rw_ctrlB                             0x0004

    #define     BA_abipll_rw_ctrlB_SSMF                        0x0004
    #define     B16abipll_rw_ctrlB_SSMF                        0x0004
    #define   LSb32abipll_rw_ctrlB_SSMF                           0
    #define   LSb16abipll_rw_ctrlB_SSMF                           0
    #define       babipll_rw_ctrlB_SSMF                        4
    #define   MSK32abipll_rw_ctrlB_SSMF                           0x0000000F

    #define     BA_abipll_rw_ctrlB_SSMD                        0x0004
    #define     B16abipll_rw_ctrlB_SSMD                        0x0004
    #define   LSb32abipll_rw_ctrlB_SSMD                           4
    #define   LSb16abipll_rw_ctrlB_SSMD                           4
    #define       babipll_rw_ctrlB_SSMD                        3
    #define   MSK32abipll_rw_ctrlB_SSMD                           0x00000070

    #define     BA_abipll_rw_ctrlB_SSE_RSVD                    0x0004
    #define     B16abipll_rw_ctrlB_SSE_RSVD                    0x0004
    #define   LSb32abipll_rw_ctrlB_SSE_RSVD                       7
    #define   LSb16abipll_rw_ctrlB_SSE_RSVD                       7
    #define       babipll_rw_ctrlB_SSE_RSVD                    1
    #define   MSK32abipll_rw_ctrlB_SSE_RSVD                       0x00000080

    #define     BA_abipll_rw_ctrlB_SSE                         0x0005
    #define     B16abipll_rw_ctrlB_SSE                         0x0004
    #define   LSb32abipll_rw_ctrlB_SSE                            8
    #define   LSb16abipll_rw_ctrlB_SSE                            8
    #define       babipll_rw_ctrlB_SSE                         1
    #define   MSK32abipll_rw_ctrlB_SSE                            0x00000100

    #define     BA_abipll_rw_ctrlB_SSDS                        0x0005
    #define     B16abipll_rw_ctrlB_SSDS                        0x0004
    #define   LSb32abipll_rw_ctrlB_SSDS                           9
    #define   LSb16abipll_rw_ctrlB_SSDS                           9
    #define       babipll_rw_ctrlB_SSDS                        1
    #define   MSK32abipll_rw_ctrlB_SSDS                           0x00000200
    ///////////////////////////////////////////////////////////
    #define     RA_abipll_rw_ctrlC                             0x0008

    #define     BA_abipll_rw_ctrlC_DIVR                        0x0008
    #define     B16abipll_rw_ctrlC_DIVR                        0x0008
    #define   LSb32abipll_rw_ctrlC_DIVR                           0
    #define   LSb16abipll_rw_ctrlC_DIVR                           0
    #define       babipll_rw_ctrlC_DIVR                        6
    #define   MSK32abipll_rw_ctrlC_DIVR                           0x0000003F
    ///////////////////////////////////////////////////////////
    #define     RA_abipll_rw_ctrlD                             0x000C

    #define     BA_abipll_rw_ctrlD_DIVFI                       0x000C
    #define     B16abipll_rw_ctrlD_DIVFI                       0x000C
    #define   LSb32abipll_rw_ctrlD_DIVFI                          0
    #define   LSb16abipll_rw_ctrlD_DIVFI                          0
    #define       babipll_rw_ctrlD_DIVFI                       9
    #define   MSK32abipll_rw_ctrlD_DIVFI                          0x000001FF
    ///////////////////////////////////////////////////////////
    #define     RA_abipll_rw_ctrlE                             0x0010

    #define     BA_abipll_rw_ctrlE_DIVFF                       0x0010
    #define     B16abipll_rw_ctrlE_DIVFF                       0x0010
    #define   LSb32abipll_rw_ctrlE_DIVFF                          0
    #define   LSb16abipll_rw_ctrlE_DIVFF                          0
    #define       babipll_rw_ctrlE_DIVFF                       24
    #define   MSK32abipll_rw_ctrlE_DIVFF                          0x00FFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_abipll_rw_ctrlF                             0x0014

    #define     BA_abipll_rw_ctrlF_DIVQ                        0x0014
    #define     B16abipll_rw_ctrlF_DIVQ                        0x0014
    #define   LSb32abipll_rw_ctrlF_DIVQ                           0
    #define   LSb16abipll_rw_ctrlF_DIVQ                           0
    #define       babipll_rw_ctrlF_DIVQ                        5
    #define   MSK32abipll_rw_ctrlF_DIVQ                           0x0000001F
    ///////////////////////////////////////////////////////////
    #define     RA_abipll_rw_ctrlG                             0x0018

    #define     BA_abipll_rw_ctrlG_DIVQF                       0x0018
    #define     B16abipll_rw_ctrlG_DIVQF                       0x0018
    #define   LSb32abipll_rw_ctrlG_DIVQF                          0
    #define   LSb16abipll_rw_ctrlG_DIVQF                          0
    #define       babipll_rw_ctrlG_DIVQF                       3
    #define   MSK32abipll_rw_ctrlG_DIVQF                          0x00000007
    ///////////////////////////////////////////////////////////
    #define     RA_abipll_rw_status                            0x001C

    #define     BA_abipll_rw_status_LOCK                       0x001C
    #define     B16abipll_rw_status_LOCK                       0x001C
    #define   LSb32abipll_rw_status_LOCK                          0
    #define   LSb16abipll_rw_status_LOCK                          0
    #define       babipll_rw_status_LOCK                       1
    #define   MSK32abipll_rw_status_LOCK                          0x00000001

    #define     BA_abipll_rw_status_DIVACK                     0x001C
    #define     B16abipll_rw_status_DIVACK                     0x001C
    #define   LSb32abipll_rw_status_DIVACK                        1
    #define   LSb16abipll_rw_status_DIVACK                        1
    #define       babipll_rw_status_DIVACK                     1
    #define   MSK32abipll_rw_status_DIVACK                        0x00000002
    ///////////////////////////////////////////////////////////

    typedef struct SIE_abipll_rw {
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_rw_ctrlA_RESET(r32)                  _BFGET_(r32, 0, 0)
    #define   SET32abipll_rw_ctrlA_RESET(r32, v)                _BFSET_(r32, 0, 0, v)
    #define   GET16abipll_rw_ctrlA_RESET(r16)                  _BFGET_(r16, 0, 0)
    #define   SET16abipll_rw_ctrlA_RESET(r16, v)                _BFSET_(r16, 0, 0, v)

    #define   GET32abipll_rw_ctrlA_BYPASS(r32)                 _BFGET_(r32, 1, 1)
    #define   SET32abipll_rw_ctrlA_BYPASS(r32, v)               _BFSET_(r32, 1, 1, v)
    #define   GET16abipll_rw_ctrlA_BYPASS(r16)                 _BFGET_(r16, 1, 1)
    #define   SET16abipll_rw_ctrlA_BYPASS(r16, v)               _BFSET_(r16, 1, 1, v)

    #define   GET32abipll_rw_ctrlA_NEWDIV(r32)                 _BFGET_(r32, 2, 2)
    #define   SET32abipll_rw_ctrlA_NEWDIV(r32, v)               _BFSET_(r32, 2, 2, v)
    #define   GET16abipll_rw_ctrlA_NEWDIV(r16)                 _BFGET_(r16, 2, 2)
    #define   SET16abipll_rw_ctrlA_NEWDIV(r16, v)               _BFSET_(r16, 2, 2, v)

    #define   GET32abipll_rw_ctrlA_RANGE(r32)                  _BFGET_(r32, 5, 3)
    #define   SET32abipll_rw_ctrlA_RANGE(r32, v)                _BFSET_(r32, 5, 3, v)
    #define   GET16abipll_rw_ctrlA_RANGE(r16)                  _BFGET_(r16, 5, 3)
    #define   SET16abipll_rw_ctrlA_RANGE(r16, v)                _BFSET_(r16, 5, 3, v)

    #define     w32abipll_rw_ctrlA                             {\
	    UNSG32 uctrlA_RESET                                :  1;\
	    UNSG32 uctrlA_BYPASS                               :  1;\
	    UNSG32 uctrlA_NEWDIV                               :  1;\
	    UNSG32 uctrlA_RANGE                                :  3;\
	    UNSG32 RSVDx0_b6                                   : 26;\
	}
    union { UNSG32 u32abipll_rw_ctrlA;
	    struct w32abipll_rw_ctrlA;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_rw_ctrlB_SSMF(r32)                   _BFGET_(r32, 3, 0)
    #define   SET32abipll_rw_ctrlB_SSMF(r32, v)                 _BFSET_(r32, 3, 0, v)
    #define   GET16abipll_rw_ctrlB_SSMF(r16)                   _BFGET_(r16, 3, 0)
    #define   SET16abipll_rw_ctrlB_SSMF(r16, v)                 _BFSET_(r16, 3, 0, v)

    #define   GET32abipll_rw_ctrlB_SSMD(r32)                   _BFGET_(r32, 6, 4)
    #define   SET32abipll_rw_ctrlB_SSMD(r32, v)                 _BFSET_(r32, 6, 4, v)
    #define   GET16abipll_rw_ctrlB_SSMD(r16)                   _BFGET_(r16, 6, 4)
    #define   SET16abipll_rw_ctrlB_SSMD(r16, v)                 _BFSET_(r16, 6, 4, v)

    #define   GET32abipll_rw_ctrlB_SSE_RSVD(r32)               _BFGET_(r32, 7, 7)
    #define   SET32abipll_rw_ctrlB_SSE_RSVD(r32, v)             _BFSET_(r32, 7, 7, v)
    #define   GET16abipll_rw_ctrlB_SSE_RSVD(r16)               _BFGET_(r16, 7, 7)
    #define   SET16abipll_rw_ctrlB_SSE_RSVD(r16, v)             _BFSET_(r16, 7, 7, v)

    #define   GET32abipll_rw_ctrlB_SSE(r32)                    _BFGET_(r32, 8, 8)
    #define   SET32abipll_rw_ctrlB_SSE(r32, v)                  _BFSET_(r32, 8, 8, v)
    #define   GET16abipll_rw_ctrlB_SSE(r16)                    _BFGET_(r16, 8, 8)
    #define   SET16abipll_rw_ctrlB_SSE(r16, v)                  _BFSET_(r16, 8, 8, v)

    #define   GET32abipll_rw_ctrlB_SSDS(r32)                   _BFGET_(r32, 9, 9)
    #define   SET32abipll_rw_ctrlB_SSDS(r32, v)                 _BFSET_(r32, 9, 9, v)
    #define   GET16abipll_rw_ctrlB_SSDS(r16)                   _BFGET_(r16, 9, 9)
    #define   SET16abipll_rw_ctrlB_SSDS(r16, v)                 _BFSET_(r16, 9, 9, v)

    #define     w32abipll_rw_ctrlB                             {\
	    UNSG32 uctrlB_SSMF                                 :  4;\
	    UNSG32 uctrlB_SSMD                                 :  3;\
	    UNSG32 uctrlB_SSE_RSVD                             :  1;\
	    UNSG32 uctrlB_SSE                                  :  1;\
	    UNSG32 uctrlB_SSDS                                 :  1;\
	    UNSG32 RSVDx4_b10                                  : 22;\
	}
    union { UNSG32 u32abipll_rw_ctrlB;
	    struct w32abipll_rw_ctrlB;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_rw_ctrlC_DIVR(r32)                   _BFGET_(r32, 5, 0)
    #define   SET32abipll_rw_ctrlC_DIVR(r32, v)                 _BFSET_(r32, 5, 0, v)
    #define   GET16abipll_rw_ctrlC_DIVR(r16)                   _BFGET_(r16, 5, 0)
    #define   SET16abipll_rw_ctrlC_DIVR(r16, v)                 _BFSET_(r16, 5, 0, v)

    #define     w32abipll_rw_ctrlC                             {\
	    UNSG32 uctrlC_DIVR                                 :  6;\
	    UNSG32 RSVDx8_b6                                   : 26;\
	}
    union { UNSG32 u32abipll_rw_ctrlC;
	    struct w32abipll_rw_ctrlC;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_rw_ctrlD_DIVFI(r32)                  _BFGET_(r32, 8, 0)
    #define   SET32abipll_rw_ctrlD_DIVFI(r32, v)                _BFSET_(r32, 8, 0, v)
    #define   GET16abipll_rw_ctrlD_DIVFI(r16)                  _BFGET_(r16, 8, 0)
    #define   SET16abipll_rw_ctrlD_DIVFI(r16, v)                _BFSET_(r16, 8, 0, v)

    #define     w32abipll_rw_ctrlD                             {\
	    UNSG32 uctrlD_DIVFI                                :  9;\
	    UNSG32 RSVDxC_b9                                   : 23;\
	}
    union { UNSG32 u32abipll_rw_ctrlD;
	    struct w32abipll_rw_ctrlD;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_rw_ctrlE_DIVFF(r32)                  _BFGET_(r32, 23, 0)
    #define   SET32abipll_rw_ctrlE_DIVFF(r32, v)                _BFSET_(r32, 23, 0, v)

    #define     w32abipll_rw_ctrlE                             {\
	    UNSG32 uctrlE_DIVFF                                : 24;\
	    UNSG32 RSVDx10_b24                                 :  8;\
	}
    union { UNSG32 u32abipll_rw_ctrlE;
	    struct w32abipll_rw_ctrlE;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_rw_ctrlF_DIVQ(r32)                   _BFGET_(r32, 4, 0)
    #define   SET32abipll_rw_ctrlF_DIVQ(r32, v)                 _BFSET_(r32, 4, 0, v)
    #define   GET16abipll_rw_ctrlF_DIVQ(r16)                   _BFGET_(r16, 4, 0)
    #define   SET16abipll_rw_ctrlF_DIVQ(r16, v)                 _BFSET_(r16, 4, 0, v)

    #define     w32abipll_rw_ctrlF                             {\
	    UNSG32 uctrlF_DIVQ                                 :  5;\
	    UNSG32 RSVDx14_b5                                  : 27;\
	}
    union { UNSG32 u32abipll_rw_ctrlF;
	    struct w32abipll_rw_ctrlF;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_rw_ctrlG_DIVQF(r32)                  _BFGET_(r32, 2, 0)
    #define   SET32abipll_rw_ctrlG_DIVQF(r32, v)                _BFSET_(r32, 2, 0, v)
    #define   GET16abipll_rw_ctrlG_DIVQF(r16)                  _BFGET_(r16, 2, 0)
    #define   SET16abipll_rw_ctrlG_DIVQF(r16, v)                _BFSET_(r16, 2, 0, v)

    #define     w32abipll_rw_ctrlG                             {\
	    UNSG32 uctrlG_DIVQF                                :  3;\
	    UNSG32 RSVDx18_b3                                  : 29;\
	}
    union { UNSG32 u32abipll_rw_ctrlG;
	    struct w32abipll_rw_ctrlG;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32abipll_rw_status_LOCK(r32)                  _BFGET_(r32, 0, 0)
    #define   SET32abipll_rw_status_LOCK(r32, v)                _BFSET_(r32, 0, 0, v)
    #define   GET16abipll_rw_status_LOCK(r16)                  _BFGET_(r16, 0, 0)
    #define   SET16abipll_rw_status_LOCK(r16, v)                _BFSET_(r16, 0, 0, v)

    #define   GET32abipll_rw_status_DIVACK(r32)                _BFGET_(r32, 1, 1)
    #define   SET32abipll_rw_status_DIVACK(r32, v)              _BFSET_(r32, 1, 1, v)
    #define   GET16abipll_rw_status_DIVACK(r16)                _BFGET_(r16, 1, 1)
    #define   SET16abipll_rw_status_DIVACK(r16, v)              _BFSET_(r16, 1, 1, v)

    #define     w32abipll_rw_status                            {\
	    UNSG32 ustatus_LOCK                                :  1;\
	    UNSG32 ustatus_DIVACK                              :  1;\
	    UNSG32 RSVDx1C_b2                                  : 30;\
	}
    union { UNSG32 u32abipll_rw_status;
	    struct w32abipll_rw_status;
	  };
    ///////////////////////////////////////////////////////////
    } SIE_abipll_rw;

    typedef union  T32abipll_rw_ctrlA {
		UNSG32 u32;
	    struct w32abipll_rw_ctrlA;
		 } T32abipll_rw_ctrlA;
    typedef union  T32abipll_rw_ctrlB {
		UNSG32 u32;
	    struct w32abipll_rw_ctrlB;
		 } T32abipll_rw_ctrlB;
    typedef union  T32abipll_rw_ctrlC {
		UNSG32 u32;
	    struct w32abipll_rw_ctrlC;
		 } T32abipll_rw_ctrlC;
    typedef union  T32abipll_rw_ctrlD {
		UNSG32 u32;
	    struct w32abipll_rw_ctrlD;
		 } T32abipll_rw_ctrlD;
    typedef union  T32abipll_rw_ctrlE {
		UNSG32 u32;
	    struct w32abipll_rw_ctrlE;
		 } T32abipll_rw_ctrlE;
    typedef union  T32abipll_rw_ctrlF {
		UNSG32 u32;
	    struct w32abipll_rw_ctrlF;
		 } T32abipll_rw_ctrlF;
    typedef union  T32abipll_rw_ctrlG {
		UNSG32 u32;
	    struct w32abipll_rw_ctrlG;
		 } T32abipll_rw_ctrlG;
    typedef union  T32abipll_rw_status {
		UNSG32 u32;
	    struct w32abipll_rw_status;
		 } T32abipll_rw_status;
    ///////////////////////////////////////////////////////////

    typedef union  Tabipll_rw_ctrlA {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_rw_ctrlA;
		   };
		 } Tabipll_rw_ctrlA;
    typedef union  Tabipll_rw_ctrlB {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_rw_ctrlB;
		   };
		 } Tabipll_rw_ctrlB;
    typedef union  Tabipll_rw_ctrlC {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_rw_ctrlC;
		   };
		 } Tabipll_rw_ctrlC;
    typedef union  Tabipll_rw_ctrlD {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_rw_ctrlD;
		   };
		 } Tabipll_rw_ctrlD;
    typedef union  Tabipll_rw_ctrlE {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_rw_ctrlE;
		   };
		 } Tabipll_rw_ctrlE;
    typedef union  Tabipll_rw_ctrlF {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_rw_ctrlF;
		   };
		 } Tabipll_rw_ctrlF;
    typedef union  Tabipll_rw_ctrlG {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_rw_ctrlG;
		   };
		 } Tabipll_rw_ctrlG;
    typedef union  Tabipll_rw_status {
		UNSG32 u32[1];
	    struct {
	    struct w32abipll_rw_status;
		   };
		 } Tabipll_rw_status;

    ///////////////////////////////////////////////////////////
     SIGN32 abipll_rw_drvrd(SIE_abipll_rw *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 abipll_rw_drvwr(SIE_abipll_rw *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void abipll_rw_reset(SIE_abipll_rw *p);
     SIGN32 abipll_rw_cmp(SIE_abipll_rw *p, SIE_abipll_rw *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define abipll_rw_check(p, pie, pfx, hLOG) abipll_rw_cmp(p, pie, pfx, (void *)(hLOG), 0, 0)
    #define abipll_rw_print(p,    pfx, hLOG) abipll_rw_cmp(p, 0,  pfx, (void *)(hLOG), 0, 0)

#endif
//////
/// ENDOFINTERFACE: abipll_rw
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE pwrOff                                   (4,4)
///     ###
///     * Register for the Power domain which is OFF by default
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 ctrl                 (P-)
///               ###
///               * Power Domain Control Register
///               ###
///               %unsigned 1  iso_eN                    0x0
///                                    : enable                    0x0
///                                    : disable                   0x1
///                                                 ###
///                                                 * Isolation control bit. Active low
///                                                 * 0 : Isolation is enabled
///                                                 * 1 : Isolation is disabled (default)
///                                                 ###
///               %unsigned 2  pwrSwitchCtrl             0x0
///                                    : PWROFF                    0x0
///                                    : PWRON                     0x3
///                                                 ###
///                                                 * Power Switch control
///                                                 * Bit 1 : SLP1B
///                                                 * Bit 0 : SLP2B
///                                                 * SLP1B SLP2B
///                                                 * 0               X               Switch is turned off
///                                                 * 1               0               PMOS switch in current mirror configuration. Constant current charging to limit in-rush current
///                                                 * 1               1               PMOS switch is fully turned on to reduce Ron
///                                                 ###
///               %unsigned 1  pwrDomainRstN             0x0
///                                    : enable                    0x0
///                                    : disable                   0x1
///                                                 ###
///                                                 * Power Domain Reset. Active low.
///                                                 * 0 : Reset the power domain
///                                                 * 1:   De-assert the reset for the power domain
///                                                 ###
///               %%        28         # Stuffing bits...
///     @ 0x00004 status               (R-)
///               %unsigned 2  pwrStatus
///                                    ###
///                                    * Power domain Status output from the power domain module
///                                    * Bit 1 : SLP1B
///                                    * Bit 0 : SLP2B
///                                    * SLP1B SLP2B
///                                    * 0               X               Switch is turned off
///                                    * 1               0               PMOS switch in current mirror configuration. Constant current charging to limit in-rush current
///                                    * 1               1               PMOS switch is fully turned on to reduce Ron
///                                    ###
///               %%        30         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       8B, bits:       6b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_pwrOff
#define h_pwrOff () {}

    #define     RA_pwrOff_ctrl                                 0x0000

    #define     BA_pwrOff_ctrl_iso_eN                          0x0000
    #define     B16pwrOff_ctrl_iso_eN                          0x0000
    #define   LSb32pwrOff_ctrl_iso_eN                             0
    #define   LSb16pwrOff_ctrl_iso_eN                             0
    #define       bpwrOff_ctrl_iso_eN                          1
    #define   MSK32pwrOff_ctrl_iso_eN                             0x00000001
    #define        pwrOff_ctrl_iso_eN_enable                                0x0
    #define        pwrOff_ctrl_iso_eN_disable                               0x1

    #define     BA_pwrOff_ctrl_pwrSwitchCtrl                   0x0000
    #define     B16pwrOff_ctrl_pwrSwitchCtrl                   0x0000
    #define   LSb32pwrOff_ctrl_pwrSwitchCtrl                      1
    #define   LSb16pwrOff_ctrl_pwrSwitchCtrl                      1
    #define       bpwrOff_ctrl_pwrSwitchCtrl                   2
    #define   MSK32pwrOff_ctrl_pwrSwitchCtrl                      0x00000006
    #define        pwrOff_ctrl_pwrSwitchCtrl_PWROFF                         0x0
    #define        pwrOff_ctrl_pwrSwitchCtrl_PWRON                          0x3

    #define     BA_pwrOff_ctrl_pwrDomainRstN                   0x0000
    #define     B16pwrOff_ctrl_pwrDomainRstN                   0x0000
    #define   LSb32pwrOff_ctrl_pwrDomainRstN                      3
    #define   LSb16pwrOff_ctrl_pwrDomainRstN                      3
    #define       bpwrOff_ctrl_pwrDomainRstN                   1
    #define   MSK32pwrOff_ctrl_pwrDomainRstN                      0x00000008
    #define        pwrOff_ctrl_pwrDomainRstN_enable                         0x0
    #define        pwrOff_ctrl_pwrDomainRstN_disable                        0x1
    ///////////////////////////////////////////////////////////
    #define     RA_pwrOff_status                               0x0004

    #define     BA_pwrOff_status_pwrStatus                     0x0004
    #define     B16pwrOff_status_pwrStatus                     0x0004
    #define   LSb32pwrOff_status_pwrStatus                        0
    #define   LSb16pwrOff_status_pwrStatus                        0
    #define       bpwrOff_status_pwrStatus                     2
    #define   MSK32pwrOff_status_pwrStatus                        0x00000003
    ///////////////////////////////////////////////////////////

    typedef struct SIE_pwrOff {
    ///////////////////////////////////////////////////////////
    #define   GET32pwrOff_ctrl_iso_eN(r32)                     _BFGET_(r32, 0, 0)
    #define   SET32pwrOff_ctrl_iso_eN(r32, v)                   _BFSET_(r32, 0, 0, v)
    #define   GET16pwrOff_ctrl_iso_eN(r16)                     _BFGET_(r16, 0, 0)
    #define   SET16pwrOff_ctrl_iso_eN(r16, v)                   _BFSET_(r16, 0, 0, v)

    #define   GET32pwrOff_ctrl_pwrSwitchCtrl(r32)              _BFGET_(r32, 2, 1)
    #define   SET32pwrOff_ctrl_pwrSwitchCtrl(r32, v)            _BFSET_(r32, 2, 1, v)
    #define   GET16pwrOff_ctrl_pwrSwitchCtrl(r16)              _BFGET_(r16, 2, 1)
    #define   SET16pwrOff_ctrl_pwrSwitchCtrl(r16, v)            _BFSET_(r16, 2, 1, v)

    #define   GET32pwrOff_ctrl_pwrDomainRstN(r32)              _BFGET_(r32, 3, 3)
    #define   SET32pwrOff_ctrl_pwrDomainRstN(r32, v)            _BFSET_(r32, 3, 3, v)
    #define   GET16pwrOff_ctrl_pwrDomainRstN(r16)              _BFGET_(r16, 3, 3)
    #define   SET16pwrOff_ctrl_pwrDomainRstN(r16, v)            _BFSET_(r16, 3, 3, v)

    #define     w32pwrOff_ctrl                                 {\
	    UNSG32 uctrl_iso_eN                                :  1;\
	    UNSG32 uctrl_pwrSwitchCtrl                         :  2;\
	    UNSG32 uctrl_pwrDomainRstN                         :  1;\
	    UNSG32 RSVDx0_b4                                   : 28;\
	}
    union { UNSG32 u32pwrOff_ctrl;
	    struct w32pwrOff_ctrl;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32pwrOff_status_pwrStatus(r32)                _BFGET_(r32, 1, 0)
    #define   SET32pwrOff_status_pwrStatus(r32, v)              _BFSET_(r32, 1, 0, v)
    #define   GET16pwrOff_status_pwrStatus(r16)                _BFGET_(r16, 1, 0)
    #define   SET16pwrOff_status_pwrStatus(r16, v)              _BFSET_(r16, 1, 0, v)

    #define     w32pwrOff_status                               {\
	    UNSG32 ustatus_pwrStatus                           :  2;\
	    UNSG32 RSVDx4_b2                                   : 30;\
	}
    union { UNSG32 u32pwrOff_status;
	    struct w32pwrOff_status;
	  };
    ///////////////////////////////////////////////////////////
    } SIE_pwrOff;

    typedef union  T32pwrOff_ctrl {
		UNSG32 u32;
	    struct w32pwrOff_ctrl;
		 } T32pwrOff_ctrl;
    typedef union  T32pwrOff_status {
		UNSG32 u32;
	    struct w32pwrOff_status;
		 } T32pwrOff_status;
    ///////////////////////////////////////////////////////////

    typedef union  TpwrOff_ctrl {
		UNSG32 u32[1];
	    struct {
	    struct w32pwrOff_ctrl;
		   };
		 } TpwrOff_ctrl;
    typedef union  TpwrOff_status {
		UNSG32 u32[1];
	    struct {
	    struct w32pwrOff_status;
		   };
		 } TpwrOff_status;

    ///////////////////////////////////////////////////////////
     SIGN32 pwrOff_drvrd(SIE_pwrOff *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 pwrOff_drvwr(SIE_pwrOff *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void pwrOff_reset(SIE_pwrOff *p);
     SIGN32 pwrOff_cmp(SIE_pwrOff *p, SIE_pwrOff *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define pwrOff_check(p, pie, pfx, hLOG) pwrOff_cmp(p, pie, pfx, (void *)(hLOG), 0, 0)
    #define pwrOff_print(p,    pfx, hLOG) pwrOff_cmp(p, 0,  pfx, (void *)(hLOG), 0, 0)

#endif
//////
/// ENDOFINTERFACE: pwrOff
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE pwrOn                                    (4,4)
///     ###
///     * Register for the Power domain which is ON by default
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 ctrl                 (P-)
///               ###
///               * Power Domain Control Register
///               ###
///               %unsigned 1  iso_eN                    0x1
///                                    : enable                    0x0
///                                    : disable                   0x1
///                                                 ###
///                                                 * Isolation control bit. Active low
///                                                 * 0 : Isolation is enabled
///                                                 * 1 : Isolation is disabled (default)
///                                                 ###
///               %unsigned 2  pwrSwitchCtrl             0x3
///                                    ###
///                                    * Power Switch control
///                                    * Bit 1 : SLP1B
///                                    * Bit 0 : SLP2B
///                                    * SLP1B SLP2B
///                                    * 0               X               Switch is turned off
///                                    * 1               0               PMOS switch in current mirror configuration. Constant current charging to limit in-rush current
///                                    * 1               1               PMOS switch is fully turned on to reduce Ron
///                                    ###
///               %unsigned 1  pwrDomainRstN             0x1
///                                    ###
///                                    * Power Domain Reset. Active low.
///                                    * 0 : Reset the power domain
///                                    * 1:   De-assert the reset for the power domain
///                                    ###
///               %%        28         # Stuffing bits...
///     @ 0x00004 status               (R-)
///               %unsigned 2  pwrStatus
///                                    ###
///                                    * Power domain Status output from the power domain module
///                                    * Bit 1 : SLP1B
///                                    * Bit 0 : SLP2B
///                                    * SLP1B SLP2B
///                                    * 0               X               Switch is turned off
///                                    * 1               0               PMOS switch in current mirror configuration. Constant current charging to limit in-rush current
///                                    * 1               1               PMOS switch is fully turned on to reduce Ron
///                                    ###
///               %%        30         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       8B, bits:       6b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_pwrOn
#define h_pwrOn () {}

    #define     RA_pwrOn_ctrl                                  0x0000

    #define     BA_pwrOn_ctrl_iso_eN                           0x0000
    #define     B16pwrOn_ctrl_iso_eN                           0x0000
    #define   LSb32pwrOn_ctrl_iso_eN                              0
    #define   LSb16pwrOn_ctrl_iso_eN                              0
    #define       bpwrOn_ctrl_iso_eN                           1
    #define   MSK32pwrOn_ctrl_iso_eN                              0x00000001
    #define        pwrOn_ctrl_iso_eN_enable                                 0x0
    #define        pwrOn_ctrl_iso_eN_disable                                0x1

    #define     BA_pwrOn_ctrl_pwrSwitchCtrl                    0x0000
    #define     B16pwrOn_ctrl_pwrSwitchCtrl                    0x0000
    #define   LSb32pwrOn_ctrl_pwrSwitchCtrl                       1
    #define   LSb16pwrOn_ctrl_pwrSwitchCtrl                       1
    #define       bpwrOn_ctrl_pwrSwitchCtrl                    2
    #define   MSK32pwrOn_ctrl_pwrSwitchCtrl                       0x00000006

    #define     BA_pwrOn_ctrl_pwrDomainRstN                    0x0000
    #define     B16pwrOn_ctrl_pwrDomainRstN                    0x0000
    #define   LSb32pwrOn_ctrl_pwrDomainRstN                       3
    #define   LSb16pwrOn_ctrl_pwrDomainRstN                       3
    #define       bpwrOn_ctrl_pwrDomainRstN                    1
    #define   MSK32pwrOn_ctrl_pwrDomainRstN                       0x00000008
    ///////////////////////////////////////////////////////////
    #define     RA_pwrOn_status                                0x0004

    #define     BA_pwrOn_status_pwrStatus                      0x0004
    #define     B16pwrOn_status_pwrStatus                      0x0004
    #define   LSb32pwrOn_status_pwrStatus                         0
    #define   LSb16pwrOn_status_pwrStatus                         0
    #define       bpwrOn_status_pwrStatus                      2
    #define   MSK32pwrOn_status_pwrStatus                         0x00000003
    ///////////////////////////////////////////////////////////

    typedef struct SIE_pwrOn {
    ///////////////////////////////////////////////////////////
    #define   GET32pwrOn_ctrl_iso_eN(r32)                      _BFGET_(r32, 0, 0)
    #define   SET32pwrOn_ctrl_iso_eN(r32, v)                    _BFSET_(r32, 0, 0, v)
    #define   GET16pwrOn_ctrl_iso_eN(r16)                      _BFGET_(r16, 0, 0)
    #define   SET16pwrOn_ctrl_iso_eN(r16, v)                    _BFSET_(r16, 0, 0, v)

    #define   GET32pwrOn_ctrl_pwrSwitchCtrl(r32)               _BFGET_(r32, 2, 1)
    #define   SET32pwrOn_ctrl_pwrSwitchCtrl(r32, v)             _BFSET_(r32, 2, 1, v)
    #define   GET16pwrOn_ctrl_pwrSwitchCtrl(r16)               _BFGET_(r16, 2, 1)
    #define   SET16pwrOn_ctrl_pwrSwitchCtrl(r16, v)             _BFSET_(r16, 2, 1, v)

    #define   GET32pwrOn_ctrl_pwrDomainRstN(r32)               _BFGET_(r32, 3, 3)
    #define   SET32pwrOn_ctrl_pwrDomainRstN(r32, v)             _BFSET_(r32, 3, 3, v)
    #define   GET16pwrOn_ctrl_pwrDomainRstN(r16)               _BFGET_(r16, 3, 3)
    #define   SET16pwrOn_ctrl_pwrDomainRstN(r16, v)             _BFSET_(r16, 3, 3, v)

    #define     w32pwrOn_ctrl                                  {\
	    UNSG32 uctrl_iso_eN                                :  1;\
	    UNSG32 uctrl_pwrSwitchCtrl                         :  2;\
	    UNSG32 uctrl_pwrDomainRstN                         :  1;\
	    UNSG32 RSVDx0_b4                                   : 28;\
	}
    union { UNSG32 u32pwrOn_ctrl;
	    struct w32pwrOn_ctrl;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32pwrOn_status_pwrStatus(r32)                 _BFGET_(r32, 1, 0)
    #define   SET32pwrOn_status_pwrStatus(r32, v)               _BFSET_(r32, 1, 0, v)
    #define   GET16pwrOn_status_pwrStatus(r16)                 _BFGET_(r16, 1, 0)
    #define   SET16pwrOn_status_pwrStatus(r16, v)               _BFSET_(r16, 1, 0, v)

    #define     w32pwrOn_status                                {\
	    UNSG32 ustatus_pwrStatus                           :  2;\
	    UNSG32 RSVDx4_b2                                   : 30;\
	}
    union { UNSG32 u32pwrOn_status;
	    struct w32pwrOn_status;
	  };
    ///////////////////////////////////////////////////////////
    } SIE_pwrOn;

    typedef union  T32pwrOn_ctrl {
		UNSG32 u32;
	    struct w32pwrOn_ctrl;
		 } T32pwrOn_ctrl;
    typedef union  T32pwrOn_status {
		UNSG32 u32;
	    struct w32pwrOn_status;
		 } T32pwrOn_status;
    ///////////////////////////////////////////////////////////

    typedef union  TpwrOn_ctrl {
		UNSG32 u32[1];
	    struct {
	    struct w32pwrOn_ctrl;
		   };
		 } TpwrOn_ctrl;
    typedef union  TpwrOn_status {
		UNSG32 u32[1];
	    struct {
	    struct w32pwrOn_status;
		   };
		 } TpwrOn_status;

    ///////////////////////////////////////////////////////////
     SIGN32 pwrOn_drvrd(SIE_pwrOn *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 pwrOn_drvwr(SIE_pwrOn *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void pwrOn_reset(SIE_pwrOn *p);
     SIGN32 pwrOn_cmp(SIE_pwrOn *p, SIE_pwrOn *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define pwrOn_check(p, pie, pfx, hLOG) pwrOn_cmp(p, pie, pfx, (void *)(hLOG), 0, 0)
    #define pwrOn_print(p,    pfx, hLOG) pwrOn_cmp(p, 0,  pfx, (void *)(hLOG), 0, 0)

#endif
//////
/// ENDOFINTERFACE: pwrOn
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE pwrOn_iso                                (4,4)
///     ###
///     * Register for the Power domain which is ON by default
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 ctrl                 (P-)
///               ###
///               * Power Domain Control Register
///               ###
///               %unsigned 1  iso_eN                    0x0
///                                    : enable                    0x0
///                                    : disable                   0x1
///                                                 ###
///                                                 * Isolation control bit. Active low
///                                                 * 0 : Isolation is enabled
///                                                 * 1 : Isolation is disabled (default)
///                                                 ###
///               %unsigned 2  pwrSwitchCtrl             0x3
///                                    ###
///                                    * Power Switch control
///                                    * Bit 1 : SLP1B
///                                    * Bit 0 : SLP2B
///                                    * SLP1B SLP2B
///                                    * 0               X               Switch is turned off
///                                    * 1               0               PMOS switch in current mirror configuration. Constant current charging to limit in-rush current
///                                    * 1               1               PMOS switch is fully turned on to reduce Ron
///                                    ###
///               %unsigned 1  pwrDomainRstN             0x0
///                                    ###
///                                    * Power Domain Reset. Active low.
///                                    * 0 : Reset the power domain
///                                    * 1:   De-assert the reset for the power domain
///                                    ###
///               %%        28         # Stuffing bits...
///     @ 0x00004 status               (R-)
///               %unsigned 2  pwrStatus
///                                    ###
///                                    * Power domain Status output from the power domain module
///                                    * Bit 1 : SLP1B
///                                    * Bit 0 : SLP2B
///                                    * SLP1B SLP2B
///                                    * 0               X               Switch is turned off
///                                    * 1               0               PMOS switch in current mirror configuration. Constant current charging to limit in-rush current
///                                    * 1               1               PMOS switch is fully turned on to reduce Ron
///                                    ###
///               %unsigned 1  IP_IDLE
///                                    ###
///                                    * Indication from IP that it is idle and can be powered down.
///                                    * 1: Idle
///                                    * 0: Busy
///                                    ###
///               %%        29         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       8B, bits:       7b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_pwrOn_iso
#define h_pwrOn_iso () {}

    #define     RA_pwrOn_iso_ctrl                              0x0000

    #define     BA_pwrOn_iso_ctrl_iso_eN                       0x0000
    #define     B16pwrOn_iso_ctrl_iso_eN                       0x0000
    #define   LSb32pwrOn_iso_ctrl_iso_eN                          0
    #define   LSb16pwrOn_iso_ctrl_iso_eN                          0
    #define       bpwrOn_iso_ctrl_iso_eN                       1
    #define   MSK32pwrOn_iso_ctrl_iso_eN                          0x00000001
    #define        pwrOn_iso_ctrl_iso_eN_enable                             0x0
    #define        pwrOn_iso_ctrl_iso_eN_disable                            0x1

    #define     BA_pwrOn_iso_ctrl_pwrSwitchCtrl                0x0000
    #define     B16pwrOn_iso_ctrl_pwrSwitchCtrl                0x0000
    #define   LSb32pwrOn_iso_ctrl_pwrSwitchCtrl                   1
    #define   LSb16pwrOn_iso_ctrl_pwrSwitchCtrl                   1
    #define       bpwrOn_iso_ctrl_pwrSwitchCtrl                2
    #define   MSK32pwrOn_iso_ctrl_pwrSwitchCtrl                   0x00000006

    #define     BA_pwrOn_iso_ctrl_pwrDomainRstN                0x0000
    #define     B16pwrOn_iso_ctrl_pwrDomainRstN                0x0000
    #define   LSb32pwrOn_iso_ctrl_pwrDomainRstN                   3
    #define   LSb16pwrOn_iso_ctrl_pwrDomainRstN                   3
    #define       bpwrOn_iso_ctrl_pwrDomainRstN                1
    #define   MSK32pwrOn_iso_ctrl_pwrDomainRstN                   0x00000008
    ///////////////////////////////////////////////////////////
    #define     RA_pwrOn_iso_status                            0x0004

    #define     BA_pwrOn_iso_status_pwrStatus                  0x0004
    #define     B16pwrOn_iso_status_pwrStatus                  0x0004
    #define   LSb32pwrOn_iso_status_pwrStatus                     0
    #define   LSb16pwrOn_iso_status_pwrStatus                     0
    #define       bpwrOn_iso_status_pwrStatus                  2
    #define   MSK32pwrOn_iso_status_pwrStatus                     0x00000003

    #define     BA_pwrOn_iso_status_IP_IDLE                    0x0004
    #define     B16pwrOn_iso_status_IP_IDLE                    0x0004
    #define   LSb32pwrOn_iso_status_IP_IDLE                       2
    #define   LSb16pwrOn_iso_status_IP_IDLE                       2
    #define       bpwrOn_iso_status_IP_IDLE                    1
    #define   MSK32pwrOn_iso_status_IP_IDLE                       0x00000004
    ///////////////////////////////////////////////////////////

    typedef struct SIE_pwrOn_iso {
    ///////////////////////////////////////////////////////////
    #define   GET32pwrOn_iso_ctrl_iso_eN(r32)                  _BFGET_(r32, 0, 0)
    #define   SET32pwrOn_iso_ctrl_iso_eN(r32, v)                _BFSET_(r32, 0, 0, v)
    #define   GET16pwrOn_iso_ctrl_iso_eN(r16)                  _BFGET_(r16, 0, 0)
    #define   SET16pwrOn_iso_ctrl_iso_eN(r16, v)                _BFSET_(r16, 0, 0, v)

    #define   GET32pwrOn_iso_ctrl_pwrSwitchCtrl(r32)           _BFGET_(r32, 2, 1)
    #define   SET32pwrOn_iso_ctrl_pwrSwitchCtrl(r32, v)         _BFSET_(r32, 2, 1, v)
    #define   GET16pwrOn_iso_ctrl_pwrSwitchCtrl(r16)           _BFGET_(r16, 2, 1)
    #define   SET16pwrOn_iso_ctrl_pwrSwitchCtrl(r16, v)         _BFSET_(r16, 2, 1, v)

    #define   GET32pwrOn_iso_ctrl_pwrDomainRstN(r32)           _BFGET_(r32, 3, 3)
    #define   SET32pwrOn_iso_ctrl_pwrDomainRstN(r32, v)         _BFSET_(r32, 3, 3, v)
    #define   GET16pwrOn_iso_ctrl_pwrDomainRstN(r16)           _BFGET_(r16, 3, 3)
    #define   SET16pwrOn_iso_ctrl_pwrDomainRstN(r16, v)         _BFSET_(r16, 3, 3, v)

    #define     w32pwrOn_iso_ctrl                              {\
	    UNSG32 uctrl_iso_eN                                :  1;\
	    UNSG32 uctrl_pwrSwitchCtrl                         :  2;\
	    UNSG32 uctrl_pwrDomainRstN                         :  1;\
	    UNSG32 RSVDx0_b4                                   : 28;\
	}
    union { UNSG32 u32pwrOn_iso_ctrl;
	    struct w32pwrOn_iso_ctrl;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32pwrOn_iso_status_pwrStatus(r32)             _BFGET_(r32, 1, 0)
    #define   SET32pwrOn_iso_status_pwrStatus(r32, v)           _BFSET_(r32, 1, 0, v)
    #define   GET16pwrOn_iso_status_pwrStatus(r16)             _BFGET_(r16, 1, 0)
    #define   SET16pwrOn_iso_status_pwrStatus(r16, v)           _BFSET_(r16, 1, 0, v)

    #define   GET32pwrOn_iso_status_IP_IDLE(r32)               _BFGET_(r32, 2, 2)
    #define   SET32pwrOn_iso_status_IP_IDLE(r32, v)             _BFSET_(r32, 2, 2, v)
    #define   GET16pwrOn_iso_status_IP_IDLE(r16)               _BFGET_(r16, 2, 2)
    #define   SET16pwrOn_iso_status_IP_IDLE(r16, v)             _BFSET_(r16, 2, 2, v)

    #define     w32pwrOn_iso_status                            {\
	    UNSG32 ustatus_pwrStatus                           :  2;\
	    UNSG32 ustatus_IP_IDLE                             :  1;\
	    UNSG32 RSVDx4_b3                                   : 29;\
	}
    union { UNSG32 u32pwrOn_iso_status;
	    struct w32pwrOn_iso_status;
	  };
    ///////////////////////////////////////////////////////////
    } SIE_pwrOn_iso;

    typedef union  T32pwrOn_iso_ctrl {
		UNSG32 u32;
	    struct w32pwrOn_iso_ctrl;
		 } T32pwrOn_iso_ctrl;
    typedef union  T32pwrOn_iso_status {
		UNSG32 u32;
	    struct w32pwrOn_iso_status;
		 } T32pwrOn_iso_status;
    ///////////////////////////////////////////////////////////

    typedef union  TpwrOn_iso_ctrl {
		UNSG32 u32[1];
	    struct {
	    struct w32pwrOn_iso_ctrl;
		   };
		 } TpwrOn_iso_ctrl;
    typedef union  TpwrOn_iso_status {
		UNSG32 u32[1];
	    struct {
	    struct w32pwrOn_iso_status;
		   };
		 } TpwrOn_iso_status;

    ///////////////////////////////////////////////////////////
     SIGN32 pwrOn_iso_drvrd(SIE_pwrOn_iso *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 pwrOn_iso_drvwr(SIE_pwrOn_iso *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void pwrOn_iso_reset(SIE_pwrOn_iso *p);
     SIGN32 pwrOn_iso_cmp(SIE_pwrOn_iso *p, SIE_pwrOn_iso *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define pwrOn_iso_check(p, pie, pfx, hLOG) pwrOn_iso_cmp(p, pie, pfx, (void *)(hLOG), 0, 0)
    #define pwrOn_iso_print(p,    pfx, hLOG) pwrOn_iso_cmp(p, 0,  pfx, (void *)(hLOG), 0, 0)

#endif
//////
/// ENDOFINTERFACE: pwrOn_iso
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE AxiPCntStat                              (4,4)
///     ###
///     * AXI Performance Counters
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 TOTAL_CNT            (RNB-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Total no.of AXI clocks
///                                    ###
///     @ 0x00004 ARWAIT_CNT           (RNB-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Counts the no.of clocks aRValid = 1 & aRReady = 0
///                                    ###
///     @ 0x00008 RWAIT_CNT            (RNB-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Counts the no.of clocks rValid = 1 & rReady = 0
///                                    ###
///     @ 0x0000C RIDLE_CNT            (RNB-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Counts the no.of clocks rValid = 0 & rReady = 1
///                                    ###
///     @ 0x00010 RDATA_CNT            (RNB-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Counts the no.of clocks rValid = 1 & rReady = 1
///                                    ###
///     @ 0x00014 AWWAIT_CNT           (RNB-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Counts the no.of clocks aWValid = 1 & aWReady = 0
///                                    ###
///     @ 0x00018 WWAIT_CNT            (RNB-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Counts the no.of clocks wValid = 1 & wReady = 0
///                                    ###
///     @ 0x0001C WIDLE_CNT            (RNB-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Counts the no.of clocks wValid = 0 & wReady = 1
///                                    ###
///     @ 0x00020 WDATA_CNT            (RNB-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Counts the no.of clocks wValid = 1 & wReady = 1
///                                    ###
///     @ 0x00024 AWDATA_CNT           (RNB-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Counts no of clocks awValid & awReady
///                                    ###
///     @ 0x00028 ARDATA_CNT           (RNB-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * Counts no of clocks awValid & awReady
///                                    ###
///     @ 0x0002C OF_STATUS            (RNB-)
///               %unsigned 1  total                     0x0
///               %unsigned 1  arwait                    0x0
///               %unsigned 1  rwait                     0x0
///               %unsigned 1  ridle                     0x0
///               %unsigned 1  rdata                     0x0
///               %unsigned 1  awwait                    0x0
///               %unsigned 1  wwait                     0x0
///               %unsigned 1  widle                     0x0
///               %unsigned 1  wdata                     0x0
///               %unsigned 1  awdata                    0x0
///               %unsigned 1  ardata                    0x0
///                                    ###
///                                    * Overflow status of total, wait and data counters. Clear will
///                                    * clear the overflow status as well.
///                                    ###
///               %%        21         # Stuffing bits...
///     @ 0x00030 READY                (R-)
///               %unsigned 1  cnt                       0x0
///                                    ###
///                                    * This bit is set by HW when counter values are latched and it's
///                                    * ok for SW to read the counter
///                                    ###
///               %%        31         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      52B, bits:     364b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_AxiPCntStat
#define h_AxiPCntStat () {}

    #define     RA_AxiPCntStat_TOTAL_CNT                       0x0000

    #define     BA_AxiPCntStat_TOTAL_CNT_cnt                   0x0000
    #define     B16AxiPCntStat_TOTAL_CNT_cnt                   0x0000
    #define   LSb32AxiPCntStat_TOTAL_CNT_cnt                      0
    #define   LSb16AxiPCntStat_TOTAL_CNT_cnt                      0
    #define       bAxiPCntStat_TOTAL_CNT_cnt                   32
    #define   MSK32AxiPCntStat_TOTAL_CNT_cnt                      0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCntStat_ARWAIT_CNT                      0x0004

    #define     BA_AxiPCntStat_ARWAIT_CNT_cnt                  0x0004
    #define     B16AxiPCntStat_ARWAIT_CNT_cnt                  0x0004
    #define   LSb32AxiPCntStat_ARWAIT_CNT_cnt                     0
    #define   LSb16AxiPCntStat_ARWAIT_CNT_cnt                     0
    #define       bAxiPCntStat_ARWAIT_CNT_cnt                  32
    #define   MSK32AxiPCntStat_ARWAIT_CNT_cnt                     0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCntStat_RWAIT_CNT                       0x0008

    #define     BA_AxiPCntStat_RWAIT_CNT_cnt                   0x0008
    #define     B16AxiPCntStat_RWAIT_CNT_cnt                   0x0008
    #define   LSb32AxiPCntStat_RWAIT_CNT_cnt                      0
    #define   LSb16AxiPCntStat_RWAIT_CNT_cnt                      0
    #define       bAxiPCntStat_RWAIT_CNT_cnt                   32
    #define   MSK32AxiPCntStat_RWAIT_CNT_cnt                      0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCntStat_RIDLE_CNT                       0x000C

    #define     BA_AxiPCntStat_RIDLE_CNT_cnt                   0x000C
    #define     B16AxiPCntStat_RIDLE_CNT_cnt                   0x000C
    #define   LSb32AxiPCntStat_RIDLE_CNT_cnt                      0
    #define   LSb16AxiPCntStat_RIDLE_CNT_cnt                      0
    #define       bAxiPCntStat_RIDLE_CNT_cnt                   32
    #define   MSK32AxiPCntStat_RIDLE_CNT_cnt                      0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCntStat_RDATA_CNT                       0x0010

    #define     BA_AxiPCntStat_RDATA_CNT_cnt                   0x0010
    #define     B16AxiPCntStat_RDATA_CNT_cnt                   0x0010
    #define   LSb32AxiPCntStat_RDATA_CNT_cnt                      0
    #define   LSb16AxiPCntStat_RDATA_CNT_cnt                      0
    #define       bAxiPCntStat_RDATA_CNT_cnt                   32
    #define   MSK32AxiPCntStat_RDATA_CNT_cnt                      0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCntStat_AWWAIT_CNT                      0x0014

    #define     BA_AxiPCntStat_AWWAIT_CNT_cnt                  0x0014
    #define     B16AxiPCntStat_AWWAIT_CNT_cnt                  0x0014
    #define   LSb32AxiPCntStat_AWWAIT_CNT_cnt                     0
    #define   LSb16AxiPCntStat_AWWAIT_CNT_cnt                     0
    #define       bAxiPCntStat_AWWAIT_CNT_cnt                  32
    #define   MSK32AxiPCntStat_AWWAIT_CNT_cnt                     0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCntStat_WWAIT_CNT                       0x0018

    #define     BA_AxiPCntStat_WWAIT_CNT_cnt                   0x0018
    #define     B16AxiPCntStat_WWAIT_CNT_cnt                   0x0018
    #define   LSb32AxiPCntStat_WWAIT_CNT_cnt                      0
    #define   LSb16AxiPCntStat_WWAIT_CNT_cnt                      0
    #define       bAxiPCntStat_WWAIT_CNT_cnt                   32
    #define   MSK32AxiPCntStat_WWAIT_CNT_cnt                      0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCntStat_WIDLE_CNT                       0x001C

    #define     BA_AxiPCntStat_WIDLE_CNT_cnt                   0x001C
    #define     B16AxiPCntStat_WIDLE_CNT_cnt                   0x001C
    #define   LSb32AxiPCntStat_WIDLE_CNT_cnt                      0
    #define   LSb16AxiPCntStat_WIDLE_CNT_cnt                      0
    #define       bAxiPCntStat_WIDLE_CNT_cnt                   32
    #define   MSK32AxiPCntStat_WIDLE_CNT_cnt                      0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCntStat_WDATA_CNT                       0x0020

    #define     BA_AxiPCntStat_WDATA_CNT_cnt                   0x0020
    #define     B16AxiPCntStat_WDATA_CNT_cnt                   0x0020
    #define   LSb32AxiPCntStat_WDATA_CNT_cnt                      0
    #define   LSb16AxiPCntStat_WDATA_CNT_cnt                      0
    #define       bAxiPCntStat_WDATA_CNT_cnt                   32
    #define   MSK32AxiPCntStat_WDATA_CNT_cnt                      0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCntStat_AWDATA_CNT                      0x0024

    #define     BA_AxiPCntStat_AWDATA_CNT_cnt                  0x0024
    #define     B16AxiPCntStat_AWDATA_CNT_cnt                  0x0024
    #define   LSb32AxiPCntStat_AWDATA_CNT_cnt                     0
    #define   LSb16AxiPCntStat_AWDATA_CNT_cnt                     0
    #define       bAxiPCntStat_AWDATA_CNT_cnt                  32
    #define   MSK32AxiPCntStat_AWDATA_CNT_cnt                     0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCntStat_ARDATA_CNT                      0x0028

    #define     BA_AxiPCntStat_ARDATA_CNT_cnt                  0x0028
    #define     B16AxiPCntStat_ARDATA_CNT_cnt                  0x0028
    #define   LSb32AxiPCntStat_ARDATA_CNT_cnt                     0
    #define   LSb16AxiPCntStat_ARDATA_CNT_cnt                     0
    #define       bAxiPCntStat_ARDATA_CNT_cnt                  32
    #define   MSK32AxiPCntStat_ARDATA_CNT_cnt                     0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCntStat_OF_STATUS                       0x002C

    #define     BA_AxiPCntStat_OF_STATUS_total                 0x002C
    #define     B16AxiPCntStat_OF_STATUS_total                 0x002C
    #define   LSb32AxiPCntStat_OF_STATUS_total                    0
    #define   LSb16AxiPCntStat_OF_STATUS_total                    0
    #define       bAxiPCntStat_OF_STATUS_total                 1
    #define   MSK32AxiPCntStat_OF_STATUS_total                    0x00000001

    #define     BA_AxiPCntStat_OF_STATUS_arwait                0x002C
    #define     B16AxiPCntStat_OF_STATUS_arwait                0x002C
    #define   LSb32AxiPCntStat_OF_STATUS_arwait                   1
    #define   LSb16AxiPCntStat_OF_STATUS_arwait                   1
    #define       bAxiPCntStat_OF_STATUS_arwait                1
    #define   MSK32AxiPCntStat_OF_STATUS_arwait                   0x00000002

    #define     BA_AxiPCntStat_OF_STATUS_rwait                 0x002C
    #define     B16AxiPCntStat_OF_STATUS_rwait                 0x002C
    #define   LSb32AxiPCntStat_OF_STATUS_rwait                    2
    #define   LSb16AxiPCntStat_OF_STATUS_rwait                    2
    #define       bAxiPCntStat_OF_STATUS_rwait                 1
    #define   MSK32AxiPCntStat_OF_STATUS_rwait                    0x00000004

    #define     BA_AxiPCntStat_OF_STATUS_ridle                 0x002C
    #define     B16AxiPCntStat_OF_STATUS_ridle                 0x002C
    #define   LSb32AxiPCntStat_OF_STATUS_ridle                    3
    #define   LSb16AxiPCntStat_OF_STATUS_ridle                    3
    #define       bAxiPCntStat_OF_STATUS_ridle                 1
    #define   MSK32AxiPCntStat_OF_STATUS_ridle                    0x00000008

    #define     BA_AxiPCntStat_OF_STATUS_rdata                 0x002C
    #define     B16AxiPCntStat_OF_STATUS_rdata                 0x002C
    #define   LSb32AxiPCntStat_OF_STATUS_rdata                    4
    #define   LSb16AxiPCntStat_OF_STATUS_rdata                    4
    #define       bAxiPCntStat_OF_STATUS_rdata                 1
    #define   MSK32AxiPCntStat_OF_STATUS_rdata                    0x00000010

    #define     BA_AxiPCntStat_OF_STATUS_awwait                0x002C
    #define     B16AxiPCntStat_OF_STATUS_awwait                0x002C
    #define   LSb32AxiPCntStat_OF_STATUS_awwait                   5
    #define   LSb16AxiPCntStat_OF_STATUS_awwait                   5
    #define       bAxiPCntStat_OF_STATUS_awwait                1
    #define   MSK32AxiPCntStat_OF_STATUS_awwait                   0x00000020

    #define     BA_AxiPCntStat_OF_STATUS_wwait                 0x002C
    #define     B16AxiPCntStat_OF_STATUS_wwait                 0x002C
    #define   LSb32AxiPCntStat_OF_STATUS_wwait                    6
    #define   LSb16AxiPCntStat_OF_STATUS_wwait                    6
    #define       bAxiPCntStat_OF_STATUS_wwait                 1
    #define   MSK32AxiPCntStat_OF_STATUS_wwait                    0x00000040

    #define     BA_AxiPCntStat_OF_STATUS_widle                 0x002C
    #define     B16AxiPCntStat_OF_STATUS_widle                 0x002C
    #define   LSb32AxiPCntStat_OF_STATUS_widle                    7
    #define   LSb16AxiPCntStat_OF_STATUS_widle                    7
    #define       bAxiPCntStat_OF_STATUS_widle                 1
    #define   MSK32AxiPCntStat_OF_STATUS_widle                    0x00000080

    #define     BA_AxiPCntStat_OF_STATUS_wdata                 0x002D
    #define     B16AxiPCntStat_OF_STATUS_wdata                 0x002C
    #define   LSb32AxiPCntStat_OF_STATUS_wdata                    8
    #define   LSb16AxiPCntStat_OF_STATUS_wdata                    8
    #define       bAxiPCntStat_OF_STATUS_wdata                 1
    #define   MSK32AxiPCntStat_OF_STATUS_wdata                    0x00000100

    #define     BA_AxiPCntStat_OF_STATUS_awdata                0x002D
    #define     B16AxiPCntStat_OF_STATUS_awdata                0x002C
    #define   LSb32AxiPCntStat_OF_STATUS_awdata                   9
    #define   LSb16AxiPCntStat_OF_STATUS_awdata                   9
    #define       bAxiPCntStat_OF_STATUS_awdata                1
    #define   MSK32AxiPCntStat_OF_STATUS_awdata                   0x00000200

    #define     BA_AxiPCntStat_OF_STATUS_ardata                0x002D
    #define     B16AxiPCntStat_OF_STATUS_ardata                0x002C
    #define   LSb32AxiPCntStat_OF_STATUS_ardata                   10
    #define   LSb16AxiPCntStat_OF_STATUS_ardata                   10
    #define       bAxiPCntStat_OF_STATUS_ardata                1
    #define   MSK32AxiPCntStat_OF_STATUS_ardata                   0x00000400
    ///////////////////////////////////////////////////////////
    #define     RA_AxiPCntStat_READY                           0x0030

    #define     BA_AxiPCntStat_READY_cnt                       0x0030
    #define     B16AxiPCntStat_READY_cnt                       0x0030
    #define   LSb32AxiPCntStat_READY_cnt                          0
    #define   LSb16AxiPCntStat_READY_cnt                          0
    #define       bAxiPCntStat_READY_cnt                       1
    #define   MSK32AxiPCntStat_READY_cnt                          0x00000001
    ///////////////////////////////////////////////////////////

    typedef struct SIE_AxiPCntStat {
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCntStat_TOTAL_CNT_cnt(r32)              _BFGET_(r32, 31, 0)
    #define   SET32AxiPCntStat_TOTAL_CNT_cnt(r32, v)            _BFSET_(r32, 31, 0, v)

    #define     w32AxiPCntStat_TOTAL_CNT                       {\
	    UNSG32 uTOTAL_CNT_cnt                              : 32;\
	}
    union { UNSG32 u32AxiPCntStat_TOTAL_CNT;
	    struct w32AxiPCntStat_TOTAL_CNT;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCntStat_ARWAIT_CNT_cnt(r32)             _BFGET_(r32, 31, 0)
    #define   SET32AxiPCntStat_ARWAIT_CNT_cnt(r32, v)           _BFSET_(r32, 31, 0, v)

    #define     w32AxiPCntStat_ARWAIT_CNT                      {\
	    UNSG32 uARWAIT_CNT_cnt                             : 32;\
	}
    union { UNSG32 u32AxiPCntStat_ARWAIT_CNT;
	    struct w32AxiPCntStat_ARWAIT_CNT;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCntStat_RWAIT_CNT_cnt(r32)              _BFGET_(r32, 31, 0)
    #define   SET32AxiPCntStat_RWAIT_CNT_cnt(r32, v)            _BFSET_(r32, 31, 0, v)

    #define     w32AxiPCntStat_RWAIT_CNT                       {\
	    UNSG32 uRWAIT_CNT_cnt                              : 32;\
	}
    union { UNSG32 u32AxiPCntStat_RWAIT_CNT;
	    struct w32AxiPCntStat_RWAIT_CNT;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCntStat_RIDLE_CNT_cnt(r32)              _BFGET_(r32, 31, 0)
    #define   SET32AxiPCntStat_RIDLE_CNT_cnt(r32, v)            _BFSET_(r32, 31, 0, v)

    #define     w32AxiPCntStat_RIDLE_CNT                       {\
	    UNSG32 uRIDLE_CNT_cnt                              : 32;\
	}
    union { UNSG32 u32AxiPCntStat_RIDLE_CNT;
	    struct w32AxiPCntStat_RIDLE_CNT;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCntStat_RDATA_CNT_cnt(r32)              _BFGET_(r32, 31, 0)
    #define   SET32AxiPCntStat_RDATA_CNT_cnt(r32, v)            _BFSET_(r32, 31, 0, v)

    #define     w32AxiPCntStat_RDATA_CNT                       {\
	    UNSG32 uRDATA_CNT_cnt                              : 32;\
	}
    union { UNSG32 u32AxiPCntStat_RDATA_CNT;
	    struct w32AxiPCntStat_RDATA_CNT;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCntStat_AWWAIT_CNT_cnt(r32)             _BFGET_(r32, 31, 0)
    #define   SET32AxiPCntStat_AWWAIT_CNT_cnt(r32, v)           _BFSET_(r32, 31, 0, v)

    #define     w32AxiPCntStat_AWWAIT_CNT                      {\
	    UNSG32 uAWWAIT_CNT_cnt                             : 32;\
	}
    union { UNSG32 u32AxiPCntStat_AWWAIT_CNT;
	    struct w32AxiPCntStat_AWWAIT_CNT;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCntStat_WWAIT_CNT_cnt(r32)              _BFGET_(r32, 31, 0)
    #define   SET32AxiPCntStat_WWAIT_CNT_cnt(r32, v)            _BFSET_(r32, 31, 0, v)

    #define     w32AxiPCntStat_WWAIT_CNT                       {\
	    UNSG32 uWWAIT_CNT_cnt                              : 32;\
	}
    union { UNSG32 u32AxiPCntStat_WWAIT_CNT;
	    struct w32AxiPCntStat_WWAIT_CNT;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCntStat_WIDLE_CNT_cnt(r32)              _BFGET_(r32, 31, 0)
    #define   SET32AxiPCntStat_WIDLE_CNT_cnt(r32, v)            _BFSET_(r32, 31, 0, v)

    #define     w32AxiPCntStat_WIDLE_CNT                       {\
	    UNSG32 uWIDLE_CNT_cnt                              : 32;\
	}
    union { UNSG32 u32AxiPCntStat_WIDLE_CNT;
	    struct w32AxiPCntStat_WIDLE_CNT;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCntStat_WDATA_CNT_cnt(r32)              _BFGET_(r32, 31, 0)
    #define   SET32AxiPCntStat_WDATA_CNT_cnt(r32, v)            _BFSET_(r32, 31, 0, v)

    #define     w32AxiPCntStat_WDATA_CNT                       {\
	    UNSG32 uWDATA_CNT_cnt                              : 32;\
	}
    union { UNSG32 u32AxiPCntStat_WDATA_CNT;
	    struct w32AxiPCntStat_WDATA_CNT;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCntStat_AWDATA_CNT_cnt(r32)             _BFGET_(r32, 31, 0)
    #define   SET32AxiPCntStat_AWDATA_CNT_cnt(r32, v)           _BFSET_(r32, 31, 0, v)

    #define     w32AxiPCntStat_AWDATA_CNT                      {\
	    UNSG32 uAWDATA_CNT_cnt                             : 32;\
	}
    union { UNSG32 u32AxiPCntStat_AWDATA_CNT;
	    struct w32AxiPCntStat_AWDATA_CNT;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCntStat_ARDATA_CNT_cnt(r32)             _BFGET_(r32, 31, 0)
    #define   SET32AxiPCntStat_ARDATA_CNT_cnt(r32, v)           _BFSET_(r32, 31, 0, v)

    #define     w32AxiPCntStat_ARDATA_CNT                      {\
	    UNSG32 uARDATA_CNT_cnt                             : 32;\
	}
    union { UNSG32 u32AxiPCntStat_ARDATA_CNT;
	    struct w32AxiPCntStat_ARDATA_CNT;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCntStat_OF_STATUS_total(r32)            _BFGET_(r32, 0, 0)
    #define   SET32AxiPCntStat_OF_STATUS_total(r32, v)          _BFSET_(r32, 0, 0, v)
    #define   GET16AxiPCntStat_OF_STATUS_total(r16)            _BFGET_(r16, 0, 0)
    #define   SET16AxiPCntStat_OF_STATUS_total(r16, v)          _BFSET_(r16, 0, 0, v)

    #define   GET32AxiPCntStat_OF_STATUS_arwait(r32)           _BFGET_(r32, 1, 1)
    #define   SET32AxiPCntStat_OF_STATUS_arwait(r32, v)         _BFSET_(r32, 1, 1, v)
    #define   GET16AxiPCntStat_OF_STATUS_arwait(r16)           _BFGET_(r16, 1, 1)
    #define   SET16AxiPCntStat_OF_STATUS_arwait(r16, v)         _BFSET_(r16, 1, 1, v)

    #define   GET32AxiPCntStat_OF_STATUS_rwait(r32)            _BFGET_(r32, 2, 2)
    #define   SET32AxiPCntStat_OF_STATUS_rwait(r32, v)          _BFSET_(r32, 2, 2, v)
    #define   GET16AxiPCntStat_OF_STATUS_rwait(r16)            _BFGET_(r16, 2, 2)
    #define   SET16AxiPCntStat_OF_STATUS_rwait(r16, v)          _BFSET_(r16, 2, 2, v)

    #define   GET32AxiPCntStat_OF_STATUS_ridle(r32)            _BFGET_(r32, 3, 3)
    #define   SET32AxiPCntStat_OF_STATUS_ridle(r32, v)          _BFSET_(r32, 3, 3, v)
    #define   GET16AxiPCntStat_OF_STATUS_ridle(r16)            _BFGET_(r16, 3, 3)
    #define   SET16AxiPCntStat_OF_STATUS_ridle(r16, v)          _BFSET_(r16, 3, 3, v)

    #define   GET32AxiPCntStat_OF_STATUS_rdata(r32)            _BFGET_(r32, 4, 4)
    #define   SET32AxiPCntStat_OF_STATUS_rdata(r32, v)          _BFSET_(r32, 4, 4, v)
    #define   GET16AxiPCntStat_OF_STATUS_rdata(r16)            _BFGET_(r16, 4, 4)
    #define   SET16AxiPCntStat_OF_STATUS_rdata(r16, v)          _BFSET_(r16, 4, 4, v)

    #define   GET32AxiPCntStat_OF_STATUS_awwait(r32)           _BFGET_(r32, 5, 5)
    #define   SET32AxiPCntStat_OF_STATUS_awwait(r32, v)         _BFSET_(r32, 5, 5, v)
    #define   GET16AxiPCntStat_OF_STATUS_awwait(r16)           _BFGET_(r16, 5, 5)
    #define   SET16AxiPCntStat_OF_STATUS_awwait(r16, v)         _BFSET_(r16, 5, 5, v)

    #define   GET32AxiPCntStat_OF_STATUS_wwait(r32)            _BFGET_(r32, 6, 6)
    #define   SET32AxiPCntStat_OF_STATUS_wwait(r32, v)          _BFSET_(r32, 6, 6, v)
    #define   GET16AxiPCntStat_OF_STATUS_wwait(r16)            _BFGET_(r16, 6, 6)
    #define   SET16AxiPCntStat_OF_STATUS_wwait(r16, v)          _BFSET_(r16, 6, 6, v)

    #define   GET32AxiPCntStat_OF_STATUS_widle(r32)            _BFGET_(r32, 7, 7)
    #define   SET32AxiPCntStat_OF_STATUS_widle(r32, v)          _BFSET_(r32, 7, 7, v)
    #define   GET16AxiPCntStat_OF_STATUS_widle(r16)            _BFGET_(r16, 7, 7)
    #define   SET16AxiPCntStat_OF_STATUS_widle(r16, v)          _BFSET_(r16, 7, 7, v)

    #define   GET32AxiPCntStat_OF_STATUS_wdata(r32)            _BFGET_(r32, 8, 8)
    #define   SET32AxiPCntStat_OF_STATUS_wdata(r32, v)          _BFSET_(r32, 8, 8, v)
    #define   GET16AxiPCntStat_OF_STATUS_wdata(r16)            _BFGET_(r16, 8, 8)
    #define   SET16AxiPCntStat_OF_STATUS_wdata(r16, v)          _BFSET_(r16, 8, 8, v)

    #define   GET32AxiPCntStat_OF_STATUS_awdata(r32)           _BFGET_(r32, 9, 9)
    #define   SET32AxiPCntStat_OF_STATUS_awdata(r32, v)         _BFSET_(r32, 9, 9, v)
    #define   GET16AxiPCntStat_OF_STATUS_awdata(r16)           _BFGET_(r16, 9, 9)
    #define   SET16AxiPCntStat_OF_STATUS_awdata(r16, v)         _BFSET_(r16, 9, 9, v)

    #define   GET32AxiPCntStat_OF_STATUS_ardata(r32)           _BFGET_(r32, 10, 10)
    #define   SET32AxiPCntStat_OF_STATUS_ardata(r32, v)         _BFSET_(r32, 10, 10, v)
    #define   GET16AxiPCntStat_OF_STATUS_ardata(r16)           _BFGET_(r16, 10, 10)
    #define   SET16AxiPCntStat_OF_STATUS_ardata(r16, v)         _BFSET_(r16, 10, 10, v)

    #define     w32AxiPCntStat_OF_STATUS                       {\
	    UNSG32 uOF_STATUS_total                            :  1;\
	    UNSG32 uOF_STATUS_arwait                           :  1;\
	    UNSG32 uOF_STATUS_rwait                            :  1;\
	    UNSG32 uOF_STATUS_ridle                            :  1;\
	    UNSG32 uOF_STATUS_rdata                            :  1;\
	    UNSG32 uOF_STATUS_awwait                           :  1;\
	    UNSG32 uOF_STATUS_wwait                            :  1;\
	    UNSG32 uOF_STATUS_widle                            :  1;\
	    UNSG32 uOF_STATUS_wdata                            :  1;\
	    UNSG32 uOF_STATUS_awdata                           :  1;\
	    UNSG32 uOF_STATUS_ardata                           :  1;\
	    UNSG32 RSVDx2C_b11                                 : 21;\
	}
    union { UNSG32 u32AxiPCntStat_OF_STATUS;
	    struct w32AxiPCntStat_OF_STATUS;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiPCntStat_READY_cnt(r32)                  _BFGET_(r32, 0, 0)
    #define   SET32AxiPCntStat_READY_cnt(r32, v)                _BFSET_(r32, 0, 0, v)
    #define   GET16AxiPCntStat_READY_cnt(r16)                  _BFGET_(r16, 0, 0)
    #define   SET16AxiPCntStat_READY_cnt(r16, v)                _BFSET_(r16, 0, 0, v)

    #define     w32AxiPCntStat_READY                           {\
	    UNSG32 uREADY_cnt                                  :  1;\
	    UNSG32 RSVDx30_b1                                  : 31;\
	}
    union { UNSG32 u32AxiPCntStat_READY;
	    struct w32AxiPCntStat_READY;
	  };
    ///////////////////////////////////////////////////////////
    } SIE_AxiPCntStat;

    typedef union  T32AxiPCntStat_TOTAL_CNT {
		UNSG32 u32;
	    struct w32AxiPCntStat_TOTAL_CNT;
		 } T32AxiPCntStat_TOTAL_CNT;
    typedef union  T32AxiPCntStat_ARWAIT_CNT {
		UNSG32 u32;
	    struct w32AxiPCntStat_ARWAIT_CNT;
		 } T32AxiPCntStat_ARWAIT_CNT;
    typedef union  T32AxiPCntStat_RWAIT_CNT {
		UNSG32 u32;
	    struct w32AxiPCntStat_RWAIT_CNT;
		 } T32AxiPCntStat_RWAIT_CNT;
    typedef union  T32AxiPCntStat_RIDLE_CNT {
		UNSG32 u32;
	    struct w32AxiPCntStat_RIDLE_CNT;
		 } T32AxiPCntStat_RIDLE_CNT;
    typedef union  T32AxiPCntStat_RDATA_CNT {
		UNSG32 u32;
	    struct w32AxiPCntStat_RDATA_CNT;
		 } T32AxiPCntStat_RDATA_CNT;
    typedef union  T32AxiPCntStat_AWWAIT_CNT {
		UNSG32 u32;
	    struct w32AxiPCntStat_AWWAIT_CNT;
		 } T32AxiPCntStat_AWWAIT_CNT;
    typedef union  T32AxiPCntStat_WWAIT_CNT {
		UNSG32 u32;
	    struct w32AxiPCntStat_WWAIT_CNT;
		 } T32AxiPCntStat_WWAIT_CNT;
    typedef union  T32AxiPCntStat_WIDLE_CNT {
		UNSG32 u32;
	    struct w32AxiPCntStat_WIDLE_CNT;
		 } T32AxiPCntStat_WIDLE_CNT;
    typedef union  T32AxiPCntStat_WDATA_CNT {
		UNSG32 u32;
	    struct w32AxiPCntStat_WDATA_CNT;
		 } T32AxiPCntStat_WDATA_CNT;
    typedef union  T32AxiPCntStat_AWDATA_CNT {
		UNSG32 u32;
	    struct w32AxiPCntStat_AWDATA_CNT;
		 } T32AxiPCntStat_AWDATA_CNT;
    typedef union  T32AxiPCntStat_ARDATA_CNT {
		UNSG32 u32;
	    struct w32AxiPCntStat_ARDATA_CNT;
		 } T32AxiPCntStat_ARDATA_CNT;
    typedef union  T32AxiPCntStat_OF_STATUS {
		UNSG32 u32;
	    struct w32AxiPCntStat_OF_STATUS;
		 } T32AxiPCntStat_OF_STATUS;
    typedef union  T32AxiPCntStat_READY {
		UNSG32 u32;
	    struct w32AxiPCntStat_READY;
		 } T32AxiPCntStat_READY;
    ///////////////////////////////////////////////////////////

    typedef union  TAxiPCntStat_TOTAL_CNT {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiPCntStat_TOTAL_CNT;
		   };
		 } TAxiPCntStat_TOTAL_CNT;
    typedef union  TAxiPCntStat_ARWAIT_CNT {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiPCntStat_ARWAIT_CNT;
		   };
		 } TAxiPCntStat_ARWAIT_CNT;
    typedef union  TAxiPCntStat_RWAIT_CNT {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiPCntStat_RWAIT_CNT;
		   };
		 } TAxiPCntStat_RWAIT_CNT;
    typedef union  TAxiPCntStat_RIDLE_CNT {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiPCntStat_RIDLE_CNT;
		   };
		 } TAxiPCntStat_RIDLE_CNT;
    typedef union  TAxiPCntStat_RDATA_CNT {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiPCntStat_RDATA_CNT;
		   };
		 } TAxiPCntStat_RDATA_CNT;
    typedef union  TAxiPCntStat_AWWAIT_CNT {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiPCntStat_AWWAIT_CNT;
		   };
		 } TAxiPCntStat_AWWAIT_CNT;
    typedef union  TAxiPCntStat_WWAIT_CNT {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiPCntStat_WWAIT_CNT;
		   };
		 } TAxiPCntStat_WWAIT_CNT;
    typedef union  TAxiPCntStat_WIDLE_CNT {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiPCntStat_WIDLE_CNT;
		   };
		 } TAxiPCntStat_WIDLE_CNT;
    typedef union  TAxiPCntStat_WDATA_CNT {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiPCntStat_WDATA_CNT;
		   };
		 } TAxiPCntStat_WDATA_CNT;
    typedef union  TAxiPCntStat_AWDATA_CNT {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiPCntStat_AWDATA_CNT;
		   };
		 } TAxiPCntStat_AWDATA_CNT;
    typedef union  TAxiPCntStat_ARDATA_CNT {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiPCntStat_ARDATA_CNT;
		   };
		 } TAxiPCntStat_ARDATA_CNT;
    typedef union  TAxiPCntStat_OF_STATUS {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiPCntStat_OF_STATUS;
		   };
		 } TAxiPCntStat_OF_STATUS;
    typedef union  TAxiPCntStat_READY {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiPCntStat_READY;
		   };
		 } TAxiPCntStat_READY;

    ///////////////////////////////////////////////////////////
     SIGN32 AxiPCntStat_drvrd(SIE_AxiPCntStat *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 AxiPCntStat_drvwr(SIE_AxiPCntStat *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void AxiPCntStat_reset(SIE_AxiPCntStat *p);
     SIGN32 AxiPCntStat_cmp(SIE_AxiPCntStat *p, SIE_AxiPCntStat *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define AxiPCntStat_check(p, pie, pfx, hLOG) AxiPCntStat_cmp(p, pie, pfx, (void *)(hLOG), 0, 0)
    #define AxiPCntStat_print(p,    pfx, hLOG) AxiPCntStat_cmp(p, 0,  pfx, (void *)(hLOG), 0, 0)

#endif
//////
/// ENDOFINTERFACE: AxiPCntStat
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE AxiErrorMon                              (4,4)
///     ###
///     * AXI Bus Error Response Monitor
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 WriteID              (R-)
///               %unsigned 32 berrID                    0x0
///                                    ###
///                                    * ID of AXI Write Transaction that caused an error response
///                                    ###
///     @ 0x00004 WriteStat            (R-)
///               %unsigned 1  berrType                  0x0
///                                    ###
///                                    * Error Response Type
///                                    * 0: SLVERR
///                                    * 1: DECERR
///                                    ###
///               %unsigned 1  berrValid                 0x0
///                                    ###
///                                    * When asserted, an error response is detected and the information
///                                    * is captured into berrID and berrType. Monitoring is stopped.
///                                    ###
///               %%        30         # Stuffing bits...
///     @ 0x00008 WriteCtrl            (RW)
///               %unsigned 1  berrClear                 0x0
///                                    ###
///                                    * Writing 1 will clear berrValid and resume the monitoring. This
///                                    * bit self clears.
///                                    ###
///               %unsigned 1  berrIntrEn                0x0
///                                    ###
///                                    * 1: Monitor generates an active high interrupt when berrValid = 1
///                                    * 0: Interrupt is masked
///                                    * Note: To clear interrupt, write 1 to berrClear
///                                    ###
///               %%        30         # Stuffing bits...
///     @ 0x0000C ReadID               (R-)
///               %unsigned 32 rerrID                    0x0
///                                    ###
///                                    * ID of AXI Read Transaction that caused an error response
///                                    ###
///     @ 0x00010 ReadStat             (R-)
///               %unsigned 1  rerrType                  0x0
///                                    ###
///                                    * Error Response Type
///                                    * 0: SLVERR
///                                    * 1: DECERR
///                                    ###
///               %unsigned 1  rerrValid                 0x0
///                                    ###
///                                    * When asserted, an error response is detected and the information
///                                    * is captured into rerrID and rerrType. Monitoring is stopped.
///                                    ###
///               %%        30         # Stuffing bits...
///     @ 0x00014 ReadCtrl             (RW)
///               %unsigned 1  rerrClear                 0x0
///                                    ###
///                                    * Writing 1 will clear rerrValid and resume the monitoring. This
///                                    * bit self clears.
///                                    ###
///               %unsigned 1  rerrIntrEn                0x0
///                                    ###
///                                    * 1: Monitor generates an active high interrupt when berrValid = 1
///                                    * 0: Interrupt is masked.
///                                    * Note: To clear Interrupt, write 1 to berrClear
///                                    ###
///               %%        30         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:      24B, bits:      72b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_AxiErrorMon
#define h_AxiErrorMon () {}

    #define     RA_AxiErrorMon_WriteID                         0x0000

    #define     BA_AxiErrorMon_WriteID_berrID                  0x0000
    #define     B16AxiErrorMon_WriteID_berrID                  0x0000
    #define   LSb32AxiErrorMon_WriteID_berrID                     0
    #define   LSb16AxiErrorMon_WriteID_berrID                     0
    #define       bAxiErrorMon_WriteID_berrID                  32
    #define   MSK32AxiErrorMon_WriteID_berrID                     0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiErrorMon_WriteStat                       0x0004

    #define     BA_AxiErrorMon_WriteStat_berrType              0x0004
    #define     B16AxiErrorMon_WriteStat_berrType              0x0004
    #define   LSb32AxiErrorMon_WriteStat_berrType                 0
    #define   LSb16AxiErrorMon_WriteStat_berrType                 0
    #define       bAxiErrorMon_WriteStat_berrType              1
    #define   MSK32AxiErrorMon_WriteStat_berrType                 0x00000001

    #define     BA_AxiErrorMon_WriteStat_berrValid             0x0004
    #define     B16AxiErrorMon_WriteStat_berrValid             0x0004
    #define   LSb32AxiErrorMon_WriteStat_berrValid                1
    #define   LSb16AxiErrorMon_WriteStat_berrValid                1
    #define       bAxiErrorMon_WriteStat_berrValid             1
    #define   MSK32AxiErrorMon_WriteStat_berrValid                0x00000002
    ///////////////////////////////////////////////////////////
    #define     RA_AxiErrorMon_WriteCtrl                       0x0008

    #define     BA_AxiErrorMon_WriteCtrl_berrClear             0x0008
    #define     B16AxiErrorMon_WriteCtrl_berrClear             0x0008
    #define   LSb32AxiErrorMon_WriteCtrl_berrClear                0
    #define   LSb16AxiErrorMon_WriteCtrl_berrClear                0
    #define       bAxiErrorMon_WriteCtrl_berrClear             1
    #define   MSK32AxiErrorMon_WriteCtrl_berrClear                0x00000001

    #define     BA_AxiErrorMon_WriteCtrl_berrIntrEn            0x0008
    #define     B16AxiErrorMon_WriteCtrl_berrIntrEn            0x0008
    #define   LSb32AxiErrorMon_WriteCtrl_berrIntrEn               1
    #define   LSb16AxiErrorMon_WriteCtrl_berrIntrEn               1
    #define       bAxiErrorMon_WriteCtrl_berrIntrEn            1
    #define   MSK32AxiErrorMon_WriteCtrl_berrIntrEn               0x00000002
    ///////////////////////////////////////////////////////////
    #define     RA_AxiErrorMon_ReadID                          0x000C

    #define     BA_AxiErrorMon_ReadID_rerrID                   0x000C
    #define     B16AxiErrorMon_ReadID_rerrID                   0x000C
    #define   LSb32AxiErrorMon_ReadID_rerrID                      0
    #define   LSb16AxiErrorMon_ReadID_rerrID                      0
    #define       bAxiErrorMon_ReadID_rerrID                   32
    #define   MSK32AxiErrorMon_ReadID_rerrID                      0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_AxiErrorMon_ReadStat                        0x0010

    #define     BA_AxiErrorMon_ReadStat_rerrType               0x0010
    #define     B16AxiErrorMon_ReadStat_rerrType               0x0010
    #define   LSb32AxiErrorMon_ReadStat_rerrType                  0
    #define   LSb16AxiErrorMon_ReadStat_rerrType                  0
    #define       bAxiErrorMon_ReadStat_rerrType               1
    #define   MSK32AxiErrorMon_ReadStat_rerrType                  0x00000001

    #define     BA_AxiErrorMon_ReadStat_rerrValid              0x0010
    #define     B16AxiErrorMon_ReadStat_rerrValid              0x0010
    #define   LSb32AxiErrorMon_ReadStat_rerrValid                 1
    #define   LSb16AxiErrorMon_ReadStat_rerrValid                 1
    #define       bAxiErrorMon_ReadStat_rerrValid              1
    #define   MSK32AxiErrorMon_ReadStat_rerrValid                 0x00000002
    ///////////////////////////////////////////////////////////
    #define     RA_AxiErrorMon_ReadCtrl                        0x0014

    #define     BA_AxiErrorMon_ReadCtrl_rerrClear              0x0014
    #define     B16AxiErrorMon_ReadCtrl_rerrClear              0x0014
    #define   LSb32AxiErrorMon_ReadCtrl_rerrClear                 0
    #define   LSb16AxiErrorMon_ReadCtrl_rerrClear                 0
    #define       bAxiErrorMon_ReadCtrl_rerrClear              1
    #define   MSK32AxiErrorMon_ReadCtrl_rerrClear                 0x00000001

    #define     BA_AxiErrorMon_ReadCtrl_rerrIntrEn             0x0014
    #define     B16AxiErrorMon_ReadCtrl_rerrIntrEn             0x0014
    #define   LSb32AxiErrorMon_ReadCtrl_rerrIntrEn                1
    #define   LSb16AxiErrorMon_ReadCtrl_rerrIntrEn                1
    #define       bAxiErrorMon_ReadCtrl_rerrIntrEn             1
    #define   MSK32AxiErrorMon_ReadCtrl_rerrIntrEn                0x00000002
    ///////////////////////////////////////////////////////////

    typedef struct SIE_AxiErrorMon {
    ///////////////////////////////////////////////////////////
    #define   GET32AxiErrorMon_WriteID_berrID(r32)             _BFGET_(r32, 31, 0)
    #define   SET32AxiErrorMon_WriteID_berrID(r32, v)           _BFSET_(r32, 31, 0, v)

    #define     w32AxiErrorMon_WriteID                         {\
	    UNSG32 uWriteID_berrID                             : 32;\
	}
    union { UNSG32 u32AxiErrorMon_WriteID;
	    struct w32AxiErrorMon_WriteID;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiErrorMon_WriteStat_berrType(r32)         _BFGET_(r32, 0, 0)
    #define   SET32AxiErrorMon_WriteStat_berrType(r32, v)       _BFSET_(r32, 0, 0, v)
    #define   GET16AxiErrorMon_WriteStat_berrType(r16)         _BFGET_(r16, 0, 0)
    #define   SET16AxiErrorMon_WriteStat_berrType(r16, v)       _BFSET_(r16, 0, 0, v)

    #define   GET32AxiErrorMon_WriteStat_berrValid(r32)        _BFGET_(r32, 1, 1)
    #define   SET32AxiErrorMon_WriteStat_berrValid(r32, v)      _BFSET_(r32, 1, 1, v)
    #define   GET16AxiErrorMon_WriteStat_berrValid(r16)        _BFGET_(r16, 1, 1)
    #define   SET16AxiErrorMon_WriteStat_berrValid(r16, v)      _BFSET_(r16, 1, 1, v)

    #define     w32AxiErrorMon_WriteStat                       {\
	    UNSG32 uWriteStat_berrType                         :  1;\
	    UNSG32 uWriteStat_berrValid                        :  1;\
	    UNSG32 RSVDx4_b2                                   : 30;\
	}
    union { UNSG32 u32AxiErrorMon_WriteStat;
	    struct w32AxiErrorMon_WriteStat;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiErrorMon_WriteCtrl_berrClear(r32)        _BFGET_(r32, 0, 0)
    #define   SET32AxiErrorMon_WriteCtrl_berrClear(r32, v)      _BFSET_(r32, 0, 0, v)
    #define   GET16AxiErrorMon_WriteCtrl_berrClear(r16)        _BFGET_(r16, 0, 0)
    #define   SET16AxiErrorMon_WriteCtrl_berrClear(r16, v)      _BFSET_(r16, 0, 0, v)

    #define   GET32AxiErrorMon_WriteCtrl_berrIntrEn(r32)       _BFGET_(r32, 1, 1)
    #define   SET32AxiErrorMon_WriteCtrl_berrIntrEn(r32, v)     _BFSET_(r32, 1, 1, v)
    #define   GET16AxiErrorMon_WriteCtrl_berrIntrEn(r16)       _BFGET_(r16, 1, 1)
    #define   SET16AxiErrorMon_WriteCtrl_berrIntrEn(r16, v)     _BFSET_(r16, 1, 1, v)

    #define     w32AxiErrorMon_WriteCtrl                       {\
	    UNSG32 uWriteCtrl_berrClear                        :  1;\
	    UNSG32 uWriteCtrl_berrIntrEn                       :  1;\
	    UNSG32 RSVDx8_b2                                   : 30;\
	}
    union { UNSG32 u32AxiErrorMon_WriteCtrl;
	    struct w32AxiErrorMon_WriteCtrl;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiErrorMon_ReadID_rerrID(r32)              _BFGET_(r32, 31, 0)
    #define   SET32AxiErrorMon_ReadID_rerrID(r32, v)            _BFSET_(r32, 31, 0, v)

    #define     w32AxiErrorMon_ReadID                          {\
	    UNSG32 uReadID_rerrID                              : 32;\
	}
    union { UNSG32 u32AxiErrorMon_ReadID;
	    struct w32AxiErrorMon_ReadID;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiErrorMon_ReadStat_rerrType(r32)          _BFGET_(r32, 0, 0)
    #define   SET32AxiErrorMon_ReadStat_rerrType(r32, v)        _BFSET_(r32, 0, 0, v)
    #define   GET16AxiErrorMon_ReadStat_rerrType(r16)          _BFGET_(r16, 0, 0)
    #define   SET16AxiErrorMon_ReadStat_rerrType(r16, v)        _BFSET_(r16, 0, 0, v)

    #define   GET32AxiErrorMon_ReadStat_rerrValid(r32)         _BFGET_(r32, 1, 1)
    #define   SET32AxiErrorMon_ReadStat_rerrValid(r32, v)       _BFSET_(r32, 1, 1, v)
    #define   GET16AxiErrorMon_ReadStat_rerrValid(r16)         _BFGET_(r16, 1, 1)
    #define   SET16AxiErrorMon_ReadStat_rerrValid(r16, v)       _BFSET_(r16, 1, 1, v)

    #define     w32AxiErrorMon_ReadStat                        {\
	    UNSG32 uReadStat_rerrType                          :  1;\
	    UNSG32 uReadStat_rerrValid                         :  1;\
	    UNSG32 RSVDx10_b2                                  : 30;\
	}
    union { UNSG32 u32AxiErrorMon_ReadStat;
	    struct w32AxiErrorMon_ReadStat;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32AxiErrorMon_ReadCtrl_rerrClear(r32)         _BFGET_(r32, 0, 0)
    #define   SET32AxiErrorMon_ReadCtrl_rerrClear(r32, v)       _BFSET_(r32, 0, 0, v)
    #define   GET16AxiErrorMon_ReadCtrl_rerrClear(r16)         _BFGET_(r16, 0, 0)
    #define   SET16AxiErrorMon_ReadCtrl_rerrClear(r16, v)       _BFSET_(r16, 0, 0, v)

    #define   GET32AxiErrorMon_ReadCtrl_rerrIntrEn(r32)        _BFGET_(r32, 1, 1)
    #define   SET32AxiErrorMon_ReadCtrl_rerrIntrEn(r32, v)      _BFSET_(r32, 1, 1, v)
    #define   GET16AxiErrorMon_ReadCtrl_rerrIntrEn(r16)        _BFGET_(r16, 1, 1)
    #define   SET16AxiErrorMon_ReadCtrl_rerrIntrEn(r16, v)      _BFSET_(r16, 1, 1, v)

    #define     w32AxiErrorMon_ReadCtrl                        {\
	    UNSG32 uReadCtrl_rerrClear                         :  1;\
	    UNSG32 uReadCtrl_rerrIntrEn                        :  1;\
	    UNSG32 RSVDx14_b2                                  : 30;\
	}
    union { UNSG32 u32AxiErrorMon_ReadCtrl;
	    struct w32AxiErrorMon_ReadCtrl;
	  };
    ///////////////////////////////////////////////////////////
    } SIE_AxiErrorMon;

    typedef union  T32AxiErrorMon_WriteID {
		UNSG32 u32;
	    struct w32AxiErrorMon_WriteID;
		 } T32AxiErrorMon_WriteID;
    typedef union  T32AxiErrorMon_WriteStat {
		UNSG32 u32;
	    struct w32AxiErrorMon_WriteStat;
		 } T32AxiErrorMon_WriteStat;
    typedef union  T32AxiErrorMon_WriteCtrl {
		UNSG32 u32;
	    struct w32AxiErrorMon_WriteCtrl;
		 } T32AxiErrorMon_WriteCtrl;
    typedef union  T32AxiErrorMon_ReadID {
		UNSG32 u32;
	    struct w32AxiErrorMon_ReadID;
		 } T32AxiErrorMon_ReadID;
    typedef union  T32AxiErrorMon_ReadStat {
		UNSG32 u32;
	    struct w32AxiErrorMon_ReadStat;
		 } T32AxiErrorMon_ReadStat;
    typedef union  T32AxiErrorMon_ReadCtrl {
		UNSG32 u32;
	    struct w32AxiErrorMon_ReadCtrl;
		 } T32AxiErrorMon_ReadCtrl;
    ///////////////////////////////////////////////////////////

    typedef union  TAxiErrorMon_WriteID {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiErrorMon_WriteID;
		   };
		 } TAxiErrorMon_WriteID;
    typedef union  TAxiErrorMon_WriteStat {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiErrorMon_WriteStat;
		   };
		 } TAxiErrorMon_WriteStat;
    typedef union  TAxiErrorMon_WriteCtrl {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiErrorMon_WriteCtrl;
		   };
		 } TAxiErrorMon_WriteCtrl;
    typedef union  TAxiErrorMon_ReadID {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiErrorMon_ReadID;
		   };
		 } TAxiErrorMon_ReadID;
    typedef union  TAxiErrorMon_ReadStat {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiErrorMon_ReadStat;
		   };
		 } TAxiErrorMon_ReadStat;
    typedef union  TAxiErrorMon_ReadCtrl {
		UNSG32 u32[1];
	    struct {
	    struct w32AxiErrorMon_ReadCtrl;
		   };
		 } TAxiErrorMon_ReadCtrl;

    ///////////////////////////////////////////////////////////
     SIGN32 AxiErrorMon_drvrd(SIE_AxiErrorMon *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 AxiErrorMon_drvwr(SIE_AxiErrorMon *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void AxiErrorMon_reset(SIE_AxiErrorMon *p);
     SIGN32 AxiErrorMon_cmp(SIE_AxiErrorMon *p, SIE_AxiErrorMon *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define AxiErrorMon_check(p, pie, pfx, hLOG) AxiErrorMon_cmp(p, pie, pfx, (void *)(hLOG), 0, 0)
    #define AxiErrorMon_print(p,    pfx, hLOG) AxiErrorMon_cmp(p, 0,  pfx, (void *)(hLOG), 0, 0)

#endif
//////
/// ENDOFINTERFACE: AxiErrorMon
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE MC_Perf_CntStat                          (4,4)
///     ###
///     * MC performance logging signals counter
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 TOTAL_CNT            (RNB-)
///               %unsigned 32 cnt                       0x0
///                                    ###
///                                    * count
///                                    ###
///     @ 0x00004 OF_STATUS            (RNB-)
///               %unsigned 1  total                     0x0
///                                    ###
///                                    * Overflow status
///                                    ###
///               %%        31         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       8B, bits:      33b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_MC_Perf_CntStat
#define h_MC_Perf_CntStat () {}

    #define     RA_MC_Perf_CntStat_TOTAL_CNT                   0x0000

    #define     BA_MC_Perf_CntStat_TOTAL_CNT_cnt               0x0000
    #define     B16MC_Perf_CntStat_TOTAL_CNT_cnt               0x0000
    #define   LSb32MC_Perf_CntStat_TOTAL_CNT_cnt                  0
    #define   LSb16MC_Perf_CntStat_TOTAL_CNT_cnt                  0
    #define       bMC_Perf_CntStat_TOTAL_CNT_cnt               32
    #define   MSK32MC_Perf_CntStat_TOTAL_CNT_cnt                  0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_MC_Perf_CntStat_OF_STATUS                   0x0004

    #define     BA_MC_Perf_CntStat_OF_STATUS_total             0x0004
    #define     B16MC_Perf_CntStat_OF_STATUS_total             0x0004
    #define   LSb32MC_Perf_CntStat_OF_STATUS_total                0
    #define   LSb16MC_Perf_CntStat_OF_STATUS_total                0
    #define       bMC_Perf_CntStat_OF_STATUS_total             1
    #define   MSK32MC_Perf_CntStat_OF_STATUS_total                0x00000001
    ///////////////////////////////////////////////////////////

    typedef struct SIE_MC_Perf_CntStat {
    ///////////////////////////////////////////////////////////
    #define   GET32MC_Perf_CntStat_TOTAL_CNT_cnt(r32)          _BFGET_(r32, 31, 0)
    #define   SET32MC_Perf_CntStat_TOTAL_CNT_cnt(r32, v)        _BFSET_(r32, 31, 0, v)

    #define     w32MC_Perf_CntStat_TOTAL_CNT                   {\
	    UNSG32 uTOTAL_CNT_cnt                              : 32;\
	}
    union { UNSG32 u32MC_Perf_CntStat_TOTAL_CNT;
	    struct w32MC_Perf_CntStat_TOTAL_CNT;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32MC_Perf_CntStat_OF_STATUS_total(r32)        _BFGET_(r32, 0, 0)
    #define   SET32MC_Perf_CntStat_OF_STATUS_total(r32, v)      _BFSET_(r32, 0, 0, v)
    #define   GET16MC_Perf_CntStat_OF_STATUS_total(r16)        _BFGET_(r16, 0, 0)
    #define   SET16MC_Perf_CntStat_OF_STATUS_total(r16, v)      _BFSET_(r16, 0, 0, v)

    #define     w32MC_Perf_CntStat_OF_STATUS                   {\
	    UNSG32 uOF_STATUS_total                            :  1;\
	    UNSG32 RSVDx4_b1                                   : 31;\
	}
    union { UNSG32 u32MC_Perf_CntStat_OF_STATUS;
	    struct w32MC_Perf_CntStat_OF_STATUS;
	  };
    ///////////////////////////////////////////////////////////
    } SIE_MC_Perf_CntStat;

    typedef union  T32MC_Perf_CntStat_TOTAL_CNT {
		UNSG32 u32;
	    struct w32MC_Perf_CntStat_TOTAL_CNT;
		 } T32MC_Perf_CntStat_TOTAL_CNT;
    typedef union  T32MC_Perf_CntStat_OF_STATUS {
		UNSG32 u32;
	    struct w32MC_Perf_CntStat_OF_STATUS;
		 } T32MC_Perf_CntStat_OF_STATUS;
    ///////////////////////////////////////////////////////////

    typedef union  TMC_Perf_CntStat_TOTAL_CNT {
		UNSG32 u32[1];
	    struct {
	    struct w32MC_Perf_CntStat_TOTAL_CNT;
		   };
		 } TMC_Perf_CntStat_TOTAL_CNT;
    typedef union  TMC_Perf_CntStat_OF_STATUS {
		UNSG32 u32[1];
	    struct {
	    struct w32MC_Perf_CntStat_OF_STATUS;
		   };
		 } TMC_Perf_CntStat_OF_STATUS;

    ///////////////////////////////////////////////////////////
     SIGN32 MC_Perf_CntStat_drvrd(SIE_MC_Perf_CntStat *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 MC_Perf_CntStat_drvwr(SIE_MC_Perf_CntStat *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void MC_Perf_CntStat_reset(SIE_MC_Perf_CntStat *p);
     SIGN32 MC_Perf_CntStat_cmp(SIE_MC_Perf_CntStat *p, SIE_MC_Perf_CntStat *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define MC_Perf_CntStat_check(p, pie, pfx, hLOG) MC_Perf_CntStat_cmp(p, pie, pfx, (void *)(hLOG), 0, 0)
    #define MC_Perf_CntStat_print(p,    pfx, hLOG) MC_Perf_CntStat_cmp(p, 0,  pfx, (void *)(hLOG), 0, 0)

#endif
//////
/// ENDOFINTERFACE: MC_Perf_CntStat
////////////////////////////////////////////////////////////

//////
///
/// $INTERFACE mc_wrap                 biu              (4,4)
///     ###
///     * MC Wrapper
///     ###
///     # # ----------------------------------------------------------
///     @ 0x00000 MC_StickyRstn        (P)
///               ###
///               * Sticky Reset asserted by default
///               ###
///               %unsigned 1  core                      0x0
///               %unsigned 1  szc                       0x0
///               %unsigned 1  phy                       0x0
///               %unsigned 1  phy_apb                   0x1
///               %%        28         # Stuffing bits...
///     @ 0x00004 DDRPHY_BypassPClk    (P)
///               %unsigned 1  En                        0x0
///                                    ###
///                                    * This enables ByPassPclk clock input to DDRPHY
///                                    ###
///               %%        31         # Stuffing bits...
///     @ 0x00008                      (P)
///     # 0x00008 memPll
///               $abipll_rw           memPll            REG
///                                    ###
///                                    * Configuration registers for memPll
///                                    ###
///     @ 0x00028                      (P)
///     # 0x00028 dfc_pmu_pll
///               $abipll              dfc_pmu_pll       REG
///                                    ###
///                                    * Duplicate memPll registers for dfc_pmu block
///                                    ###
///     @ 0x00048 AxiPCntCTRL          (P)
///               ###
///               * 5 Performance counters are integrated in SOC.
///               * Each bit of following 3 registers is used to control one
///               * performance counter
///               * MC Port  Bus Name Number of PCnts Masters of Interest
///               * 0  CPU2DDR  5   CPU, DSP, IMTEST/AIO, PERIF, SISS
///               * 1  NPU2DDR  1   NPU
///               ###
///               %unsigned 6  clear                     0x0
///                                    ###
///                                    * Clear the counters
///                                    ###
///               %unsigned 6  enable                    0x0
///                                    ###
///                                    * Enable the counter increment, SW can make enable = 0 to
///                                    * temporarily disable counter increment
///                                    ###
///               %unsigned 6  latch                     0x0
///                                    ###
///                                    * Counter values are latched on rising edge of this signal
///                                    * Performance Counter support ID mask function. Each performance
///                                    * counter has one ID register and one Mask register.
///                                    * Only the transaction satisfies following equation would be
///                                    * counted:
///                                    * PID & Mask = TID & Mask
///                                    * PID is the programmed ID. TID is the transaction ID.
///                                    * ID mask function can be used for these counters:
///                                    * arwait, rwait, rdata, ridle, await and wdata
///                                    ###
///               %%        14         # Stuffing bits...
///     @ 0x0004C AxiMst0_0            (P)
///               %unsigned 16 PID                       0x0
///               %unsigned 16 Mask                      0x0
///     @ 0x00050 AxiMst0_1            (P)
///               %unsigned 16 PID                       0x0
///               %unsigned 16 Mask                      0x0
///     @ 0x00054 AxiMst0_2            (P)
///               %unsigned 16 PID                       0x0
///               %unsigned 16 Mask                      0x0
///     @ 0x00058 AxiMst0_3            (P)
///               %unsigned 16 PID                       0x0
///               %unsigned 16 Mask                      0x0
///     @ 0x0005C AxiMst0_4            (P)
///               %unsigned 16 PID                       0x0
///               %unsigned 16 Mask                      0x0
///     @ 0x00060 AxiMst1_0            (P)
///               %unsigned 16 PID                       0x0
///               %unsigned 16 Mask                      0x0
///     @ 0x00064                      (P)
///     # 0x00064 Mstr0_0_PCnt
///               $AxiPCntStat         Mstr0_0_PCnt      REG
///                                    ###
///                                    * master0 AXI interface performance counter
///                                    ###
///     @ 0x00098                      (P)
///     # 0x00098 Mstr0_1_PCnt
///               $AxiPCntStat         Mstr0_1_PCnt      REG
///                                    ###
///                                    * master0 AXI interface performance counter
///                                    ###
///     @ 0x000CC                      (P)
///     # 0x000CC Mstr0_2_PCnt
///               $AxiPCntStat         Mstr0_2_PCnt      REG
///                                    ###
///                                    * master0 AXI interface performance counter
///                                    ###
///     @ 0x00100                      (P)
///     # 0x00100 Mstr0_3_PCnt
///               $AxiPCntStat         Mstr0_3_PCnt      REG
///                                    ###
///                                    * master0 AXI interface performance counter
///                                    ###
///     @ 0x00134                      (P)
///     # 0x00134 Mstr0_4_PCnt
///               $AxiPCntStat         Mstr0_4_PCnt      REG
///                                    ###
///                                    * master0 AXI interface performance counter
///                                    ###
///     @ 0x00168                      (P)
///     # 0x00168 Mstr1_0_PCnt
///               $AxiPCntStat         Mstr1_0_PCnt      REG
///                                    ###
///                                    * master1 AXI interface performance counter
///                                    ###
///     @ 0x0019C                      (P)
///     # 0x0019C AxiErrorMon_Mst0
///               $AxiErrorMon         AxiErrorMon_Mst0  REG
///                                    ###
///                                    * Memory Controller Axi Interface error detector.
///                                    ###
///     @ 0x001B4                      (P)
///     # 0x001B4 AxiErrorMon_Mst1
///               $AxiErrorMon         AxiErrorMon_Mst1  REG
///                                    ###
///                                    * Memory Controller Axi Interface error detector.
///                                    ###
///     @ 0x001CC AlmSel               (P)
///               %unsigned 1  almSel
///               %%        31         # Stuffing bits...
///     @ 0x001D0 AxUrgent             (P)
///               %unsigned 2  Rd_b                      0x0
///               %unsigned 2  Rd_r                      0x0
///               %unsigned 2  Wr                        0x0
///               %%        26         # Stuffing bits...
///     @ 0x001D4 PA_MASK              (P)
///               %unsigned 4  Rd                        0x0
///                                    ###
///                                    * Port Arbiter Read Mask
///                                    ###
///               %unsigned 2  Wr                        0x0
///                                    ###
///                                    * Port Arbiter Write Mask
///                                    ###
///               %%        26         # Stuffing bits...
///     @ 0x001D8 P0_AxQoS             (P)
///               %unsigned 5  UID2MATCH_1               0x0
///               %unsigned 5  UID2MATCH_2               0x0
///               %unsigned 5  UID2MATCH_3               0x0
///               %unsigned 5  UID2MATCH_4               0x0
///               %unsigned 5  UID2MATCH_5               0x0
///               %unsigned 4  Rd4ID_1                   0x0
///               %%        3          # Stuffing bits...
///     # 0x001DC P0_AxQoS1
///               %unsigned 4  Rd4ID_2                   0x0
///               %unsigned 4  Rd4ID_3                   0x0
///               %unsigned 4  Rd4ID_4                   0x0
///               %unsigned 4  Rd4ID_5                   0x0
///               %unsigned 4  Wr4ID_1                   0x0
///               %unsigned 4  Wr4ID_2                   0x0
///               %unsigned 4  Wr4ID_3                   0x0
///               %unsigned 4  Wr4ID_4                   0x0
///     # 0x001E0 P0_AxQoS2
///               %unsigned 4  Wr4ID_5                   0x0
///                                    ###
///                                    * ARQoS for uMCTL2 port 1
///                                    * AWQoS for uMCTL2 port 1
///                                    ###
///               %%        28         # Stuffing bits...
///     @ 0x001E4 P1_AxQoS             (P)
///               %unsigned 5  UID2MATCH_1               0x0
///               %unsigned 4  Rd4ID_1                   0x0
///               %unsigned 4  Wr4ID_1                   0x0
///                                    ###
///                                    * ARQoS for uMCTL2 port 1
///                                    * AWQoS for uMCTL2 port 1
///                                    ###
///               %%        19         # Stuffing bits...
///     @ 0x001E8 hif_mrr_data         (RW)
///               %unsigned 1  lower_valid               0x0
///                                    ###
///                                    * Valid indicates lower 128 bits of DDR4 MPR data or LPDDR4 MRR
///                                    * Data is valid
///                                    ###
///               %unsigned 1  lower_valid_clear         0x0
///                                    ###
///                                    * Clear the lower_valid
///                                    ###
///               %unsigned 1  upper_valid               0x0
///                                    ###
///                                    * Valid indicates upper 128 bits of DDR4 MPR data is valid
///                                    ###
///               %unsigned 1  upper_valid_clear         0x0
///                                    ###
///                                    * Clear the lower_valid
///                                    ###
///               %%        28         # Stuffing bits...
///     @ 0x001EC hif_mrr_ddr4_lower   (R-)
///               %unsigned 32 data0                     0x0
///     # 0x001F0 hif_mrr_ddr4_lower1
///               %unsigned 32 data1                     0x0
///     # 0x001F4 hif_mrr_ddr4_lower2
///               %unsigned 32 data2                     0x0
///     # 0x001F8 hif_mrr_ddr4_lower3
///               %unsigned 32 data3                     0x0
///                                    ###
///                                    * DDR4 MPR data lower 128 bits
///                                    ###
///     @ 0x001FC hif_mrr_ddr4_upper   (R-)
///               %unsigned 32 data0                     0x0
///     # 0x00200 hif_mrr_ddr4_upper1
///               %unsigned 32 data1                     0x0
///     # 0x00204 hif_mrr_ddr4_upper2
///               %unsigned 32 data2                     0x0
///     # 0x00208 hif_mrr_ddr4_upper3
///               %unsigned 32 data3                     0x0
///                                    ###
///                                    * DDR4 MPR data upper 128 bits
///                                    ###
///     @ 0x0020C Axi_Low_Pwr_Ifc      (RW)
///               %unsigned 2  lp_req                    0x3
///               %unsigned 2  lp_ack                    0x3
///               %unsigned 2  lp_active                 0x3
///               %%        26         # Stuffing bits...
///     @ 0x00210 ddrc_low_pwr_ifc_ch0 (P)
///               %unsigned 1  freq                      0x1
///                                    ###
///                                    * Target frequency for DDRC Hardware Fast Frequency Change. This
///                                    * signal is effective only when Hardware Fast Frequency Change is
///                                    * requested (that is, csysreq_ddrc=0 and csysmode_ddrc=1).
///                                    ###
///               %unsigned 1  discamdrain               0x0
///                                    ###
///                                    * Disable CAM draining for DDRC Hardware Fast Frequency Change.
///                                    * When asserted, Self-Refresh can be entered without draining
///                                    * CAM. This signal is effective only when Hardware Fast Frequency
///                                    * Change is requested (that is, csysreq_ddrc=0 and
///                                    * csysmode_ddrc=1).
///                                    ###
///               %%        30         # Stuffing bits...
///     @ 0x00214 DFC_PMU_CTRL         (P)
///               %unsigned 1  dfc_pmu_en                0x0
///                                    ###
///                                    * Enable DFC PMU Controller
///                                    ###
///               %unsigned 2  dfc_pmu_en_ch             0x3
///                                    ###
///                                    * [0] : enables dfc_pmu for CH0
///                                    * [1] : enables dfc_pmu for CH1
///                                    ###
///               %unsigned 1  dfc_pmu_int_clr           0x0
///                                    ###
///                                    * Clear interrupt generated by dfc_pmu
///                                    ###
///               %unsigned 16 bypen_to_rsten_time       0x0
///                                    ###
///                                    * MemPll bypass_en to reset_en time
///                                    ###
///               %%        12         # Stuffing bits...
///     # 0x00218 DFC_PMU_CTRL1
///               %unsigned 16 rsten_to_newset_time      0x0
///                                    ###
///                                    * MemPll reset_en to switch to new setting time
///                                    ###
///               %unsigned 16 newset_to_rstdis_time     0x0
///                                    ###
///                                    * MemPll switch to new setting time to reset disable time
///                                    ###
///     # 0x0021C DFC_PMU_CTRL2
///               %unsigned 16 plllck_wait_time          0xFFFF
///                                    ###
///                                    * MemPll lock wait time
///                                    ###
///               %unsigned 16 plllck_to_bypdis_time     0x0
///                                    ###
///                                    * MemPll lock to bypass disable time
///                                    ###
///     @ 0x00220 stat_ddrc            (R-)
///               %unsigned 2  selfref_type_ch0          0x0
///               %unsigned 2  selfref_type_ch1          0x0
///               %%        28         # Stuffing bits...
///     @ 0x00224 ddrphy_dto           (R-)
///               %unsigned 1  ch0                       0x0
///               %unsigned 1  ch1                       0x0
///               %%        30         # Stuffing bits...
///     @ 0x00228 PwrOkIn              (P)
///               %unsigned 1  TRUE                      0x0
///                                    ###
///                                    * This will drive PwrOkIn input of DDRPHY
///                                    ###
///               %%        31         # Stuffing bits...
///     @ 0x0022C bufferen_core        (P)
///               %unsigned 1  TRUE                      0x0
///                                    ###
///                                    * Used by inno ddrphy
///                                    ###
///               %%        31         # Stuffing bits...
///     @ 0x00230 perf_log_cnt_ctrl    (P)
///               %unsigned 8  clear                     0x0
///                                    ###
///                                    * Clear the counters
///                                    ###
///               %unsigned 8  enable                    0x0
///                                    ###
///                                    * Enable the counter increment, SW can make enable = 0 to
///                                    * temporarily disable counter increment
///                                    ###
///               %unsigned 8  latch                     0x0
///                                    ###
///                                    * Enable the counter increment, SW can make enable = 0 to
///                                    * temporarily disable counter increment
///                                    ###
///               %unsigned 3  clk_div                   0x0
///                                    ###
///                                    * Clock divider for clock cycle counter
///                                    * 0x0  Divide clock by 1
///                                    * 0x1  Divide clock by 2
///                                    * 0x2  Divide clock by 4
///                                    * 0x3  Divide clock by 8
///                                    * 0x4  Divide clock by 16
///                                    * 0x5  Divide clock by 32
///                                    * 0x6  Divide clock by 64
///                                    * 0x7  Divide clock by 128
///                                    ###
///               %%        5          # Stuffing bits...
///     # 0x00234 perf_log_cnt_ctrl1
///               %unsigned 6  pc0_event_sel             0x0
///                                    ###
///                                    * 0x0 : Clock cycles
///                                    * 0x1  : perf_hif_rd_or_wr
///                                    * 0x2  : perf_hif_wr
///                                    * 0x3  : perf_hif_rd
///                                    * 0x4  : perf_hif_rmw
///                                    * 0x5  : perf_hif_hi_pri_rd
///                                    * 0x6  : perf_dfi_wr_data_cycles
///                                    * 0x7  : perf_dfi_rd_data_cycles
///                                    * 0x8  : perf_hpr_xact_when_critical
///                                    * 0x9  : perf_lpr_xact_when_critical
///                                    * 0xa  : perf_wr_xact_when_critical
///                                    * 0xb  : perf_op_is_activate
///                                    * 0xc  : perf_op_is_rd_or_wr
///                                    * 0xd  : perf_op_is_rd_activate
///                                    * 0xe  : perf_op_is_rd
///                                    * 0xf  : perf_op_is_wr
///                                    * 0x10 : perf_op_is_precharge
///                                    * 0x11 : perf_precharge_for_rdwr
///                                    * 0x12 : perf_precharge_for_other
///                                    * 0x13 : perf_rdwr_transitions
///                                    * 0x14 : perf_write_combine
///                                    * 0x15 : perf_war_hazard
///                                    * 0x16 : perf_raw_hazard
///                                    * 0x17 : perf_waw_hazard
///                                    * 0x18 : perf_op_is_enter_selfref
///                                    * 0x19 : perf_op_is_enter_powerdown
///                                    * 0x1a : perf_selfref_mode
///                                    * 0x1b : perf_op_is_refresh
///                                    * 0x1c : perf_op_is_crit_ref
///                                    * 0x1d : perf_op_is_spec_ref
///                                    * 0x1e : perf_op_is_load_mode
///                                    * 0x1f : perf_op_is_zqcl
///                                    * 0x20 : perf_op_is_zqcs
///                                    * 0x21 : perf_hpr_req_with_nocredit
///                                    * 0x22 : perf_lpr_req_with_nocredit
///                                    * 0x23 :  dfi_phymstr_req count
///                                    * 0x24 :  dfi_phymstr_ack count
///                                    * 0x25 :  dfi_ctrlupd_req count
///                                    * 0x26 :  dfi_ctrlupd_ack count
///                                    * 0x27 : dfi_phymstr_req high duration count
///                                    * 0x28 : dfi_ctrlupd_req high duration count
///                                    * 0x29 : perf_op_is_mwr
///                                    * 0x2a : perf_op_is_enter_deeppowerdown
///                                    ###
///               %unsigned 6  pc1_event_sel             0x0
///               %unsigned 6  pc2_event_sel             0x0
///               %unsigned 6  pc3_event_sel             0x0
///               %unsigned 6  pc4_event_sel             0x0
///               %%        2          # Stuffing bits...
///     # 0x00238 perf_log_cnt_ctrl2
///               %unsigned 6  pc5_event_sel             0x0
///               %unsigned 6  pc6_event_sel             0x0
///               %unsigned 6  pc7_event_sel             0x0
///               %%        14         # Stuffing bits...
///     @ 0x0023C perf_log_cnt_ready   (R-)
///               %unsigned 8  cnt                       0x0
///                                    ###
///                                    * This bit is set by HW when counter values are latched and it's
///                                    * ok for SW to read the counter
///                                    ###
///               %%        24         # Stuffing bits...
///     @ 0x00240                      (P)
///     # 0x00240 pc0
///               $MC_Perf_CntStat     pc0               REG
///                                    ###
///                                    * Performance counter0
///                                    ###
///     @ 0x00248                      (P)
///     # 0x00248 pc1
///               $MC_Perf_CntStat     pc1               REG
///                                    ###
///                                    * Performance counter1
///                                    ###
///     @ 0x00250                      (P)
///     # 0x00250 pc2
///               $MC_Perf_CntStat     pc2               REG
///                                    ###
///                                    * Performance counter2
///                                    ###
///     @ 0x00258                      (P)
///     # 0x00258 pc3
///               $MC_Perf_CntStat     pc3               REG
///                                    ###
///                                    * Performance counter3
///                                    ###
///     @ 0x00260                      (P)
///     # 0x00260 pc4
///               $MC_Perf_CntStat     pc4               REG
///                                    ###
///                                    * Performance counter4
///                                    ###
///     @ 0x00268                      (P)
///     # 0x00268 pc5
///               $MC_Perf_CntStat     pc5               REG
///                                    ###
///                                    * Performance counter5
///                                    ###
///     @ 0x00270                      (P)
///     # 0x00270 pc6
///               $MC_Perf_CntStat     pc6               REG
///                                    ###
///                                    * Performance counter6
///                                    ###
///     @ 0x00278                      (P)
///     # 0x00278 pc7
///               $MC_Perf_CntStat     pc7               REG
///                                    ###
///                                    * Performance counter7
///                                    ###
///     @ 0x00280 ddrphy_lpbk          (RW)
///               %unsigned 1  bist_mode                 0x0
///                                    ###
///                                    * Enable bist mode
///                                    ###
///               %unsigned 1  bist_mux                  0x0
///                                    ###
///                                    * 0: CMD/DATA BIST
///                                    * 1 : REG BIST
///                                    ###
///               %unsigned 1  bist_start                0x0
///               %unsigned 1  bist_complete             0x0
///               %unsigned 1  bist_error                0x0
///               %%        27         # Stuffing bits...
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:     644B, bits:    3476b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_mc_wrap
#define h_mc_wrap () {}

    #define     RA_mc_wrap_MC_StickyRstn                       0x0000

    #define     BA_mc_wrap_MC_StickyRstn_core                  0x0000
    #define     B16mc_wrap_MC_StickyRstn_core                  0x0000
    #define   LSb32mc_wrap_MC_StickyRstn_core                     0
    #define   LSb16mc_wrap_MC_StickyRstn_core                     0
    #define       bmc_wrap_MC_StickyRstn_core                  1
    #define   MSK32mc_wrap_MC_StickyRstn_core                     0x00000001

    #define     BA_mc_wrap_MC_StickyRstn_szc                   0x0000
    #define     B16mc_wrap_MC_StickyRstn_szc                   0x0000
    #define   LSb32mc_wrap_MC_StickyRstn_szc                      1
    #define   LSb16mc_wrap_MC_StickyRstn_szc                      1
    #define       bmc_wrap_MC_StickyRstn_szc                   1
    #define   MSK32mc_wrap_MC_StickyRstn_szc                      0x00000002

    #define     BA_mc_wrap_MC_StickyRstn_phy                   0x0000
    #define     B16mc_wrap_MC_StickyRstn_phy                   0x0000
    #define   LSb32mc_wrap_MC_StickyRstn_phy                      2
    #define   LSb16mc_wrap_MC_StickyRstn_phy                      2
    #define       bmc_wrap_MC_StickyRstn_phy                   1
    #define   MSK32mc_wrap_MC_StickyRstn_phy                      0x00000004

    #define     BA_mc_wrap_MC_StickyRstn_phy_apb               0x0000
    #define     B16mc_wrap_MC_StickyRstn_phy_apb               0x0000
    #define   LSb32mc_wrap_MC_StickyRstn_phy_apb                  3
    #define   LSb16mc_wrap_MC_StickyRstn_phy_apb                  3
    #define       bmc_wrap_MC_StickyRstn_phy_apb               1
    #define   MSK32mc_wrap_MC_StickyRstn_phy_apb                  0x00000008
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_DDRPHY_BypassPClk                   0x0004

    #define     BA_mc_wrap_DDRPHY_BypassPClk_En                0x0004
    #define     B16mc_wrap_DDRPHY_BypassPClk_En                0x0004
    #define   LSb32mc_wrap_DDRPHY_BypassPClk_En                   0
    #define   LSb16mc_wrap_DDRPHY_BypassPClk_En                   0
    #define       bmc_wrap_DDRPHY_BypassPClk_En                1
    #define   MSK32mc_wrap_DDRPHY_BypassPClk_En                   0x00000001
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_memPll                              0x0008
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_dfc_pmu_pll                         0x0028
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_AxiPCntCTRL                         0x0048

    #define     BA_mc_wrap_AxiPCntCTRL_clear                   0x0048
    #define     B16mc_wrap_AxiPCntCTRL_clear                   0x0048
    #define   LSb32mc_wrap_AxiPCntCTRL_clear                      0
    #define   LSb16mc_wrap_AxiPCntCTRL_clear                      0
    #define       bmc_wrap_AxiPCntCTRL_clear                   6
    #define   MSK32mc_wrap_AxiPCntCTRL_clear                      0x0000003F

    #define     BA_mc_wrap_AxiPCntCTRL_enable                  0x0048
    #define     B16mc_wrap_AxiPCntCTRL_enable                  0x0048
    #define   LSb32mc_wrap_AxiPCntCTRL_enable                     6
    #define   LSb16mc_wrap_AxiPCntCTRL_enable                     6
    #define       bmc_wrap_AxiPCntCTRL_enable                  6
    #define   MSK32mc_wrap_AxiPCntCTRL_enable                     0x00000FC0

    #define     BA_mc_wrap_AxiPCntCTRL_latch                   0x0049
    #define     B16mc_wrap_AxiPCntCTRL_latch                   0x0048
    #define   LSb32mc_wrap_AxiPCntCTRL_latch                      12
    #define   LSb16mc_wrap_AxiPCntCTRL_latch                      12
    #define       bmc_wrap_AxiPCntCTRL_latch                   6
    #define   MSK32mc_wrap_AxiPCntCTRL_latch                      0x0003F000
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_AxiMst0_0                           0x004C

    #define     BA_mc_wrap_AxiMst0_0_PID                       0x004C
    #define     B16mc_wrap_AxiMst0_0_PID                       0x004C
    #define   LSb32mc_wrap_AxiMst0_0_PID                          0
    #define   LSb16mc_wrap_AxiMst0_0_PID                          0
    #define       bmc_wrap_AxiMst0_0_PID                       16
    #define   MSK32mc_wrap_AxiMst0_0_PID                          0x0000FFFF

    #define     BA_mc_wrap_AxiMst0_0_Mask                      0x004E
    #define     B16mc_wrap_AxiMst0_0_Mask                      0x004E
    #define   LSb32mc_wrap_AxiMst0_0_Mask                         16
    #define   LSb16mc_wrap_AxiMst0_0_Mask                         0
    #define       bmc_wrap_AxiMst0_0_Mask                      16
    #define   MSK32mc_wrap_AxiMst0_0_Mask                         0xFFFF0000
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_AxiMst0_1                           0x0050

    #define     BA_mc_wrap_AxiMst0_1_PID                       0x0050
    #define     B16mc_wrap_AxiMst0_1_PID                       0x0050
    #define   LSb32mc_wrap_AxiMst0_1_PID                          0
    #define   LSb16mc_wrap_AxiMst0_1_PID                          0
    #define       bmc_wrap_AxiMst0_1_PID                       16
    #define   MSK32mc_wrap_AxiMst0_1_PID                          0x0000FFFF

    #define     BA_mc_wrap_AxiMst0_1_Mask                      0x0052
    #define     B16mc_wrap_AxiMst0_1_Mask                      0x0052
    #define   LSb32mc_wrap_AxiMst0_1_Mask                         16
    #define   LSb16mc_wrap_AxiMst0_1_Mask                         0
    #define       bmc_wrap_AxiMst0_1_Mask                      16
    #define   MSK32mc_wrap_AxiMst0_1_Mask                         0xFFFF0000
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_AxiMst0_2                           0x0054

    #define     BA_mc_wrap_AxiMst0_2_PID                       0x0054
    #define     B16mc_wrap_AxiMst0_2_PID                       0x0054
    #define   LSb32mc_wrap_AxiMst0_2_PID                          0
    #define   LSb16mc_wrap_AxiMst0_2_PID                          0
    #define       bmc_wrap_AxiMst0_2_PID                       16
    #define   MSK32mc_wrap_AxiMst0_2_PID                          0x0000FFFF

    #define     BA_mc_wrap_AxiMst0_2_Mask                      0x0056
    #define     B16mc_wrap_AxiMst0_2_Mask                      0x0056
    #define   LSb32mc_wrap_AxiMst0_2_Mask                         16
    #define   LSb16mc_wrap_AxiMst0_2_Mask                         0
    #define       bmc_wrap_AxiMst0_2_Mask                      16
    #define   MSK32mc_wrap_AxiMst0_2_Mask                         0xFFFF0000
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_AxiMst0_3                           0x0058

    #define     BA_mc_wrap_AxiMst0_3_PID                       0x0058
    #define     B16mc_wrap_AxiMst0_3_PID                       0x0058
    #define   LSb32mc_wrap_AxiMst0_3_PID                          0
    #define   LSb16mc_wrap_AxiMst0_3_PID                          0
    #define       bmc_wrap_AxiMst0_3_PID                       16
    #define   MSK32mc_wrap_AxiMst0_3_PID                          0x0000FFFF

    #define     BA_mc_wrap_AxiMst0_3_Mask                      0x005A
    #define     B16mc_wrap_AxiMst0_3_Mask                      0x005A
    #define   LSb32mc_wrap_AxiMst0_3_Mask                         16
    #define   LSb16mc_wrap_AxiMst0_3_Mask                         0
    #define       bmc_wrap_AxiMst0_3_Mask                      16
    #define   MSK32mc_wrap_AxiMst0_3_Mask                         0xFFFF0000
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_AxiMst0_4                           0x005C

    #define     BA_mc_wrap_AxiMst0_4_PID                       0x005C
    #define     B16mc_wrap_AxiMst0_4_PID                       0x005C
    #define   LSb32mc_wrap_AxiMst0_4_PID                          0
    #define   LSb16mc_wrap_AxiMst0_4_PID                          0
    #define       bmc_wrap_AxiMst0_4_PID                       16
    #define   MSK32mc_wrap_AxiMst0_4_PID                          0x0000FFFF

    #define     BA_mc_wrap_AxiMst0_4_Mask                      0x005E
    #define     B16mc_wrap_AxiMst0_4_Mask                      0x005E
    #define   LSb32mc_wrap_AxiMst0_4_Mask                         16
    #define   LSb16mc_wrap_AxiMst0_4_Mask                         0
    #define       bmc_wrap_AxiMst0_4_Mask                      16
    #define   MSK32mc_wrap_AxiMst0_4_Mask                         0xFFFF0000
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_AxiMst1_0                           0x0060

    #define     BA_mc_wrap_AxiMst1_0_PID                       0x0060
    #define     B16mc_wrap_AxiMst1_0_PID                       0x0060
    #define   LSb32mc_wrap_AxiMst1_0_PID                          0
    #define   LSb16mc_wrap_AxiMst1_0_PID                          0
    #define       bmc_wrap_AxiMst1_0_PID                       16
    #define   MSK32mc_wrap_AxiMst1_0_PID                          0x0000FFFF

    #define     BA_mc_wrap_AxiMst1_0_Mask                      0x0062
    #define     B16mc_wrap_AxiMst1_0_Mask                      0x0062
    #define   LSb32mc_wrap_AxiMst1_0_Mask                         16
    #define   LSb16mc_wrap_AxiMst1_0_Mask                         0
    #define       bmc_wrap_AxiMst1_0_Mask                      16
    #define   MSK32mc_wrap_AxiMst1_0_Mask                         0xFFFF0000
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_Mstr0_0_PCnt                        0x0064
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_Mstr0_1_PCnt                        0x0098
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_Mstr0_2_PCnt                        0x00CC
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_Mstr0_3_PCnt                        0x0100
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_Mstr0_4_PCnt                        0x0134
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_Mstr1_0_PCnt                        0x0168
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_AxiErrorMon_Mst0                    0x019C
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_AxiErrorMon_Mst1                    0x01B4
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_AlmSel                              0x01CC

    #define     BA_mc_wrap_AlmSel_almSel                       0x01CC
    #define     B16mc_wrap_AlmSel_almSel                       0x01CC
    #define   LSb32mc_wrap_AlmSel_almSel                          0
    #define   LSb16mc_wrap_AlmSel_almSel                          0
    #define       bmc_wrap_AlmSel_almSel                       1
    #define   MSK32mc_wrap_AlmSel_almSel                          0x00000001
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_AxUrgent                            0x01D0

    #define     BA_mc_wrap_AxUrgent_Rd_b                       0x01D0
    #define     B16mc_wrap_AxUrgent_Rd_b                       0x01D0
    #define   LSb32mc_wrap_AxUrgent_Rd_b                          0
    #define   LSb16mc_wrap_AxUrgent_Rd_b                          0
    #define       bmc_wrap_AxUrgent_Rd_b                       2
    #define   MSK32mc_wrap_AxUrgent_Rd_b                          0x00000003

    #define     BA_mc_wrap_AxUrgent_Rd_r                       0x01D0
    #define     B16mc_wrap_AxUrgent_Rd_r                       0x01D0
    #define   LSb32mc_wrap_AxUrgent_Rd_r                          2
    #define   LSb16mc_wrap_AxUrgent_Rd_r                          2
    #define       bmc_wrap_AxUrgent_Rd_r                       2
    #define   MSK32mc_wrap_AxUrgent_Rd_r                          0x0000000C

    #define     BA_mc_wrap_AxUrgent_Wr                         0x01D0
    #define     B16mc_wrap_AxUrgent_Wr                         0x01D0
    #define   LSb32mc_wrap_AxUrgent_Wr                            4
    #define   LSb16mc_wrap_AxUrgent_Wr                            4
    #define       bmc_wrap_AxUrgent_Wr                         2
    #define   MSK32mc_wrap_AxUrgent_Wr                            0x00000030
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_PA_MASK                             0x01D4

    #define     BA_mc_wrap_PA_MASK_Rd                          0x01D4
    #define     B16mc_wrap_PA_MASK_Rd                          0x01D4
    #define   LSb32mc_wrap_PA_MASK_Rd                             0
    #define   LSb16mc_wrap_PA_MASK_Rd                             0
    #define       bmc_wrap_PA_MASK_Rd                          4
    #define   MSK32mc_wrap_PA_MASK_Rd                             0x0000000F

    #define     BA_mc_wrap_PA_MASK_Wr                          0x01D4
    #define     B16mc_wrap_PA_MASK_Wr                          0x01D4
    #define   LSb32mc_wrap_PA_MASK_Wr                             4
    #define   LSb16mc_wrap_PA_MASK_Wr                             4
    #define       bmc_wrap_PA_MASK_Wr                          2
    #define   MSK32mc_wrap_PA_MASK_Wr                             0x00000030
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_P0_AxQoS                            0x01D8

    #define     BA_mc_wrap_P0_AxQoS_UID2MATCH_1                0x01D8
    #define     B16mc_wrap_P0_AxQoS_UID2MATCH_1                0x01D8
    #define   LSb32mc_wrap_P0_AxQoS_UID2MATCH_1                   0
    #define   LSb16mc_wrap_P0_AxQoS_UID2MATCH_1                   0
    #define       bmc_wrap_P0_AxQoS_UID2MATCH_1                5
    #define   MSK32mc_wrap_P0_AxQoS_UID2MATCH_1                   0x0000001F

    #define     BA_mc_wrap_P0_AxQoS_UID2MATCH_2                0x01D8
    #define     B16mc_wrap_P0_AxQoS_UID2MATCH_2                0x01D8
    #define   LSb32mc_wrap_P0_AxQoS_UID2MATCH_2                   5
    #define   LSb16mc_wrap_P0_AxQoS_UID2MATCH_2                   5
    #define       bmc_wrap_P0_AxQoS_UID2MATCH_2                5
    #define   MSK32mc_wrap_P0_AxQoS_UID2MATCH_2                   0x000003E0

    #define     BA_mc_wrap_P0_AxQoS_UID2MATCH_3                0x01D9
    #define     B16mc_wrap_P0_AxQoS_UID2MATCH_3                0x01D8
    #define   LSb32mc_wrap_P0_AxQoS_UID2MATCH_3                   10
    #define   LSb16mc_wrap_P0_AxQoS_UID2MATCH_3                   10
    #define       bmc_wrap_P0_AxQoS_UID2MATCH_3                5
    #define   MSK32mc_wrap_P0_AxQoS_UID2MATCH_3                   0x00007C00

    #define     BA_mc_wrap_P0_AxQoS_UID2MATCH_4                0x01D9
    #define     B16mc_wrap_P0_AxQoS_UID2MATCH_4                0x01D8
    #define   LSb32mc_wrap_P0_AxQoS_UID2MATCH_4                   15
    #define   LSb16mc_wrap_P0_AxQoS_UID2MATCH_4                   15
    #define       bmc_wrap_P0_AxQoS_UID2MATCH_4                5
    #define   MSK32mc_wrap_P0_AxQoS_UID2MATCH_4                   0x000F8000

    #define     BA_mc_wrap_P0_AxQoS_UID2MATCH_5                0x01DA
    #define     B16mc_wrap_P0_AxQoS_UID2MATCH_5                0x01DA
    #define   LSb32mc_wrap_P0_AxQoS_UID2MATCH_5                   20
    #define   LSb16mc_wrap_P0_AxQoS_UID2MATCH_5                   4
    #define       bmc_wrap_P0_AxQoS_UID2MATCH_5                5
    #define   MSK32mc_wrap_P0_AxQoS_UID2MATCH_5                   0x01F00000

    #define     BA_mc_wrap_P0_AxQoS_Rd4ID_1                    0x01DB
    #define     B16mc_wrap_P0_AxQoS_Rd4ID_1                    0x01DA
    #define   LSb32mc_wrap_P0_AxQoS_Rd4ID_1                       25
    #define   LSb16mc_wrap_P0_AxQoS_Rd4ID_1                       9
    #define       bmc_wrap_P0_AxQoS_Rd4ID_1                    4
    #define   MSK32mc_wrap_P0_AxQoS_Rd4ID_1                       0x1E000000

    #define     RA_mc_wrap_P0_AxQoS1                           0x01DC

    #define     BA_mc_wrap_P0_AxQoS_Rd4ID_2                    0x01DC
    #define     B16mc_wrap_P0_AxQoS_Rd4ID_2                    0x01DC
    #define   LSb32mc_wrap_P0_AxQoS_Rd4ID_2                       0
    #define   LSb16mc_wrap_P0_AxQoS_Rd4ID_2                       0
    #define       bmc_wrap_P0_AxQoS_Rd4ID_2                    4
    #define   MSK32mc_wrap_P0_AxQoS_Rd4ID_2                       0x0000000F

    #define     BA_mc_wrap_P0_AxQoS_Rd4ID_3                    0x01DC
    #define     B16mc_wrap_P0_AxQoS_Rd4ID_3                    0x01DC
    #define   LSb32mc_wrap_P0_AxQoS_Rd4ID_3                       4
    #define   LSb16mc_wrap_P0_AxQoS_Rd4ID_3                       4
    #define       bmc_wrap_P0_AxQoS_Rd4ID_3                    4
    #define   MSK32mc_wrap_P0_AxQoS_Rd4ID_3                       0x000000F0

    #define     BA_mc_wrap_P0_AxQoS_Rd4ID_4                    0x01DD
    #define     B16mc_wrap_P0_AxQoS_Rd4ID_4                    0x01DC
    #define   LSb32mc_wrap_P0_AxQoS_Rd4ID_4                       8
    #define   LSb16mc_wrap_P0_AxQoS_Rd4ID_4                       8
    #define       bmc_wrap_P0_AxQoS_Rd4ID_4                    4
    #define   MSK32mc_wrap_P0_AxQoS_Rd4ID_4                       0x00000F00

    #define     BA_mc_wrap_P0_AxQoS_Rd4ID_5                    0x01DD
    #define     B16mc_wrap_P0_AxQoS_Rd4ID_5                    0x01DC
    #define   LSb32mc_wrap_P0_AxQoS_Rd4ID_5                       12
    #define   LSb16mc_wrap_P0_AxQoS_Rd4ID_5                       12
    #define       bmc_wrap_P0_AxQoS_Rd4ID_5                    4
    #define   MSK32mc_wrap_P0_AxQoS_Rd4ID_5                       0x0000F000

    #define     BA_mc_wrap_P0_AxQoS_Wr4ID_1                    0x01DE
    #define     B16mc_wrap_P0_AxQoS_Wr4ID_1                    0x01DE
    #define   LSb32mc_wrap_P0_AxQoS_Wr4ID_1                       16
    #define   LSb16mc_wrap_P0_AxQoS_Wr4ID_1                       0
    #define       bmc_wrap_P0_AxQoS_Wr4ID_1                    4
    #define   MSK32mc_wrap_P0_AxQoS_Wr4ID_1                       0x000F0000

    #define     BA_mc_wrap_P0_AxQoS_Wr4ID_2                    0x01DE
    #define     B16mc_wrap_P0_AxQoS_Wr4ID_2                    0x01DE
    #define   LSb32mc_wrap_P0_AxQoS_Wr4ID_2                       20
    #define   LSb16mc_wrap_P0_AxQoS_Wr4ID_2                       4
    #define       bmc_wrap_P0_AxQoS_Wr4ID_2                    4
    #define   MSK32mc_wrap_P0_AxQoS_Wr4ID_2                       0x00F00000

    #define     BA_mc_wrap_P0_AxQoS_Wr4ID_3                    0x01DF
    #define     B16mc_wrap_P0_AxQoS_Wr4ID_3                    0x01DE
    #define   LSb32mc_wrap_P0_AxQoS_Wr4ID_3                       24
    #define   LSb16mc_wrap_P0_AxQoS_Wr4ID_3                       8
    #define       bmc_wrap_P0_AxQoS_Wr4ID_3                    4
    #define   MSK32mc_wrap_P0_AxQoS_Wr4ID_3                       0x0F000000

    #define     BA_mc_wrap_P0_AxQoS_Wr4ID_4                    0x01DF
    #define     B16mc_wrap_P0_AxQoS_Wr4ID_4                    0x01DE
    #define   LSb32mc_wrap_P0_AxQoS_Wr4ID_4                       28
    #define   LSb16mc_wrap_P0_AxQoS_Wr4ID_4                       12
    #define       bmc_wrap_P0_AxQoS_Wr4ID_4                    4
    #define   MSK32mc_wrap_P0_AxQoS_Wr4ID_4                       0xF0000000

    #define     RA_mc_wrap_P0_AxQoS2                           0x01E0

    #define     BA_mc_wrap_P0_AxQoS_Wr4ID_5                    0x01E0
    #define     B16mc_wrap_P0_AxQoS_Wr4ID_5                    0x01E0
    #define   LSb32mc_wrap_P0_AxQoS_Wr4ID_5                       0
    #define   LSb16mc_wrap_P0_AxQoS_Wr4ID_5                       0
    #define       bmc_wrap_P0_AxQoS_Wr4ID_5                    4
    #define   MSK32mc_wrap_P0_AxQoS_Wr4ID_5                       0x0000000F
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_P1_AxQoS                            0x01E4

    #define     BA_mc_wrap_P1_AxQoS_UID2MATCH_1                0x01E4
    #define     B16mc_wrap_P1_AxQoS_UID2MATCH_1                0x01E4
    #define   LSb32mc_wrap_P1_AxQoS_UID2MATCH_1                   0
    #define   LSb16mc_wrap_P1_AxQoS_UID2MATCH_1                   0
    #define       bmc_wrap_P1_AxQoS_UID2MATCH_1                5
    #define   MSK32mc_wrap_P1_AxQoS_UID2MATCH_1                   0x0000001F

    #define     BA_mc_wrap_P1_AxQoS_Rd4ID_1                    0x01E4
    #define     B16mc_wrap_P1_AxQoS_Rd4ID_1                    0x01E4
    #define   LSb32mc_wrap_P1_AxQoS_Rd4ID_1                       5
    #define   LSb16mc_wrap_P1_AxQoS_Rd4ID_1                       5
    #define       bmc_wrap_P1_AxQoS_Rd4ID_1                    4
    #define   MSK32mc_wrap_P1_AxQoS_Rd4ID_1                       0x000001E0

    #define     BA_mc_wrap_P1_AxQoS_Wr4ID_1                    0x01E5
    #define     B16mc_wrap_P1_AxQoS_Wr4ID_1                    0x01E4
    #define   LSb32mc_wrap_P1_AxQoS_Wr4ID_1                       9
    #define   LSb16mc_wrap_P1_AxQoS_Wr4ID_1                       9
    #define       bmc_wrap_P1_AxQoS_Wr4ID_1                    4
    #define   MSK32mc_wrap_P1_AxQoS_Wr4ID_1                       0x00001E00
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_hif_mrr_data                        0x01E8

    #define     BA_mc_wrap_hif_mrr_data_lower_valid            0x01E8
    #define     B16mc_wrap_hif_mrr_data_lower_valid            0x01E8
    #define   LSb32mc_wrap_hif_mrr_data_lower_valid               0
    #define   LSb16mc_wrap_hif_mrr_data_lower_valid               0
    #define       bmc_wrap_hif_mrr_data_lower_valid            1
    #define   MSK32mc_wrap_hif_mrr_data_lower_valid               0x00000001

    #define     BA_mc_wrap_hif_mrr_data_lower_valid_clear      0x01E8
    #define     B16mc_wrap_hif_mrr_data_lower_valid_clear      0x01E8
    #define   LSb32mc_wrap_hif_mrr_data_lower_valid_clear         1
    #define   LSb16mc_wrap_hif_mrr_data_lower_valid_clear         1
    #define       bmc_wrap_hif_mrr_data_lower_valid_clear      1
    #define   MSK32mc_wrap_hif_mrr_data_lower_valid_clear         0x00000002

    #define     BA_mc_wrap_hif_mrr_data_upper_valid            0x01E8
    #define     B16mc_wrap_hif_mrr_data_upper_valid            0x01E8
    #define   LSb32mc_wrap_hif_mrr_data_upper_valid               2
    #define   LSb16mc_wrap_hif_mrr_data_upper_valid               2
    #define       bmc_wrap_hif_mrr_data_upper_valid            1
    #define   MSK32mc_wrap_hif_mrr_data_upper_valid               0x00000004

    #define     BA_mc_wrap_hif_mrr_data_upper_valid_clear      0x01E8
    #define     B16mc_wrap_hif_mrr_data_upper_valid_clear      0x01E8
    #define   LSb32mc_wrap_hif_mrr_data_upper_valid_clear         3
    #define   LSb16mc_wrap_hif_mrr_data_upper_valid_clear         3
    #define       bmc_wrap_hif_mrr_data_upper_valid_clear      1
    #define   MSK32mc_wrap_hif_mrr_data_upper_valid_clear         0x00000008
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_hif_mrr_ddr4_lower                  0x01EC

    #define     BA_mc_wrap_hif_mrr_ddr4_lower_data0            0x01EC
    #define     B16mc_wrap_hif_mrr_ddr4_lower_data0            0x01EC
    #define   LSb32mc_wrap_hif_mrr_ddr4_lower_data0               0
    #define   LSb16mc_wrap_hif_mrr_ddr4_lower_data0               0
    #define       bmc_wrap_hif_mrr_ddr4_lower_data0            32
    #define   MSK32mc_wrap_hif_mrr_ddr4_lower_data0               0xFFFFFFFF

    #define     RA_mc_wrap_hif_mrr_ddr4_lower1                 0x01F0

    #define     BA_mc_wrap_hif_mrr_ddr4_lower_data1            0x01F0
    #define     B16mc_wrap_hif_mrr_ddr4_lower_data1            0x01F0
    #define   LSb32mc_wrap_hif_mrr_ddr4_lower_data1               0
    #define   LSb16mc_wrap_hif_mrr_ddr4_lower_data1               0
    #define       bmc_wrap_hif_mrr_ddr4_lower_data1            32
    #define   MSK32mc_wrap_hif_mrr_ddr4_lower_data1               0xFFFFFFFF

    #define     RA_mc_wrap_hif_mrr_ddr4_lower2                 0x01F4

    #define     BA_mc_wrap_hif_mrr_ddr4_lower_data2            0x01F4
    #define     B16mc_wrap_hif_mrr_ddr4_lower_data2            0x01F4
    #define   LSb32mc_wrap_hif_mrr_ddr4_lower_data2               0
    #define   LSb16mc_wrap_hif_mrr_ddr4_lower_data2               0
    #define       bmc_wrap_hif_mrr_ddr4_lower_data2            32
    #define   MSK32mc_wrap_hif_mrr_ddr4_lower_data2               0xFFFFFFFF

    #define     RA_mc_wrap_hif_mrr_ddr4_lower3                 0x01F8

    #define     BA_mc_wrap_hif_mrr_ddr4_lower_data3            0x01F8
    #define     B16mc_wrap_hif_mrr_ddr4_lower_data3            0x01F8
    #define   LSb32mc_wrap_hif_mrr_ddr4_lower_data3               0
    #define   LSb16mc_wrap_hif_mrr_ddr4_lower_data3               0
    #define       bmc_wrap_hif_mrr_ddr4_lower_data3            32
    #define   MSK32mc_wrap_hif_mrr_ddr4_lower_data3               0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_hif_mrr_ddr4_upper                  0x01FC

    #define     BA_mc_wrap_hif_mrr_ddr4_upper_data0            0x01FC
    #define     B16mc_wrap_hif_mrr_ddr4_upper_data0            0x01FC
    #define   LSb32mc_wrap_hif_mrr_ddr4_upper_data0               0
    #define   LSb16mc_wrap_hif_mrr_ddr4_upper_data0               0
    #define       bmc_wrap_hif_mrr_ddr4_upper_data0            32
    #define   MSK32mc_wrap_hif_mrr_ddr4_upper_data0               0xFFFFFFFF

    #define     RA_mc_wrap_hif_mrr_ddr4_upper1                 0x0200

    #define     BA_mc_wrap_hif_mrr_ddr4_upper_data1            0x0200
    #define     B16mc_wrap_hif_mrr_ddr4_upper_data1            0x0200
    #define   LSb32mc_wrap_hif_mrr_ddr4_upper_data1               0
    #define   LSb16mc_wrap_hif_mrr_ddr4_upper_data1               0
    #define       bmc_wrap_hif_mrr_ddr4_upper_data1            32
    #define   MSK32mc_wrap_hif_mrr_ddr4_upper_data1               0xFFFFFFFF

    #define     RA_mc_wrap_hif_mrr_ddr4_upper2                 0x0204

    #define     BA_mc_wrap_hif_mrr_ddr4_upper_data2            0x0204
    #define     B16mc_wrap_hif_mrr_ddr4_upper_data2            0x0204
    #define   LSb32mc_wrap_hif_mrr_ddr4_upper_data2               0
    #define   LSb16mc_wrap_hif_mrr_ddr4_upper_data2               0
    #define       bmc_wrap_hif_mrr_ddr4_upper_data2            32
    #define   MSK32mc_wrap_hif_mrr_ddr4_upper_data2               0xFFFFFFFF

    #define     RA_mc_wrap_hif_mrr_ddr4_upper3                 0x0208

    #define     BA_mc_wrap_hif_mrr_ddr4_upper_data3            0x0208
    #define     B16mc_wrap_hif_mrr_ddr4_upper_data3            0x0208
    #define   LSb32mc_wrap_hif_mrr_ddr4_upper_data3               0
    #define   LSb16mc_wrap_hif_mrr_ddr4_upper_data3               0
    #define       bmc_wrap_hif_mrr_ddr4_upper_data3            32
    #define   MSK32mc_wrap_hif_mrr_ddr4_upper_data3               0xFFFFFFFF
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_Axi_Low_Pwr_Ifc                     0x020C

    #define     BA_mc_wrap_Axi_Low_Pwr_Ifc_lp_req              0x020C
    #define     B16mc_wrap_Axi_Low_Pwr_Ifc_lp_req              0x020C
    #define   LSb32mc_wrap_Axi_Low_Pwr_Ifc_lp_req                 0
    #define   LSb16mc_wrap_Axi_Low_Pwr_Ifc_lp_req                 0
    #define       bmc_wrap_Axi_Low_Pwr_Ifc_lp_req              2
    #define   MSK32mc_wrap_Axi_Low_Pwr_Ifc_lp_req                 0x00000003

    #define     BA_mc_wrap_Axi_Low_Pwr_Ifc_lp_ack              0x020C
    #define     B16mc_wrap_Axi_Low_Pwr_Ifc_lp_ack              0x020C
    #define   LSb32mc_wrap_Axi_Low_Pwr_Ifc_lp_ack                 2
    #define   LSb16mc_wrap_Axi_Low_Pwr_Ifc_lp_ack                 2
    #define       bmc_wrap_Axi_Low_Pwr_Ifc_lp_ack              2
    #define   MSK32mc_wrap_Axi_Low_Pwr_Ifc_lp_ack                 0x0000000C

    #define     BA_mc_wrap_Axi_Low_Pwr_Ifc_lp_active           0x020C
    #define     B16mc_wrap_Axi_Low_Pwr_Ifc_lp_active           0x020C
    #define   LSb32mc_wrap_Axi_Low_Pwr_Ifc_lp_active              4
    #define   LSb16mc_wrap_Axi_Low_Pwr_Ifc_lp_active              4
    #define       bmc_wrap_Axi_Low_Pwr_Ifc_lp_active           2
    #define   MSK32mc_wrap_Axi_Low_Pwr_Ifc_lp_active              0x00000030
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_ddrc_low_pwr_ifc_ch0                0x0210

    #define     BA_mc_wrap_ddrc_low_pwr_ifc_ch0_freq           0x0210
    #define     B16mc_wrap_ddrc_low_pwr_ifc_ch0_freq           0x0210
    #define   LSb32mc_wrap_ddrc_low_pwr_ifc_ch0_freq              0
    #define   LSb16mc_wrap_ddrc_low_pwr_ifc_ch0_freq              0
    #define       bmc_wrap_ddrc_low_pwr_ifc_ch0_freq           1
    #define   MSK32mc_wrap_ddrc_low_pwr_ifc_ch0_freq              0x00000001

    #define     BA_mc_wrap_ddrc_low_pwr_ifc_ch0_discamdrain    0x0210
    #define     B16mc_wrap_ddrc_low_pwr_ifc_ch0_discamdrain    0x0210
    #define   LSb32mc_wrap_ddrc_low_pwr_ifc_ch0_discamdrain       1
    #define   LSb16mc_wrap_ddrc_low_pwr_ifc_ch0_discamdrain       1
    #define       bmc_wrap_ddrc_low_pwr_ifc_ch0_discamdrain    1
    #define   MSK32mc_wrap_ddrc_low_pwr_ifc_ch0_discamdrain       0x00000002
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_DFC_PMU_CTRL                        0x0214

    #define     BA_mc_wrap_DFC_PMU_CTRL_dfc_pmu_en             0x0214
    #define     B16mc_wrap_DFC_PMU_CTRL_dfc_pmu_en             0x0214
    #define   LSb32mc_wrap_DFC_PMU_CTRL_dfc_pmu_en                0
    #define   LSb16mc_wrap_DFC_PMU_CTRL_dfc_pmu_en                0
    #define       bmc_wrap_DFC_PMU_CTRL_dfc_pmu_en             1
    #define   MSK32mc_wrap_DFC_PMU_CTRL_dfc_pmu_en                0x00000001

    #define     BA_mc_wrap_DFC_PMU_CTRL_dfc_pmu_en_ch          0x0214
    #define     B16mc_wrap_DFC_PMU_CTRL_dfc_pmu_en_ch          0x0214
    #define   LSb32mc_wrap_DFC_PMU_CTRL_dfc_pmu_en_ch             1
    #define   LSb16mc_wrap_DFC_PMU_CTRL_dfc_pmu_en_ch             1
    #define       bmc_wrap_DFC_PMU_CTRL_dfc_pmu_en_ch          2
    #define   MSK32mc_wrap_DFC_PMU_CTRL_dfc_pmu_en_ch             0x00000006

    #define     BA_mc_wrap_DFC_PMU_CTRL_dfc_pmu_int_clr        0x0214
    #define     B16mc_wrap_DFC_PMU_CTRL_dfc_pmu_int_clr        0x0214
    #define   LSb32mc_wrap_DFC_PMU_CTRL_dfc_pmu_int_clr           3
    #define   LSb16mc_wrap_DFC_PMU_CTRL_dfc_pmu_int_clr           3
    #define       bmc_wrap_DFC_PMU_CTRL_dfc_pmu_int_clr        1
    #define   MSK32mc_wrap_DFC_PMU_CTRL_dfc_pmu_int_clr           0x00000008

    #define     BA_mc_wrap_DFC_PMU_CTRL_bypen_to_rsten_time    0x0214
    #define     B16mc_wrap_DFC_PMU_CTRL_bypen_to_rsten_time    0x0214
    #define   LSb32mc_wrap_DFC_PMU_CTRL_bypen_to_rsten_time       4
    #define   LSb16mc_wrap_DFC_PMU_CTRL_bypen_to_rsten_time       4
    #define       bmc_wrap_DFC_PMU_CTRL_bypen_to_rsten_time    16
    #define   MSK32mc_wrap_DFC_PMU_CTRL_bypen_to_rsten_time       0x000FFFF0

    #define     RA_mc_wrap_DFC_PMU_CTRL1                       0x0218

    #define     BA_mc_wrap_DFC_PMU_CTRL_rsten_to_newset_time   0x0218
    #define     B16mc_wrap_DFC_PMU_CTRL_rsten_to_newset_time   0x0218
    #define   LSb32mc_wrap_DFC_PMU_CTRL_rsten_to_newset_time      0
    #define   LSb16mc_wrap_DFC_PMU_CTRL_rsten_to_newset_time      0
    #define       bmc_wrap_DFC_PMU_CTRL_rsten_to_newset_time   16
    #define   MSK32mc_wrap_DFC_PMU_CTRL_rsten_to_newset_time      0x0000FFFF

    #define     BA_mc_wrap_DFC_PMU_CTRL_newset_to_rstdis_time  0x021A
    #define     B16mc_wrap_DFC_PMU_CTRL_newset_to_rstdis_time  0x021A
    #define   LSb32mc_wrap_DFC_PMU_CTRL_newset_to_rstdis_time     16
    #define   LSb16mc_wrap_DFC_PMU_CTRL_newset_to_rstdis_time     0
    #define       bmc_wrap_DFC_PMU_CTRL_newset_to_rstdis_time  16
    #define   MSK32mc_wrap_DFC_PMU_CTRL_newset_to_rstdis_time     0xFFFF0000

    #define     RA_mc_wrap_DFC_PMU_CTRL2                       0x021C

    #define     BA_mc_wrap_DFC_PMU_CTRL_plllck_wait_time       0x021C
    #define     B16mc_wrap_DFC_PMU_CTRL_plllck_wait_time       0x021C
    #define   LSb32mc_wrap_DFC_PMU_CTRL_plllck_wait_time          0
    #define   LSb16mc_wrap_DFC_PMU_CTRL_plllck_wait_time          0
    #define       bmc_wrap_DFC_PMU_CTRL_plllck_wait_time       16
    #define   MSK32mc_wrap_DFC_PMU_CTRL_plllck_wait_time          0x0000FFFF

    #define     BA_mc_wrap_DFC_PMU_CTRL_plllck_to_bypdis_time  0x021E
    #define     B16mc_wrap_DFC_PMU_CTRL_plllck_to_bypdis_time  0x021E
    #define   LSb32mc_wrap_DFC_PMU_CTRL_plllck_to_bypdis_time     16
    #define   LSb16mc_wrap_DFC_PMU_CTRL_plllck_to_bypdis_time     0
    #define       bmc_wrap_DFC_PMU_CTRL_plllck_to_bypdis_time  16
    #define   MSK32mc_wrap_DFC_PMU_CTRL_plllck_to_bypdis_time     0xFFFF0000
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_stat_ddrc                           0x0220

    #define     BA_mc_wrap_stat_ddrc_selfref_type_ch0          0x0220
    #define     B16mc_wrap_stat_ddrc_selfref_type_ch0          0x0220
    #define   LSb32mc_wrap_stat_ddrc_selfref_type_ch0             0
    #define   LSb16mc_wrap_stat_ddrc_selfref_type_ch0             0
    #define       bmc_wrap_stat_ddrc_selfref_type_ch0          2
    #define   MSK32mc_wrap_stat_ddrc_selfref_type_ch0             0x00000003

    #define     BA_mc_wrap_stat_ddrc_selfref_type_ch1          0x0220
    #define     B16mc_wrap_stat_ddrc_selfref_type_ch1          0x0220
    #define   LSb32mc_wrap_stat_ddrc_selfref_type_ch1             2
    #define   LSb16mc_wrap_stat_ddrc_selfref_type_ch1             2
    #define       bmc_wrap_stat_ddrc_selfref_type_ch1          2
    #define   MSK32mc_wrap_stat_ddrc_selfref_type_ch1             0x0000000C
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_ddrphy_dto                          0x0224

    #define     BA_mc_wrap_ddrphy_dto_ch0                      0x0224
    #define     B16mc_wrap_ddrphy_dto_ch0                      0x0224
    #define   LSb32mc_wrap_ddrphy_dto_ch0                         0
    #define   LSb16mc_wrap_ddrphy_dto_ch0                         0
    #define       bmc_wrap_ddrphy_dto_ch0                      1
    #define   MSK32mc_wrap_ddrphy_dto_ch0                         0x00000001

    #define     BA_mc_wrap_ddrphy_dto_ch1                      0x0224
    #define     B16mc_wrap_ddrphy_dto_ch1                      0x0224
    #define   LSb32mc_wrap_ddrphy_dto_ch1                         1
    #define   LSb16mc_wrap_ddrphy_dto_ch1                         1
    #define       bmc_wrap_ddrphy_dto_ch1                      1
    #define   MSK32mc_wrap_ddrphy_dto_ch1                         0x00000002
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_PwrOkIn                             0x0228

    #define     BA_mc_wrap_PwrOkIn_TRUE                        0x0228
    #define     B16mc_wrap_PwrOkIn_TRUE                        0x0228
    #define   LSb32mc_wrap_PwrOkIn_TRUE                           0
    #define   LSb16mc_wrap_PwrOkIn_TRUE                           0
    #define       bmc_wrap_PwrOkIn_TRUE                        1
    #define   MSK32mc_wrap_PwrOkIn_TRUE                           0x00000001
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_bufferen_core                       0x022C

    #define     BA_mc_wrap_bufferen_core_TRUE                  0x022C
    #define     B16mc_wrap_bufferen_core_TRUE                  0x022C
    #define   LSb32mc_wrap_bufferen_core_TRUE                     0
    #define   LSb16mc_wrap_bufferen_core_TRUE                     0
    #define       bmc_wrap_bufferen_core_TRUE                  1
    #define   MSK32mc_wrap_bufferen_core_TRUE                     0x00000001
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_perf_log_cnt_ctrl                   0x0230

    #define     BA_mc_wrap_perf_log_cnt_ctrl_clear             0x0230
    #define     B16mc_wrap_perf_log_cnt_ctrl_clear             0x0230
    #define   LSb32mc_wrap_perf_log_cnt_ctrl_clear                0
    #define   LSb16mc_wrap_perf_log_cnt_ctrl_clear                0
    #define       bmc_wrap_perf_log_cnt_ctrl_clear             8
    #define   MSK32mc_wrap_perf_log_cnt_ctrl_clear                0x000000FF

    #define     BA_mc_wrap_perf_log_cnt_ctrl_enable            0x0231
    #define     B16mc_wrap_perf_log_cnt_ctrl_enable            0x0230
    #define   LSb32mc_wrap_perf_log_cnt_ctrl_enable               8
    #define   LSb16mc_wrap_perf_log_cnt_ctrl_enable               8
    #define       bmc_wrap_perf_log_cnt_ctrl_enable            8
    #define   MSK32mc_wrap_perf_log_cnt_ctrl_enable               0x0000FF00

    #define     BA_mc_wrap_perf_log_cnt_ctrl_latch             0x0232
    #define     B16mc_wrap_perf_log_cnt_ctrl_latch             0x0232
    #define   LSb32mc_wrap_perf_log_cnt_ctrl_latch                16
    #define   LSb16mc_wrap_perf_log_cnt_ctrl_latch                0
    #define       bmc_wrap_perf_log_cnt_ctrl_latch             8
    #define   MSK32mc_wrap_perf_log_cnt_ctrl_latch                0x00FF0000

    #define     BA_mc_wrap_perf_log_cnt_ctrl_clk_div           0x0233
    #define     B16mc_wrap_perf_log_cnt_ctrl_clk_div           0x0232
    #define   LSb32mc_wrap_perf_log_cnt_ctrl_clk_div              24
    #define   LSb16mc_wrap_perf_log_cnt_ctrl_clk_div              8
    #define       bmc_wrap_perf_log_cnt_ctrl_clk_div           3
    #define   MSK32mc_wrap_perf_log_cnt_ctrl_clk_div              0x07000000

    #define     RA_mc_wrap_perf_log_cnt_ctrl1                  0x0234

    #define     BA_mc_wrap_perf_log_cnt_ctrl_pc0_event_sel     0x0234
    #define     B16mc_wrap_perf_log_cnt_ctrl_pc0_event_sel     0x0234
    #define   LSb32mc_wrap_perf_log_cnt_ctrl_pc0_event_sel        0
    #define   LSb16mc_wrap_perf_log_cnt_ctrl_pc0_event_sel        0
    #define       bmc_wrap_perf_log_cnt_ctrl_pc0_event_sel     6
    #define   MSK32mc_wrap_perf_log_cnt_ctrl_pc0_event_sel        0x0000003F

    #define     BA_mc_wrap_perf_log_cnt_ctrl_pc1_event_sel     0x0234
    #define     B16mc_wrap_perf_log_cnt_ctrl_pc1_event_sel     0x0234
    #define   LSb32mc_wrap_perf_log_cnt_ctrl_pc1_event_sel        6
    #define   LSb16mc_wrap_perf_log_cnt_ctrl_pc1_event_sel        6
    #define       bmc_wrap_perf_log_cnt_ctrl_pc1_event_sel     6
    #define   MSK32mc_wrap_perf_log_cnt_ctrl_pc1_event_sel        0x00000FC0

    #define     BA_mc_wrap_perf_log_cnt_ctrl_pc2_event_sel     0x0235
    #define     B16mc_wrap_perf_log_cnt_ctrl_pc2_event_sel     0x0234
    #define   LSb32mc_wrap_perf_log_cnt_ctrl_pc2_event_sel        12
    #define   LSb16mc_wrap_perf_log_cnt_ctrl_pc2_event_sel        12
    #define       bmc_wrap_perf_log_cnt_ctrl_pc2_event_sel     6
    #define   MSK32mc_wrap_perf_log_cnt_ctrl_pc2_event_sel        0x0003F000

    #define     BA_mc_wrap_perf_log_cnt_ctrl_pc3_event_sel     0x0236
    #define     B16mc_wrap_perf_log_cnt_ctrl_pc3_event_sel     0x0236
    #define   LSb32mc_wrap_perf_log_cnt_ctrl_pc3_event_sel        18
    #define   LSb16mc_wrap_perf_log_cnt_ctrl_pc3_event_sel        2
    #define       bmc_wrap_perf_log_cnt_ctrl_pc3_event_sel     6
    #define   MSK32mc_wrap_perf_log_cnt_ctrl_pc3_event_sel        0x00FC0000

    #define     BA_mc_wrap_perf_log_cnt_ctrl_pc4_event_sel     0x0237
    #define     B16mc_wrap_perf_log_cnt_ctrl_pc4_event_sel     0x0236
    #define   LSb32mc_wrap_perf_log_cnt_ctrl_pc4_event_sel        24
    #define   LSb16mc_wrap_perf_log_cnt_ctrl_pc4_event_sel        8
    #define       bmc_wrap_perf_log_cnt_ctrl_pc4_event_sel     6
    #define   MSK32mc_wrap_perf_log_cnt_ctrl_pc4_event_sel        0x3F000000

    #define     RA_mc_wrap_perf_log_cnt_ctrl2                  0x0238

    #define     BA_mc_wrap_perf_log_cnt_ctrl_pc5_event_sel     0x0238
    #define     B16mc_wrap_perf_log_cnt_ctrl_pc5_event_sel     0x0238
    #define   LSb32mc_wrap_perf_log_cnt_ctrl_pc5_event_sel        0
    #define   LSb16mc_wrap_perf_log_cnt_ctrl_pc5_event_sel        0
    #define       bmc_wrap_perf_log_cnt_ctrl_pc5_event_sel     6
    #define   MSK32mc_wrap_perf_log_cnt_ctrl_pc5_event_sel        0x0000003F

    #define     BA_mc_wrap_perf_log_cnt_ctrl_pc6_event_sel     0x0238
    #define     B16mc_wrap_perf_log_cnt_ctrl_pc6_event_sel     0x0238
    #define   LSb32mc_wrap_perf_log_cnt_ctrl_pc6_event_sel        6
    #define   LSb16mc_wrap_perf_log_cnt_ctrl_pc6_event_sel        6
    #define       bmc_wrap_perf_log_cnt_ctrl_pc6_event_sel     6
    #define   MSK32mc_wrap_perf_log_cnt_ctrl_pc6_event_sel        0x00000FC0

    #define     BA_mc_wrap_perf_log_cnt_ctrl_pc7_event_sel     0x0239
    #define     B16mc_wrap_perf_log_cnt_ctrl_pc7_event_sel     0x0238
    #define   LSb32mc_wrap_perf_log_cnt_ctrl_pc7_event_sel        12
    #define   LSb16mc_wrap_perf_log_cnt_ctrl_pc7_event_sel        12
    #define       bmc_wrap_perf_log_cnt_ctrl_pc7_event_sel     6
    #define   MSK32mc_wrap_perf_log_cnt_ctrl_pc7_event_sel        0x0003F000
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_perf_log_cnt_ready                  0x023C

    #define     BA_mc_wrap_perf_log_cnt_ready_cnt              0x023C
    #define     B16mc_wrap_perf_log_cnt_ready_cnt              0x023C
    #define   LSb32mc_wrap_perf_log_cnt_ready_cnt                 0
    #define   LSb16mc_wrap_perf_log_cnt_ready_cnt                 0
    #define       bmc_wrap_perf_log_cnt_ready_cnt              8
    #define   MSK32mc_wrap_perf_log_cnt_ready_cnt                 0x000000FF
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_pc0                                 0x0240
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_pc1                                 0x0248
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_pc2                                 0x0250
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_pc3                                 0x0258
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_pc4                                 0x0260
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_pc5                                 0x0268
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_pc6                                 0x0270
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_pc7                                 0x0278
    ///////////////////////////////////////////////////////////
    #define     RA_mc_wrap_ddrphy_lpbk                         0x0280

    #define     BA_mc_wrap_ddrphy_lpbk_bist_mode               0x0280
    #define     B16mc_wrap_ddrphy_lpbk_bist_mode               0x0280
    #define   LSb32mc_wrap_ddrphy_lpbk_bist_mode                  0
    #define   LSb16mc_wrap_ddrphy_lpbk_bist_mode                  0
    #define       bmc_wrap_ddrphy_lpbk_bist_mode               1
    #define   MSK32mc_wrap_ddrphy_lpbk_bist_mode                  0x00000001

    #define     BA_mc_wrap_ddrphy_lpbk_bist_mux                0x0280
    #define     B16mc_wrap_ddrphy_lpbk_bist_mux                0x0280
    #define   LSb32mc_wrap_ddrphy_lpbk_bist_mux                   1
    #define   LSb16mc_wrap_ddrphy_lpbk_bist_mux                   1
    #define       bmc_wrap_ddrphy_lpbk_bist_mux                1
    #define   MSK32mc_wrap_ddrphy_lpbk_bist_mux                   0x00000002

    #define     BA_mc_wrap_ddrphy_lpbk_bist_start              0x0280
    #define     B16mc_wrap_ddrphy_lpbk_bist_start              0x0280
    #define   LSb32mc_wrap_ddrphy_lpbk_bist_start                 2
    #define   LSb16mc_wrap_ddrphy_lpbk_bist_start                 2
    #define       bmc_wrap_ddrphy_lpbk_bist_start              1
    #define   MSK32mc_wrap_ddrphy_lpbk_bist_start                 0x00000004

    #define     BA_mc_wrap_ddrphy_lpbk_bist_complete           0x0280
    #define     B16mc_wrap_ddrphy_lpbk_bist_complete           0x0280
    #define   LSb32mc_wrap_ddrphy_lpbk_bist_complete              3
    #define   LSb16mc_wrap_ddrphy_lpbk_bist_complete              3
    #define       bmc_wrap_ddrphy_lpbk_bist_complete           1
    #define   MSK32mc_wrap_ddrphy_lpbk_bist_complete              0x00000008

    #define     BA_mc_wrap_ddrphy_lpbk_bist_error              0x0280
    #define     B16mc_wrap_ddrphy_lpbk_bist_error              0x0280
    #define   LSb32mc_wrap_ddrphy_lpbk_bist_error                 4
    #define   LSb16mc_wrap_ddrphy_lpbk_bist_error                 4
    #define       bmc_wrap_ddrphy_lpbk_bist_error              1
    #define   MSK32mc_wrap_ddrphy_lpbk_bist_error                 0x00000010
    ///////////////////////////////////////////////////////////

    typedef struct SIE_mc_wrap {
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_MC_StickyRstn_core(r32)             _BFGET_(r32, 0, 0)
    #define   SET32mc_wrap_MC_StickyRstn_core(r32, v)           _BFSET_(r32, 0, 0, v)
    #define   GET16mc_wrap_MC_StickyRstn_core(r16)             _BFGET_(r16, 0, 0)
    #define   SET16mc_wrap_MC_StickyRstn_core(r16, v)           _BFSET_(r16, 0, 0, v)

    #define   GET32mc_wrap_MC_StickyRstn_szc(r32)              _BFGET_(r32, 1, 1)
    #define   SET32mc_wrap_MC_StickyRstn_szc(r32, v)            _BFSET_(r32, 1, 1, v)
    #define   GET16mc_wrap_MC_StickyRstn_szc(r16)              _BFGET_(r16, 1, 1)
    #define   SET16mc_wrap_MC_StickyRstn_szc(r16, v)            _BFSET_(r16, 1, 1, v)

    #define   GET32mc_wrap_MC_StickyRstn_phy(r32)              _BFGET_(r32, 2, 2)
    #define   SET32mc_wrap_MC_StickyRstn_phy(r32, v)            _BFSET_(r32, 2, 2, v)
    #define   GET16mc_wrap_MC_StickyRstn_phy(r16)              _BFGET_(r16, 2, 2)
    #define   SET16mc_wrap_MC_StickyRstn_phy(r16, v)            _BFSET_(r16, 2, 2, v)

    #define   GET32mc_wrap_MC_StickyRstn_phy_apb(r32)          _BFGET_(r32, 3, 3)
    #define   SET32mc_wrap_MC_StickyRstn_phy_apb(r32, v)        _BFSET_(r32, 3, 3, v)
    #define   GET16mc_wrap_MC_StickyRstn_phy_apb(r16)          _BFGET_(r16, 3, 3)
    #define   SET16mc_wrap_MC_StickyRstn_phy_apb(r16, v)        _BFSET_(r16, 3, 3, v)

    #define     w32mc_wrap_MC_StickyRstn                       {\
	    UNSG32 uMC_StickyRstn_core                         :  1;\
	    UNSG32 uMC_StickyRstn_szc                          :  1;\
	    UNSG32 uMC_StickyRstn_phy                          :  1;\
	    UNSG32 uMC_StickyRstn_phy_apb                      :  1;\
	    UNSG32 RSVDx0_b4                                   : 28;\
	}
    union { UNSG32 u32mc_wrap_MC_StickyRstn;
	    struct w32mc_wrap_MC_StickyRstn;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_DDRPHY_BypassPClk_En(r32)           _BFGET_(r32, 0, 0)
    #define   SET32mc_wrap_DDRPHY_BypassPClk_En(r32, v)         _BFSET_(r32, 0, 0, v)
    #define   GET16mc_wrap_DDRPHY_BypassPClk_En(r16)           _BFGET_(r16, 0, 0)
    #define   SET16mc_wrap_DDRPHY_BypassPClk_En(r16, v)         _BFSET_(r16, 0, 0, v)

    #define     w32mc_wrap_DDRPHY_BypassPClk                   {\
	    UNSG32 uDDRPHY_BypassPClk_En                       :  1;\
	    UNSG32 RSVDx4_b1                                   : 31;\
	}
    union { UNSG32 u32mc_wrap_DDRPHY_BypassPClk;
	    struct w32mc_wrap_DDRPHY_BypassPClk;
	  };
    ///////////////////////////////////////////////////////////
	SIE_abipll_rw                                    ie_memPll;
    ///////////////////////////////////////////////////////////
	SIE_abipll                                       ie_dfc_pmu_pll;
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_AxiPCntCTRL_clear(r32)              _BFGET_(r32, 5, 0)
    #define   SET32mc_wrap_AxiPCntCTRL_clear(r32, v)            _BFSET_(r32, 5, 0, v)
    #define   GET16mc_wrap_AxiPCntCTRL_clear(r16)              _BFGET_(r16, 5, 0)
    #define   SET16mc_wrap_AxiPCntCTRL_clear(r16, v)            _BFSET_(r16, 5, 0, v)

    #define   GET32mc_wrap_AxiPCntCTRL_enable(r32)             _BFGET_(r32, 11, 6)
    #define   SET32mc_wrap_AxiPCntCTRL_enable(r32, v)           _BFSET_(r32, 11, 6, v)
    #define   GET16mc_wrap_AxiPCntCTRL_enable(r16)             _BFGET_(r16, 11, 6)
    #define   SET16mc_wrap_AxiPCntCTRL_enable(r16, v)           _BFSET_(r16, 11, 6, v)

    #define   GET32mc_wrap_AxiPCntCTRL_latch(r32)              _BFGET_(r32, 17, 12)
    #define   SET32mc_wrap_AxiPCntCTRL_latch(r32, v)            _BFSET_(r32, 17, 12, v)

    #define     w32mc_wrap_AxiPCntCTRL                         {\
	    UNSG32 uAxiPCntCTRL_clear                          :  6;\
	    UNSG32 uAxiPCntCTRL_enable                         :  6;\
	    UNSG32 uAxiPCntCTRL_latch                          :  6;\
	    UNSG32 RSVDx48_b18                                 : 14;\
	}
    union { UNSG32 u32mc_wrap_AxiPCntCTRL;
	    struct w32mc_wrap_AxiPCntCTRL;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_AxiMst0_0_PID(r32)                  _BFGET_(r32, 15, 0)
    #define   SET32mc_wrap_AxiMst0_0_PID(r32, v)                _BFSET_(r32, 15, 0, v)
    #define   GET16mc_wrap_AxiMst0_0_PID(r16)                  _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_AxiMst0_0_PID(r16, v)                _BFSET_(r16, 15, 0, v)

    #define   GET32mc_wrap_AxiMst0_0_Mask(r32)                 _BFGET_(r32, 31, 16)
    #define   SET32mc_wrap_AxiMst0_0_Mask(r32, v)               _BFSET_(r32, 31, 16, v)
    #define   GET16mc_wrap_AxiMst0_0_Mask(r16)                 _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_AxiMst0_0_Mask(r16, v)               _BFSET_(r16, 15, 0, v)

    #define     w32mc_wrap_AxiMst0_0                           {\
	    UNSG32 uAxiMst0_0_PID                              : 16;\
	    UNSG32 uAxiMst0_0_Mask                             : 16;\
	}
    union { UNSG32 u32mc_wrap_AxiMst0_0;
	    struct w32mc_wrap_AxiMst0_0;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_AxiMst0_1_PID(r32)                  _BFGET_(r32, 15, 0)
    #define   SET32mc_wrap_AxiMst0_1_PID(r32, v)                _BFSET_(r32, 15, 0, v)
    #define   GET16mc_wrap_AxiMst0_1_PID(r16)                  _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_AxiMst0_1_PID(r16, v)                _BFSET_(r16, 15, 0, v)

    #define   GET32mc_wrap_AxiMst0_1_Mask(r32)                 _BFGET_(r32, 31, 16)
    #define   SET32mc_wrap_AxiMst0_1_Mask(r32, v)               _BFSET_(r32, 31, 16, v)
    #define   GET16mc_wrap_AxiMst0_1_Mask(r16)                 _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_AxiMst0_1_Mask(r16, v)               _BFSET_(r16, 15, 0, v)

    #define     w32mc_wrap_AxiMst0_1                           {\
	    UNSG32 uAxiMst0_1_PID                              : 16;\
	    UNSG32 uAxiMst0_1_Mask                             : 16;\
	}
    union { UNSG32 u32mc_wrap_AxiMst0_1;
	    struct w32mc_wrap_AxiMst0_1;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_AxiMst0_2_PID(r32)                  _BFGET_(r32, 15, 0)
    #define   SET32mc_wrap_AxiMst0_2_PID(r32, v)                _BFSET_(r32, 15, 0, v)
    #define   GET16mc_wrap_AxiMst0_2_PID(r16)                  _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_AxiMst0_2_PID(r16, v)                _BFSET_(r16, 15, 0, v)

    #define   GET32mc_wrap_AxiMst0_2_Mask(r32)                 _BFGET_(r32, 31, 16)
    #define   SET32mc_wrap_AxiMst0_2_Mask(r32, v)               _BFSET_(r32, 31, 16, v)
    #define   GET16mc_wrap_AxiMst0_2_Mask(r16)                 _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_AxiMst0_2_Mask(r16, v)               _BFSET_(r16, 15, 0, v)

    #define     w32mc_wrap_AxiMst0_2                           {\
	    UNSG32 uAxiMst0_2_PID                              : 16;\
	    UNSG32 uAxiMst0_2_Mask                             : 16;\
	}
    union { UNSG32 u32mc_wrap_AxiMst0_2;
	    struct w32mc_wrap_AxiMst0_2;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_AxiMst0_3_PID(r32)                  _BFGET_(r32, 15, 0)
    #define   SET32mc_wrap_AxiMst0_3_PID(r32, v)                _BFSET_(r32, 15, 0, v)
    #define   GET16mc_wrap_AxiMst0_3_PID(r16)                  _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_AxiMst0_3_PID(r16, v)                _BFSET_(r16, 15, 0, v)

    #define   GET32mc_wrap_AxiMst0_3_Mask(r32)                 _BFGET_(r32, 31, 16)
    #define   SET32mc_wrap_AxiMst0_3_Mask(r32, v)               _BFSET_(r32, 31, 16, v)
    #define   GET16mc_wrap_AxiMst0_3_Mask(r16)                 _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_AxiMst0_3_Mask(r16, v)               _BFSET_(r16, 15, 0, v)

    #define     w32mc_wrap_AxiMst0_3                           {\
	    UNSG32 uAxiMst0_3_PID                              : 16;\
	    UNSG32 uAxiMst0_3_Mask                             : 16;\
	}
    union { UNSG32 u32mc_wrap_AxiMst0_3;
	    struct w32mc_wrap_AxiMst0_3;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_AxiMst0_4_PID(r32)                  _BFGET_(r32, 15, 0)
    #define   SET32mc_wrap_AxiMst0_4_PID(r32, v)                _BFSET_(r32, 15, 0, v)
    #define   GET16mc_wrap_AxiMst0_4_PID(r16)                  _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_AxiMst0_4_PID(r16, v)                _BFSET_(r16, 15, 0, v)

    #define   GET32mc_wrap_AxiMst0_4_Mask(r32)                 _BFGET_(r32, 31, 16)
    #define   SET32mc_wrap_AxiMst0_4_Mask(r32, v)               _BFSET_(r32, 31, 16, v)
    #define   GET16mc_wrap_AxiMst0_4_Mask(r16)                 _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_AxiMst0_4_Mask(r16, v)               _BFSET_(r16, 15, 0, v)

    #define     w32mc_wrap_AxiMst0_4                           {\
	    UNSG32 uAxiMst0_4_PID                              : 16;\
	    UNSG32 uAxiMst0_4_Mask                             : 16;\
	}
    union { UNSG32 u32mc_wrap_AxiMst0_4;
	    struct w32mc_wrap_AxiMst0_4;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_AxiMst1_0_PID(r32)                  _BFGET_(r32, 15, 0)
    #define   SET32mc_wrap_AxiMst1_0_PID(r32, v)                _BFSET_(r32, 15, 0, v)
    #define   GET16mc_wrap_AxiMst1_0_PID(r16)                  _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_AxiMst1_0_PID(r16, v)                _BFSET_(r16, 15, 0, v)

    #define   GET32mc_wrap_AxiMst1_0_Mask(r32)                 _BFGET_(r32, 31, 16)
    #define   SET32mc_wrap_AxiMst1_0_Mask(r32, v)               _BFSET_(r32, 31, 16, v)
    #define   GET16mc_wrap_AxiMst1_0_Mask(r16)                 _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_AxiMst1_0_Mask(r16, v)               _BFSET_(r16, 15, 0, v)

    #define     w32mc_wrap_AxiMst1_0                           {\
	    UNSG32 uAxiMst1_0_PID                              : 16;\
	    UNSG32 uAxiMst1_0_Mask                             : 16;\
	}
    union { UNSG32 u32mc_wrap_AxiMst1_0;
	    struct w32mc_wrap_AxiMst1_0;
	  };
    ///////////////////////////////////////////////////////////
	SIE_AxiPCntStat                                  ie_Mstr0_0_PCnt;
    ///////////////////////////////////////////////////////////
	SIE_AxiPCntStat                                  ie_Mstr0_1_PCnt;
    ///////////////////////////////////////////////////////////
	SIE_AxiPCntStat                                  ie_Mstr0_2_PCnt;
    ///////////////////////////////////////////////////////////
	SIE_AxiPCntStat                                  ie_Mstr0_3_PCnt;
    ///////////////////////////////////////////////////////////
	SIE_AxiPCntStat                                  ie_Mstr0_4_PCnt;
    ///////////////////////////////////////////////////////////
	SIE_AxiPCntStat                                  ie_Mstr1_0_PCnt;
    ///////////////////////////////////////////////////////////
	SIE_AxiErrorMon                                  ie_AxiErrorMon_Mst0;
    ///////////////////////////////////////////////////////////
	SIE_AxiErrorMon                                  ie_AxiErrorMon_Mst1;
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_AlmSel_almSel(r32)                  _BFGET_(r32, 0, 0)
    #define   SET32mc_wrap_AlmSel_almSel(r32, v)                _BFSET_(r32, 0, 0, v)
    #define   GET16mc_wrap_AlmSel_almSel(r16)                  _BFGET_(r16, 0, 0)
    #define   SET16mc_wrap_AlmSel_almSel(r16, v)                _BFSET_(r16, 0, 0, v)

    #define     w32mc_wrap_AlmSel                              {\
	    UNSG32 uAlmSel_almSel                              :  1;\
	    UNSG32 RSVDx1CC_b1                                 : 31;\
	}
    union { UNSG32 u32mc_wrap_AlmSel;
	    struct w32mc_wrap_AlmSel;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_AxUrgent_Rd_b(r32)                  _BFGET_(r32, 1, 0)
    #define   SET32mc_wrap_AxUrgent_Rd_b(r32, v)                _BFSET_(r32, 1, 0, v)
    #define   GET16mc_wrap_AxUrgent_Rd_b(r16)                  _BFGET_(r16, 1, 0)
    #define   SET16mc_wrap_AxUrgent_Rd_b(r16, v)                _BFSET_(r16, 1, 0, v)

    #define   GET32mc_wrap_AxUrgent_Rd_r(r32)                  _BFGET_(r32, 3, 2)
    #define   SET32mc_wrap_AxUrgent_Rd_r(r32, v)                _BFSET_(r32, 3, 2, v)
    #define   GET16mc_wrap_AxUrgent_Rd_r(r16)                  _BFGET_(r16, 3, 2)
    #define   SET16mc_wrap_AxUrgent_Rd_r(r16, v)                _BFSET_(r16, 3, 2, v)

    #define   GET32mc_wrap_AxUrgent_Wr(r32)                    _BFGET_(r32, 5, 4)
    #define   SET32mc_wrap_AxUrgent_Wr(r32, v)                  _BFSET_(r32, 5, 4, v)
    #define   GET16mc_wrap_AxUrgent_Wr(r16)                    _BFGET_(r16, 5, 4)
    #define   SET16mc_wrap_AxUrgent_Wr(r16, v)                  _BFSET_(r16, 5, 4, v)

    #define     w32mc_wrap_AxUrgent                            {\
	    UNSG32 uAxUrgent_Rd_b                              :  2;\
	    UNSG32 uAxUrgent_Rd_r                              :  2;\
	    UNSG32 uAxUrgent_Wr                                :  2;\
	    UNSG32 RSVDx1D0_b6                                 : 26;\
	}
    union { UNSG32 u32mc_wrap_AxUrgent;
	    struct w32mc_wrap_AxUrgent;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_PA_MASK_Rd(r32)                     _BFGET_(r32, 3, 0)
    #define   SET32mc_wrap_PA_MASK_Rd(r32, v)                   _BFSET_(r32, 3, 0, v)
    #define   GET16mc_wrap_PA_MASK_Rd(r16)                     _BFGET_(r16, 3, 0)
    #define   SET16mc_wrap_PA_MASK_Rd(r16, v)                   _BFSET_(r16, 3, 0, v)

    #define   GET32mc_wrap_PA_MASK_Wr(r32)                     _BFGET_(r32, 5, 4)
    #define   SET32mc_wrap_PA_MASK_Wr(r32, v)                   _BFSET_(r32, 5, 4, v)
    #define   GET16mc_wrap_PA_MASK_Wr(r16)                     _BFGET_(r16, 5, 4)
    #define   SET16mc_wrap_PA_MASK_Wr(r16, v)                   _BFSET_(r16, 5, 4, v)

    #define     w32mc_wrap_PA_MASK                             {\
	    UNSG32 uPA_MASK_Rd                                 :  4;\
	    UNSG32 uPA_MASK_Wr                                 :  2;\
	    UNSG32 RSVDx1D4_b6                                 : 26;\
	}
    union { UNSG32 u32mc_wrap_PA_MASK;
	    struct w32mc_wrap_PA_MASK;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_P0_AxQoS_UID2MATCH_1(r32)           _BFGET_(r32, 4, 0)
    #define   SET32mc_wrap_P0_AxQoS_UID2MATCH_1(r32, v)         _BFSET_(r32, 4, 0, v)
    #define   GET16mc_wrap_P0_AxQoS_UID2MATCH_1(r16)           _BFGET_(r16, 4, 0)
    #define   SET16mc_wrap_P0_AxQoS_UID2MATCH_1(r16, v)         _BFSET_(r16, 4, 0, v)

    #define   GET32mc_wrap_P0_AxQoS_UID2MATCH_2(r32)           _BFGET_(r32, 9, 5)
    #define   SET32mc_wrap_P0_AxQoS_UID2MATCH_2(r32, v)         _BFSET_(r32, 9, 5, v)
    #define   GET16mc_wrap_P0_AxQoS_UID2MATCH_2(r16)           _BFGET_(r16, 9, 5)
    #define   SET16mc_wrap_P0_AxQoS_UID2MATCH_2(r16, v)         _BFSET_(r16, 9, 5, v)

    #define   GET32mc_wrap_P0_AxQoS_UID2MATCH_3(r32)           _BFGET_(r32, 14, 10)
    #define   SET32mc_wrap_P0_AxQoS_UID2MATCH_3(r32, v)         _BFSET_(r32, 14, 10, v)
    #define   GET16mc_wrap_P0_AxQoS_UID2MATCH_3(r16)           _BFGET_(r16, 14, 10)
    #define   SET16mc_wrap_P0_AxQoS_UID2MATCH_3(r16, v)         _BFSET_(r16, 14, 10, v)

    #define   GET32mc_wrap_P0_AxQoS_UID2MATCH_4(r32)           _BFGET_(r32, 19, 15)
    #define   SET32mc_wrap_P0_AxQoS_UID2MATCH_4(r32, v)         _BFSET_(r32, 19, 15, v)

    #define   GET32mc_wrap_P0_AxQoS_UID2MATCH_5(r32)           _BFGET_(r32, 24, 20)
    #define   SET32mc_wrap_P0_AxQoS_UID2MATCH_5(r32, v)         _BFSET_(r32, 24, 20, v)
    #define   GET16mc_wrap_P0_AxQoS_UID2MATCH_5(r16)           _BFGET_(r16, 8, 4)
    #define   SET16mc_wrap_P0_AxQoS_UID2MATCH_5(r16, v)         _BFSET_(r16, 8, 4, v)

    #define   GET32mc_wrap_P0_AxQoS_Rd4ID_1(r32)               _BFGET_(r32, 28, 25)
    #define   SET32mc_wrap_P0_AxQoS_Rd4ID_1(r32, v)             _BFSET_(r32, 28, 25, v)
    #define   GET16mc_wrap_P0_AxQoS_Rd4ID_1(r16)               _BFGET_(r16, 12, 9)
    #define   SET16mc_wrap_P0_AxQoS_Rd4ID_1(r16, v)             _BFSET_(r16, 12, 9, v)

    #define     w32mc_wrap_P0_AxQoS                            {\
	    UNSG32 uP0_AxQoS_UID2MATCH_1                       :  5;\
	    UNSG32 uP0_AxQoS_UID2MATCH_2                       :  5;\
	    UNSG32 uP0_AxQoS_UID2MATCH_3                       :  5;\
	    UNSG32 uP0_AxQoS_UID2MATCH_4                       :  5;\
	    UNSG32 uP0_AxQoS_UID2MATCH_5                       :  5;\
	    UNSG32 uP0_AxQoS_Rd4ID_1                           :  4;\
	    UNSG32 RSVDx1D8_b29                                :  3;\
	}
    union { UNSG32 u32mc_wrap_P0_AxQoS;
	    struct w32mc_wrap_P0_AxQoS;
	  };
    #define   GET32mc_wrap_P0_AxQoS_Rd4ID_2(r32)               _BFGET_(r32, 3, 0)
    #define   SET32mc_wrap_P0_AxQoS_Rd4ID_2(r32, v)             _BFSET_(r32, 3, 0, v)
    #define   GET16mc_wrap_P0_AxQoS_Rd4ID_2(r16)               _BFGET_(r16, 3, 0)
    #define   SET16mc_wrap_P0_AxQoS_Rd4ID_2(r16, v)             _BFSET_(r16, 3, 0, v)

    #define   GET32mc_wrap_P0_AxQoS_Rd4ID_3(r32)               _BFGET_(r32, 7, 4)
    #define   SET32mc_wrap_P0_AxQoS_Rd4ID_3(r32, v)             _BFSET_(r32, 7, 4, v)
    #define   GET16mc_wrap_P0_AxQoS_Rd4ID_3(r16)               _BFGET_(r16, 7, 4)
    #define   SET16mc_wrap_P0_AxQoS_Rd4ID_3(r16, v)             _BFSET_(r16, 7, 4, v)

    #define   GET32mc_wrap_P0_AxQoS_Rd4ID_4(r32)               _BFGET_(r32, 11, 8)
    #define   SET32mc_wrap_P0_AxQoS_Rd4ID_4(r32, v)             _BFSET_(r32, 11, 8, v)
    #define   GET16mc_wrap_P0_AxQoS_Rd4ID_4(r16)               _BFGET_(r16, 11, 8)
    #define   SET16mc_wrap_P0_AxQoS_Rd4ID_4(r16, v)             _BFSET_(r16, 11, 8, v)

    #define   GET32mc_wrap_P0_AxQoS_Rd4ID_5(r32)               _BFGET_(r32, 15, 12)
    #define   SET32mc_wrap_P0_AxQoS_Rd4ID_5(r32, v)             _BFSET_(r32, 15, 12, v)
    #define   GET16mc_wrap_P0_AxQoS_Rd4ID_5(r16)               _BFGET_(r16, 15, 12)
    #define   SET16mc_wrap_P0_AxQoS_Rd4ID_5(r16, v)             _BFSET_(r16, 15, 12, v)

    #define   GET32mc_wrap_P0_AxQoS_Wr4ID_1(r32)               _BFGET_(r32, 19, 16)
    #define   SET32mc_wrap_P0_AxQoS_Wr4ID_1(r32, v)             _BFSET_(r32, 19, 16, v)
    #define   GET16mc_wrap_P0_AxQoS_Wr4ID_1(r16)               _BFGET_(r16, 3, 0)
    #define   SET16mc_wrap_P0_AxQoS_Wr4ID_1(r16, v)             _BFSET_(r16, 3, 0, v)

    #define   GET32mc_wrap_P0_AxQoS_Wr4ID_2(r32)               _BFGET_(r32, 23, 20)
    #define   SET32mc_wrap_P0_AxQoS_Wr4ID_2(r32, v)             _BFSET_(r32, 23, 20, v)
    #define   GET16mc_wrap_P0_AxQoS_Wr4ID_2(r16)               _BFGET_(r16, 7, 4)
    #define   SET16mc_wrap_P0_AxQoS_Wr4ID_2(r16, v)             _BFSET_(r16, 7, 4, v)

    #define   GET32mc_wrap_P0_AxQoS_Wr4ID_3(r32)               _BFGET_(r32, 27, 24)
    #define   SET32mc_wrap_P0_AxQoS_Wr4ID_3(r32, v)             _BFSET_(r32, 27, 24, v)
    #define   GET16mc_wrap_P0_AxQoS_Wr4ID_3(r16)               _BFGET_(r16, 11, 8)
    #define   SET16mc_wrap_P0_AxQoS_Wr4ID_3(r16, v)             _BFSET_(r16, 11, 8, v)

    #define   GET32mc_wrap_P0_AxQoS_Wr4ID_4(r32)               _BFGET_(r32, 31, 28)
    #define   SET32mc_wrap_P0_AxQoS_Wr4ID_4(r32, v)             _BFSET_(r32, 31, 28, v)
    #define   GET16mc_wrap_P0_AxQoS_Wr4ID_4(r16)               _BFGET_(r16, 15, 12)
    #define   SET16mc_wrap_P0_AxQoS_Wr4ID_4(r16, v)             _BFSET_(r16, 15, 12, v)

    #define     w32mc_wrap_P0_AxQoS1                           {\
	    UNSG32 uP0_AxQoS_Rd4ID_2                           :  4;\
	    UNSG32 uP0_AxQoS_Rd4ID_3                           :  4;\
	    UNSG32 uP0_AxQoS_Rd4ID_4                           :  4;\
	    UNSG32 uP0_AxQoS_Rd4ID_5                           :  4;\
	    UNSG32 uP0_AxQoS_Wr4ID_1                           :  4;\
	    UNSG32 uP0_AxQoS_Wr4ID_2                           :  4;\
	    UNSG32 uP0_AxQoS_Wr4ID_3                           :  4;\
	    UNSG32 uP0_AxQoS_Wr4ID_4                           :  4;\
	}
    union { UNSG32 u32mc_wrap_P0_AxQoS1;
	    struct w32mc_wrap_P0_AxQoS1;
	  };
    #define   GET32mc_wrap_P0_AxQoS_Wr4ID_5(r32)               _BFGET_(r32, 3, 0)
    #define   SET32mc_wrap_P0_AxQoS_Wr4ID_5(r32, v)             _BFSET_(r32, 3, 0, v)
    #define   GET16mc_wrap_P0_AxQoS_Wr4ID_5(r16)               _BFGET_(r16, 3, 0)
    #define   SET16mc_wrap_P0_AxQoS_Wr4ID_5(r16, v)             _BFSET_(r16, 3, 0, v)

    #define     w32mc_wrap_P0_AxQoS2                           {\
	    UNSG32 uP0_AxQoS_Wr4ID_5                           :  4;\
	    UNSG32 RSVDx1E0_b4                                 : 28;\
	}
    union { UNSG32 u32mc_wrap_P0_AxQoS2;
	    struct w32mc_wrap_P0_AxQoS2;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_P1_AxQoS_UID2MATCH_1(r32)           _BFGET_(r32, 4, 0)
    #define   SET32mc_wrap_P1_AxQoS_UID2MATCH_1(r32, v)         _BFSET_(r32, 4, 0, v)
    #define   GET16mc_wrap_P1_AxQoS_UID2MATCH_1(r16)           _BFGET_(r16, 4, 0)
    #define   SET16mc_wrap_P1_AxQoS_UID2MATCH_1(r16, v)         _BFSET_(r16, 4, 0, v)

    #define   GET32mc_wrap_P1_AxQoS_Rd4ID_1(r32)               _BFGET_(r32, 8, 5)
    #define   SET32mc_wrap_P1_AxQoS_Rd4ID_1(r32, v)             _BFSET_(r32, 8, 5, v)
    #define   GET16mc_wrap_P1_AxQoS_Rd4ID_1(r16)               _BFGET_(r16, 8, 5)
    #define   SET16mc_wrap_P1_AxQoS_Rd4ID_1(r16, v)             _BFSET_(r16, 8, 5, v)

    #define   GET32mc_wrap_P1_AxQoS_Wr4ID_1(r32)               _BFGET_(r32, 12, 9)
    #define   SET32mc_wrap_P1_AxQoS_Wr4ID_1(r32, v)             _BFSET_(r32, 12, 9, v)
    #define   GET16mc_wrap_P1_AxQoS_Wr4ID_1(r16)               _BFGET_(r16, 12, 9)
    #define   SET16mc_wrap_P1_AxQoS_Wr4ID_1(r16, v)             _BFSET_(r16, 12, 9, v)

    #define     w32mc_wrap_P1_AxQoS                            {\
	    UNSG32 uP1_AxQoS_UID2MATCH_1                       :  5;\
	    UNSG32 uP1_AxQoS_Rd4ID_1                           :  4;\
	    UNSG32 uP1_AxQoS_Wr4ID_1                           :  4;\
	    UNSG32 RSVDx1E4_b13                                : 19;\
	}
    union { UNSG32 u32mc_wrap_P1_AxQoS;
	    struct w32mc_wrap_P1_AxQoS;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_hif_mrr_data_lower_valid(r32)       _BFGET_(r32, 0, 0)
    #define   SET32mc_wrap_hif_mrr_data_lower_valid(r32, v)     _BFSET_(r32, 0, 0, v)
    #define   GET16mc_wrap_hif_mrr_data_lower_valid(r16)       _BFGET_(r16, 0, 0)
    #define   SET16mc_wrap_hif_mrr_data_lower_valid(r16, v)     _BFSET_(r16, 0, 0, v)

    #define   GET32mc_wrap_hif_mrr_data_lower_valid_clear(r32) _BFGET_(r32, 1, 1)
    #define   SET32mc_wrap_hif_mrr_data_lower_valid_clear(r32, v) _BFSET_(r32, 1, 1, v)
    #define   GET16mc_wrap_hif_mrr_data_lower_valid_clear(r16) _BFGET_(r16, 1, 1)
    #define   SET16mc_wrap_hif_mrr_data_lower_valid_clear(r16, v) _BFSET_(r16, 1, 1, v)

    #define   GET32mc_wrap_hif_mrr_data_upper_valid(r32)       _BFGET_(r32, 2, 2)
    #define   SET32mc_wrap_hif_mrr_data_upper_valid(r32, v)     _BFSET_(r32, 2, 2, v)
    #define   GET16mc_wrap_hif_mrr_data_upper_valid(r16)       _BFGET_(r16, 2, 2)
    #define   SET16mc_wrap_hif_mrr_data_upper_valid(r16, v)     _BFSET_(r16, 2, 2, v)

    #define   GET32mc_wrap_hif_mrr_data_upper_valid_clear(r32) _BFGET_(r32, 3, 3)
    #define   SET32mc_wrap_hif_mrr_data_upper_valid_clear(r32, v) _BFSET_(r32, 3, 3, v)
    #define   GET16mc_wrap_hif_mrr_data_upper_valid_clear(r16) _BFGET_(r16, 3, 3)
    #define   SET16mc_wrap_hif_mrr_data_upper_valid_clear(r16, v) _BFSET_(r16, 3, 3, v)

    #define     w32mc_wrap_hif_mrr_data                        {\
	    UNSG32 uhif_mrr_data_lower_valid                   :  1;\
	    UNSG32 uhif_mrr_data_lower_valid_clear             :  1;\
	    UNSG32 uhif_mrr_data_upper_valid                   :  1;\
	    UNSG32 uhif_mrr_data_upper_valid_clear             :  1;\
	    UNSG32 RSVDx1E8_b4                                 : 28;\
	}
    union { UNSG32 u32mc_wrap_hif_mrr_data;
	    struct w32mc_wrap_hif_mrr_data;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_hif_mrr_ddr4_lower_data0(r32)       _BFGET_(r32, 31, 0)
    #define   SET32mc_wrap_hif_mrr_ddr4_lower_data0(r32, v)     _BFSET_(r32, 31, 0, v)

    #define     w32mc_wrap_hif_mrr_ddr4_lower                  {\
	    UNSG32 uhif_mrr_ddr4_lower_data0                   : 32;\
	}
    union { UNSG32 u32mc_wrap_hif_mrr_ddr4_lower;
	    struct w32mc_wrap_hif_mrr_ddr4_lower;
	  };
    #define   GET32mc_wrap_hif_mrr_ddr4_lower_data1(r32)       _BFGET_(r32, 31, 0)
    #define   SET32mc_wrap_hif_mrr_ddr4_lower_data1(r32, v)     _BFSET_(r32, 31, 0, v)

    #define     w32mc_wrap_hif_mrr_ddr4_lower1                 {\
	    UNSG32 uhif_mrr_ddr4_lower_data1                   : 32;\
	}
    union { UNSG32 u32mc_wrap_hif_mrr_ddr4_lower1;
	    struct w32mc_wrap_hif_mrr_ddr4_lower1;
	  };
    #define   GET32mc_wrap_hif_mrr_ddr4_lower_data2(r32)       _BFGET_(r32, 31, 0)
    #define   SET32mc_wrap_hif_mrr_ddr4_lower_data2(r32, v)     _BFSET_(r32, 31, 0, v)

    #define     w32mc_wrap_hif_mrr_ddr4_lower2                 {\
	    UNSG32 uhif_mrr_ddr4_lower_data2                   : 32;\
	}
    union { UNSG32 u32mc_wrap_hif_mrr_ddr4_lower2;
	    struct w32mc_wrap_hif_mrr_ddr4_lower2;
	  };
    #define   GET32mc_wrap_hif_mrr_ddr4_lower_data3(r32)       _BFGET_(r32, 31, 0)
    #define   SET32mc_wrap_hif_mrr_ddr4_lower_data3(r32, v)     _BFSET_(r32, 31, 0, v)

    #define     w32mc_wrap_hif_mrr_ddr4_lower3                 {\
	    UNSG32 uhif_mrr_ddr4_lower_data3                   : 32;\
	}
    union { UNSG32 u32mc_wrap_hif_mrr_ddr4_lower3;
	    struct w32mc_wrap_hif_mrr_ddr4_lower3;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_hif_mrr_ddr4_upper_data0(r32)       _BFGET_(r32, 31, 0)
    #define   SET32mc_wrap_hif_mrr_ddr4_upper_data0(r32, v)     _BFSET_(r32, 31, 0, v)

    #define     w32mc_wrap_hif_mrr_ddr4_upper                  {\
	    UNSG32 uhif_mrr_ddr4_upper_data0                   : 32;\
	}
    union { UNSG32 u32mc_wrap_hif_mrr_ddr4_upper;
	    struct w32mc_wrap_hif_mrr_ddr4_upper;
	  };
    #define   GET32mc_wrap_hif_mrr_ddr4_upper_data1(r32)       _BFGET_(r32, 31, 0)
    #define   SET32mc_wrap_hif_mrr_ddr4_upper_data1(r32, v)     _BFSET_(r32, 31, 0, v)

    #define     w32mc_wrap_hif_mrr_ddr4_upper1                 {\
	    UNSG32 uhif_mrr_ddr4_upper_data1                   : 32;\
	}
    union { UNSG32 u32mc_wrap_hif_mrr_ddr4_upper1;
	    struct w32mc_wrap_hif_mrr_ddr4_upper1;
	  };
    #define   GET32mc_wrap_hif_mrr_ddr4_upper_data2(r32)       _BFGET_(r32, 31, 0)
    #define   SET32mc_wrap_hif_mrr_ddr4_upper_data2(r32, v)     _BFSET_(r32, 31, 0, v)

    #define     w32mc_wrap_hif_mrr_ddr4_upper2                 {\
	    UNSG32 uhif_mrr_ddr4_upper_data2                   : 32;\
	}
    union { UNSG32 u32mc_wrap_hif_mrr_ddr4_upper2;
	    struct w32mc_wrap_hif_mrr_ddr4_upper2;
	  };
    #define   GET32mc_wrap_hif_mrr_ddr4_upper_data3(r32)       _BFGET_(r32, 31, 0)
    #define   SET32mc_wrap_hif_mrr_ddr4_upper_data3(r32, v)     _BFSET_(r32, 31, 0, v)

    #define     w32mc_wrap_hif_mrr_ddr4_upper3                 {\
	    UNSG32 uhif_mrr_ddr4_upper_data3                   : 32;\
	}
    union { UNSG32 u32mc_wrap_hif_mrr_ddr4_upper3;
	    struct w32mc_wrap_hif_mrr_ddr4_upper3;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_Axi_Low_Pwr_Ifc_lp_req(r32)         _BFGET_(r32, 1, 0)
    #define   SET32mc_wrap_Axi_Low_Pwr_Ifc_lp_req(r32, v)       _BFSET_(r32, 1, 0, v)
    #define   GET16mc_wrap_Axi_Low_Pwr_Ifc_lp_req(r16)         _BFGET_(r16, 1, 0)
    #define   SET16mc_wrap_Axi_Low_Pwr_Ifc_lp_req(r16, v)       _BFSET_(r16, 1, 0, v)

    #define   GET32mc_wrap_Axi_Low_Pwr_Ifc_lp_ack(r32)         _BFGET_(r32, 3, 2)
    #define   SET32mc_wrap_Axi_Low_Pwr_Ifc_lp_ack(r32, v)       _BFSET_(r32, 3, 2, v)
    #define   GET16mc_wrap_Axi_Low_Pwr_Ifc_lp_ack(r16)         _BFGET_(r16, 3, 2)
    #define   SET16mc_wrap_Axi_Low_Pwr_Ifc_lp_ack(r16, v)       _BFSET_(r16, 3, 2, v)

    #define   GET32mc_wrap_Axi_Low_Pwr_Ifc_lp_active(r32)      _BFGET_(r32, 5, 4)
    #define   SET32mc_wrap_Axi_Low_Pwr_Ifc_lp_active(r32, v)    _BFSET_(r32, 5, 4, v)
    #define   GET16mc_wrap_Axi_Low_Pwr_Ifc_lp_active(r16)      _BFGET_(r16, 5, 4)
    #define   SET16mc_wrap_Axi_Low_Pwr_Ifc_lp_active(r16, v)    _BFSET_(r16, 5, 4, v)

    #define     w32mc_wrap_Axi_Low_Pwr_Ifc                     {\
	    UNSG32 uAxi_Low_Pwr_Ifc_lp_req                     :  2;\
	    UNSG32 uAxi_Low_Pwr_Ifc_lp_ack                     :  2;\
	    UNSG32 uAxi_Low_Pwr_Ifc_lp_active                  :  2;\
	    UNSG32 RSVDx20C_b6                                 : 26;\
	}
    union { UNSG32 u32mc_wrap_Axi_Low_Pwr_Ifc;
	    struct w32mc_wrap_Axi_Low_Pwr_Ifc;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_ddrc_low_pwr_ifc_ch0_freq(r32)      _BFGET_(r32, 0, 0)
    #define   SET32mc_wrap_ddrc_low_pwr_ifc_ch0_freq(r32, v)    _BFSET_(r32, 0, 0, v)
    #define   GET16mc_wrap_ddrc_low_pwr_ifc_ch0_freq(r16)      _BFGET_(r16, 0, 0)
    #define   SET16mc_wrap_ddrc_low_pwr_ifc_ch0_freq(r16, v)    _BFSET_(r16, 0, 0, v)

    #define   GET32mc_wrap_ddrc_low_pwr_ifc_ch0_discamdrain(r32) _BFGET_(r32, 1, 1)
    #define   SET32mc_wrap_ddrc_low_pwr_ifc_ch0_discamdrain(r32, v) _BFSET_(r32, 1, 1, v)
    #define   GET16mc_wrap_ddrc_low_pwr_ifc_ch0_discamdrain(r16) _BFGET_(r16, 1, 1)
    #define   SET16mc_wrap_ddrc_low_pwr_ifc_ch0_discamdrain(r16, v) _BFSET_(r16, 1, 1, v)

    #define     w32mc_wrap_ddrc_low_pwr_ifc_ch0                {\
	    UNSG32 uddrc_low_pwr_ifc_ch0_freq                  :  1;\
	    UNSG32 uddrc_low_pwr_ifc_ch0_discamdrain           :  1;\
	    UNSG32 RSVDx210_b2                                 : 30;\
	}
    union { UNSG32 u32mc_wrap_ddrc_low_pwr_ifc_ch0;
	    struct w32mc_wrap_ddrc_low_pwr_ifc_ch0;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_DFC_PMU_CTRL_dfc_pmu_en(r32)        _BFGET_(r32, 0, 0)
    #define   SET32mc_wrap_DFC_PMU_CTRL_dfc_pmu_en(r32, v)      _BFSET_(r32, 0, 0, v)
    #define   GET16mc_wrap_DFC_PMU_CTRL_dfc_pmu_en(r16)        _BFGET_(r16, 0, 0)
    #define   SET16mc_wrap_DFC_PMU_CTRL_dfc_pmu_en(r16, v)      _BFSET_(r16, 0, 0, v)

    #define   GET32mc_wrap_DFC_PMU_CTRL_dfc_pmu_en_ch(r32)     _BFGET_(r32, 2, 1)
    #define   SET32mc_wrap_DFC_PMU_CTRL_dfc_pmu_en_ch(r32, v)   _BFSET_(r32, 2, 1, v)
    #define   GET16mc_wrap_DFC_PMU_CTRL_dfc_pmu_en_ch(r16)     _BFGET_(r16, 2, 1)
    #define   SET16mc_wrap_DFC_PMU_CTRL_dfc_pmu_en_ch(r16, v)   _BFSET_(r16, 2, 1, v)

    #define   GET32mc_wrap_DFC_PMU_CTRL_dfc_pmu_int_clr(r32)   _BFGET_(r32, 3, 3)
    #define   SET32mc_wrap_DFC_PMU_CTRL_dfc_pmu_int_clr(r32, v) _BFSET_(r32, 3, 3, v)
    #define   GET16mc_wrap_DFC_PMU_CTRL_dfc_pmu_int_clr(r16)   _BFGET_(r16, 3, 3)
    #define   SET16mc_wrap_DFC_PMU_CTRL_dfc_pmu_int_clr(r16, v) _BFSET_(r16, 3, 3, v)

    #define   GET32mc_wrap_DFC_PMU_CTRL_bypen_to_rsten_time(r32) _BFGET_(r32, 19, 4)
    #define   SET32mc_wrap_DFC_PMU_CTRL_bypen_to_rsten_time(r32, v) _BFSET_(r32, 19, 4, v)

    #define     w32mc_wrap_DFC_PMU_CTRL                        {\
	    UNSG32 uDFC_PMU_CTRL_dfc_pmu_en                    :  1;\
	    UNSG32 uDFC_PMU_CTRL_dfc_pmu_en_ch                 :  2;\
	    UNSG32 uDFC_PMU_CTRL_dfc_pmu_int_clr               :  1;\
	    UNSG32 uDFC_PMU_CTRL_bypen_to_rsten_time           : 16;\
	    UNSG32 RSVDx214_b20                                : 12;\
	}
    union { UNSG32 u32mc_wrap_DFC_PMU_CTRL;
	    struct w32mc_wrap_DFC_PMU_CTRL;
	  };
    #define   GET32mc_wrap_DFC_PMU_CTRL_rsten_to_newset_time(r32) _BFGET_(r32, 15, 0)
    #define   SET32mc_wrap_DFC_PMU_CTRL_rsten_to_newset_time(r32, v) _BFSET_(r32, 15, 0, v)
    #define   GET16mc_wrap_DFC_PMU_CTRL_rsten_to_newset_time(r16) _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_DFC_PMU_CTRL_rsten_to_newset_time(r16, v) _BFSET_(r16, 15, 0, v)

    #define   GET32mc_wrap_DFC_PMU_CTRL_newset_to_rstdis_time(r32) _BFGET_(r32, 31, 16)
    #define   SET32mc_wrap_DFC_PMU_CTRL_newset_to_rstdis_time(r32, v) _BFSET_(r32, 31, 16, v)
    #define   GET16mc_wrap_DFC_PMU_CTRL_newset_to_rstdis_time(r16) _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_DFC_PMU_CTRL_newset_to_rstdis_time(r16, v) _BFSET_(r16, 15, 0, v)

    #define     w32mc_wrap_DFC_PMU_CTRL1                       {\
	    UNSG32 uDFC_PMU_CTRL_rsten_to_newset_time          : 16;\
	    UNSG32 uDFC_PMU_CTRL_newset_to_rstdis_time         : 16;\
	}
    union { UNSG32 u32mc_wrap_DFC_PMU_CTRL1;
	    struct w32mc_wrap_DFC_PMU_CTRL1;
	  };
    #define   GET32mc_wrap_DFC_PMU_CTRL_plllck_wait_time(r32)  _BFGET_(r32, 15, 0)
    #define   SET32mc_wrap_DFC_PMU_CTRL_plllck_wait_time(r32, v) _BFSET_(r32, 15, 0, v)
    #define   GET16mc_wrap_DFC_PMU_CTRL_plllck_wait_time(r16)  _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_DFC_PMU_CTRL_plllck_wait_time(r16, v) _BFSET_(r16, 15, 0, v)

    #define   GET32mc_wrap_DFC_PMU_CTRL_plllck_to_bypdis_time(r32) _BFGET_(r32, 31, 16)
    #define   SET32mc_wrap_DFC_PMU_CTRL_plllck_to_bypdis_time(r32, v) _BFSET_(r32, 31, 16, v)
    #define   GET16mc_wrap_DFC_PMU_CTRL_plllck_to_bypdis_time(r16) _BFGET_(r16, 15, 0)
    #define   SET16mc_wrap_DFC_PMU_CTRL_plllck_to_bypdis_time(r16, v) _BFSET_(r16, 15, 0, v)

    #define     w32mc_wrap_DFC_PMU_CTRL2                       {\
	    UNSG32 uDFC_PMU_CTRL_plllck_wait_time              : 16;\
	    UNSG32 uDFC_PMU_CTRL_plllck_to_bypdis_time         : 16;\
	}
    union { UNSG32 u32mc_wrap_DFC_PMU_CTRL2;
	    struct w32mc_wrap_DFC_PMU_CTRL2;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_stat_ddrc_selfref_type_ch0(r32)     _BFGET_(r32, 1, 0)
    #define   SET32mc_wrap_stat_ddrc_selfref_type_ch0(r32, v)   _BFSET_(r32, 1, 0, v)
    #define   GET16mc_wrap_stat_ddrc_selfref_type_ch0(r16)     _BFGET_(r16, 1, 0)
    #define   SET16mc_wrap_stat_ddrc_selfref_type_ch0(r16, v)   _BFSET_(r16, 1, 0, v)

    #define   GET32mc_wrap_stat_ddrc_selfref_type_ch1(r32)     _BFGET_(r32, 3, 2)
    #define   SET32mc_wrap_stat_ddrc_selfref_type_ch1(r32, v)   _BFSET_(r32, 3, 2, v)
    #define   GET16mc_wrap_stat_ddrc_selfref_type_ch1(r16)     _BFGET_(r16, 3, 2)
    #define   SET16mc_wrap_stat_ddrc_selfref_type_ch1(r16, v)   _BFSET_(r16, 3, 2, v)

    #define     w32mc_wrap_stat_ddrc                           {\
	    UNSG32 ustat_ddrc_selfref_type_ch0                 :  2;\
	    UNSG32 ustat_ddrc_selfref_type_ch1                 :  2;\
	    UNSG32 RSVDx220_b4                                 : 28;\
	}
    union { UNSG32 u32mc_wrap_stat_ddrc;
	    struct w32mc_wrap_stat_ddrc;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_ddrphy_dto_ch0(r32)                 _BFGET_(r32, 0, 0)
    #define   SET32mc_wrap_ddrphy_dto_ch0(r32, v)               _BFSET_(r32, 0, 0, v)
    #define   GET16mc_wrap_ddrphy_dto_ch0(r16)                 _BFGET_(r16, 0, 0)
    #define   SET16mc_wrap_ddrphy_dto_ch0(r16, v)               _BFSET_(r16, 0, 0, v)

    #define   GET32mc_wrap_ddrphy_dto_ch1(r32)                 _BFGET_(r32, 1, 1)
    #define   SET32mc_wrap_ddrphy_dto_ch1(r32, v)               _BFSET_(r32, 1, 1, v)
    #define   GET16mc_wrap_ddrphy_dto_ch1(r16)                 _BFGET_(r16, 1, 1)
    #define   SET16mc_wrap_ddrphy_dto_ch1(r16, v)               _BFSET_(r16, 1, 1, v)

    #define     w32mc_wrap_ddrphy_dto                          {\
	    UNSG32 uddrphy_dto_ch0                             :  1;\
	    UNSG32 uddrphy_dto_ch1                             :  1;\
	    UNSG32 RSVDx224_b2                                 : 30;\
	}
    union { UNSG32 u32mc_wrap_ddrphy_dto;
	    struct w32mc_wrap_ddrphy_dto;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_PwrOkIn_TRUE(r32)                   _BFGET_(r32, 0, 0)
    #define   SET32mc_wrap_PwrOkIn_TRUE(r32, v)                 _BFSET_(r32, 0, 0, v)
    #define   GET16mc_wrap_PwrOkIn_TRUE(r16)                   _BFGET_(r16, 0, 0)
    #define   SET16mc_wrap_PwrOkIn_TRUE(r16, v)                 _BFSET_(r16, 0, 0, v)

    #define     w32mc_wrap_PwrOkIn                             {\
	    UNSG32 uPwrOkIn_TRUE                               :  1;\
	    UNSG32 RSVDx228_b1                                 : 31;\
	}
    union { UNSG32 u32mc_wrap_PwrOkIn;
	    struct w32mc_wrap_PwrOkIn;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_bufferen_core_TRUE(r32)             _BFGET_(r32, 0, 0)
    #define   SET32mc_wrap_bufferen_core_TRUE(r32, v)           _BFSET_(r32, 0, 0, v)
    #define   GET16mc_wrap_bufferen_core_TRUE(r16)             _BFGET_(r16, 0, 0)
    #define   SET16mc_wrap_bufferen_core_TRUE(r16, v)           _BFSET_(r16, 0, 0, v)

    #define     w32mc_wrap_bufferen_core                       {\
	    UNSG32 ubufferen_core_TRUE                         :  1;\
	    UNSG32 RSVDx22C_b1                                 : 31;\
	}
    union { UNSG32 u32mc_wrap_bufferen_core;
	    struct w32mc_wrap_bufferen_core;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_perf_log_cnt_ctrl_clear(r32)        _BFGET_(r32, 7, 0)
    #define   SET32mc_wrap_perf_log_cnt_ctrl_clear(r32, v)      _BFSET_(r32, 7, 0, v)
    #define   GET16mc_wrap_perf_log_cnt_ctrl_clear(r16)        _BFGET_(r16, 7, 0)
    #define   SET16mc_wrap_perf_log_cnt_ctrl_clear(r16, v)      _BFSET_(r16, 7, 0, v)

    #define   GET32mc_wrap_perf_log_cnt_ctrl_enable(r32)       _BFGET_(r32, 15, 8)
    #define   SET32mc_wrap_perf_log_cnt_ctrl_enable(r32, v)     _BFSET_(r32, 15, 8, v)
    #define   GET16mc_wrap_perf_log_cnt_ctrl_enable(r16)       _BFGET_(r16, 15, 8)
    #define   SET16mc_wrap_perf_log_cnt_ctrl_enable(r16, v)     _BFSET_(r16, 15, 8, v)

    #define   GET32mc_wrap_perf_log_cnt_ctrl_latch(r32)        _BFGET_(r32, 23, 16)
    #define   SET32mc_wrap_perf_log_cnt_ctrl_latch(r32, v)      _BFSET_(r32, 23, 16, v)
    #define   GET16mc_wrap_perf_log_cnt_ctrl_latch(r16)        _BFGET_(r16, 7, 0)
    #define   SET16mc_wrap_perf_log_cnt_ctrl_latch(r16, v)      _BFSET_(r16, 7, 0, v)

    #define   GET32mc_wrap_perf_log_cnt_ctrl_clk_div(r32)      _BFGET_(r32, 26, 24)
    #define   SET32mc_wrap_perf_log_cnt_ctrl_clk_div(r32, v)    _BFSET_(r32, 26, 24, v)
    #define   GET16mc_wrap_perf_log_cnt_ctrl_clk_div(r16)      _BFGET_(r16, 10, 8)
    #define   SET16mc_wrap_perf_log_cnt_ctrl_clk_div(r16, v)    _BFSET_(r16, 10, 8, v)

    #define     w32mc_wrap_perf_log_cnt_ctrl                   {\
	    UNSG32 uperf_log_cnt_ctrl_clear                    :  8;\
	    UNSG32 uperf_log_cnt_ctrl_enable                   :  8;\
	    UNSG32 uperf_log_cnt_ctrl_latch                    :  8;\
	    UNSG32 uperf_log_cnt_ctrl_clk_div                  :  3;\
	    UNSG32 RSVDx230_b27                                :  5;\
	}
    union { UNSG32 u32mc_wrap_perf_log_cnt_ctrl;
	    struct w32mc_wrap_perf_log_cnt_ctrl;
	  };
    #define   GET32mc_wrap_perf_log_cnt_ctrl_pc0_event_sel(r32) _BFGET_(r32, 5, 0)
    #define   SET32mc_wrap_perf_log_cnt_ctrl_pc0_event_sel(r32, v) _BFSET_(r32, 5, 0, v)
    #define   GET16mc_wrap_perf_log_cnt_ctrl_pc0_event_sel(r16) _BFGET_(r16, 5, 0)
    #define   SET16mc_wrap_perf_log_cnt_ctrl_pc0_event_sel(r16, v) _BFSET_(r16, 5, 0, v)

    #define   GET32mc_wrap_perf_log_cnt_ctrl_pc1_event_sel(r32) _BFGET_(r32, 11, 6)
    #define   SET32mc_wrap_perf_log_cnt_ctrl_pc1_event_sel(r32, v) _BFSET_(r32, 11, 6, v)
    #define   GET16mc_wrap_perf_log_cnt_ctrl_pc1_event_sel(r16) _BFGET_(r16, 11, 6)
    #define   SET16mc_wrap_perf_log_cnt_ctrl_pc1_event_sel(r16, v) _BFSET_(r16, 11, 6, v)

    #define   GET32mc_wrap_perf_log_cnt_ctrl_pc2_event_sel(r32) _BFGET_(r32, 17, 12)
    #define   SET32mc_wrap_perf_log_cnt_ctrl_pc2_event_sel(r32, v) _BFSET_(r32, 17, 12, v)

    #define   GET32mc_wrap_perf_log_cnt_ctrl_pc3_event_sel(r32) _BFGET_(r32, 23, 18)
    #define   SET32mc_wrap_perf_log_cnt_ctrl_pc3_event_sel(r32, v) _BFSET_(r32, 23, 18, v)
    #define   GET16mc_wrap_perf_log_cnt_ctrl_pc3_event_sel(r16) _BFGET_(r16, 7, 2)
    #define   SET16mc_wrap_perf_log_cnt_ctrl_pc3_event_sel(r16, v) _BFSET_(r16, 7, 2, v)

    #define   GET32mc_wrap_perf_log_cnt_ctrl_pc4_event_sel(r32) _BFGET_(r32, 29, 24)
    #define   SET32mc_wrap_perf_log_cnt_ctrl_pc4_event_sel(r32, v) _BFSET_(r32, 29, 24, v)
    #define   GET16mc_wrap_perf_log_cnt_ctrl_pc4_event_sel(r16) _BFGET_(r16, 13, 8)
    #define   SET16mc_wrap_perf_log_cnt_ctrl_pc4_event_sel(r16, v) _BFSET_(r16, 13, 8, v)

    #define     w32mc_wrap_perf_log_cnt_ctrl1                  {\
	    UNSG32 uperf_log_cnt_ctrl_pc0_event_sel            :  6;\
	    UNSG32 uperf_log_cnt_ctrl_pc1_event_sel            :  6;\
	    UNSG32 uperf_log_cnt_ctrl_pc2_event_sel            :  6;\
	    UNSG32 uperf_log_cnt_ctrl_pc3_event_sel            :  6;\
	    UNSG32 uperf_log_cnt_ctrl_pc4_event_sel            :  6;\
	    UNSG32 RSVDx234_b30                                :  2;\
	}
    union { UNSG32 u32mc_wrap_perf_log_cnt_ctrl1;
	    struct w32mc_wrap_perf_log_cnt_ctrl1;
	  };
    #define   GET32mc_wrap_perf_log_cnt_ctrl_pc5_event_sel(r32) _BFGET_(r32, 5, 0)
    #define   SET32mc_wrap_perf_log_cnt_ctrl_pc5_event_sel(r32, v) _BFSET_(r32, 5, 0, v)
    #define   GET16mc_wrap_perf_log_cnt_ctrl_pc5_event_sel(r16) _BFGET_(r16, 5, 0)
    #define   SET16mc_wrap_perf_log_cnt_ctrl_pc5_event_sel(r16, v) _BFSET_(r16, 5, 0, v)

    #define   GET32mc_wrap_perf_log_cnt_ctrl_pc6_event_sel(r32) _BFGET_(r32, 11, 6)
    #define   SET32mc_wrap_perf_log_cnt_ctrl_pc6_event_sel(r32, v) _BFSET_(r32, 11, 6, v)
    #define   GET16mc_wrap_perf_log_cnt_ctrl_pc6_event_sel(r16) _BFGET_(r16, 11, 6)
    #define   SET16mc_wrap_perf_log_cnt_ctrl_pc6_event_sel(r16, v) _BFSET_(r16, 11, 6, v)

    #define   GET32mc_wrap_perf_log_cnt_ctrl_pc7_event_sel(r32) _BFGET_(r32, 17, 12)
    #define   SET32mc_wrap_perf_log_cnt_ctrl_pc7_event_sel(r32, v) _BFSET_(r32, 17, 12, v)

    #define     w32mc_wrap_perf_log_cnt_ctrl2                  {\
	    UNSG32 uperf_log_cnt_ctrl_pc5_event_sel            :  6;\
	    UNSG32 uperf_log_cnt_ctrl_pc6_event_sel            :  6;\
	    UNSG32 uperf_log_cnt_ctrl_pc7_event_sel            :  6;\
	    UNSG32 RSVDx238_b18                                : 14;\
	}
    union { UNSG32 u32mc_wrap_perf_log_cnt_ctrl2;
	    struct w32mc_wrap_perf_log_cnt_ctrl2;
	  };
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_perf_log_cnt_ready_cnt(r32)         _BFGET_(r32, 7, 0)
    #define   SET32mc_wrap_perf_log_cnt_ready_cnt(r32, v)       _BFSET_(r32, 7, 0, v)
    #define   GET16mc_wrap_perf_log_cnt_ready_cnt(r16)         _BFGET_(r16, 7, 0)
    #define   SET16mc_wrap_perf_log_cnt_ready_cnt(r16, v)       _BFSET_(r16, 7, 0, v)

    #define     w32mc_wrap_perf_log_cnt_ready                  {\
	    UNSG32 uperf_log_cnt_ready_cnt                     :  8;\
	    UNSG32 RSVDx23C_b8                                 : 24;\
	}
    union { UNSG32 u32mc_wrap_perf_log_cnt_ready;
	    struct w32mc_wrap_perf_log_cnt_ready;
	  };
    ///////////////////////////////////////////////////////////
	SIE_MC_Perf_CntStat                              ie_pc0;
    ///////////////////////////////////////////////////////////
	SIE_MC_Perf_CntStat                              ie_pc1;
    ///////////////////////////////////////////////////////////
	SIE_MC_Perf_CntStat                              ie_pc2;
    ///////////////////////////////////////////////////////////
	SIE_MC_Perf_CntStat                              ie_pc3;
    ///////////////////////////////////////////////////////////
	SIE_MC_Perf_CntStat                              ie_pc4;
    ///////////////////////////////////////////////////////////
	SIE_MC_Perf_CntStat                              ie_pc5;
    ///////////////////////////////////////////////////////////
	SIE_MC_Perf_CntStat                              ie_pc6;
    ///////////////////////////////////////////////////////////
	SIE_MC_Perf_CntStat                              ie_pc7;
    ///////////////////////////////////////////////////////////
    #define   GET32mc_wrap_ddrphy_lpbk_bist_mode(r32)          _BFGET_(r32, 0, 0)
    #define   SET32mc_wrap_ddrphy_lpbk_bist_mode(r32, v)        _BFSET_(r32, 0, 0, v)
    #define   GET16mc_wrap_ddrphy_lpbk_bist_mode(r16)          _BFGET_(r16, 0, 0)
    #define   SET16mc_wrap_ddrphy_lpbk_bist_mode(r16, v)        _BFSET_(r16, 0, 0, v)

    #define   GET32mc_wrap_ddrphy_lpbk_bist_mux(r32)           _BFGET_(r32, 1, 1)
    #define   SET32mc_wrap_ddrphy_lpbk_bist_mux(r32, v)         _BFSET_(r32, 1, 1, v)
    #define   GET16mc_wrap_ddrphy_lpbk_bist_mux(r16)           _BFGET_(r16, 1, 1)
    #define   SET16mc_wrap_ddrphy_lpbk_bist_mux(r16, v)         _BFSET_(r16, 1, 1, v)

    #define   GET32mc_wrap_ddrphy_lpbk_bist_start(r32)         _BFGET_(r32, 2, 2)
    #define   SET32mc_wrap_ddrphy_lpbk_bist_start(r32, v)       _BFSET_(r32, 2, 2, v)
    #define   GET16mc_wrap_ddrphy_lpbk_bist_start(r16)         _BFGET_(r16, 2, 2)
    #define   SET16mc_wrap_ddrphy_lpbk_bist_start(r16, v)       _BFSET_(r16, 2, 2, v)

    #define   GET32mc_wrap_ddrphy_lpbk_bist_complete(r32)      _BFGET_(r32, 3, 3)
    #define   SET32mc_wrap_ddrphy_lpbk_bist_complete(r32, v)    _BFSET_(r32, 3, 3, v)
    #define   GET16mc_wrap_ddrphy_lpbk_bist_complete(r16)      _BFGET_(r16, 3, 3)
    #define   SET16mc_wrap_ddrphy_lpbk_bist_complete(r16, v)    _BFSET_(r16, 3, 3, v)

    #define   GET32mc_wrap_ddrphy_lpbk_bist_error(r32)         _BFGET_(r32, 4, 4)
    #define   SET32mc_wrap_ddrphy_lpbk_bist_error(r32, v)       _BFSET_(r32, 4, 4, v)
    #define   GET16mc_wrap_ddrphy_lpbk_bist_error(r16)         _BFGET_(r16, 4, 4)
    #define   SET16mc_wrap_ddrphy_lpbk_bist_error(r16, v)       _BFSET_(r16, 4, 4, v)

    #define     w32mc_wrap_ddrphy_lpbk                         {\
	    UNSG32 uddrphy_lpbk_bist_mode                      :  1;\
	    UNSG32 uddrphy_lpbk_bist_mux                       :  1;\
	    UNSG32 uddrphy_lpbk_bist_start                     :  1;\
	    UNSG32 uddrphy_lpbk_bist_complete                  :  1;\
	    UNSG32 uddrphy_lpbk_bist_error                     :  1;\
	    UNSG32 RSVDx280_b5                                 : 27;\
	}
    union { UNSG32 u32mc_wrap_ddrphy_lpbk;
	    struct w32mc_wrap_ddrphy_lpbk;
	  };
    ///////////////////////////////////////////////////////////
    } SIE_mc_wrap;

    typedef union  T32mc_wrap_MC_StickyRstn {
		UNSG32 u32;
	    struct w32mc_wrap_MC_StickyRstn;
		 } T32mc_wrap_MC_StickyRstn;
    typedef union  T32mc_wrap_DDRPHY_BypassPClk {
		UNSG32 u32;
	    struct w32mc_wrap_DDRPHY_BypassPClk;
		 } T32mc_wrap_DDRPHY_BypassPClk;
    typedef union  T32mc_wrap_AxiPCntCTRL {
		UNSG32 u32;
	    struct w32mc_wrap_AxiPCntCTRL;
		 } T32mc_wrap_AxiPCntCTRL;
    typedef union  T32mc_wrap_AxiMst0_0 {
		UNSG32 u32;
	    struct w32mc_wrap_AxiMst0_0;
		 } T32mc_wrap_AxiMst0_0;
    typedef union  T32mc_wrap_AxiMst0_1 {
		UNSG32 u32;
	    struct w32mc_wrap_AxiMst0_1;
		 } T32mc_wrap_AxiMst0_1;
    typedef union  T32mc_wrap_AxiMst0_2 {
		UNSG32 u32;
	    struct w32mc_wrap_AxiMst0_2;
		 } T32mc_wrap_AxiMst0_2;
    typedef union  T32mc_wrap_AxiMst0_3 {
		UNSG32 u32;
	    struct w32mc_wrap_AxiMst0_3;
		 } T32mc_wrap_AxiMst0_3;
    typedef union  T32mc_wrap_AxiMst0_4 {
		UNSG32 u32;
	    struct w32mc_wrap_AxiMst0_4;
		 } T32mc_wrap_AxiMst0_4;
    typedef union  T32mc_wrap_AxiMst1_0 {
		UNSG32 u32;
	    struct w32mc_wrap_AxiMst1_0;
		 } T32mc_wrap_AxiMst1_0;
    typedef union  T32mc_wrap_AlmSel {
		UNSG32 u32;
	    struct w32mc_wrap_AlmSel;
		 } T32mc_wrap_AlmSel;
    typedef union  T32mc_wrap_AxUrgent {
		UNSG32 u32;
	    struct w32mc_wrap_AxUrgent;
		 } T32mc_wrap_AxUrgent;
    typedef union  T32mc_wrap_PA_MASK {
		UNSG32 u32;
	    struct w32mc_wrap_PA_MASK;
		 } T32mc_wrap_PA_MASK;
    typedef union  T32mc_wrap_P0_AxQoS {
		UNSG32 u32;
	    struct w32mc_wrap_P0_AxQoS;
		 } T32mc_wrap_P0_AxQoS;
    typedef union  T32mc_wrap_P0_AxQoS1 {
		UNSG32 u32;
	    struct w32mc_wrap_P0_AxQoS1;
		 } T32mc_wrap_P0_AxQoS1;
    typedef union  T32mc_wrap_P0_AxQoS2 {
		UNSG32 u32;
	    struct w32mc_wrap_P0_AxQoS2;
		 } T32mc_wrap_P0_AxQoS2;
    typedef union  T32mc_wrap_P1_AxQoS {
		UNSG32 u32;
	    struct w32mc_wrap_P1_AxQoS;
		 } T32mc_wrap_P1_AxQoS;
    typedef union  T32mc_wrap_hif_mrr_data {
		UNSG32 u32;
	    struct w32mc_wrap_hif_mrr_data;
		 } T32mc_wrap_hif_mrr_data;
    typedef union  T32mc_wrap_hif_mrr_ddr4_lower {
		UNSG32 u32;
	    struct w32mc_wrap_hif_mrr_ddr4_lower;
		 } T32mc_wrap_hif_mrr_ddr4_lower;
    typedef union  T32mc_wrap_hif_mrr_ddr4_lower1 {
		UNSG32 u32;
	    struct w32mc_wrap_hif_mrr_ddr4_lower1;
		 } T32mc_wrap_hif_mrr_ddr4_lower1;
    typedef union  T32mc_wrap_hif_mrr_ddr4_lower2 {
		UNSG32 u32;
	    struct w32mc_wrap_hif_mrr_ddr4_lower2;
		 } T32mc_wrap_hif_mrr_ddr4_lower2;
    typedef union  T32mc_wrap_hif_mrr_ddr4_lower3 {
		UNSG32 u32;
	    struct w32mc_wrap_hif_mrr_ddr4_lower3;
		 } T32mc_wrap_hif_mrr_ddr4_lower3;
    typedef union  T32mc_wrap_hif_mrr_ddr4_upper {
		UNSG32 u32;
	    struct w32mc_wrap_hif_mrr_ddr4_upper;
		 } T32mc_wrap_hif_mrr_ddr4_upper;
    typedef union  T32mc_wrap_hif_mrr_ddr4_upper1 {
		UNSG32 u32;
	    struct w32mc_wrap_hif_mrr_ddr4_upper1;
		 } T32mc_wrap_hif_mrr_ddr4_upper1;
    typedef union  T32mc_wrap_hif_mrr_ddr4_upper2 {
		UNSG32 u32;
	    struct w32mc_wrap_hif_mrr_ddr4_upper2;
		 } T32mc_wrap_hif_mrr_ddr4_upper2;
    typedef union  T32mc_wrap_hif_mrr_ddr4_upper3 {
		UNSG32 u32;
	    struct w32mc_wrap_hif_mrr_ddr4_upper3;
		 } T32mc_wrap_hif_mrr_ddr4_upper3;
    typedef union  T32mc_wrap_Axi_Low_Pwr_Ifc {
		UNSG32 u32;
	    struct w32mc_wrap_Axi_Low_Pwr_Ifc;
		 } T32mc_wrap_Axi_Low_Pwr_Ifc;
    typedef union  T32mc_wrap_ddrc_low_pwr_ifc_ch0 {
		UNSG32 u32;
	    struct w32mc_wrap_ddrc_low_pwr_ifc_ch0;
		 } T32mc_wrap_ddrc_low_pwr_ifc_ch0;
    typedef union  T32mc_wrap_DFC_PMU_CTRL {
		UNSG32 u32;
	    struct w32mc_wrap_DFC_PMU_CTRL;
		 } T32mc_wrap_DFC_PMU_CTRL;
    typedef union  T32mc_wrap_DFC_PMU_CTRL1 {
		UNSG32 u32;
	    struct w32mc_wrap_DFC_PMU_CTRL1;
		 } T32mc_wrap_DFC_PMU_CTRL1;
    typedef union  T32mc_wrap_DFC_PMU_CTRL2 {
		UNSG32 u32;
	    struct w32mc_wrap_DFC_PMU_CTRL2;
		 } T32mc_wrap_DFC_PMU_CTRL2;
    typedef union  T32mc_wrap_stat_ddrc {
		UNSG32 u32;
	    struct w32mc_wrap_stat_ddrc;
		 } T32mc_wrap_stat_ddrc;
    typedef union  T32mc_wrap_ddrphy_dto {
		UNSG32 u32;
	    struct w32mc_wrap_ddrphy_dto;
		 } T32mc_wrap_ddrphy_dto;
    typedef union  T32mc_wrap_PwrOkIn {
		UNSG32 u32;
	    struct w32mc_wrap_PwrOkIn;
		 } T32mc_wrap_PwrOkIn;
    typedef union  T32mc_wrap_bufferen_core {
		UNSG32 u32;
	    struct w32mc_wrap_bufferen_core;
		 } T32mc_wrap_bufferen_core;
    typedef union  T32mc_wrap_perf_log_cnt_ctrl {
		UNSG32 u32;
	    struct w32mc_wrap_perf_log_cnt_ctrl;
		 } T32mc_wrap_perf_log_cnt_ctrl;
    typedef union  T32mc_wrap_perf_log_cnt_ctrl1 {
		UNSG32 u32;
	    struct w32mc_wrap_perf_log_cnt_ctrl1;
		 } T32mc_wrap_perf_log_cnt_ctrl1;
    typedef union  T32mc_wrap_perf_log_cnt_ctrl2 {
		UNSG32 u32;
	    struct w32mc_wrap_perf_log_cnt_ctrl2;
		 } T32mc_wrap_perf_log_cnt_ctrl2;
    typedef union  T32mc_wrap_perf_log_cnt_ready {
		UNSG32 u32;
	    struct w32mc_wrap_perf_log_cnt_ready;
		 } T32mc_wrap_perf_log_cnt_ready;
    typedef union  T32mc_wrap_ddrphy_lpbk {
		UNSG32 u32;
	    struct w32mc_wrap_ddrphy_lpbk;
		 } T32mc_wrap_ddrphy_lpbk;
    ///////////////////////////////////////////////////////////

    typedef union  Tmc_wrap_MC_StickyRstn {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_MC_StickyRstn;
		   };
		 } Tmc_wrap_MC_StickyRstn;
    typedef union  Tmc_wrap_DDRPHY_BypassPClk {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_DDRPHY_BypassPClk;
		   };
		 } Tmc_wrap_DDRPHY_BypassPClk;
    typedef union  Tmc_wrap_AxiPCntCTRL {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_AxiPCntCTRL;
		   };
		 } Tmc_wrap_AxiPCntCTRL;
    typedef union  Tmc_wrap_AxiMst0_0 {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_AxiMst0_0;
		   };
		 } Tmc_wrap_AxiMst0_0;
    typedef union  Tmc_wrap_AxiMst0_1 {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_AxiMst0_1;
		   };
		 } Tmc_wrap_AxiMst0_1;
    typedef union  Tmc_wrap_AxiMst0_2 {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_AxiMst0_2;
		   };
		 } Tmc_wrap_AxiMst0_2;
    typedef union  Tmc_wrap_AxiMst0_3 {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_AxiMst0_3;
		   };
		 } Tmc_wrap_AxiMst0_3;
    typedef union  Tmc_wrap_AxiMst0_4 {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_AxiMst0_4;
		   };
		 } Tmc_wrap_AxiMst0_4;
    typedef union  Tmc_wrap_AxiMst1_0 {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_AxiMst1_0;
		   };
		 } Tmc_wrap_AxiMst1_0;
    typedef union  Tmc_wrap_AlmSel {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_AlmSel;
		   };
		 } Tmc_wrap_AlmSel;
    typedef union  Tmc_wrap_AxUrgent {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_AxUrgent;
		   };
		 } Tmc_wrap_AxUrgent;
    typedef union  Tmc_wrap_PA_MASK {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_PA_MASK;
		   };
		 } Tmc_wrap_PA_MASK;
    typedef union  Tmc_wrap_P0_AxQoS {
		UNSG32 u32[3];
	    struct {
	    struct w32mc_wrap_P0_AxQoS;
	    struct w32mc_wrap_P0_AxQoS1;
	    struct w32mc_wrap_P0_AxQoS2;
		   };
		 } Tmc_wrap_P0_AxQoS;
    typedef union  Tmc_wrap_P1_AxQoS {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_P1_AxQoS;
		   };
		 } Tmc_wrap_P1_AxQoS;
    typedef union  Tmc_wrap_hif_mrr_data {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_hif_mrr_data;
		   };
		 } Tmc_wrap_hif_mrr_data;
    typedef union  Tmc_wrap_hif_mrr_ddr4_lower {
		UNSG32 u32[4];
	    struct {
	    struct w32mc_wrap_hif_mrr_ddr4_lower;
	    struct w32mc_wrap_hif_mrr_ddr4_lower1;
	    struct w32mc_wrap_hif_mrr_ddr4_lower2;
	    struct w32mc_wrap_hif_mrr_ddr4_lower3;
		   };
		 } Tmc_wrap_hif_mrr_ddr4_lower;
    typedef union  Tmc_wrap_hif_mrr_ddr4_upper {
		UNSG32 u32[4];
	    struct {
	    struct w32mc_wrap_hif_mrr_ddr4_upper;
	    struct w32mc_wrap_hif_mrr_ddr4_upper1;
	    struct w32mc_wrap_hif_mrr_ddr4_upper2;
	    struct w32mc_wrap_hif_mrr_ddr4_upper3;
		   };
		 } Tmc_wrap_hif_mrr_ddr4_upper;
    typedef union  Tmc_wrap_Axi_Low_Pwr_Ifc {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_Axi_Low_Pwr_Ifc;
		   };
		 } Tmc_wrap_Axi_Low_Pwr_Ifc;
    typedef union  Tmc_wrap_ddrc_low_pwr_ifc_ch0 {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_ddrc_low_pwr_ifc_ch0;
		   };
		 } Tmc_wrap_ddrc_low_pwr_ifc_ch0;
    typedef union  Tmc_wrap_DFC_PMU_CTRL {
		UNSG32 u32[3];
	    struct {
	    struct w32mc_wrap_DFC_PMU_CTRL;
	    struct w32mc_wrap_DFC_PMU_CTRL1;
	    struct w32mc_wrap_DFC_PMU_CTRL2;
		   };
		 } Tmc_wrap_DFC_PMU_CTRL;
    typedef union  Tmc_wrap_stat_ddrc {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_stat_ddrc;
		   };
		 } Tmc_wrap_stat_ddrc;
    typedef union  Tmc_wrap_ddrphy_dto {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_ddrphy_dto;
		   };
		 } Tmc_wrap_ddrphy_dto;
    typedef union  Tmc_wrap_PwrOkIn {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_PwrOkIn;
		   };
		 } Tmc_wrap_PwrOkIn;
    typedef union  Tmc_wrap_bufferen_core {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_bufferen_core;
		   };
		 } Tmc_wrap_bufferen_core;
    typedef union  Tmc_wrap_perf_log_cnt_ctrl {
		UNSG32 u32[3];
	    struct {
	    struct w32mc_wrap_perf_log_cnt_ctrl;
	    struct w32mc_wrap_perf_log_cnt_ctrl1;
	    struct w32mc_wrap_perf_log_cnt_ctrl2;
		   };
		 } Tmc_wrap_perf_log_cnt_ctrl;
    typedef union  Tmc_wrap_perf_log_cnt_ready {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_perf_log_cnt_ready;
		   };
		 } Tmc_wrap_perf_log_cnt_ready;
    typedef union  Tmc_wrap_ddrphy_lpbk {
		UNSG32 u32[1];
	    struct {
	    struct w32mc_wrap_ddrphy_lpbk;
		   };
		 } Tmc_wrap_ddrphy_lpbk;

    ///////////////////////////////////////////////////////////
     SIGN32 mc_wrap_drvrd(SIE_mc_wrap *p, UNSG32 base, SIGN32 mem, SIGN32 tst);
     SIGN32 mc_wrap_drvwr(SIE_mc_wrap *p, UNSG32 base, SIGN32 mem, SIGN32 tst, UNSG32 *pcmd);
       void mc_wrap_reset(SIE_mc_wrap *p);
     SIGN32 mc_wrap_cmp(SIE_mc_wrap *p, SIE_mc_wrap *pie, char *pfx, void *hLOG, SIGN32 mem, SIGN32 tst);
    #define mc_wrap_check(p, pie, pfx, hLOG) mc_wrap_cmp(p, pie, pfx, (void *)(hLOG), 0, 0)
    #define mc_wrap_print(p,    pfx, hLOG) mc_wrap_cmp(p, 0,  pfx, (void *)(hLOG), 0, 0)

#endif
//////
/// ENDOFINTERFACE: mc_wrap
////////////////////////////////////////////////////////////

#ifdef __cplusplus
  }
#endif
#pragma  pack()

#endif
//////
/// ENDOFFILE: mc_wrap.h
////////////////////////////////////////////////////////////
