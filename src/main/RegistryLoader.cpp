
#include "RegistryLoader.hpp"

#include "Registers/RegistersDefinition.hpp"
#include "RegistryReader.hpp"
#include <iostream>

long extractValue(ReadedRegistryData readedRegistryData, ByteDefinition *byteDefinition)
{
    int startByteIndex = byteDefinition->index / 8;
    int startBitOffset = byteDefinition->index % 8;

    long extractedChar = 0;
    for (int i = 0; i < byteDefinition->size; ++i)
    {
        int bitIndex = startBitOffset + i;
        int byteIndex = startByteIndex + bitIndex / 8;
        int bitOffset = bitIndex % 8;

        bool bitValue = (readedRegistryData.dataBuffor[byteIndex] >> bitOffset) & 1;
        extractedChar |= (bitValue << i);
    }

    return extractedChar;
}

void extractBigValues(
    ReadedRegistryData readedRegistryData,
    ByteDefinition *byteDefinition,
    unsigned char *charTable)
{
    int outputIndex = 0;

    for (int i = byteDefinition->index; i < byteDefinition->index + byteDefinition->size; ++i)
    {
        int byteIndex = i / 8;
        int bitOffset = i % 8;

        bool bitValue = (readedRegistryData.dataBuffor[byteIndex] >> bitOffset) & 1;
        charTable[outputIndex / 8] |= (bitValue << (outputIndex % 8));

        outputIndex++;
    }
}

bool dataExtractorBool(ReadedRegistryData readedRegistryData, ByteDefinition *byteDefinition)
{
    return static_cast<bool>(extractValue(readedRegistryData, byteDefinition));
}

unsigned char dataExtractorChar(ReadedRegistryData readedRegistryData, ByteDefinition *byteDefinition)
{
    return static_cast<unsigned char>(extractValue(readedRegistryData, byteDefinition));
}

unsigned int dataExtractorInt(ReadedRegistryData readedRegistryData, ByteDefinition *byteDefinition)
{
    return static_cast<unsigned int>(extractValue(readedRegistryData, byteDefinition));
}

unsigned short dataExtractorShort(ReadedRegistryData readedRegistryData, ByteDefinition *byteDefinition)
{
    return static_cast<unsigned short>(extractValue(readedRegistryData, byteDefinition));
}

unsigned long dataExtractorLong(ReadedRegistryData readedRegistryData, ByteDefinition *byteDefinition)
{
    return static_cast<unsigned long>(extractValue(readedRegistryData, byteDefinition));
}
void load(DEV_ID *devId)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(dev_id_def.registry));

    devId->rev = dataExtractorChar(readedValue, dev_id_def.rev);
    devId->ver = dataExtractorChar(readedValue, dev_id_def.ver);
    devId->model = dataExtractorChar(readedValue, dev_id_def.model);
    devId->ridtag = dataExtractorChar(readedValue, dev_id_def.ridtag);
    delete readedValue.dataBuffor;
}

void load(PANADR *pandra)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(pandra_def.registry));

    pandra->panId = dataExtractorInt(readedValue, pandra_def.panId);
    pandra->shortAddr = dataExtractorInt(readedValue, pandra_def.shortAddr);

    delete readedValue.dataBuffor;
}

void load(SYS_CFG *sys_cfg)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(sys_cfg_def.registry));

    sys_cfg->ffen = dataExtractorBool(readedValue, sys_cfg_def.ffen);
    sys_cfg->disFcsTx = dataExtractorBool(readedValue, sys_cfg_def.disFcsTx);
    sys_cfg->disFce = dataExtractorBool(readedValue, sys_cfg_def.disFce);
    sys_cfg->disDrxb = dataExtractorBool(readedValue, sys_cfg_def.disDrxb);
    sys_cfg->phrMode = dataExtractorBool(readedValue, sys_cfg_def.phrMode);
    sys_cfg->phr6M8 = dataExtractorBool(readedValue, sys_cfg_def.phr6M8);
    sys_cfg->spiCrcen = dataExtractorBool(readedValue, sys_cfg_def.spiCrcen);
    sys_cfg->ciaIpatov = dataExtractorBool(readedValue, sys_cfg_def.ciaIpatov);
    sys_cfg->ciaSts = dataExtractorBool(readedValue, sys_cfg_def.ciaSts);
    sys_cfg->rxwtoe = dataExtractorBool(readedValue, sys_cfg_def.rxwtoe);
    sys_cfg->rxautr = dataExtractorBool(readedValue, sys_cfg_def.rxautr);
    sys_cfg->autoAck = dataExtractorBool(readedValue, sys_cfg_def.autoAck);
    sys_cfg->cpSpc = dataExtractorChar(readedValue, sys_cfg_def.cpSpc);
    sys_cfg->cpSdc = dataExtractorBool(readedValue, sys_cfg_def.cpSdc);
    sys_cfg->pdoaMode = dataExtractorChar(readedValue, sys_cfg_def.pdoaMode);
    sys_cfg->fastAat = dataExtractorBool(readedValue, sys_cfg_def.fastAat);

    delete readedValue.dataBuffor;
}

