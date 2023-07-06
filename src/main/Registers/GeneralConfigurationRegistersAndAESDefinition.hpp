#pragma once

#include "../RegistryReader.hpp"
#include "ByteDefinition.hpp"

struct DEV_ID_DEF
{
    Registry *registry = new Registry(0x00, 0x00, 4);
    ByteDefinition *rev = new ByteDefinition(0, 4);
    ByteDefinition *ver = new ByteDefinition(4, 4);
    ByteDefinition *model = new ByteDefinition(8, 8);
    ByteDefinition *ridtag = new ByteDefinition(16, 16);
};

extern const DEV_ID_DEF dev_id_def;

struct PANADR_DEF
{
    Registry *registry = new Registry(0x00, 0x0C, 4);
    ByteDefinition *panId = new ByteDefinition(0, 16);
    ByteDefinition *shortAddr = new ByteDefinition(16, 16);
};

extern const PANADR_DEF pandra_def;

struct SYS_CFG_DEF
{
    Registry *registry = new Registry(0x00, 0x10, 4);

    ByteDefinition *ffen = new ByteDefinition(0, 1);
    ByteDefinition *disFcsTx = new ByteDefinition(1, 1);
    ByteDefinition *disFce = new ByteDefinition(2, 1);
    ByteDefinition *disDrxb = new ByteDefinition(3, 1);
    ByteDefinition *phrMode = new ByteDefinition(4, 1);
    ByteDefinition *phr6M8 = new ByteDefinition(5, 1);
    ByteDefinition *spiCrcen = new ByteDefinition(6, 1);
    ByteDefinition *ciaIpatov = new ByteDefinition(7, 1);
    ByteDefinition *ciaSts = new ByteDefinition(8, 1);
    ByteDefinition *rxwtoe = new ByteDefinition(9, 1);
    ByteDefinition *rxautr = new ByteDefinition(10, 1);
    ByteDefinition *autoAck = new ByteDefinition(11, 1);
    ByteDefinition *cpSpc = new ByteDefinition(12, 2);
    ByteDefinition *cpSdc = new ByteDefinition(15, 1);
    ByteDefinition *pdoaMode = new ByteDefinition(16, 2);
    ByteDefinition *fastAat = new ByteDefinition(18, 1);
};

extern const SYS_CFG_DEF sys_cfg_def;

struct FF_CFG_DEF
{
    Registry *registry = new Registry(0x00, 0x14, 2);

    ByteDefinition *ffab = new ByteDefinition(0, 1);
    ByteDefinition *ffad = new ByteDefinition(1, 1);
    ByteDefinition *ffaa = new ByteDefinition(2, 1);
    ByteDefinition *ffam = new ByteDefinition(3, 1);
    ByteDefinition *ffar = new ByteDefinition(4, 1);
    ByteDefinition *faamulti = new ByteDefinition(5, 1);
    ByteDefinition *ffaf = new ByteDefinition(6, 1);
    ByteDefinition *ffae = new ByteDefinition(7, 1);
    ByteDefinition *ffbc = new ByteDefinition(8, 1);
    ByteDefinition *ffib = new ByteDefinition(9, 1);
    ByteDefinition *le0Pend = new ByteDefinition(10, 1);
    ByteDefinition *le1Pend = new ByteDefinition(11, 1);
    ByteDefinition *le2Pend = new ByteDefinition(12, 1);
    ByteDefinition *le3Pend = new ByteDefinition(13, 1);
    ByteDefinition *ssadrape = new ByteDefinition(14, 1);
    ByteDefinition *lsadrape = new ByteDefinition(15, 1);
};

extern const FF_CFG_DEF ff_cfg_def;

struct SPI_RD_CRC_DEF
{
    Registry *registry = new Registry(0x00, 0x18, 1);

    ByteDefinition *value = new ByteDefinition(0, 8);
};

extern const SPI_RD_CRC_DEF spi_rd_crc_def;

struct SYS_TIME_DEF
{
    Registry *registry = new Registry(0x00, 0x1C, 4);

    ByteDefinition *value = new ByteDefinition(0, 32);
};

