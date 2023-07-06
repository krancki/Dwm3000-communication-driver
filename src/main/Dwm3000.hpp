#pragma once

class DEV_ID
{
  public:
    unsigned int rev;
    unsigned char ver;
    unsigned char model;
    unsigned char ridtag;
};

class PANADR
{
  public:
    unsigned int panId;
    unsigned int shortAddr;
};

class SYS_CFG
{
  public:
    bool ffen;
    bool disFcsTx;
    bool disFce;
    bool disDrxb;
    bool phrMode;
    bool phr6M8;
    bool spiCrcen;
    bool ciaIpatov;
    bool ciaSts;
    bool rxwtoe;
    bool rxautr;
    bool autoAck;
    unsigned char cpSpc;
    bool cpSdc;
    unsigned char pdoaMode;
    bool fastAat;
};

class FF_CFG
{
  public:
    bool ffab;
    bool ffad;
    bool ffaa;
    bool ffam;
    bool ffar;
    bool faamulti;
    bool ffaf;
    bool ffae;
    bool ffbc;
    bool ffib;
    bool le0Pend;
    bool le1Pend;
    bool le2Pend;
    bool le3Pend;
    bool ssadrape;
    bool lsadrape;
};

class SPI_RD_CRC
{
  public:
    unsigned char value;
};

class SYS_TIME
{
  public:
    unsigned long value;
};

class TX_FCTRL
{
  public:
    unsigned char finePlen;
    unsigned int txFlen;
    bool txBr;
    bool tr;
    unsigned char txPsr;
    unsigned int txbOffset;
};

class DX_TIME
{
  public:
    unsigned int value;
};

class DREF_TIME
{
  public:
    unsigned int value;
};

class RX_FWTO
{
  public:
    unsigned int value;
};

class SYS_CTR
{
  public:
    unsigned char value;
};

class SYS_ENABLE
{
  public:
    bool arfeEn;
    bool cperrEn;
    bool hpdWarnEn;
    bool rxStoEn;
    bool pllHiloEn;
    bool rCinitEn;
    bool spiRdyEn;
    bool rxPtoEn;
    bool rxOvrrEn;
    bool vWarnEn;
    bool ciaErrEn;
    bool rxFtoEn;
    bool rxRfslEn;
    bool rxFceEn;
    bool rxFcgEn;
    bool rxFrEn;
    bool rxPheEn;
    bool rxPhdEn;
    bool ciaDoneEn;
    bool rxSfddEn;
    bool rxPrdEn;
    bool txFrsEn;
    bool txPhsEn;
    bool txPrsEn;
    bool txFrbEn;
    bool aatEn;
    bool spiCrceEn;
    bool cpLockEn;

    bool ccaFailEn;
    bool spiErrEn;
    bool spiUnfEn;
    bool spiOvfEn;
    bool cmdErrEn;
    bool aesErrEn;
    bool aesDoneEn;
    bool gpioIrqEn;
    bool vtDetEn;
    bool rxPrejEn;
};

class SYS_STATUS
{
  public:
    bool arfe;
    bool cpErr;
    bool hpdWarn;
    bool rxSto;
    bool pllHilo;
    bool rcInit;
    bool spiRdy;
    bool rxPto;
    bool rxoVrr;
    bool vWarn;
    bool ciaErr;
    bool rxFto;
    bool rxFsl;
    bool rxFce;
    bool rxFcg;
    bool rxFr;
    bool rxPhe;
    bool rxPhd;
    bool ciaDone;
    bool rxSfdd;
    bool rxPrd;
    bool txFrs;
    bool txPhs;
    bool txPrs;
    bool txFrb;
    bool aat;
    bool spiCrce;
    bool cpLock;
    bool irqs;
    bool ccaFail;
    bool spierr;
    bool spiUnf;
    bool spiOvf;
    bool cmdErr;
    bool aesErr;
    bool aesDone;
    bool gpioIrq;
    bool vtDet;
    bool rxPrej;
};

class RX_FINFO
{
  public:
    unsigned short rxPacc;
    unsigned char rxPsr;
    unsigned char rxPrf;
    bool rng;
    bool rxBr;
    unsigned char rxNspl;
    unsigned short rxFlen;
};