void load(FF_CFG *ffCfg)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(ff_cfg_def.registry));
    ffCfg->ffab = dataExtractorBool(readedValue, ff_cfg_def.ffab);
    ffCfg->ffad = dataExtractorBool(readedValue, ff_cfg_def.ffad);
    ffCfg->ffaa = dataExtractorBool(readedValue, ff_cfg_def.ffaa);
    ffCfg->ffam = dataExtractorBool(readedValue, ff_cfg_def.ffam);
    ffCfg->ffar = dataExtractorBool(readedValue, ff_cfg_def.ffar);
    ffCfg->faamulti = dataExtractorBool(readedValue, ff_cfg_def.faamulti);
    ffCfg->ffaf = dataExtractorBool(readedValue, ff_cfg_def.ffaf);
    ffCfg->ffae = dataExtractorBool(readedValue, ff_cfg_def.ffae);
    ffCfg->ffbc = dataExtractorBool(readedValue, ff_cfg_def.ffbc);
    ffCfg->ffib = dataExtractorBool(readedValue, ff_cfg_def.ffib);
    ffCfg->le0Pend = dataExtractorBool(readedValue, ff_cfg_def.le0Pend);
    ffCfg->le1Pend = dataExtractorBool(readedValue, ff_cfg_def.le1Pend);
    ffCfg->le2Pend = dataExtractorBool(readedValue, ff_cfg_def.le2Pend);
    ffCfg->le3Pend = dataExtractorBool(readedValue, ff_cfg_def.le3Pend);
    ffCfg->ssadrape = dataExtractorBool(readedValue, ff_cfg_def.ssadrape);
    ffCfg->lsadrape = dataExtractorBool(readedValue, ff_cfg_def.lsadrape);

    delete readedValue.dataBuffor;
}
void load(SPI_RD_CRC *spiRdCrc)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(spi_rd_crc_def.registry));
    spiRdCrc->value = dataExtractorLong(readedValue, spi_rd_crc_def.value);

    delete readedValue.dataBuffor;
}

void load(SYS_TIME *sysTime)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(sys_time_def.registry));
    sysTime->value = dataExtractorLong(readedValue, sys_time_def.value);

    delete readedValue.dataBuffor;
}

void load(TX_FCTRL *txFctrl)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(spi_rd_crc_def.registry));
    txFctrl->finePlen = dataExtractorChar(readedValue, tx_fctrl_def.finePlen);
    txFctrl->txFlen = dataExtractorInt(readedValue, tx_fctrl_def.txFlen);
    txFctrl->txBr = dataExtractorBool(readedValue, tx_fctrl_def.txBr);
    txFctrl->tr = dataExtractorBool(readedValue, tx_fctrl_def.tr);
    txFctrl->txPsr = dataExtractorChar(readedValue, tx_fctrl_def.txPsr);
    txFctrl->txbOffset = dataExtractorInt(readedValue, tx_fctrl_def.txbOffset);

    delete readedValue.dataBuffor;
}

void load(DX_TIME *dxTime)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(dx_time_def.registry));
    dxTime->value = dataExtractorLong(readedValue, dx_time_def.value);

    delete readedValue.dataBuffor;
}
void load(DREF_TIME *drefTime)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(dref_time_def.registry));
    drefTime->value = dataExtractorLong(readedValue, dref_time_def.value);

    delete readedValue.dataBuffor;
}
void load(RX_FWTO *rxFwto)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rx_fwto_def.registry));
    rxFwto->value = dataExtractorLong(readedValue, rx_fwto_def.value);

    delete readedValue.dataBuffor;
}
void load(SYS_CTR *sysCtr)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(sys_ctr_def.registry));
    sysCtr->value = dataExtractorLong(readedValue, sys_ctr_def.value);

    delete readedValue.dataBuffor;
}

void load(SYS_ENABLE *sysEnable)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(sys_enable_def.registry));

    sysEnable->arfeEn = dataExtractorBool(readedValue, sys_enable_def.arfeEn);
    sysEnable->cperrEn = dataExtractorBool(readedValue, sys_enable_def.cperrEn);
    sysEnable->hpdWarnEn = dataExtractorBool(readedValue, sys_enable_def.hpdWarnEn);
    sysEnable->rxStoEn = dataExtractorBool(readedValue, sys_enable_def.rxStoEn);
    sysEnable->pllHiloEn = dataExtractorBool(readedValue, sys_enable_def.pllHiloEn);
    sysEnable->rCinitEn = dataExtractorBool(readedValue, sys_enable_def.rCinitEn);
    sysEnable->spiRdyEn = dataExtractorBool(readedValue, sys_enable_def.spiRdyEn);
    sysEnable->rxPtoEn = dataExtractorBool(readedValue, sys_enable_def.rxPtoEn);
    sysEnable->rxOvrrEn = dataExtractorBool(readedValue, sys_enable_def.rxOvrrEn);
    sysEnable->vWarnEn = dataExtractorBool(readedValue, sys_enable_def.vWarnEn);
    sysEnable->ciaErrEn = dataExtractorBool(readedValue, sys_enable_def.ciaErrEn);
    sysEnable->rxFtoEn = dataExtractorBool(readedValue, sys_enable_def.rxFtoEn);
    sysEnable->rxRfslEn = dataExtractorBool(readedValue, sys_enable_def.rxRfslEn);
    sysEnable->rxFceEn = dataExtractorBool(readedValue, sys_enable_def.rxFceEn);
    sysEnable->rxFcgEn = dataExtractorBool(readedValue, sys_enable_def.rxFcgEn);
    sysEnable->rxFrEn = dataExtractorBool(readedValue, sys_enable_def.rxFrEn);
    sysEnable->rxPheEn = dataExtractorBool(readedValue, sys_enable_def.rxPheEn);
    sysEnable->rxPhdEn = dataExtractorBool(readedValue, sys_enable_def.rxPhdEn);
    sysEnable->ciaDoneEn = dataExtractorBool(readedValue, sys_enable_def.ciaDoneEn);
    sysEnable->rxSfddEn = dataExtractorBool(readedValue, sys_enable_def.rxSfddEn);
    sysEnable->rxPrdEn = dataExtractorBool(readedValue, sys_enable_def.rxPrdEn);
    sysEnable->txFrsEn = dataExtractorBool(readedValue, sys_enable_def.txFrsEn);
    sysEnable->txPhsEn = dataExtractorBool(readedValue, sys_enable_def.txPhsEn);
    sysEnable->txPrsEn = dataExtractorBool(readedValue, sys_enable_def.txPrsEn);
    sysEnable->txFrbEn = dataExtractorBool(readedValue, sys_enable_def.txFrbEn);
    sysEnable->aatEn = dataExtractorBool(readedValue, sys_enable_def.aatEn);
    sysEnable->spiCrceEn = dataExtractorBool(readedValue, sys_enable_def.spiCrceEn);
    sysEnable->cpLockEn = dataExtractorBool(readedValue, sys_enable_def.cpLockEn);
    sysEnable->ccaFailEn = dataExtractorBool(readedValue, sys_enable_def.ccaFailEn);
    sysEnable->spiErrEn = dataExtractorBool(readedValue, sys_enable_def.spiErrEn);
    sysEnable->spiUnfEn = dataExtractorBool(readedValue, sys_enable_def.spiUnfEn);
    sysEnable->spiOvfEn = dataExtractorBool(readedValue, sys_enable_def.spiOvfEn);
    sysEnable->cmdErrEn = dataExtractorBool(readedValue, sys_enable_def.cmdErrEn);
    sysEnable->aesErrEn = dataExtractorBool(readedValue, sys_enable_def.aesErrEn);
    sysEnable->aesDoneEn = dataExtractorBool(readedValue, sys_enable_def.aesDoneEn);
    sysEnable->gpioIrqEn = dataExtractorBool(readedValue, sys_enable_def.gpioIrqEn);
    sysEnable->vtDetEn = dataExtractorBool(readedValue, sys_enable_def.vtDetEn);
    sysEnable->rxPrejEn = dataExtractorBool(readedValue, sys_enable_def.rxPrejEn);

    delete readedValue.dataBuffor;
}

