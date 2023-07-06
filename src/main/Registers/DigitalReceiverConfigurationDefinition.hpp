#pragma once

#include "../RegistryReader.hpp"
#include "ByteDefinition.hpp"

struct DTUNE_0_DEF
{
    Registry *registry = new Registry(0x06, 0x00, 2);
    ByteDefinition *pac = new ByteDefinition(0, 2);
    ByteDefinition *dt0b4 = new ByteDefinition(4, 1);
};

extern const DTUNE_0_DEF dtune_0_def;

struct RX_SFD_TOC_DEF
{
    Registry *registry = new Registry(0x06, 0x02, 2);
    ByteDefinition *value = new ByteDefinition(0, 16);
};

extern const RX_SFD_TOC_DEF rx_sfd_toc_def;

struct PRE_TOC_DEF
{
    Registry *registry = new Registry(0x06, 0x04, 2);
    ByteDefinition *value = new ByteDefinition(0, 16);
};

extern const PRE_TOC_DEF pre_toc_def;

struct DTUNE3_DEF
{
    Registry *registry = new Registry(0x06, 0x0C, 4);
    ByteDefinition *value = new ByteDefinition(0, 32);
};

extern const DTUNE3_DEF dtune_3_def;

struct DTUNE5_DEF
{
    Registry *registry = new Registry(0x06, 0x14, 4);
    ByteDefinition *value = new ByteDefinition(0, 32);
};

extern const DTUNE5_DEF dtune_5_def;

struct DRX_CAR_INT_DEF
{
    Registry *registry = new Registry(0x06, 0x29, 3);
    ByteDefinition *fractionalPart = new ByteDefinition(0, 17);
    ByteDefinition *portion = new ByteDefinition(17, 4);
};

extern const DRX_CAR_INT_DEF drx_car_int_def;