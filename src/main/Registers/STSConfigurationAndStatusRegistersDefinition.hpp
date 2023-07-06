#pragma once
#include "../RegistryReader.hpp"
#include "ByteDefinition.hpp"

struct STS_CFG_DEF
{
    Registry *registry = new Registry(0x02, 0x00, 2);
    ByteDefinition *cpsLen = new ByteDefinition(0, 8);
};

extern const STS_CFG_DEF sts_cfg_def;

struct STS_CTRL_DEF
{
    Registry *registry = new Registry(0x02, 0x04, 1);
    ByteDefinition *loadIV = new ByteDefinition(0, 1);
    ByteDefinition *rstLast = new ByteDefinition(1, 1);
};

extern const STS_CTRL_DEF sts_ctrl_def;

struct STS_STS_DEF
{
    Registry *registry = new Registry(0x02, 0x08, 2);
    ByteDefinition *accQual = new ByteDefinition(0, 12);
};

extern const STS_STS_DEF sts_sts_def;

struct STS_KEY_DEF
{
    Registry *registry = new Registry(0x02, 0x0C, 16);
    ByteDefinition *values = new ByteDefinition(0, 128);
};

extern const STS_KEY_DEF sts_key_def;

struct STS_IV_DEF
{
    Registry *registry = new Registry(0x02, 0x1C, 16);
    ByteDefinition *values = new ByteDefinition(0, 128);
};

extern const STS_IV_DEF sts_iv_def;