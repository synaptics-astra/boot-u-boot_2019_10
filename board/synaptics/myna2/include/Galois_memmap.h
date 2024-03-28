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

#ifndef Galois_memmap_h
#define Galois_memmap_h () {}

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
/// $INTERFACE MEMMAP                                   (4,4)
///     # # ----------------------------------------------------------
///               : DRAM_CACHE_BASE    0x0
///                            ###
///                            * This should be big enough. Bigger dram will make not make sense
///                            * for cost consideration.
///                            * 1024 MB
///                            ###
///               : DRAM_CACHE_SIZE    0x40000000
///                            ###
///                            * Size of cacheable DDR memory mapping
///                            ###
///               : DRAM_CACHE_DEC_BIT 0x1E
///                            ###
///                            * 1024 MB has a 30 bits offset
///                            ###
///               : DRAM_UNCACHE_BASE  0x40000000
///                            ###
///                            * Start address of uncacheable DDR
///                            * 1024 MB
///                            ###
///               : DRAM_UNCACHE_SIZE  0x40000000
///                            ###
///                            * Size of uncacheable DDR memory mapping
///                            ###
///               : DRAM_UNCACHE_DEC_BIT 0x1E
///                            ###
///                            * 1024 MB has a 30 bits offset
///                            ###
///               : DRAM_2GBTO3GB_BASE 0x80000000
///                            ###
///                            * Start address of 2GB to 3GB DDR
///                            * 1024 MB
///                            ###
///               : DRAM_2GBTO3GB_SIZE 0x40000000
///                            ###
///                            * Size of 2GB to 3GB memory mapping
///                            ###
///               : DRAM_2GBTO3GB_DEC_BIT 0x1E
///                            ###
///                            * 1024 MB has 30 bits offset
///                            ###
///               : DRAM_3GBTO3P5GB_BASE 0xC0000000
///                            ###
///                            * Start address of 3GB to 3.5GB DDR
///                            * 512 MB
///                            ###
///               : DRAM_3GBTO3P5GB_SIZE 0x20000000
///                            ###
///                            * Size of 3GB to 3.5GB memory mapping
///                            ###
///               : DRAM_3GBTO3P5GB_DEC_BIT 0x1D
///                            ###
///                            * 512 MB has 29 bits offset
///                            ###
///               : SPI_FLASH_BASE     0xF0000000
///                            ###
///                            * The following 256 MB can be mapped to host PCI-Express for
///                            * easier access /debugging
///                            * Base address for SPI flash
///                            * 64 MB (depends on the configuration)
///                            * 100M AHB
///                            ###
///               : SPI_FLASH_SIZE     0x2000000
///                            ###
///                            * Size of SPI flash
///                            * 32 MB
///                            ###
///               : SPI_FLASH_DEC_BIT  0x19
///                            ###
///                            * 32 MB has a 26 bits offset
///                            * Memory map for CORESIGHT registers
///                            ###
///               : CORESIGHT_REG_BASE 0xF6800000
///                            ###
///                            * Base address of CS registers
///                            * 8MB
///                            * Size of CORESIGHT registers
///                            ###
///               : CORESIGHT_REG_SIZE 0x800000
///                            ###
///                            * Size of CS Registers
///                            * Address decoding bit
///                            ###
///               : CORESIGHT_REG_DEC_BIT 0x17
///                            ###
///                            * 8MB has 23-bit offset
///                            ###
///               : AVIO_REG_BASE      0xF7400000
///                            ###
///                            * Base address of AVIO Registers
///                            * 2MB
///                            ###
///               : AVIO_REG_SIZE      0x200000
///                            ###
///                            * Size of AVIO Registers
///                            * Address decoding bit
///                            ###
///               : AVIO_REG_DEC_BIT   0x15
///                            ###
///                            * 2MB has 21-bit offset
///                            ###
///               : CA7_REG_BASE       0xF7920000
///                            ###
///                            * Base address of  CA7 and CPUPLL Registers
///                            * 64KB
///                            ###
///               : CA7_REG_SIZE       0x10000
///                            ###
///                            * Size of CA7 Registers
///                            ###
///               : CA7_REG_DEC_BIT    0x10
///                            ###
///                            * 64KB has 16-bit offset
///                            ###
///               : BCM_REG_BASE       0xF7930000
///                            ###
///                            * Base address of  BCM Registers
///                            * 64KB
///                            ###
///               : BCM_REG_SIZE       0x10000
///                            ###
///                            * Size of BCM Registers
///                            ###
///               : BCM_REG_DEC_BIT    0x10
///                            ###
///                            * 64KB has 16-bit offset
///                            ###
///               : MCTRLSS_REG_BASE   0xF7940000
///                            ###
///                            * Base address of  MCTRL_SS Registers
///                            * 64KB
///                            ###
///               : MCTRLSS_REG_SIZE   0x10000
///                            ###
///                            * Size of MCTRLSS Registers
///                            ###
///               : MCTRLSS_REG_DEC_BIT 0x10
///                            ###
///                            * 64KB has 16-bit offset
///                            * Memory map for GFX3D subsystem
///                            ###
///               : GFX3D_REG_BASE     0xF7980000
///                            ###
///                            * Base address of GFX3D Registers
///                            * 512KB
///                            * Size of GFX3D registers
///                            ###
///               : GFX3D_REG_SIZE     0x80000
///                            ###
///                            * Size of GFX3D Registers
///                            * Address decoding bit
///                            ###
///               : GFX3D_REG_DEC_BIT  0x13
///                            ###
///                            * 512KB has 19-bit offset
///                            ###
///               : MC_ALM_REG_BASE    0xF7A80000
///                            ###
///                            * Base address for Axi Latency meter in GFX
///                            * 64 KB
///                            ###
///               : MC_ALM_REG_SIZE    0x10000
///                            ###
///                            * Size of  MC ALM Registers memory mapping
///                            ###
///               : MC_ALM_REG_DEC_BIT 0x10
///                            ###
///                            * 64 KB has a 16 bits offset
///                            * Memory map for EMMC inside perif subsystem
///                            ###
///               : EMMC_REG_BASE      0xF7AA0000
///                            ###
///                            * Base address of EMMC Registers
///                            * 4KB
///                            * Size of EMMC registers
///                            ###
///               : EMMC_REG_SIZE      0x1000
///                            ###
///                            * Size of EMMC Registers
///                            * Address decoding bit
///                            ###
///               : EMMC_REG_DEC_BIT   0xC
///                            ###
///                            * 4KB has 16-bit offset
///                            * Memory map for SDIO3 inside perif subsystem
///                            ###
///               : SDIO3_REG_BASE     0xF7AB0000
///                            ###
///                            * Base address of SDIO3 Registers
///                            * 4KB
///                            * Size of SDIO3 registers
///                            ###
///               : SDIO3_REG_SIZE     0x1000
///                            ###
///                            * Size of SDIO3 Registers
///                            * Address decoding bit
///                            ###
///               : SDIO3_REG_DEC_BIT  0xC
///                            ###
///                            * 4KB has 16-bit offset
///                            ###
///               : PB_REG_BASE        0xF7B30000
///                            ###
///                            * Base address for PB Registers
///                            * 64KB
///                            ###
///               : PB_REG_SIZE        0x10000
///                            ###
///                            * Size of PBridge Registers
///                            ###
///               : PB_REG_DEC_BIT     0x10
///                            ###
///                            * 64KB has a 16bits offset
///                            ###
///               : MTEST_REG_BASE     0xF7B40000
///                            ###
///                            * Base address for MTEST Registers
///                            * 64KB
///                            ###
///               : MTEST_REG_SIZE     0x10000
///                            ###
///                            * Size of MTEST Registers
///                            ###
///               : MTEST_REG_DEC_BIT  0x10
///                            ###
///                            * 64KB has 16-bit offset
///                            ###
///               : GE_REG_BASE        0xF7B60000
///                            ###
///                            * Base address for Gigabit Ethernet Controller Registers
///                            * 64KB
///                            ###
///               : GE_REG_SIZE        0x10000
///                            ###
///                            * Size of Gigabit Ethernet Controller Registers
///                            ###
///               : GE_REG_DEC_BIT     0x10
///                            ###
///                            * 64KB has 16-bit offset
///                            ###
///               : NPU_RSVD_REG_BASE  0xF7BC0000
///                            ###
///                            * Legacy Base address for NPU Registers
///                            * 256KB
///                            ###
///               : NPU_RSVD_REG_SIZE  0x40000
///                            ###
///                            * Size of legacy NPU Registers
///                            ###
///               : NPU_RSVD_REG_DEC_BIT 0x12
///                            ###
///                            * 256KB has 18-bit offset
///                            ###
///               : USB0_REG_BASE      0xF7C00000
///                            ###
///                            * Base address for USB OTG Registers
///                            * 512KB
///                            ###
///               : USB0_REG_SIZE      0x80000
///                            ###
///                            * Size of USB OTG register memory mapping
///                            ###
///               : USB0_REG_DEC_BIT   0x13
///                            ###
///                            * 512KB has 19-bit offset
///                            ###
///               : USB0_PHY_REG_BASE  0xF7C40000
///                            ###
///                            * Base address for USB0 PHY registers. Defined for SW usage.
///                            * **FOR SW PURPOSE ONLY**
///                            ###
///               : SOC_REG_BASE       0xF7CA0000
///                            ###
///                            * Base address for SOC registers
///                            * 64KB
///                            ###
///               : SOC_REG_SIZE       0x10000
///                            ###
///                            * Size of SOC register memory mapping
///                            ###
///               : SOC_REG_DEC_BIT    0x10
///                            ###
///                            * 64KB has 16-bit offset
///                            ###
///               : DDR_REG_BASE       0xF7CB0000
///                            ###
///                            * Base address for DDR registers
///                            * 16KB
///                            ###
///               : DDR_REG_SIZE       0x4000
///                            ###
///                            * Size of DDR registers memory mapping
///                            ###
///               : DDR_REG_DEC_BIT    0xE
///                            ###
///                            * 16KB has 14-bit offset
///                            ###
///               : TSI_REG_BASE       0xF7CC0000
///                            ###
///                            * Base address of TSI register region
///                            * 256KB
///                            ###
///               : TSI_REG_SIZE       0x40000
///                            ###
///                            * Size of TSI register region
///                            ###
///               : TSI_REG_DEC_BIT    0x12
///                            ###
///                            * 256KB has 18-bit offset
///                            ###
///               : USB3_REG_BASE      0xF7D00000
///                            ###
///                            * Base address of USB3 Registers
///                            * 1MB
///                            ###
///               : USB3_REG_SIZE      0x100000
///                            ###
///                            * Size of USB3 Registers
///                            ###
///               : USB3_REG_DEC_BIT   0x14
///                            ###
///                            * 1MB has 20-bit offset
///                            ###
///               : APBPERIF_REG_BASE  0xF7E80000
///                            ###
///                            * Base address for ApbPerif Registers
///                            * ApbPerif is designed to integrate all the low speed I/O
///                            * functionalities.
///                            * It provides an AHB interface for processor to access the low
///                            * speed I/O devices and memory-mapped SPI Flash device. It also
///                            * have a OCP master interface for external Host to access chip
///                            * internal address through I2C interface
///                            * I2C master/slave; SPI master; UART controller; GPIO; Timer;
///                            * Watchdog timer; Interrupt controller
///                            * 64 KB
///                            ###
///               : APBPERIF_REG_SIZE  0x10000
///                            ###
///                            * Size of ApbPerif Registers memory mapping
///                            ###
///               : APBPERIF_REG_DEC_BIT 0x10
///                            ###
///                            * 64 KB has a 16 bits offset
///                            ###
///               : CHIP_CTRL_REG_BASE 0xF7EA0000
///                            ###
///                            * Chip Control (Processor Reset, Bootstrap, ...)
///                            * 64 KB
///                            ###
///               : CHIP_CTRL_REG_SIZE 0x10000
///                            ###
///                            * Size of CHIP ID Registers memory mapping
///                            ###
///               : CHIP_CTRL_REG_DEC_BIT 0x10
///                            ###
///                            * 64 KB has a 16 bits offset
///                            ###
///               : NAND_FLASH_REG_BASE 0xF7F00000
///                            ###
///                            * Base address of NAND flash control Registers
///                            * 64 KB
///                            ###
///               : NAND_FLASH_REG_SIZE 0x10000
///                            ###
///                            * Size of NAND flash Registers memory mapping
///                            ###
///               : NAND_FLASH_DEC_BIT 0x10
///                            ###
///                            * 64 KB has a 16 bits offset
///                            ###
///               : NAND_AHB_REG_BASE  0xF7F10000
///                            ###
///                            * Base address of Local Bus Controller Registers
///                            * 64 KB
///                            ###
///               : NAND_AHB_REG_SIZE  0x10000
///                            ###
///                            * Size of Local Bus Controller Registers memory mapping
///                            ###
///               : NAND_AHB_REG_DEC_BIT 0x10
///                            ###
///                            * 64 KB has a 16 bits offset
///                            ###
///               : PWM_REG_BASE       0xF7F20000
///                            ###
///                            * Base address of Pulse Width Modulator control Registers
///                            * 64 KB
///                            ###
///               : PWM_REG_SIZE       0x10000
///                            ###
///                            * Size of Pulse Width Modulator Registers memory mapping
///                            ###
///               : PWM_REG_DEC_BIT    0x10
///                            ###
///                            * 64 KB has a 16 bits offset
///                            * **INTERNAL_ONLY**
///                            ###
///               : MC_DFI0_REG_BASE   0xF8000000
///                            ###
///                            * Base address of MC DFI0 Control  Registers
///                            * 4 KB
///                            ###
///               : MC_DFI0_REG_SIZE   0x1000
///                            ###
///                            * Size of MC DFI0 control Registers
///                            ###
///               : MC_DFI0_REG_DEC_BIT 0xC
///                            ###
///                            * 4KB has 16-bit offset
///                            ###
///               : MPTS_REG_BASE      0xF9000000
///                            ###
///                            * Base address of MPT Registers
///                            * 256KB
///                            ###
///               : MPTS_REG_SIZE      0x40000
///                            ###
///                            * Size of MPT memory mapping
///                            ###
///               : MPTS_REG_DEC_BIT   0x12
///                            ###
///                            * 256KB has a 18 bits offset
///                            ###
///               : SRAM_REG_BASE      0xF9200000
///                            ###
///                            * Base address of SRAM Registers
///                            * 128KB
///                            ###
///               : SRAM_REG_SIZE      0x20000
///                            ###
///                            * Size of SRAM memory mapping
///                            * Note:
///                            * Decode must be 2^N aligned. Actual SRAM in Myna2 is 80KB.
///                            ###
///               : SRAM_REG_DEC_BIT   0x11
///                            ###
///                            * 128 KB has 17 bit offset
///                            ###
///               : IPC_RSVD_REG_BASE  0xF9300000
///                            ###
///                            * Base address of IPC Registers
///                            * 64KB
///                            ###
///               : IPC_RSVD_REG_SIZE  0x10000
///                            ###
///                            * Size of IPC mapping
///                            ###
///               : IPC_RSVD_REG_DEC_BIT 0x10
///                            ###
///                            * 64 KB has 16 bit offset
///                            ###
///               : GIC_REG_BASE       0xF7900000
///                            ###
///                            * Base address of GIC Registers
///                            * 32KB
///                            ###
///               : GIC_REG_SIZE       0x8000
///                            ###
///                            * Size of GIC mapping
///                            ###
///               : GIC_REG_DEC_BIT    0xF
///                            ###
///                            * 32 KB has 16 bit offset
///                            ###
///               : DSP0_RSVD_REG_BASE 0xF9400000
///                            ###
///                            * Base address of HIFI4 DSP0 control Registers
///                            * 64 KB
///                            ###
///               : DSP0_RSVD_REG_SIZE 0x10000
///                            ###
///                            * Size of HIFI4 DSP0 Registers memory mapping
///                            ###
///               : DSP0_RSVD_REG_DEC_BIT 0x10
///                            ###
///                            * 64 KB has a 16 bits offset
///                            ###
///               : HIGH_ROM_VECTOR_BASE 0xFFFF0000
///                            ###
///                            * VECTORS = 0xFFFF-0000 ~ 0xFFFF-BFFF
///                            * HIGH ADDRESS ROM = 0xFFFF-C000 ~ 0xFFFF-FFFF
///                            ###
///               : HIGH_ROM_VECTOR_SIZE 0x10000
///                            ###
///                            * VECTOR has 48 KB; High address ROM has 16 KB
///                            * 64 KB
///                            ###
///               : HIGH_ROM_VECTOR_DEC_BIT 0x10
///                            ###
///                            * 64 KB has a 16 bits offset
///                            ###
///     # # ----------------------------------------------------------
/// $ENDOFINTERFACE  # size:       0B, bits:       0b, padding:     0B
////////////////////////////////////////////////////////////
#ifndef h_MEMMAP
#define h_MEMMAP () {}

    #define        MEMMAP_DRAM_CACHE_BASE                      0x0
    #define        MEMMAP_DRAM_CACHE_SIZE                      0x40000000
    #define        MEMMAP_DRAM_CACHE_DEC_BIT                   0x1E
    #define        MEMMAP_DRAM_UNCACHE_BASE                    0x40000000
    #define        MEMMAP_DRAM_UNCACHE_SIZE                    0x40000000
    #define        MEMMAP_DRAM_UNCACHE_DEC_BIT                 0x1E
    #define        MEMMAP_DRAM_2GBTO3GB_BASE                   0x80000000
    #define        MEMMAP_DRAM_2GBTO3GB_SIZE                   0x40000000
    #define        MEMMAP_DRAM_2GBTO3GB_DEC_BIT                0x1E
    #define        MEMMAP_DRAM_3GBTO3P5GB_BASE                 0xC0000000
    #define        MEMMAP_DRAM_3GBTO3P5GB_SIZE                 0x20000000
    #define        MEMMAP_DRAM_3GBTO3P5GB_DEC_BIT              0x1D
    #define        MEMMAP_SPI_FLASH_BASE                       0xF0000000
    #define        MEMMAP_SPI_FLASH_SIZE                       0x2000000
    #define        MEMMAP_SPI_FLASH_DEC_BIT                    0x19
    #define        MEMMAP_CORESIGHT_REG_BASE                   0xF6800000
    #define        MEMMAP_CORESIGHT_REG_SIZE                   0x800000
    #define        MEMMAP_CORESIGHT_REG_DEC_BIT                0x17
    #define        MEMMAP_AVIO_REG_BASE                        0xF7400000
    #define        MEMMAP_AVIO_REG_SIZE                        0x200000
    #define        MEMMAP_AVIO_REG_DEC_BIT                     0x15
    #define        MEMMAP_CA7_REG_BASE                         0xF7920000
    #define        MEMMAP_CA7_REG_SIZE                         0x10000
    #define        MEMMAP_CA7_REG_DEC_BIT                      0x10
    #define        MEMMAP_BCM_REG_BASE                         0xF7930000
    #define        MEMMAP_BCM_REG_SIZE                         0x10000
    #define        MEMMAP_BCM_REG_DEC_BIT                      0x10
    #define        MEMMAP_MCTRLSS_REG_BASE                     0xF7940000
    #define        MEMMAP_MCTRLSS_REG_SIZE                     0x10000
    #define        MEMMAP_MCTRLSS_REG_DEC_BIT                  0x10
    #define        MEMMAP_GFX3D_REG_BASE                       0xF7980000
    #define        MEMMAP_GFX3D_REG_SIZE                       0x80000
    #define        MEMMAP_GFX3D_REG_DEC_BIT                    0x13
    #define        MEMMAP_MC_ALM_REG_BASE                      0xF7A80000
    #define        MEMMAP_MC_ALM_REG_SIZE                      0x10000
    #define        MEMMAP_MC_ALM_REG_DEC_BIT                   0x10
    #define        MEMMAP_EMMC_REG_BASE                        0xF7AA0000
    #define        MEMMAP_EMMC_REG_SIZE                        0x1000
    #define        MEMMAP_EMMC_REG_DEC_BIT                     0xC
    #define        MEMMAP_SDIO3_REG_BASE                       0xF7AB0000
    #define        MEMMAP_SDIO3_REG_SIZE                       0x1000
    #define        MEMMAP_SDIO3_REG_DEC_BIT                    0xC
    #define        MEMMAP_PB_REG_BASE                          0xF7B30000
    #define        MEMMAP_PB_REG_SIZE                          0x10000
    #define        MEMMAP_PB_REG_DEC_BIT                       0x10
    #define        MEMMAP_MTEST_REG_BASE                       0xF7B40000
    #define        MEMMAP_MTEST_REG_SIZE                       0x10000
    #define        MEMMAP_MTEST_REG_DEC_BIT                    0x10
    #define        MEMMAP_GE_REG_BASE                          0xF7B60000
    #define        MEMMAP_GE_REG_SIZE                          0x10000
    #define        MEMMAP_GE_REG_DEC_BIT                       0x10
    #define        MEMMAP_NPU_RSVD_REG_BASE                    0xF7BC0000
    #define        MEMMAP_NPU_RSVD_REG_SIZE                    0x40000
    #define        MEMMAP_NPU_RSVD_REG_DEC_BIT                 0x12
    #define        MEMMAP_USB0_REG_BASE                        0xF7C00000
    #define        MEMMAP_USB0_REG_SIZE                        0x80000
    #define        MEMMAP_USB0_REG_DEC_BIT                     0x13
    #define        MEMMAP_USB0_PHY_REG_BASE                    0xF7C40000
    #define        MEMMAP_SOC_REG_BASE                         0xF7CA0000
    #define        MEMMAP_SOC_REG_SIZE                         0x10000
    #define        MEMMAP_SOC_REG_DEC_BIT                      0x10
    #define        MEMMAP_DDR_REG_BASE                         0xF7CB0000
    #define        MEMMAP_DDR_REG_SIZE                         0x4000
    #define        MEMMAP_DDR_REG_DEC_BIT                      0xE
    #define        MEMMAP_TSI_REG_BASE                         0xF7CC0000
    #define        MEMMAP_TSI_REG_SIZE                         0x40000
    #define        MEMMAP_TSI_REG_DEC_BIT                      0x12
    #define        MEMMAP_USB3_REG_BASE                        0xF7D00000
    #define        MEMMAP_USB3_REG_SIZE                        0x100000
    #define        MEMMAP_USB3_REG_DEC_BIT                     0x14
    #define        MEMMAP_APBPERIF_REG_BASE                    0xF7E80000
    #define        MEMMAP_APBPERIF_REG_SIZE                    0x10000
    #define        MEMMAP_APBPERIF_REG_DEC_BIT                 0x10
    #define        MEMMAP_CHIP_CTRL_REG_BASE                   0xF7EA0000
    #define        MEMMAP_CHIP_CTRL_REG_SIZE                   0x10000
    #define        MEMMAP_CHIP_CTRL_REG_DEC_BIT                0x10
    #define        MEMMAP_NAND_FLASH_REG_BASE                  0xF7F00000
    #define        MEMMAP_NAND_FLASH_REG_SIZE                  0x10000
    #define        MEMMAP_NAND_FLASH_DEC_BIT                   0x10
    #define        MEMMAP_NAND_AHB_REG_BASE                    0xF7F10000
    #define        MEMMAP_NAND_AHB_REG_SIZE                    0x10000
    #define        MEMMAP_NAND_AHB_REG_DEC_BIT                 0x10
    #define        MEMMAP_PWM_REG_BASE                         0xF7F20000
    #define        MEMMAP_PWM_REG_SIZE                         0x10000
    #define        MEMMAP_PWM_REG_DEC_BIT                      0x10
    #define        MEMMAP_MC_DFI0_REG_BASE                     0xF8000000
    #define        MEMMAP_MC_DFI0_REG_SIZE                     0x1000
    #define        MEMMAP_MC_DFI0_REG_DEC_BIT                  0xC
    #define        MEMMAP_MPTS_REG_BASE                        0xF9000000
    #define        MEMMAP_MPTS_REG_SIZE                        0x40000
    #define        MEMMAP_MPTS_REG_DEC_BIT                     0x12
    #define        MEMMAP_SRAM_REG_BASE                        0xF9200000
    #define        MEMMAP_SRAM_REG_SIZE                        0x20000
    #define        MEMMAP_SRAM_REG_DEC_BIT                     0x11
    #define        MEMMAP_IPC_RSVD_REG_BASE                    0xF9300000
    #define        MEMMAP_IPC_RSVD_REG_SIZE                    0x10000
    #define        MEMMAP_IPC_RSVD_REG_DEC_BIT                 0x10
    #define        MEMMAP_GIC_REG_BASE                         0xF7900000
    #define        MEMMAP_GIC_REG_SIZE                         0x8000
    #define        MEMMAP_GIC_REG_DEC_BIT                      0xF
    #define        MEMMAP_DSP0_RSVD_REG_BASE                   0xF9400000
    #define        MEMMAP_DSP0_RSVD_REG_SIZE                   0x10000
    #define        MEMMAP_DSP0_RSVD_REG_DEC_BIT                0x10
    #define        MEMMAP_HIGH_ROM_VECTOR_BASE                 0xFFFF0000
    #define        MEMMAP_HIGH_ROM_VECTOR_SIZE                 0x10000
    #define        MEMMAP_HIGH_ROM_VECTOR_DEC_BIT              0x10
    #define        MEMMAP_HIGH_EXCEPT_RESET_REG                0xFFFF0000
    #define        MEMMAP_HIGH_EXCEPT_UNDEF_REG                0xFFFF0004
    #define        MEMMAP_HIGH_EXCEPT_SOFT_REG                 0xFFFF0008
    #define        MEMMAP_HIGH_EXCEPT_PREFETCH_REG             0xFFFF000C
    #define        MEMMAP_HIGH_EXCEPT_DATA_REG                 0xFFFF0010
    #define        MEMMAP_HIGH_EXCEPT_UNUSED_REG               0xFFFF0014
    #define        MEMMAP_HIGH_EXCEPT_IRQ_REG                  0xFFFF0018
    #define        MEMMAP_HIGH_EXCEPT_FIQ_REG                  0xFFFF001C
    #define        MEMMAP_SOFTWARE_RESET_ADDR_REG              0xFFFF0094
    ///////////////////////////////////////////////////////////

#endif
//////
/// ENDOFINTERFACE: MEMMAP
////////////////////////////////////////////////////////////

#ifdef __cplusplus
  }
#endif
#pragma  pack()

#endif
//////
/// ENDOFFILE: Galois_memmap.h
////////////////////////////////////////////////////////////