extern const SYS_TIME_DEF sys_time_def;

struct TX_FCTRL_DEF
{
    Registry *registry = new Registry(0x00, 0x24, 6);

    ByteDefinition *finePlen = new ByteDefinition(8, 8);
    ByteDefinition *txFlen = new ByteDefinition(32, 10);
    ByteDefinition *txBr = new ByteDefinition(42, 1);
    ByteDefinition *tr = new ByteDefinition(43, 1);
    ByteDefinition *txPsr = new ByteDefinition(44, 4);
    ByteDefinition *txbOffset = new ByteDefinition(48, 10);
};

extern const TX_FCTRL_DEF tx_fctrl_def;

struct DX_TIME_DEF
{
    Registry *registry = new Registry(0x00, 0x2C, 4);

    ByteDefinition *value = new ByteDefinition(0, 32);
};

extern const DX_TIME_DEF dx_time_def;

struct DREF_TIME_DEF
{
    Registry *registry = new Registry(0x00, 0x30, 4);

    ByteDefinition *value = new ByteDefinition(0, 32);
};

extern const DREF_TIME_DEF dref_time_def;

struct RX_FWTO_DEF
{
    Registry *registry = new Registry(0x00, 0x34, 3);

    ByteDefinition *value = new ByteDefinition(0, 24);
};

extern const RX_FWTO_DEF rx_fwto_def;

struct SYS_CTR_DEF
{
    Registry *registry = new Registry(0x00, 0x38, 1);

    ByteDefinition *value = new ByteDefinition(0, 8);
};

extern const SYS_CTR_DEF sys_ctr_def;

struct SYS_ENABLE_DEF
{
    Registry *registry = new Registry(0x00, 0x3C, 6);

    ByteDefinition *arfeEn = new ByteDefinition(61, 1);
    ByteDefinition *cperrEn = new ByteDefinition(60, 1);
    ByteDefinition *hpdWarnEn = new ByteDefinition(59, 1);
    ByteDefinition *rxStoEn = new ByteDefinition(58, 1);
    ByteDefinition *pllHiloEn = new ByteDefinition(57, 1);
    ByteDefinition *rCinitEn = new ByteDefinition(56, 1);
    ByteDefinition *spiRdyEn = new ByteDefinition(55, 1);
    ByteDefinition *rxPtoEn = new ByteDefinition(53, 1);
    ByteDefinition *rxOvrrEn = new ByteDefinition(52, 1);
    ByteDefinition *vWarnEn = new ByteDefinition(51, 1);
    ByteDefinition *ciaErrEn = new ByteDefinition(50, 1);
    ByteDefinition *rxFtoEn = new ByteDefinition(49, 1);
    ByteDefinition *rxRfslEn = new ByteDefinition(48, 1);
    ByteDefinition *rxFceEn = new ByteDefinition(47, 1);
    ByteDefinition *rxFcgEn = new ByteDefinition(46, 1);
    ByteDefinition *rxFrEn = new ByteDefinition(45, 1);
    ByteDefinition *rxPheEn = new ByteDefinition(44, 1);
    ByteDefinition *rxPhdEn = new ByteDefinition(43, 1);
    ByteDefinition *ciaDoneEn = new ByteDefinition(42, 1);
    ByteDefinition *rxSfddEn = new ByteDefinition(41, 1);
    ByteDefinition *rxPrdEn = new ByteDefinition(40, 1);
    ByteDefinition *txFrsEn = new ByteDefinition(39, 1);
    ByteDefinition *txPhsEn = new ByteDefinition(38, 1);
    ByteDefinition *txPrsEn = new ByteDefinition(37, 1);
    ByteDefinition *txFrbEn = new ByteDefinition(36, 1);
    ByteDefinition *aatEn = new ByteDefinition(35, 1);
    ByteDefinition *spiCrceEn = new ByteDefinition(34, 1);
    ByteDefinition *cpLockEn = new ByteDefinition(33, 1);
    ByteDefinition *ccaFailEn = new ByteDefinition(12, 1);
    ByteDefinition *spiErrEn = new ByteDefinition(11, 1);
    ByteDefinition *spiUnfEn = new ByteDefinition(10, 1);
    ByteDefinition *spiOvfEn = new ByteDefinition(9, 1);
    ByteDefinition *cmdErrEn = new ByteDefinition(8, 1);
    ByteDefinition *aesErrEn = new ByteDefinition(7, 1);
    ByteDefinition *aesDoneEn = new ByteDefinition(6, 1);
    ByteDefinition *gpioIrqEn = new ByteDefinition(5, 1);
    ByteDefinition *vtDetEn = new ByteDefinition(4, 1);
    ByteDefinition *rxPrejEn = new ByteDefinition(1, 1);
};