void load(SYS_STATUS *sysStatus)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(sys_status_def.registry));

    sysStatus->arfe = dataExtractorBool(readedValue, sys_status_def.arfe);
    sysStatus->cpErr = dataExtractorBool(readedValue, sys_status_def.cpErr);
    sysStatus->hpdWarn = dataExtractorBool(readedValue, sys_status_def.hpdWarn);
    sysStatus->rxSto = dataExtractorBool(readedValue, sys_status_def.rxSto);
    sysStatus->pllHilo = dataExtractorBool(readedValue, sys_status_def.pllHilo);
    sysStatus->rcInit = dataExtractorBool(readedValue, sys_status_def.rcInit);
    sysStatus->spiRdy = dataExtractorBool(readedValue, sys_status_def.spiRdy);
    sysStatus->rxPto = dataExtractorBool(readedValue, sys_status_def.rxPto);
    sysStatus->rxoVrr = dataExtractorBool(readedValue, sys_status_def.rxoVrr);
    sysStatus->vWarn = dataExtractorBool(readedValue, sys_status_def.vWarn);
    sysStatus->ciaErr = dataExtractorBool(readedValue, sys_status_def.ciaErr);
    sysStatus->rxFto = dataExtractorBool(readedValue, sys_status_def.rxFto);
    sysStatus->rxFsl = dataExtractorBool(readedValue, sys_status_def.rxFsl);
    sysStatus->rxFce = dataExtractorBool(readedValue, sys_status_def.rxFce);
    sysStatus->rxFcg = dataExtractorBool(readedValue, sys_status_def.rxFcg);
    sysStatus->rxFr = dataExtractorBool(readedValue, sys_status_def.rxFr);
    sysStatus->rxPhe = dataExtractorBool(readedValue, sys_status_def.rxPhe);
    sysStatus->rxPhd = dataExtractorBool(readedValue, sys_status_def.rxPhd);
    sysStatus->ciaDone = dataExtractorBool(readedValue, sys_status_def.ciaDone);
    sysStatus->rxSfdd = dataExtractorBool(readedValue, sys_status_def.rxSfdd);
    sysStatus->rxPrd = dataExtractorBool(readedValue, sys_status_def.rxPrd);
    sysStatus->txFrs = dataExtractorBool(readedValue, sys_status_def.txFrs);
    sysStatus->txPhs = dataExtractorBool(readedValue, sys_status_def.txPhs);
    sysStatus->txPrs = dataExtractorBool(readedValue, sys_status_def.txPrs);
    sysStatus->txFrb = dataExtractorBool(readedValue, sys_status_def.txFrb);
    sysStatus->aat = dataExtractorBool(readedValue, sys_status_def.aat);
    sysStatus->spiCrce = dataExtractorBool(readedValue, sys_status_def.spiCrce);
    sysStatus->cpLock = dataExtractorBool(readedValue, sys_status_def.cpLock);
    sysStatus->irqs = dataExtractorBool(readedValue, sys_status_def.irqs);
    sysStatus->ccaFail = dataExtractorBool(readedValue, sys_status_def.ccaFail);
    sysStatus->spierr = dataExtractorBool(readedValue, sys_status_def.spierr);
    sysStatus->spiUnf = dataExtractorBool(readedValue, sys_status_def.spiUnf);
    sysStatus->spiOvf = dataExtractorBool(readedValue, sys_status_def.spiOvf);
    sysStatus->cmdErr = dataExtractorBool(readedValue, sys_status_def.cmdErr);
    sysStatus->aesErr = dataExtractorBool(readedValue, sys_status_def.aesErr);
    sysStatus->aesDone = dataExtractorBool(readedValue, sys_status_def.aesDone);
    sysStatus->gpioIrq = dataExtractorBool(readedValue, sys_status_def.gpioIrq);
    sysStatus->vtDet = dataExtractorBool(readedValue, sys_status_def.vtDet);
    sysStatus->rxPrej = dataExtractorBool(readedValue, sys_status_def.rxPrej);

    delete readedValue.dataBuffor;
}

void load(RX_FINFO *rxFinfo)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rx_finfo_def.registry));
    rxFinfo->rxPacc = dataExtractorShort(readedValue, rx_finfo_def.rxPacc);
    rxFinfo->rxPsr = dataExtractorChar(readedValue, rx_finfo_def.rxPsr);
    rxFinfo->rxPrf = dataExtractorChar(readedValue, rx_finfo_def.rxPrf);
    rxFinfo->rng = dataExtractorBool(readedValue, rx_finfo_def.rng);
    rxFinfo->rxBr = dataExtractorBool(readedValue, rx_finfo_def.rxBr);
    rxFinfo->rxNspl = dataExtractorChar(readedValue, rx_finfo_def.rxNspl);
    rxFinfo->rxFlen = dataExtractorShort(readedValue, rx_finfo_def.rxFlen);

    delete readedValue.dataBuffor;
}

