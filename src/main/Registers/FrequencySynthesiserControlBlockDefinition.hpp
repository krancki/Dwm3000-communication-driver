#pragma once

#include "../RegistryReader.hpp"
#include "ByteDefinition.hpp"

struct PLL_CFG_DEF
{
    Registry *registry = new Registry(0x09, 0x00, 2);
    ByteDefinition *value = new ByteDefinition(0, 16);
};

extern const PLL_CFG_DEF pll_cfg_def;

struct PLL_CC_DEF
{
    Registry *registry = new Registry(0x09, 0x04, 1);
    ByteDefinition *ch9Code = new ByteDefinition(0, 8);
    ByteDefinition *ch5Code = new ByteDefinition(8, 14);
};

extern const PLL_CC_DEF pll_cc_def;

struct PLL_CAL_DEF
{
    Registry *registry = new Registry(0x09, 0x08, 2);
    ByteDefinition *useOld = new ByteDefinition(1, 1);
    ByteDefinition *pllCfgLd = new ByteDefinition(4, 4);
    ByteDefinition *calEn = new ByteDefinition(8, 1);
};

extern const PLL_CAL_DEF pll_cal_def;

struct XTAL_DEF
{
    Registry *registry = new Registry(0x09, 0x14, 1);
    ByteDefinition *xtalTrim = new ByteDefinition(0, 5);
};

extern const XTAL_DEF xtal_def;