extern const SYS_ENABLE_DEF sys_enable_def;

struct SYS_STATUS_DEF
{
    Registry *registry = new Registry(0x00, 0x44, 6);

    ByteDefinition *arfe = new ByteDefinition(61, 1);
    ByteDefinition *cpErr = new ByteDefinition(60, 1);
    ByteDefinition *hpdWarn = new ByteDefinition(59, 1);
    ByteDefinition *rxSto = new ByteDefinition(58, 1);
    ByteDefinition *pllHilo = new ByteDefinition(57, 1);
    ByteDefinition *rcInit = new ByteDefinition(56, 1);
    ByteDefinition *spiRdy = new ByteDefinition(55, 1);
    ByteDefinition *rxPto = new ByteDefinition(53, 1);
    ByteDefinition *rxoVrr = new ByteDefinition(52, 1);
    ByteDefinition *vWarn = new ByteDefinition(51, 1);
    ByteDefinition *ciaErr = new ByteDefinition(50, 1);
    ByteDefinition *rxFto = new ByteDefinition(49, 1);
    ByteDefinition *rxFsl = new ByteDefinition(48, 1);
    ByteDefinition *rxFce = new ByteDefinition(47, 1);
    ByteDefinition *rxFcg = new ByteDefinition(46, 1);
    ByteDefinition *rxFr = new ByteDefinition(45, 1);
    ByteDefinition *rxPhe = new ByteDefinition(44, 1);
    ByteDefinition *rxPhd = new ByteDefinition(43, 1);
    ByteDefinition *ciaDone = new ByteDefinition(42, 1);
    ByteDefinition *rxSfdd = new ByteDefinition(41, 1);
    ByteDefinition *rxPrd = new ByteDefinition(40, 1);
    ByteDefinition *txFrs = new ByteDefinition(39, 1);
    ByteDefinition *txPhs = new ByteDefinition(38, 1);
    ByteDefinition *txPrs = new ByteDefinition(37, 1);
    ByteDefinition *txFrb = new ByteDefinition(36, 1);
    ByteDefinition *aat = new ByteDefinition(35, 1);
    ByteDefinition *spiCrce = new ByteDefinition(34, 1);
    ByteDefinition *cpLock = new ByteDefinition(33, 1);
    ByteDefinition *irqs = new ByteDefinition(32, 1);
    ByteDefinition *ccaFail = new ByteDefinition(12, 1);
    ByteDefinition *spierr = new ByteDefinition(11, 1);
    ByteDefinition *spiUnf = new ByteDefinition(10, 1);
    ByteDefinition *spiOvf = new ByteDefinition(9, 1);
    ByteDefinition *cmdErr = new ByteDefinition(8, 1);
    ByteDefinition *aesErr = new ByteDefinition(7, 1);
    ByteDefinition *aesDone = new ByteDefinition(6, 1);
    ByteDefinition *gpioIrq = new ByteDefinition(5, 1);
    ByteDefinition *vtDet = new ByteDefinition(4, 1);
    ByteDefinition *rxPrej = new ByteDefinition(1, 1);
};
extern const SYS_STATUS_DEF sys_status_def;

struct RX_FINFO_DEF
{
    Registry *registry = new Registry(0x00, 0x4C, 4);
    ByteDefinition *rxPacc = new ByteDefinition(20, 12);
    ByteDefinition *rxPsr = new ByteDefinition(18, 2);
    ByteDefinition *rxPrf = new ByteDefinition(16, 2);
    ByteDefinition *rng = new ByteDefinition(15, 1);
    ByteDefinition *rxBr = new ByteDefinition(13, 1);
    ByteDefinition *rxNspl = new ByteDefinition(11, 2);
    ByteDefinition *rxFlen = new ByteDefinition(0, 10);
};
extern const RX_FINFO_DEF rx_finfo_def;