class RX_TIME
{
  public:
    unsigned long rxStamp;
    unsigned int rxRawst;
};

class TX_TIME
{
  public:
    unsigned long txStamp;
};

class TX_RAWST
{
  public:
    unsigned long value;
};

class TX_ANTD
{
  public:
    unsigned short value;
};

class ACK_RESP_T
{
  public:
    unsigned int w4rTim;
    unsigned char ackTim;
};

class TX_POWER
{
  public:
    unsigned char dataPwr;
    unsigned char phrPwr;
    unsigned char shrPwr;
    unsigned char stsPwr;
};

class CHAN_CTRL
{
  public:
    bool rfChan;
    unsigned char sfdType;
    unsigned char txPcode;
    unsigned char rxPcode;
};

class LE_PEND_01
{
  public:
    unsigned short leAddr0;
    unsigned short lrAddr1;
};

class LE_PEND_23
{
  public:
    unsigned short leAddr2;
    unsigned short lrAddr3;
};

class SPI_COLLISION
{
  public:
    unsigned char spiCollision;
};

class RDB_STATUS
{
  public:
    bool rxfcg0;
    bool rxFr0;
    bool ciaDone0;
    bool cpErr0;
    bool rxFcg1;
    bool rxFr1;
    bool ciaDone1;
    bool cpErr1;
};

class RDB_DIAG
{
  public:
    unsigned char rdbDmode;
};

class AES_CFG
{
  public:
    bool mode;
    unsigned char keySize;
    unsigned char keyAddr;
    bool keyLoad;
    bool keySrc;
    unsigned char tagSize;
    bool coreSel;
    bool keyOpt;
};

class AES_IV0
{
  public:
    unsigned int value;
};

class AES_IV1
{
  public:
    unsigned int value;
};

class AES_IV2
{
  public:
    unsigned int value;
};

class AES_IV3
{
  public:
    unsigned short value;
};

class AES_IV4
{
  public:
    unsigned short value;
};

class DMA_CFG
{
  public:
    unsigned char srcPort;
    unsigned short srcAddr;
    unsigned char dstPort;
    unsigned short dstAddr;
    bool cpEndSel;
    unsigned char hdrSize;
    unsigned char pyldSize;
};

class AES_START
{
  public:
    bool aesStart;
};

class AES_STS
{
  public:
    bool aesDone;
    bool authErr;
    bool transErr;
    bool memConf;
    bool ramEmpty;
    bool ramFull;
};

class AES_KEY
{
  public:
    unsigned char values[16];
};

class STS_CFG
{
  public:
    unsigned char cpsLen;
};

class STS_CTRL
{
  public:
    bool loadIV;
    bool rstLast;
};

class STS_STS
{
  public:
    unsigned short accQual;
};

class STS_KEY
{
  public:
    unsigned char values[16];
};

class STS_IV
{
  public:
    unsigned char values[16];
};

class RX_TUNE
{
    // not configured
};

class DGC_CFG
{
  public:
    bool rxTuneEn;
    unsigned char thr64;
};

class DHC_DBG
{
  public:
    unsigned char dgcDecision;
};

class EX_CTRL
{
  public:
    unsigned char ostsWait;
    bool ostrMode;
};

class RX_CAL
{
  public:
    bool calMode;
    bool calEn;
    unsigned char compDly;
};

class RX_CAL_RESI
{
  public:
    unsigned int value;
};

class RX_CAL_RESQ
{
  public:
    unsigned int value;
};

class RX_CAL_STS
{
  public:
    bool value;
};

class GPIO_MODE
{
  public:
    unsigned char msGp0;
    unsigned char msGp1;
    unsigned char msGp2;
    unsigned char msGp3;
    unsigned char msGp4;
    unsigned char msGp5;
    unsigned char msGp6;
    unsigned char msGp7;
    unsigned char msGp8;
};

class GPIO_PULL_EN
{
  public:
    bool msGp0;
    bool msGp1;
    bool msGp2;
    bool msGp3;
    bool msGp4;
    bool msGp5;
    bool msGp6;
    bool msGp7;
    bool msGp8;
};

