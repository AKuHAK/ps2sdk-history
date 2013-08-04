/*
# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2004, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
#
# $Id$
*/

#ifndef _HELPER_H
#define _HELPER_H

#define ATAD_MODE_READ ATA_DIR_READ
#define ATAD_MODE_WRITE ATA_DIR_WRITE

#define t_shddInfo ata_devinfo_t

#define atadInit ata_get_devinfo
#define atadDmaTransfer ata_device_sector_io
#define atadSceUnlock ata_device_sec_unlock
#define atadIdle ata_device_idle
#define atadSceIdentifyDrive ata_device_sce_security_init
#define atadGetStatus ata_device_smart_get_status
#define atadUpdateAttrib ata_device_smart_save_attr
#define atadFlushCache ata_device_flush_cache

#endif
