/*
 * dev9.h - DEV9 Device Driver definitions and imports.
 *
 * Copyright (c) 2003 Marcus R. Brown <mrbrown@0xd6.org>
 *
 * See the file LICENSE included with this distribution for licensing terms.
 */

#ifndef IOP_DEV9_H
#define IOP_DEV9_H

#include "types.h"
#include "irx.h"

typedef int (*dev9_intr_cb_t)(int flag);

#define dev9_IMPORTS_start DECLARE_IMPORT_TABLE(dev9, 1, 1)
#define dev9_IMPORTS_end END_IMPORT_TABLE

void dev9RegisterIntrCb(int intr, dev9_intr_cb_t cb);
#define I_dev9RegisterIntrCb DECLARE_IMPORT(4, dev9RegisterIntrCb)

int dev9DmaTransfer(int ctrl, void *buf, int bcr, int dir);
#define I_dev9DmaTransfer DECLARE_IMPORT(5, dev9DmaTransfer)

void dev9Shutdown(void);
#define I_dev9Shutdown DECLARE_IMPORT(6, dev9Shutdown)
void dev9IntrEnable(int mask);
#define I_dev9IntrEnable DECLARE_IMPORT(7, dev9IntrEnable)
void dev9IntrDisable(int mask);
#define I_dev9IntrDisable DECLARE_IMPORT(8, dev9IntrDisable)

int dev9GetEEPROM(u16 *buf);
#define I_dev9GetEEPROM DECLARE_IMPORT(9, dev9GetEEPROM)

void dev9LEDCtl(int ctl);
#define I_dev9LEDCtl DECLARE_IMPORT(10, dev9LEDCtl)

#endif /* IOP_PS2DEV9_H */