class GPIO_DIR
{
  public:
    bool msGp0;
    bool msGp1;
    bool msGp2;
    bool msGp3;
    bool msGp4;
    bool msGp5;
    bool msGp6;
    bool msGp7;
    bool msGp8;
};

class GPIO_OUT
{
  public:
    bool msGp0;
    bool msGp1;
    bool msGp2;
    bool msGp3;
    bool msGp4;
    bool msGp5;
    bool msGp6;
    bool msGp7;
    bool msGp8;
};

class GPIO_IRQE
{
  public:
    bool msGp0;
    bool msGp1;
    bool msGp2;
    bool msGp3;
    bool msGp4;
    bool msGp5;
    bool msGp6;
    bool msGp7;
    bool msGp8;
};

class GPIO_ISTS
{
  public:
    bool msGp0;
    bool msGp1;
    bool msGp2;
    bool msGp3;
    bool msGp4;
    bool msGp5;
    bool msGp6;
    bool msGp7;
    bool msGp8;
};

class GPIO_ISEN
{
  public:
    bool msGp0;
    bool msGp1;
    bool msGp2;
    bool msGp3;
    bool msGp4;
    bool msGp5;
    bool msGp6;
    bool msGp7;
    bool msGp8;
};

class GPIO_IMODE
{
  public:
    bool msGp0;
    bool msGp1;
    bool msGp2;
    bool msGp3;
    bool msGp4;
    bool msGp5;
    bool msGp6;
    bool msGp7;
    bool msGp8;
};

class GPIO_IBES
{
  public:
    bool msGp0;
    bool msGp1;
    bool msGp2;
    bool msGp3;
    bool msGp4;
    bool msGp5;
    bool msGp6;
    bool msGp7;
    bool msGp8;
};

class GPIO_ICLR
{
  public:
    bool msGp0;
    bool msGp1;
    bool msGp2;
    bool msGp3;
    bool msGp4;
    bool msGp5;
    bool msGp6;
    bool msGp7;
    bool msGp8;
};

class GPIO_IDBE
{
  public:
    bool msGp0;
    bool msGp1;
    bool msGp2;
    bool msGp3;
    bool msGp4;
    bool msGp5;
    bool msGp6;
    bool msGp7;
    bool msGp8;
};

class GPIO_RAW
{
  public:
    bool msGp0;
    bool msGp1;
    bool msGp2;
    bool msGp3;
    bool msGp4;
    bool msGp5;
    bool msGp6;
    bool msGp7;
    bool msGp8;
};

class DTUNE_0
{
  public:
    unsigned char pac;
    bool dt0b4;
};

class RX_SFD_TOC
{
  public:
    unsigned short value;
};

class PRE_TOC
{
  public:
    unsigned short value;
};

class DTUNE3
{
  public:
    unsigned int value;
};

class DTUNE5
{
  public:
    unsigned int value;
};

class DRX_CAR_INT
{
  public:
    unsigned long fractionalPart;
    unsigned short portion;
};

class RF_ENABLE
{
  public:
    unsigned int value;
};

class RF_CTRL_MASK
{
  public:
    unsigned int value;
};
class RF_SWITCH
{
  public:
    bool antswNotToggle;
    bool antswPdoaPort;
    bool antSwen;
    unsigned char antSwctrl;
    bool trxSwen;
    unsigned char trxSwctrl;
};

class RF_TX_CTRL_1
{
  public:
    unsigned char value;
};

class RF_TX_CTRL_2
{
  public:
    unsigned char pgDelay;
};

class TX_TEST
{
  public:
    unsigned char txEntest;
};

class SAR_TEST
{
  public:
    bool sarRden;
};

class LDO_TUNE
{
  public:
    unsigned long ldoTune;
};

class LDO_CTRL
{
  public:
    unsigned int ldoCtrl;
};

class LDO_RLOAD
{
  public:
    unsigned char value;
};
// 8.2.8.6
//  0x08 – Transmitter calibration block
class SAR_CTRL
{
  public:
    bool sarStart;
};

class SAR_STATUS
{
  public:
    bool sarDone;
};

class SAR_READING
{
  public:
    unsigned char sarLvbat;
    unsigned char sarLtemp;
};

class SAR_WAKE_RD
{
  public:
    unsigned char sarWvbat;
    unsigned char sarWtemp;
};