struct RX_TIME_DEF
{
    Registry *registry = new Registry(0x00, 0x64, 16);
    ByteDefinition *rxStamp = new ByteDefinition(0, 40);
    ByteDefinition *rxRawst = new ByteDefinition(63, 32);
};
extern const RX_TIME_DEF rx_time_def;

struct TX_TIME_DEF
{
    Registry *registry = new Registry(0x00, 0x74, 5);
    ByteDefinition *txStamp = new ByteDefinition(0, 40);
};

extern const TX_TIME_DEF tx_time_def;

struct TX_RAWST_DEF
{
    Registry *registry = new Registry(0x01, 0x00, 4);
    ByteDefinition *value = new ByteDefinition(0, 32);
};

extern const TX_RAWST_DEF tx_rawst_def;

struct TX_ANTD_DEF
{
    Registry *registry = new Registry(0x01, 0x04, 2);
    ByteDefinition *value = new ByteDefinition(0, 16);
};

extern const TX_ANTD_DEF tx_antd_def;

struct ACK_RESP_T_DEF
{
    Registry *registry = new Registry(0x01, 0x08, 4);
    ByteDefinition *w4rTim = new ByteDefinition(0, 20);
    ByteDefinition *ackTim = new ByteDefinition(24, 8);
};

extern const ACK_RESP_T_DEF ack_resp_t_def;

struct TX_POWER_DEF
{
    Registry *registry = new Registry(0x01, 0x0C, 4);
    ByteDefinition *dataPwr = new ByteDefinition(0, 8);
    ByteDefinition *phrPwr = new ByteDefinition(8, 8);
    ByteDefinition *shrPwr = new ByteDefinition(16, 8);
    ByteDefinition *stsPwr = new ByteDefinition(24, 8);
};

extern const TX_POWER_DEF tx_power_def;

struct CHAN_CTRL_DEF
{
    Registry *registry = new Registry(0x01, 0x14, 2);
    ByteDefinition *rfChan = new ByteDefinition(0, 1);
    ByteDefinition *sfdType = new ByteDefinition(1, 2);
    ByteDefinition *txPcode = new ByteDefinition(3, 5);
    ByteDefinition *rxPcode = new ByteDefinition(8, 5);
};

extern const CHAN_CTRL_DEF chan_ctrl_def;

struct LE_PEND_01_DEF
{
    Registry *registry = new Registry(0x01, 0x18, 4);
    ByteDefinition *leAddr0 = new ByteDefinition(0, 16);
    ByteDefinition *lrAddr1 = new ByteDefinition(16, 16);
};

extern const LE_PEND_01_DEF le_pend_01_def;

struct LE_PEND_23_DEF
{
    Registry *registry = new Registry(0x01, 0x18, 4);
    ByteDefinition *leAddr2 = new ByteDefinition(0, 16);
    ByteDefinition *lrAddr3 = new ByteDefinition(16, 16);
};

extern const LE_PEND_23_DEF le_pend_23_def;

struct SPI_COLLISION_DEF
{
    Registry *registry = new Registry(0x01, 0x20, 1);
    ByteDefinition *spiCollision = new ByteDefinition(0, 5);
};

extern const SPI_COLLISION_DEF spi_collision_def;

struct RDB_STATUS_DEF
{
    Registry *registry = new Registry(0x01, 0x24, 1);
    ByteDefinition *rxfcg0 = new ByteDefinition(0, 1);
    ByteDefinition *rxFr0 = new ByteDefinition(1, 1);
    ByteDefinition *ciaDone0 = new ByteDefinition(2, 1);
    ByteDefinition *cpErr0 = new ByteDefinition(3, 1);
    ByteDefinition *rxFcg1 = new ByteDefinition(4, 1);
    ByteDefinition *rxFr1 = new ByteDefinition(5, 1);
    ByteDefinition *ciaDone1 = new ByteDefinition(6, 1);
    ByteDefinition *cpErr1 = new ByteDefinition(7, 1);
};