void load(RX_TIME *rxTime)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rx_time_def.registry));
    rxTime->rxStamp = dataExtractorLong(readedValue, rx_time_def.rxStamp);
    rxTime->rxRawst = dataExtractorLong(readedValue, rx_time_def.rxRawst);

    delete readedValue.dataBuffor;
}

void load(TX_TIME *txTime)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(tx_time_def.registry));
    txTime->txStamp = dataExtractorLong(readedValue, tx_time_def.txStamp);

    delete readedValue.dataBuffor;
}

void load(TX_RAWST *txRawst)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(tx_rawst_def.registry));
    txRawst->value = dataExtractorLong(readedValue, tx_rawst_def.value);

    delete readedValue.dataBuffor;
}

void load(TX_ANTD *tx_antd)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(tx_antd_def.registry));
    tx_antd->value = dataExtractorShort(readedValue, tx_antd_def.value);

    delete readedValue.dataBuffor;
}

void load(ACK_RESP_T *ackRespT)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(ack_resp_t_def.registry));
    ackRespT->w4rTim = dataExtractorInt(readedValue, ack_resp_t_def.w4rTim);
    ackRespT->ackTim = dataExtractorChar(readedValue, ack_resp_t_def.ackTim);

    delete readedValue.dataBuffor;
}

void load(TX_POWER *txPower)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(tx_power_def.registry));
    txPower->dataPwr = dataExtractorInt(readedValue, tx_power_def.dataPwr);
    txPower->phrPwr = dataExtractorChar(readedValue, tx_power_def.phrPwr);
    txPower->shrPwr = dataExtractorInt(readedValue, tx_power_def.shrPwr);
    txPower->stsPwr = dataExtractorChar(readedValue, tx_power_def.stsPwr);

    delete readedValue.dataBuffor;
}

void load(CHAN_CTRL *chanCtrl)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(chan_ctrl_def.registry));
    chanCtrl->rfChan = dataExtractorBool(readedValue, chan_ctrl_def.rfChan);
    chanCtrl->sfdType = dataExtractorChar(readedValue, chan_ctrl_def.sfdType);
    chanCtrl->txPcode = dataExtractorChar(readedValue, chan_ctrl_def.txPcode);
    chanCtrl->rxPcode = dataExtractorChar(readedValue, chan_ctrl_def.rxPcode);

    delete readedValue.dataBuffor;
}

void load(LE_PEND_01 *lePend01)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(le_pend_01_def.registry));
    lePend01->leAddr0 = dataExtractorShort(readedValue, le_pend_01_def.leAddr0);
    lePend01->lrAddr1 = dataExtractorShort(readedValue, le_pend_01_def.lrAddr1);

    delete readedValue.dataBuffor;
}

void load(LE_PEND_23 *lePend23)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(le_pend_23_def.registry));
    lePend23->leAddr2 = dataExtractorShort(readedValue, le_pend_23_def.leAddr2);
    lePend23->lrAddr3 = dataExtractorShort(readedValue, le_pend_23_def.lrAddr3);

    delete readedValue.dataBuffor;
}

void load(SPI_COLLISION *spiCollision)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(spi_collision_def.registry));
    spiCollision->spiCollision = dataExtractorChar(readedValue, spi_collision_def.spiCollision);

    delete readedValue.dataBuffor;
}

void load(RDB_STATUS *rdbStatus)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rdb_status_def.registry));
    rdbStatus->rxfcg0 = dataExtractorBool(readedValue, rdb_status_def.rxfcg0);
    rdbStatus->rxFr0 = dataExtractorBool(readedValue, rdb_status_def.rxFr0);
    rdbStatus->ciaDone0 = dataExtractorBool(readedValue, rdb_status_def.ciaDone0);
    rdbStatus->cpErr0 = dataExtractorBool(readedValue, rdb_status_def.cpErr0);
    rdbStatus->rxFcg1 = dataExtractorBool(readedValue, rdb_status_def.rxFcg1);
    rdbStatus->rxFr1 = dataExtractorBool(readedValue, rdb_status_def.rxFr1);
    rdbStatus->ciaDone1 = dataExtractorBool(readedValue, rdb_status_def.ciaDone1);
    rdbStatus->cpErr1 = dataExtractorBool(readedValue, rdb_status_def.cpErr1);

    delete readedValue.dataBuffor;
}

void load(RDB_DIAG *rdbDiag)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rdb_status_def.registry));
    rdbDiag->rdbDmode = dataExtractorChar(readedValue, rdb_status_def.rxfcg0);

    delete readedValue.dataBuffor;
}

void load(AES_CFG *aesCfg)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(aes_cfg_def.registry));
    aesCfg->mode = dataExtractorBool(readedValue, aes_cfg_def.mode);
    aesCfg->keySize = dataExtractorChar(readedValue, aes_cfg_def.keySize);
    aesCfg->keyAddr = dataExtractorChar(readedValue, aes_cfg_def.keyAddr);
    aesCfg->keyLoad = dataExtractorBool(readedValue, aes_cfg_def.keyLoad);
    aesCfg->keySrc = dataExtractorBool(readedValue, aes_cfg_def.keySrc);
    aesCfg->tagSize = dataExtractorChar(readedValue, aes_cfg_def.tagSize);
    aesCfg->coreSel = dataExtractorBool(readedValue, aes_cfg_def.coreSel);
    aesCfg->keyOpt = dataExtractorBool(readedValue, aes_cfg_def.keyOpt);

    delete readedValue.dataBuffor;
}

