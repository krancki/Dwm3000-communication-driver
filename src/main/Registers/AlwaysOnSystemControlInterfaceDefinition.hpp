#pragma once

#include "../RegistryReader.hpp"
#include "ByteDefinition.hpp"

struct AON_DIG_CFG_DEF
{
    Registry *registry = new Registry(0x0A, 0x00, 3);
    ByteDefinition *onwAonDld = new ByteDefinition(0, 1);
    ByteDefinition *onwRunSar = new ByteDefinition(1, 1);
    ByteDefinition *onwGo2Idle = new ByteDefinition(8, 1);
    ByteDefinition *onwGo2rx = new ByteDefinition(9, 1);
    ByteDefinition *onwPgfcal = new ByteDefinition(11, 1);
};

extern const AON_DIG_CFG_DEF aon_dig_cfg_def;

struct AON_CTRL_DEF
{
    Registry *registry = new Registry(0x0A, 0x04, 1);
    ByteDefinition *restore = new ByteDefinition(0, 1);
    ByteDefinition *save = new ByteDefinition(1, 1);
    ByteDefinition *cfgUpload = new ByteDefinition(2, 1);
    ByteDefinition *dcaRead = new ByteDefinition(3, 1);
    ByteDefinition *dcaWrite = new ByteDefinition(4, 1);
    ByteDefinition *dcaWriteHi = new ByteDefinition(5, 1);
    ByteDefinition *dcaEnab = new ByteDefinition(7, 1);
};

extern const AON_CTRL_DEF aon_ctrl_def;

struct AON_RDATA_DEF
{
    Registry *registry = new Registry(0x0A, 0x08, 1);
    ByteDefinition *value = new ByteDefinition(0, 8);
};

extern const AON_RDATA_DEF aon_rdata_def;

struct AON_ADDR_DEF
{
    Registry *registry = new Registry(0x0A, 0x0C, 2);
    ByteDefinition *value = new ByteDefinition(0, 16);
};

extern const AON_ADDR_DEF aon_addr_def;

struct AON_WDATA_DEF
{
    Registry *registry = new Registry(0x0A, 0x10, 1);
    ByteDefinition *value = new ByteDefinition(0, 8);
};

extern const AON_WDATA_DEF aon_wdata_def;

struct AON_CFG_DEF
{
    Registry *registry = new Registry(0x0A, 0x14, 1);
    ByteDefinition *sleepEn = new ByteDefinition(0, 1);
    ByteDefinition *wakeCnt = new ByteDefinition(1, 1);
    ByteDefinition *broutEn = new ByteDefinition(2, 1);
    ByteDefinition *wakeCsn = new ByteDefinition(3, 1);
    ByteDefinition *wakeWup = new ByteDefinition(4, 1);
    ByteDefinition *presSleep = new ByteDefinition(5, 1);
};

extern const AON_CFG_DEF aon_cfg_def;
