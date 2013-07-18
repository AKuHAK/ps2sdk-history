#include "common.h"

#define SaveGP() \
	void *_ori_gp;	\
	__asm volatile("move %0, $gp\n"	\
	"move $gp, %1" :"=r"(_ori_gp): "r"(_gp))

#define RestoreGP() \
	__asm volatile("move $gp, %0" :: "r"(_ori_gp))

struct RuntimeStats{
	unsigned int RxDroppedFrameCount;
	unsigned short int RxFrameOverrunCount;
	unsigned short int RxFrameBadLengthCount;
	unsigned short int RxFrameBadFCSCount;
	unsigned short int RxFrameBadAlignmentCount;
	unsigned int TxDroppedFrameCount;
	unsigned short int TxFrameLOSSCRCount;
	unsigned short int TxFrameEDEFERCount;
	unsigned short int TxFrameCollisionCount;
	unsigned short int TxFrameUnderrunCount;
};

struct SmapDriverData{
	volatile u8 *smap_regbase;
	volatile u8 *emac3_regbase;
	unsigned int TxBufferSpaceAvailable;
	struct RuntimeStats RuntimeStats;
	unsigned char NumPacketsInTx;
	unsigned char TxBDIndex;
	unsigned char RxBDIndex;
	unsigned char TxDNVBDIndex;
	int Dev9IntrEventFlag;
	int TxEndEventFlag;
	int IntrHandlerThreadID;
	int TxHandlerThreadID;
	unsigned char SmapIsInitialized;
	unsigned char NetDevStopFlag;
	unsigned char EnableLinkCheckTimer;
	unsigned char LinkStatus;
	unsigned char LinkMode;
	iop_sys_clock_t LinkCheckTimer;
};

/* Function prototypes */
int smap_init(int argc, char *argv[]);
int SMAPStart(void);
void SMAPStop(void);
int SMAPGetMACAddress(unsigned char *buffer);

#include "xfer.h"