class PGC_CTRL
{
  public:
    bool pgStart;
    bool pgcAutoCal;
    unsigned char pgcTmeas;
};

class PGC_STATUS
{
  public:
    unsigned short pgDelayCnt;
    bool autocalDone;
};

class PG_TEST
{
  public:
    unsigned short value;
};

class PG_CAL_TARGET
{
  public:
    unsigned short pgTarget;
};

// 0x09 – Frequency synthesiser control block
class PLL_CFG
{
  public:
    unsigned short value;
};

class PLL_CC
{
  public:
    unsigned char ch9Code;
    unsigned short ch5Code;
};

class PLL_CAL
{
  public:
    bool useOld;
    unsigned char pllCfgLd;
    bool calEn;
};

class XTAL
{
  public:
    unsigned char xtalTrim;
};

// 0x0A – Always-on system control interface
class AON_DIG_CFG
{
  public:
    bool onwAonDld;
    bool onwRunSar;
    bool onwGo2Idle;
    bool onwGo2rx;
    bool onwPgfcal;
};

class AON_CTRL
{
  public:
    bool restore;
    bool save;
    bool cfgUpload;
    bool dcaRead;
    bool dcaWrite;
    bool dcaWriteHi;
    bool dcaEnab;
};

class AON_RDATA
{
  public:
    unsigned char value;
};

class AON_ADDR
{
  public:
    unsigned short value;
};

class AON_WDATA
{
  public:
    unsigned char value;
};

class AON_CFG
{
  public:
    bool sleepEn;
    bool wakeCnt;
    bool broutEn;
    bool wakeCsn;
    bool wakeWup;
    bool presSleep;
};

// 0x0B – OTP memory interface

class OTP_WDATA
{
  public:
    unsigned int value;
};
class OTP_ADDR
{
  public:
    unsigned short otpAddr;
};

class OTP_CFG
{
  public:
    bool otpMan;
    bool otpRead;
    bool otpWrite;
    bool otpWriteMr;
    bool dgcKick;
    bool ldoKick;
    bool biasKick;
    bool opsKick;
    bool opsSel;
    bool dgcSel;
};

class OTP_STAT
{
  public:
    bool otpProgDone;
    bool otpVppOk;
};

class OTP_RDATA
{
  public:
    unsigned int value;
};
class OTP_SRDATA
{
  public:
    unsigned int value;
};

// 0x0C, 0x0D, 0x0E – CIA Interface

class IP_TS
{
  public:
    unsigned long ipToa;
    unsigned short ipPoa;
    unsigned char ipToast;
};

class STS_TS
{
  public:
    unsigned long stsToa;
    unsigned short stsPoa;
    unsigned short stsToast;
};

class STS1_TS
{
  public:
    unsigned long sts1Toa;
    unsigned short sts1Poa;
    unsigned short sts1Toast;
};

class TDOA
{
  public:
    unsigned long value;
};

class PDOA
{
  public:
    unsigned short value;
    bool fpThMd;
};

class CIA_DIAG_0
{
  public:
    unsigned short coePpm;
};

class CIA_DIAG_1
{
  public:
    unsigned int value;
};

class IP_DIAG_0
{
  public:
    unsigned int ipPeaka;
    unsigned short ipPeaki;
};

class IP_DIAG_1
{
  public:
    unsigned int ipCarea;
};

class IP_DIAG_2
{
  public:
    unsigned int ipFp1m;
};

class IP_DIAG_3
{
  public:
    unsigned int ipFp2m;
};

class IP_DIAG_4
{
  public:
    unsigned int ipFp3m;
};

class IP_DIAG_RES1 // not usable
{
  public:
    unsigned int value;
};

class IP_DIAG_8
{
  public:
    unsigned short ipFp;
};

class IP_DIAG_12
{
  public:
    unsigned short ipNacc;
};

class STS_DIAG_0
{
  public:
    unsigned int cpPeaka;
    unsigned short cpPeaki;
};

class STS_DIAG_1
{
  public:
    unsigned short cpCarea;
};

class STS_DIAG_2
{
  public:
    unsigned int cpFp1m;
};