extern const RDB_STATUS_DEF rdb_status_def;

struct RDB_DIAG_DEF
{
    Registry *registry = new Registry(0x01, 0x28, 1);
    ByteDefinition *rdbDmode = new ByteDefinition(0, 3);
};

extern const RDB_DIAG_DEF rdb_diag_def;

struct AES_CFG_DEF
{
    Registry *registry = new Registry(0x01, 0x30, 2);
    ByteDefinition *mode = new ByteDefinition(0, 1);
    ByteDefinition *keySize = new ByteDefinition(1, 2);
    ByteDefinition *keyAddr = new ByteDefinition(3, 3);
    ByteDefinition *keyLoad = new ByteDefinition(6, 1);
    ByteDefinition *keySrc = new ByteDefinition(7, 1);
    ByteDefinition *tagSize = new ByteDefinition(8, 3);
    ByteDefinition *coreSel = new ByteDefinition(11, 1);
    ByteDefinition *keyOpt = new ByteDefinition(12, 1);
};

extern const AES_CFG_DEF aes_cfg_def;

struct AES_IV0_DEF
{
    Registry *registry = new Registry(0x01, 34, 4);
    ByteDefinition *value = new ByteDefinition(0, 32);
};
extern const AES_IV0_DEF aes_iv0_def;

struct AES_IV1_DEF
{
    Registry *registry = new Registry(0x01, 38, 4);
    ByteDefinition *value = new ByteDefinition(0, 32);
};
extern const AES_IV1_DEF aes_iv1_def;

struct AES_IV2_DEF
{
    Registry *registry = new Registry(0x01, 0x3C, 4);
    ByteDefinition *value = new ByteDefinition(0, 32);
};
extern const AES_IV2_DEF aes_iv2_def;

struct AES_IV3_DEF
{
    Registry *registry = new Registry(0x01, 0x40, 2);
    ByteDefinition *value = new ByteDefinition(0, 16);
};
extern const AES_IV3_DEF aes_iv3_def;

struct AES_IV4_DEF
{
    Registry *registry = new Registry(0x01, 0x42, 2);
    ByteDefinition *value = new ByteDefinition(0, 16);
};
extern const AES_IV4_DEF aes_iv4_def;

struct DMA_CFG_DEF
{
    Registry *registry = new Registry(0x01, 0x44, 8);
    ByteDefinition *srcPort = new ByteDefinition(0, 3);
    ByteDefinition *srcAddr = new ByteDefinition(3, 10);
    ByteDefinition *dstPort = new ByteDefinition(13, 3);
    ByteDefinition *dstAddr = new ByteDefinition(16, 10);
    ByteDefinition *cpEndSel = new ByteDefinition(26, 1);
    ByteDefinition *hdrSize = new ByteDefinition(32, 7);
    ByteDefinition *pyldSize = new ByteDefinition(39, 10);
};

extern const DMA_CFG_DEF dma_cfg_def;

struct AES_START_DEF
{
    Registry *registry = new Registry(0x01, 0x4C, 1);
    ByteDefinition *aesStart = new ByteDefinition(0, 1);
};

extern const AES_START_DEF aes_start_def;

struct AES_STS_DEF
{
    Registry *registry = new Registry(0x01, 0x50, 4);
    ByteDefinition *aesDone = new ByteDefinition(0, 1);
    ByteDefinition *authErr = new ByteDefinition(1, 1);
    ByteDefinition *transErr = new ByteDefinition(2, 1);
    ByteDefinition *memConf = new ByteDefinition(3, 1);
    ByteDefinition *ramEmpty = new ByteDefinition(4, 1);
    ByteDefinition *ramFull = new ByteDefinition(5, 1);
};

extern const AES_STS_DEF aes_sts_def;

struct AES_KEY_DEF
{
    Registry *registry = new Registry(0x01, 0x54, 16);
    ByteDefinition *values = new ByteDefinition(0, 128);
};

extern const AES_KEY_DEF aes_key_def;