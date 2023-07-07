#pragma once

#include "Dwm3000.hpp"

// 0x00-0x1 – General configuration registers and AES
void load(DEV_ID *devId);
void load(PANADR *pandra);
void load(SYS_CFG *sys_cfg);
void load(FF_CFG *ffCfg);
void load(SPI_RD_CRC *spiRdCrc);
void load(SYS_TIME *sysTime);
void load(TX_FCTRL *txFctrl);
void load(DX_TIME *dxTime);
void load(DREF_TIME *drefTime);
void load(RX_FWTO *rxFwto);
void load(SYS_CTR *sysCtr);
void load(SYS_ENABLE *sysEnable);
void load(SYS_STATUS *sysStatus);
void load(RX_FINFO *rxFinfo);
void load(RX_TIME *rxTime);
void load(TX_TIME *txTime);
void load(TX_RAWST *txRawst);
void load(TX_ANTD *txAntd);
void load(ACK_RESP_T *ackRespT);
void load(TX_POWER *txPower);
void load(CHAN_CTRL *chanCtrl);
void load(LE_PEND_01 *lePend01);
void load(LE_PEND_23 *lePend23);
void load(SPI_COLLISION *spiCollision);
void load(RDB_STATUS *rdbStatus);
void load(RDB_DIAG *rdbDiag);
void load(AES_CFG *aesCfg);
void load(AES_IV0 *aesIv0);
void load(AES_IV1 *aesIv1);
void load(AES_IV2 *aesIv2);
void load(AES_IV3 *aesIv3);
void load(AES_IV4 *aesIv4);
void load(DMA_CFG *dmaCfg);
void load(AES_START *aesStart);
void load(AES_KEY *aesKey);

// 0x02 – STS configuration and status registers
void load(STS_CFG *stsCfg);
void load(STS_CTRL *stsCtrl);
void load(STS_STS *stsSts);
void load(STS_KEY *stsKey);

// 0x03 – Receiver tuning parameters
void load(DGC_CFG *dgcCfg);
void load(DHC_DBG *dhcDbg);

// 0x04 – External sync control and RX calibration
void load(EX_CTRL *exCtrl);
void load(RX_CAL *rxCal);
void load(RX_CAL_RESI *rxCalResi);
void load(RX_CAL_RESQ *rxCalResq);
void load(RX_CAL_STS *rxCalSts);

//  0x05 – GPIO control and status
void load(GPIO_MODE *gpioMode);
void load(GPIO_PULL_EN *gpioPullEn);
void load(GPIO_DIR *gpioDir);
void load(GPIO_OUT *gpioOut);
void load(GPIO_IRQE *gpioIrqe);
void load(GPIO_ISTS *gpioIsts);
void load(GPIO_ISEN *gpioIsen);
void load(GPIO_IMODE *gpioImode);
void load(GPIO_IBES *gpioIbes);
void load(GPIO_ICLR *gpioIclr);
void load(GPIO_IDBE *gpioIdbe);
void load(GPIO_RAW *gpioRaw);

//  0x06 – Digital receiver configuration
void load(DTUNE_0 *dtune0);
void load(RX_SFD_TOC *rxSfdToc);
void load(PRE_TOC *preToc);
void load(DTUNE3 *dtune3);
void load(DTUNE5 *dtune5);
void load(DRX_CAR_INT *drxCarInt);

// 0x07 – Analog RF configuration block
void load(RF_ENABLE *rfEnable);
void load(RF_CTRL_MASK *rfCtrlMask);
void load(RF_SWITCH *rfSwitch);
void load(RF_TX_CTRL_1 *rfTxCtrl1);
void load(RF_TX_CTRL_2 *rfTxCtrl2);
void load(TX_TEST *txTest);
void load(SAR_TEST *sarTest);
void load(LDO_TUNE *ldoTune);
void load(LDO_CTRL *ldoCtrl);
void load(LDO_RLOAD *ldoRload);

// 0x08 – Transmitter calibration block
void load(SAR_CTRL *sarCtrl);
void load(SAR_STATUS *sarStatus);
void load(SAR_READING *sarReading);
void load(SAR_WAKE_RD *sarWakeRd);
void load(PGC_CTRL *pgcCtrl);
void load(PGC_STATUS *pgcStatus);
void load(PG_TEST *pgTest);
void load(PG_CAL_TARGET *pgCalTarget);

// 0x09 – Frequency synthesiser control block
void load(PLL_CFG *pllCfg);
void load(PLL_CC *pllCc);
void load(PLL_CAL *pllCal);
void load(XTAL *xtal);

// 0x0A – Always-on system control interface

void load(AON_DIG_CFG *aonDigCfg);
void load(AON_CTRL *aonCtrl);
void load(AON_RDATA *aonRdata);
void load(AON_ADDR *aonAddr);
void load(AON_WDATA *aonWdata);
void load(AON_CFG *aonCfg);