class STS_DIAG_3
{
  public:
    unsigned int cpFp2m;
};

class STS_DIAG_4
{
  public:
    unsigned int cpFp3m;
};

class STS_DIAG_8
{
  public:
    unsigned int cpFp;
};

class STS_DIAG_12
{
  public:
    unsigned int cpNacc;
};

class STS1_DIAG_0
{
  public:
    unsigned int cpPeaka;
    unsigned short cpPeaki;
};

class STS1_DIAG_1
{
  public:
    unsigned short cpCarea;
};

class STS1_DIAG_2
{
  public:
    unsigned int cpFp1m;
};

class STS1_DIAG_3
{
  public:
    unsigned int cpFp2m;
};

class STS1_DIAG_4
{
  public:
    unsigned int cpFp3m;
};

class STS1_DIAG_8
{
  public:
    unsigned int cpFp;
};

class STS1_DIAG_12
{
  public:
    unsigned int cpNacc;
};

class CIA_CONF
{
  public:
    unsigned char rxantd;
    bool mindiag;
};

class FP_CONF
{
  public:
    unsigned char fpAgreedTh;
    unsigned char calTemp;
    bool tcRxdlyEn;
};

class Dwm3000
{
  public:
    DEV_ID *dev_id = new DEV_ID();
    PANADR *panadr = new PANADR();
    SYS_CFG *sysCfg = new SYS_CFG();
    FF_CFG *ffCfg = new FF_CFG();
    SPI_RD_CRC *spiRdCrc = new SPI_RD_CRC();
    SYS_TIME *sysTime = new SYS_TIME();
    TX_FCTRL *txFctrl = new TX_FCTRL();
    DX_TIME *dxTime = new DX_TIME();
    DREF_TIME *drefTime = new DREF_TIME();
    RX_FWTO *rxFwto = new RX_FWTO();
    SYS_CTR *sysCtr = new SYS_CTR();
    SYS_ENABLE *sysEnable = new SYS_ENABLE();
    SYS_STATUS *sysStatus = new SYS_STATUS();
    RX_FINFO *rxFinfo = new RX_FINFO();
    RX_TIME *rxTime = new RX_TIME();

