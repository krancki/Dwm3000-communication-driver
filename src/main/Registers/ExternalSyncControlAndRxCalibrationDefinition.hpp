#pragma once
#include "../RegistryReader.hpp"
#include "ByteDefinition.hpp"

struct EX_CTRL_DEF
{
    Registry *registry = new Registry(0x04, 0x00, 4);
    ByteDefinition *ostsWait = new ByteDefinition(3, 8);
    ByteDefinition *ostrMode = new ByteDefinition(11, 1);
};

extern const EX_CTRL_DEF ex_ctrl_def;

struct RX_CAL_DEF
{
    Registry *registry = new Registry(0x04, 0x0C, 4);
    ByteDefinition *calMode = new ByteDefinition(0, 2);
    ByteDefinition *calEn = new ByteDefinition(4, 1);
    ByteDefinition *compDly = new ByteDefinition(16, 4);
};

extern const RX_CAL_DEF rx_cal_def;

struct RX_CAL_RESI_DEF
{
    Registry *registry = new Registry(0x04, 0x14, 4);
    ByteDefinition *value = new ByteDefinition(0, 29);
};

extern const RX_CAL_RESI_DEF rx_cal_resi_def;

struct RX_CAL_RESQ_DEF
{
    Registry *registry = new Registry(0x04, 0x1C, 4);
    ByteDefinition *value = new ByteDefinition(0, 29);
};

extern const RX_CAL_RESQ_DEF rx_cal_resq_def;

struct RX_CAL_STS_DEF
{
    Registry *registry = new Registry(0x04, 0x20, 1);
    ByteDefinition *value = new ByteDefinition(0, 1);
};

extern const RX_CAL_STS_DEF rx_cal_sts_def;
