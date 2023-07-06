#pragma once
#include "../RegistryReader.hpp"
#include "ByteDefinition.hpp"

struct DGC_CFG_DEF
{
    Registry *registry = new Registry(0x03, 0x18, 2);
    ByteDefinition *rxTuneEn = new ByteDefinition(0, 1);
    ByteDefinition *thr64 = new ByteDefinition(9, 6);
};

extern const DGC_CFG_DEF dgc_cfg_def;

struct DHC_DBG_DEF
{
    Registry *registry = new Registry(0x03, 0x60, 4);
    ByteDefinition *dgcDecision = new ByteDefinition(28, 3);
};

extern const DHC_DBG_DEF dhc_dbg_def;