void load(AES_IV0 *aesIv0)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(aes_iv0_def.registry));
    aesIv0->value = dataExtractorInt(readedValue, aes_iv0_def.value);

    delete readedValue.dataBuffor;
}
void load(AES_IV1 *aesIv1)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(aes_iv1_def.registry));
    aesIv1->value = dataExtractorInt(readedValue, aes_iv1_def.value);

    delete readedValue.dataBuffor;
}
void load(AES_IV2 *aesIv2)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(aes_iv2_def.registry));
    aesIv2->value = dataExtractorInt(readedValue, aes_iv2_def.value);

    delete readedValue.dataBuffor;
}
void load(AES_IV3 *aesIv3)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(aes_iv3_def.registry));
    aesIv3->value = dataExtractorShort(readedValue, aes_iv3_def.value);

    delete readedValue.dataBuffor;
}
void load(AES_IV4 *aesIv4)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(aes_iv4_def.registry));
    aesIv4->value = dataExtractorShort(readedValue, aes_iv4_def.value);

    delete readedValue.dataBuffor;
}

void load(DMA_CFG *dmaCfg)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(dma_cfg_def.registry));
    dmaCfg->srcPort = dataExtractorChar(readedValue, dma_cfg_def.srcPort);
    dmaCfg->srcAddr = dataExtractorShort(readedValue, dma_cfg_def.srcAddr);
    dmaCfg->dstPort = dataExtractorChar(readedValue, dma_cfg_def.dstPort);
    dmaCfg->dstAddr = dataExtractorShort(readedValue, dma_cfg_def.dstAddr);
    dmaCfg->cpEndSel = dataExtractorBool(readedValue, dma_cfg_def.cpEndSel);
    dmaCfg->hdrSize = dataExtractorChar(readedValue, dma_cfg_def.hdrSize);
    dmaCfg->pyldSize = dataExtractorChar(readedValue, dma_cfg_def.pyldSize);

    delete readedValue.dataBuffor;
}

void load(AES_START *aesStart)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(aes_start_def.registry));
    aesStart->aesStart = dataExtractorBool(readedValue, aes_start_def.aesStart);

    delete readedValue.dataBuffor;
}

void load(AES_STS *aesSts)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(aes_sts_def.registry));
    aesSts->aesDone = dataExtractorBool(readedValue, aes_sts_def.aesDone);
    aesSts->authErr = dataExtractorBool(readedValue, aes_sts_def.authErr);
    aesSts->transErr = dataExtractorBool(readedValue, aes_sts_def.transErr);
    aesSts->memConf = dataExtractorBool(readedValue, aes_sts_def.memConf);
    aesSts->ramEmpty = dataExtractorBool(readedValue, aes_sts_def.ramEmpty);
    aesSts->ramFull = dataExtractorBool(readedValue, aes_sts_def.ramFull);

    delete readedValue.dataBuffor;
}

void load(AES_KEY *aesKey)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(aes_key_def.registry));
    extractBigValues(readedValue, aes_key_def.values, aesKey->values);

    delete readedValue.dataBuffor;
}

void load(STS_CFG *stsCfg)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(sts_cfg_def.registry));
    stsCfg->cpsLen = dataExtractorChar(readedValue, sts_cfg_def.cpsLen);

    delete readedValue.dataBuffor;
}

void load(STS_CTRL *stsCtrl)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(sts_ctrl_def.registry));
    stsCtrl->loadIV = dataExtractorBool(readedValue, sts_ctrl_def.loadIV);
    stsCtrl->rstLast = dataExtractorBool(readedValue, sts_ctrl_def.rstLast);

    delete readedValue.dataBuffor;
}

void load(STS_STS *stsSts)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(sts_sts_def.registry));
    stsSts->accQual = dataExtractorShort(readedValue, sts_sts_def.accQual);

    delete readedValue.dataBuffor;
}

void load(STS_KEY *stsKey)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(sts_key_def.registry));
    extractBigValues(readedValue, sts_key_def.values, stsKey->values);

    delete readedValue.dataBuffor;
}

void load(STS_IV *stsIv)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(sts_iv_def.registry));
    extractBigValues(readedValue, sts_iv_def.values, stsIv->values);

    delete readedValue.dataBuffor;
}

void load(DGC_CFG *dgcCfg)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(dgc_cfg_def.registry));
    dgcCfg->rxTuneEn = dataExtractorBool(readedValue, dgc_cfg_def.rxTuneEn);
    dgcCfg->thr64 = dataExtractorChar(readedValue, dgc_cfg_def.thr64);

    delete readedValue.dataBuffor;
}

void load(DHC_DBG *dhcDbg)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(dhc_dbg_def.registry));
    dhcDbg->dgcDecision = dataExtractorChar(readedValue, dhc_dbg_def.dgcDecision);

    delete readedValue.dataBuffor;
}

void load(EX_CTRL *exCtrl)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(ex_ctrl_def.registry));
    exCtrl->ostsWait = dataExtractorChar(readedValue, ex_ctrl_def.ostsWait);
    exCtrl->ostrMode = dataExtractorBool(readedValue, ex_ctrl_def.ostrMode);

    delete readedValue.dataBuffor;
}

void load(RX_CAL *rxCal)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rx_cal_def.registry));
    rxCal->calMode = dataExtractorBool(readedValue, rx_cal_def.calMode);
    rxCal->calEn = dataExtractorBool(readedValue, rx_cal_def.calEn);
    rxCal->compDly = dataExtractorChar(readedValue, rx_cal_def.compDly);

    delete readedValue.dataBuffor;
}

void load(RX_CAL_RESI *rxCalResi)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rx_cal_resi_def.registry));
    rxCalResi->value = dataExtractorInt(readedValue, rx_cal_resi_def.value);

    delete readedValue.dataBuffor;
}

void load(RX_CAL_RESQ *rxCalResq)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rx_cal_resq_def.registry));
    rxCalResq->value = dataExtractorInt(readedValue, rx_cal_resq_def.value);

    delete readedValue.dataBuffor;
}

void load(RX_CAL_STS *rxCalSts)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rx_cal_sts_def.registry));
    rxCalSts->value = dataExtractorBool(readedValue, rx_cal_sts_def.value);

    delete readedValue.dataBuffor;
}

