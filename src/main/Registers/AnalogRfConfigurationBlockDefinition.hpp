#pragma once
#include "../RegistryReader.hpp"
#include "ByteDefinition.hpp"

struct RF_ENABLE_DEF
{
    Registry *registry = new Registry(0x07, 0x00, 4);
    ByteDefinition *value = new ByteDefinition(0, 32);
};

extern const RF_ENABLE_DEF rf_enable_def;

struct RF_CTRL_MASK_DEF
{
    Registry *registry = new Registry(0x07, 0x04, 4);
    ByteDefinition *value = new ByteDefinition(0, 32);
};

extern const RF_CTRL_MASK_DEF rf_ctrl_mask_def;

struct RF_SWITCH_DEF
{
    Registry *registry = new Registry(0x07, 0x14, 4);
    ByteDefinition *antswNotToggle = new ByteDefinition(0, 1);
    ByteDefinition *antswPdoaPort = new ByteDefinition(1, 1);
    ByteDefinition *antSwen = new ByteDefinition(8, 1);
    ByteDefinition *antSwctrl = new ByteDefinition(12, 3);
    ByteDefinition *trxSwen = new ByteDefinition(16, 1);
    ByteDefinition *trxSwctrl = new ByteDefinition(24, 6);
};

extern const RF_SWITCH_DEF rf_switch_def;

struct RF_TX_CTRL_1_DEF
{
    Registry *registry = new Registry(0x07, 0x1A, 1);
    ByteDefinition *value = new ByteDefinition(0, 8);
};

extern const RF_TX_CTRL_1_DEF rf_tx_ctrl_1_def;

struct RF_TX_CTRL_2_DEF
{
    Registry *registry = new Registry(0x07, 0x1C, 4);
    ByteDefinition *pgDelay = new ByteDefinition(0, 6);
};

extern const RF_TX_CTRL_2_DEF rf_tx_ctrl_2_def;

struct TX_TEST_DEF
{
    Registry *registry = new Registry(0x07, 0x28, 1);
    ByteDefinition *txEntest = new ByteDefinition(0, 4);
};

extern const TX_TEST_DEF tx_test_def;

struct SAR_TEST_DEF
{
    Registry *registry = new Registry(0x07, 0x34, 1);
    ByteDefinition *sarRden = new ByteDefinition(2, 1);
};

extern const SAR_TEST_DEF sar_test_def;

struct LDO_TUNE_DEF
{
    Registry *registry = new Registry(0x07, 0x40, 8);
    ByteDefinition *ldoTune = new ByteDefinition(0, 60);
};

extern const LDO_TUNE_DEF ldo_tune_def;

struct LDO_CTRL_DEF
{
    Registry *registry = new Registry(0x07, 0x48, 1);
    ByteDefinition *ldoCtrl = new ByteDefinition(0, 32);
};

extern const LDO_CTRL_DEF ldo_ctrl_def;

struct LDO_RLOAD_DEF
{
    Registry *registry = new Registry(0x07, 0x51, 1);
    ByteDefinition *value = new ByteDefinition(0, 8);
};

extern const LDO_RLOAD_DEF ldo_rload_def;