    TX_TIME *txTime = new TX_TIME();
    TX_RAWST *txRawst = new TX_RAWST();
    TX_ANTD *txAntd = new TX_ANTD();
    ACK_RESP_T *ackRespT = new ACK_RESP_T();
    TX_POWER *txPower = new TX_POWER();
    CHAN_CTRL *chanCtrl = new CHAN_CTRL();
    LE_PEND_01 *lePend01 = new LE_PEND_01();
    LE_PEND_23 *lePend23 = new LE_PEND_23();
    SPI_COLLISION *spiCollision = new SPI_COLLISION();
    RDB_STATUS *rdbStatus = new RDB_STATUS();
    RDB_DIAG *rdbDiag = new RDB_DIAG();
    AES_CFG *aesCfg = new AES_CFG();
    AES_IV0 *aesIv0 = new AES_IV0();
    AES_IV1 *aesIv1 = new AES_IV1();
    AES_IV2 *aesIv2 = new AES_IV2();
    AES_IV3 *aesIv3 = new AES_IV3();
    AES_IV4 *aesIv4 = new AES_IV4();
    DMA_CFG *dmaCfg = new DMA_CFG();
    AES_START *aesStart = new AES_START();
    AES_STS *aesSts = new AES_STS();
    AES_KEY *aesKey = new AES_KEY();
    STS_CFG *stsCfg = new STS_CFG();
    STS_CTRL *stsCtrl = new STS_CTRL();
    STS_STS *stsSts = new STS_STS();
    STS_KEY *stsKey = new STS_KEY();
    STS_IV *stsIv = new STS_IV();
    RX_TUNE *rxTune = new RX_TUNE();
    DGC_CFG *dgcCfg = new DGC_CFG();
    DHC_DBG *dhcDbg = new DHC_DBG();
    EX_CTRL *exCtrl = new EX_CTRL();
    RX_CAL *rxCal = new RX_CAL();
    RX_CAL_RESI *rxCalResi = new RX_CAL_RESI();
    RX_CAL_RESQ *rxCalResq = new RX_CAL_RESQ();
    RX_CAL_STS *rxCalSts = new RX_CAL_STS();
    GPIO_MODE *gpioMode = new GPIO_MODE();
    GPIO_PULL_EN *gpioPullEn = new GPIO_PULL_EN();
    GPIO_DIR *gpioDir = new GPIO_DIR();
    GPIO_OUT *gpioOut = new GPIO_OUT();
    GPIO_IRQE *gpioIrqe = new GPIO_IRQE();
    GPIO_ISTS *gpioIsts = new GPIO_ISTS();
    GPIO_ISEN *gpioIsen = new GPIO_ISEN();
    GPIO_IMODE *gpioImode = new GPIO_IMODE();
    GPIO_IBES *gpioIbes = new GPIO_IBES();
    GPIO_ICLR *gpioIclr = new GPIO_ICLR();
    GPIO_IDBE *gpioIdbe = new GPIO_IDBE();
    GPIO_RAW *gpioRaw = new GPIO_RAW();
    DTUNE_0 *dune0 = new DTUNE_0();
    RX_SFD_TOC *rxSfdToc = new RX_SFD_TOC();
    PRE_TOC *preToc = new PRE_TOC();
    DTUNE3 *dune3 = new DTUNE3();
    DTUNE5 *dune5 = new DTUNE5();
    DRX_CAR_INT *drxCarInt = new DRX_CAR_INT();
    RF_ENABLE *rfEnable = new RF_ENABLE();
    RF_CTRL_MASK *rfCtrlMask = new RF_CTRL_MASK();
    RF_SWITCH *rfSwitch = new RF_SWITCH();
    RF_TX_CTRL_1 *rfTxCtrl1 = new RF_TX_CTRL_1();
    RF_TX_CTRL_2 *rfTxCtrl2 = new RF_TX_CTRL_2();
    TX_TEST *txTest = new TX_TEST();
    SAR_TEST *sarTest = new SAR_TEST();
    LDO_TUNE *ldoTune = new LDO_TUNE();
    LDO_CTRL *ldoCtrl = new LDO_CTRL();
    LDO_RLOAD *ldoRload = new LDO_RLOAD();

    Dwm3000()
    {
    }

  private:
    ~Dwm3000()
    {
        delete dev_id;
        delete panadr;
        delete sysCfg;
        delete ffCfg;
        delete spiRdCrc;
        delete sysTime;
        delete txFctrl;
        delete dxTime;
        delete drefTime;
        delete rxFwto;
        delete sysCtr;
        delete sysEnable;
        delete sysStatus;
        delete rxFinfo;
        delete rxTime;
        delete txTime;
        delete txRawst;
        delete txAntd;
        delete ackRespT;
        delete txPower;
        delete chanCtrl;
        delete lePend01;
        delete lePend23;
        delete spiCollision;
        delete rdbStatus;
        delete rdbDiag;
        delete aesCfg;
        delete aesIv0;
        delete aesIv1;
        delete aesIv2;
        delete aesIv3;
        delete aesIv4;
        delete dmaCfg;
        delete aesStart;
        delete aesSts;
        delete aesKey;
        delete stsCfg;
        delete stsCtrl;
        delete stsSts;
        delete stsKey;
        delete stsIv;
        delete rxTune;
        delete dgcCfg;
        delete dhcDbg;
        delete exCtrl;
        delete rxCal;
        delete rxCalResi;
        delete rxCalResq;
        delete rxCalSts;
        delete gpioMode;
        delete gpioPullEn;
        delete gpioDir;
        delete gpioOut;
        delete gpioIrqe;
        delete gpioIsts;
        delete gpioIsen;
        delete gpioImode;
        delete gpioIbes;
        delete gpioIclr;
        delete gpioIdbe;
        delete gpioRaw;
        delete dune0;
        delete rxSfdToc;
        delete preToc;
        delete dune3;
        delete dune5;
        delete drxCarInt;
        delete rfEnable;
        delete rfCtrlMask;
        delete rfSwitch;
        delete rfTxCtrl1;
        delete rfTxCtrl2;
        delete txTest;
        delete sarTest;
        delete ldoTune;
        delete ldoCtrl;
        delete ldoRload;
    }
};