void load(GPIO_MODE *gpioMode)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(gpio_mode_def.registry));
    gpioMode->msGp0 = dataExtractorChar(readedValue, gpio_mode_def.msGp0);
    gpioMode->msGp1 = dataExtractorChar(readedValue, gpio_mode_def.msGp1);
    gpioMode->msGp2 = dataExtractorChar(readedValue, gpio_mode_def.msGp2);
    gpioMode->msGp3 = dataExtractorChar(readedValue, gpio_mode_def.msGp3);
    gpioMode->msGp4 = dataExtractorChar(readedValue, gpio_mode_def.msGp4);
    gpioMode->msGp5 = dataExtractorChar(readedValue, gpio_mode_def.msGp5);
    gpioMode->msGp6 = dataExtractorChar(readedValue, gpio_mode_def.msGp6);
    gpioMode->msGp7 = dataExtractorChar(readedValue, gpio_mode_def.msGp7);
    gpioMode->msGp8 = dataExtractorChar(readedValue, gpio_mode_def.msGp8);

    delete readedValue.dataBuffor;
}

void load(GPIO_PULL_EN *gpioPullEn)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(gpio_pull_en_def.registry));
    gpioPullEn->msGp0 = dataExtractorBool(readedValue, gpio_pull_en_def.msGp0);
    gpioPullEn->msGp1 = dataExtractorBool(readedValue, gpio_pull_en_def.msGp1);
    gpioPullEn->msGp2 = dataExtractorBool(readedValue, gpio_pull_en_def.msGp2);
    gpioPullEn->msGp3 = dataExtractorBool(readedValue, gpio_pull_en_def.msGp3);
    gpioPullEn->msGp4 = dataExtractorBool(readedValue, gpio_pull_en_def.msGp4);
    gpioPullEn->msGp5 = dataExtractorBool(readedValue, gpio_pull_en_def.msGp5);
    gpioPullEn->msGp6 = dataExtractorBool(readedValue, gpio_pull_en_def.msGp6);
    gpioPullEn->msGp7 = dataExtractorBool(readedValue, gpio_pull_en_def.msGp7);
    gpioPullEn->msGp8 = dataExtractorBool(readedValue, gpio_pull_en_def.msGp8);

    delete readedValue.dataBuffor;
}

void load(GPIO_DIR *gpioDir)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(gpio_dir_def.registry));
    gpioDir->msGp0 = dataExtractorBool(readedValue, gpio_dir_def.msGp0);
    gpioDir->msGp1 = dataExtractorBool(readedValue, gpio_dir_def.msGp1);
    gpioDir->msGp2 = dataExtractorBool(readedValue, gpio_dir_def.msGp2);
    gpioDir->msGp3 = dataExtractorBool(readedValue, gpio_dir_def.msGp3);
    gpioDir->msGp4 = dataExtractorBool(readedValue, gpio_dir_def.msGp4);
    gpioDir->msGp5 = dataExtractorBool(readedValue, gpio_dir_def.msGp5);
    gpioDir->msGp6 = dataExtractorBool(readedValue, gpio_dir_def.msGp6);
    gpioDir->msGp7 = dataExtractorBool(readedValue, gpio_dir_def.msGp7);
    gpioDir->msGp8 = dataExtractorBool(readedValue, gpio_dir_def.msGp8);

    delete readedValue.dataBuffor;
}

void load(GPIO_OUT *gpioOut)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(gpio_out_def.registry));
    gpioOut->msGp0 = dataExtractorBool(readedValue, gpio_out_def.msGp0);
    gpioOut->msGp1 = dataExtractorBool(readedValue, gpio_out_def.msGp1);
    gpioOut->msGp2 = dataExtractorBool(readedValue, gpio_out_def.msGp2);
    gpioOut->msGp3 = dataExtractorBool(readedValue, gpio_out_def.msGp3);
    gpioOut->msGp4 = dataExtractorBool(readedValue, gpio_out_def.msGp4);
    gpioOut->msGp5 = dataExtractorBool(readedValue, gpio_out_def.msGp5);
    gpioOut->msGp6 = dataExtractorBool(readedValue, gpio_out_def.msGp6);
    gpioOut->msGp7 = dataExtractorBool(readedValue, gpio_out_def.msGp7);
    gpioOut->msGp8 = dataExtractorBool(readedValue, gpio_out_def.msGp8);

    delete readedValue.dataBuffor;
}

void load(GPIO_IRQE *gpioIrqe)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(gpio_irqe_def.registry));
    gpioIrqe->msGp0 = dataExtractorBool(readedValue, gpio_irqe_def.msGp0);
    gpioIrqe->msGp1 = dataExtractorBool(readedValue, gpio_irqe_def.msGp1);
    gpioIrqe->msGp2 = dataExtractorBool(readedValue, gpio_irqe_def.msGp2);
    gpioIrqe->msGp3 = dataExtractorBool(readedValue, gpio_irqe_def.msGp3);
    gpioIrqe->msGp4 = dataExtractorBool(readedValue, gpio_irqe_def.msGp4);
    gpioIrqe->msGp5 = dataExtractorBool(readedValue, gpio_irqe_def.msGp5);
    gpioIrqe->msGp6 = dataExtractorBool(readedValue, gpio_irqe_def.msGp6);
    gpioIrqe->msGp7 = dataExtractorBool(readedValue, gpio_irqe_def.msGp7);
    gpioIrqe->msGp8 = dataExtractorBool(readedValue, gpio_irqe_def.msGp8);

    delete readedValue.dataBuffor;
}

