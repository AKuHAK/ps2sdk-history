/*
# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2004, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.
*/

/**
 * @file
 * PS2 ROM0 Info.
 * Some useful method for extracting info from ROM0
 */

#include <rom0_info.h>
#include <fcntl.h>
#include <unistd.h>


extern char g_RomName[];

#ifdef F__info_internals
/** stores romname of ps2 */
char g_RomName[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#endif

#ifdef F_GetRomName
char* GetRomName(char *romname)
{
	int fd;

	fd = open("rom0:ROMVER", O_RDONLY);
	read(fd, romname, 14);
	close(fd);
	return romname;
}
#endif

#ifdef F_IsDESRMachine
int IsDESRMachine(void)
{
	int fd;

	fd = open("rom0:PSXVER", O_RDONLY);
	if (fd > 0) {
		close(fd);
		return 1;
	}

return 0;
}
#endif

#ifdef F_IsT10K
int IsT10K(void)
{
	// only read in the romname the first time
	if(g_RomName[0] == 0)
		GetRomName(g_RomName);
	return (g_RomName[4] == 'T') ? 1 : 0;
}
#endif