void load(GPIO_ISTS *gpioIsts)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(gpio_ists_def.registry));
    gpioIsts->msGp0 = dataExtractorBool(readedValue, gpio_ists_def.msGp0);
    gpioIsts->msGp1 = dataExtractorBool(readedValue, gpio_ists_def.msGp1);
    gpioIsts->msGp2 = dataExtractorBool(readedValue, gpio_ists_def.msGp2);
    gpioIsts->msGp3 = dataExtractorBool(readedValue, gpio_ists_def.msGp3);
    gpioIsts->msGp4 = dataExtractorBool(readedValue, gpio_ists_def.msGp4);
    gpioIsts->msGp5 = dataExtractorBool(readedValue, gpio_ists_def.msGp5);
    gpioIsts->msGp6 = dataExtractorBool(readedValue, gpio_ists_def.msGp6);
    gpioIsts->msGp7 = dataExtractorBool(readedValue, gpio_ists_def.msGp7);
    gpioIsts->msGp8 = dataExtractorBool(readedValue, gpio_ists_def.msGp8);

    delete readedValue.dataBuffor;
}

void load(GPIO_ISEN *gpioIsen)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(gpio_isen_def.registry));
    gpioIsen->msGp0 = dataExtractorBool(readedValue, gpio_isen_def.msGp0);
    gpioIsen->msGp1 = dataExtractorBool(readedValue, gpio_isen_def.msGp1);
    gpioIsen->msGp2 = dataExtractorBool(readedValue, gpio_isen_def.msGp2);
    gpioIsen->msGp3 = dataExtractorBool(readedValue, gpio_isen_def.msGp3);
    gpioIsen->msGp4 = dataExtractorBool(readedValue, gpio_isen_def.msGp4);
    gpioIsen->msGp5 = dataExtractorBool(readedValue, gpio_isen_def.msGp5);
    gpioIsen->msGp6 = dataExtractorBool(readedValue, gpio_isen_def.msGp6);
    gpioIsen->msGp7 = dataExtractorBool(readedValue, gpio_isen_def.msGp7);
    gpioIsen->msGp8 = dataExtractorBool(readedValue, gpio_isen_def.msGp8);

    delete readedValue.dataBuffor;
}

void load(GPIO_IMODE *gpioImode)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(gpio_imode_def.registry));
    gpioImode->msGp0 = dataExtractorBool(readedValue, gpio_imode_def.msGp0);
    gpioImode->msGp1 = dataExtractorBool(readedValue, gpio_imode_def.msGp1);
    gpioImode->msGp2 = dataExtractorBool(readedValue, gpio_imode_def.msGp2);
    gpioImode->msGp3 = dataExtractorBool(readedValue, gpio_imode_def.msGp3);
    gpioImode->msGp4 = dataExtractorBool(readedValue, gpio_imode_def.msGp4);
    gpioImode->msGp5 = dataExtractorBool(readedValue, gpio_imode_def.msGp5);
    gpioImode->msGp6 = dataExtractorBool(readedValue, gpio_imode_def.msGp6);
    gpioImode->msGp7 = dataExtractorBool(readedValue, gpio_imode_def.msGp7);
    gpioImode->msGp8 = dataExtractorBool(readedValue, gpio_imode_def.msGp8);

    delete readedValue.dataBuffor;
}

void load(GPIO_IBES *gpioIbes)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(gpio_ibes_def.registry));
    gpioIbes->msGp0 = dataExtractorBool(readedValue, gpio_ibes_def.msGp0);
    gpioIbes->msGp1 = dataExtractorBool(readedValue, gpio_ibes_def.msGp1);
    gpioIbes->msGp2 = dataExtractorBool(readedValue, gpio_ibes_def.msGp2);
    gpioIbes->msGp3 = dataExtractorBool(readedValue, gpio_ibes_def.msGp3);
    gpioIbes->msGp4 = dataExtractorBool(readedValue, gpio_ibes_def.msGp4);
    gpioIbes->msGp5 = dataExtractorBool(readedValue, gpio_ibes_def.msGp5);
    gpioIbes->msGp6 = dataExtractorBool(readedValue, gpio_ibes_def.msGp6);
    gpioIbes->msGp7 = dataExtractorBool(readedValue, gpio_ibes_def.msGp7);
    gpioIbes->msGp8 = dataExtractorBool(readedValue, gpio_ibes_def.msGp8);

    delete readedValue.dataBuffor;
}

void load(GPIO_ICLR *gpioIclr)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(gpio_iclr_def.registry));
    gpioIclr->msGp0 = dataExtractorBool(readedValue, gpio_iclr_def.msGp0);
    gpioIclr->msGp1 = dataExtractorBool(readedValue, gpio_iclr_def.msGp1);
    gpioIclr->msGp2 = dataExtractorBool(readedValue, gpio_iclr_def.msGp2);
    gpioIclr->msGp3 = dataExtractorBool(readedValue, gpio_iclr_def.msGp3);
    gpioIclr->msGp4 = dataExtractorBool(readedValue, gpio_iclr_def.msGp4);
    gpioIclr->msGp5 = dataExtractorBool(readedValue, gpio_iclr_def.msGp5);
    gpioIclr->msGp6 = dataExtractorBool(readedValue, gpio_iclr_def.msGp6);
    gpioIclr->msGp7 = dataExtractorBool(readedValue, gpio_iclr_def.msGp7);
    gpioIclr->msGp8 = dataExtractorBool(readedValue, gpio_iclr_def.msGp8);

    delete readedValue.dataBuffor;
}

void load(GPIO_IDBE *gpioIdbe)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(gpio_idbe_def.registry));
    gpioIdbe->msGp0 = dataExtractorBool(readedValue, gpio_idbe_def.msGp0);
    gpioIdbe->msGp1 = dataExtractorBool(readedValue, gpio_idbe_def.msGp1);
    gpioIdbe->msGp2 = dataExtractorBool(readedValue, gpio_idbe_def.msGp2);
    gpioIdbe->msGp3 = dataExtractorBool(readedValue, gpio_idbe_def.msGp3);
    gpioIdbe->msGp4 = dataExtractorBool(readedValue, gpio_idbe_def.msGp4);
    gpioIdbe->msGp5 = dataExtractorBool(readedValue, gpio_idbe_def.msGp5);
    gpioIdbe->msGp6 = dataExtractorBool(readedValue, gpio_idbe_def.msGp6);
    gpioIdbe->msGp7 = dataExtractorBool(readedValue, gpio_idbe_def.msGp7);
    gpioIdbe->msGp8 = dataExtractorBool(readedValue, gpio_idbe_def.msGp8);

    delete readedValue.dataBuffor;
}

void load(GPIO_RAW *gpioRaw)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(gpio_raw_def.registry));
    gpioRaw->msGp0 = dataExtractorBool(readedValue, gpio_raw_def.msGp0);
    gpioRaw->msGp1 = dataExtractorBool(readedValue, gpio_raw_def.msGp1);
    gpioRaw->msGp2 = dataExtractorBool(readedValue, gpio_raw_def.msGp2);
    gpioRaw->msGp3 = dataExtractorBool(readedValue, gpio_raw_def.msGp3);
    gpioRaw->msGp4 = dataExtractorBool(readedValue, gpio_raw_def.msGp4);
    gpioRaw->msGp5 = dataExtractorBool(readedValue, gpio_raw_def.msGp5);
    gpioRaw->msGp6 = dataExtractorBool(readedValue, gpio_raw_def.msGp6);
    gpioRaw->msGp7 = dataExtractorBool(readedValue, gpio_raw_def.msGp7);
    gpioRaw->msGp8 = dataExtractorBool(readedValue, gpio_raw_def.msGp8);

    delete readedValue.dataBuffor;
}

void load(DTUNE_0 *dtune0)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(dtune_0_def.registry));
    dtune0->pac = dataExtractorChar(readedValue, dtune_0_def.pac);
    dtune0->dt0b4 = dataExtractorBool(readedValue, dtune_0_def.dt0b4);

    delete readedValue.dataBuffor;
}

void load(RX_SFD_TOC *rxSfdToc)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rx_sfd_toc_def.registry));
    rxSfdToc->value = dataExtractorShort(readedValue, rx_sfd_toc_def.value);

    delete readedValue.dataBuffor;
}

void load(PRE_TOC *preToc)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(pre_toc_def.registry));
    preToc->value = dataExtractorShort(readedValue, pre_toc_def.value);

    delete readedValue.dataBuffor;
}

void load(DTUNE3 *dtune3)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(dtune_3_def.registry));
    dtune3->value = dataExtractorInt(readedValue, dtune_3_def.value);

    delete readedValue.dataBuffor;
}

void load(DTUNE5 *dtune5)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(dtune_5_def.registry));
    dtune5->value = dataExtractorInt(readedValue, dtune_5_def.value);

    delete readedValue.dataBuffor;
}

void load(DRX_CAR_INT *drxCarInt)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(drx_car_int_def.registry));
    drxCarInt->fractionalPart = dataExtractorLong(readedValue, drx_car_int_def.fractionalPart);
    drxCarInt->portion = dataExtractorShort(readedValue, drx_car_int_def.portion);

    delete readedValue.dataBuffor;
}

void load(RF_ENABLE *rfEnable)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rf_enable_def.registry));
    rfEnable->value = dataExtractorInt(readedValue, rf_enable_def.value);

    delete readedValue.dataBuffor;
}

void load(RF_CTRL_MASK *rfCtrlMask)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rf_ctrl_mask_def.registry));
    rfCtrlMask->value = dataExtractorInt(readedValue, rf_ctrl_mask_def.value);

    delete readedValue.dataBuffor;
}

void load(RF_SWITCH *rfSwitch)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rf_switch_def.registry));
    rfSwitch->antswNotToggle = dataExtractorBool(readedValue, rf_switch_def.antswNotToggle);
    rfSwitch->antswPdoaPort = dataExtractorBool(readedValue, rf_switch_def.antswPdoaPort);
    rfSwitch->antSwen = dataExtractorBool(readedValue, rf_switch_def.antSwen);
    rfSwitch->antSwctrl = dataExtractorChar(readedValue, rf_switch_def.antSwctrl);
    rfSwitch->trxSwen = dataExtractorBool(readedValue, rf_switch_def.trxSwen);
    rfSwitch->trxSwctrl = dataExtractorChar(readedValue, rf_switch_def.trxSwctrl);

    delete readedValue.dataBuffor;
}

void load(RF_TX_CTRL_1 *rfTxCtrl1)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rf_tx_ctrl_1_def.registry));
    rfTxCtrl1->value = dataExtractorChar(readedValue, rf_tx_ctrl_1_def.value);

    delete readedValue.dataBuffor;
}

void load(RF_TX_CTRL_2 *rfTxCtrl2)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(rf_tx_ctrl_2_def.registry));
    rfTxCtrl2->pgDelay = dataExtractorChar(readedValue, rf_tx_ctrl_2_def.pgDelay);

    delete readedValue.dataBuffor;
}

void load(TX_TEST *txTest)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(tx_test_def.registry));
    txTest->txEntest = dataExtractorChar(readedValue, tx_test_def.txEntest);

    delete readedValue.dataBuffor;
}
void load(SAR_TEST *sarTest)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(sar_test_def.registry));
    sarTest->sarRden = dataExtractorBool(readedValue, sar_test_def.sarRden);

    delete readedValue.dataBuffor;
}

void load(LDO_TUNE *ldoTune)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(ldo_tune_def.registry));
    ldoTune->ldoTune = dataExtractorLong(readedValue, ldo_tune_def.ldoTune);

    delete readedValue.dataBuffor;
}
void load(LDO_CTRL *ldoCtrl)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(ldo_ctrl_def.registry));
    ldoCtrl->ldoCtrl = dataExtractorInt(readedValue, ldo_ctrl_def.ldoCtrl);

    delete readedValue.dataBuffor;
}

void load(LDO_RLOAD *ldoRload)
{
    ReadedRegistryData readedValue = readValue(ReadOperand(ldo_rload_def.registry));
    ldoRload->value = dataExtractorChar(readedValue, ldo_rload_def.value);

    delete readedValue.dataBuffor;
}
// 8.2.8.6