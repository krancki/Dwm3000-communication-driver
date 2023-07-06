#pragma once
#include "../RegistryReader.hpp"
#include "ByteDefinition.hpp"

struct GPIO_MODE_DEF
{
    Registry *registry = new Registry(0x05, 0x00, 4);
    ByteDefinition *msGp0 = new ByteDefinition(0, 3);
    ByteDefinition *msGp1 = new ByteDefinition(3, 3);
    ByteDefinition *msGp2 = new ByteDefinition(6, 3);
    ByteDefinition *msGp3 = new ByteDefinition(9, 3);
    ByteDefinition *msGp4 = new ByteDefinition(12, 3);
    ByteDefinition *msGp5 = new ByteDefinition(15, 3);
    ByteDefinition *msGp6 = new ByteDefinition(18, 3);
    ByteDefinition *msGp7 = new ByteDefinition(21, 3);
    ByteDefinition *msGp8 = new ByteDefinition(24, 3);
};

extern const GPIO_MODE_DEF gpio_mode_def;

struct GPIO_PULL_EN_DEF
{
    Registry *registry = new Registry(0x05, 0x04, 2);
    ByteDefinition *msGp0 = new ByteDefinition(0, 1);
    ByteDefinition *msGp1 = new ByteDefinition(1, 1);
    ByteDefinition *msGp2 = new ByteDefinition(2, 1);
    ByteDefinition *msGp3 = new ByteDefinition(3, 1);
    ByteDefinition *msGp4 = new ByteDefinition(4, 1);
    ByteDefinition *msGp5 = new ByteDefinition(5, 1);
    ByteDefinition *msGp6 = new ByteDefinition(6, 1);
    ByteDefinition *msGp7 = new ByteDefinition(7, 1);
    ByteDefinition *msGp8 = new ByteDefinition(8, 1);
};

extern const GPIO_PULL_EN_DEF gpio_pull_en_def;

struct GPIO_DIR_DEF
{
    Registry *registry = new Registry(0x05, 0x08, 2);
    ByteDefinition *msGp0 = new ByteDefinition(0, 1);
    ByteDefinition *msGp1 = new ByteDefinition(1, 1);
    ByteDefinition *msGp2 = new ByteDefinition(2, 1);
    ByteDefinition *msGp3 = new ByteDefinition(3, 1);
    ByteDefinition *msGp4 = new ByteDefinition(4, 1);
    ByteDefinition *msGp5 = new ByteDefinition(5, 1);
    ByteDefinition *msGp6 = new ByteDefinition(6, 1);
    ByteDefinition *msGp7 = new ByteDefinition(7, 1);
    ByteDefinition *msGp8 = new ByteDefinition(8, 1);
};

extern const GPIO_DIR_DEF gpio_dir_def;

struct GPIO_OUT_DEF
{
    Registry *registry = new Registry(0x05, 0x0C, 2);
    ByteDefinition *msGp0 = new ByteDefinition(0, 1);
    ByteDefinition *msGp1 = new ByteDefinition(1, 1);
    ByteDefinition *msGp2 = new ByteDefinition(2, 1);
    ByteDefinition *msGp3 = new ByteDefinition(3, 1);
    ByteDefinition *msGp4 = new ByteDefinition(4, 1);
    ByteDefinition *msGp5 = new ByteDefinition(5, 1);
    ByteDefinition *msGp6 = new ByteDefinition(6, 1);
    ByteDefinition *msGp7 = new ByteDefinition(7, 1);
    ByteDefinition *msGp8 = new ByteDefinition(8, 1);
};

extern const GPIO_OUT_DEF gpio_out_def;

struct GPIO_IRQE_DEF
{
    Registry *registry = new Registry(0x05, 0x10, 2);
    ByteDefinition *msGp0 = new ByteDefinition(0, 1);
    ByteDefinition *msGp1 = new ByteDefinition(1, 1);
    ByteDefinition *msGp2 = new ByteDefinition(2, 1);
    ByteDefinition *msGp3 = new ByteDefinition(3, 1);
    ByteDefinition *msGp4 = new ByteDefinition(4, 1);
    ByteDefinition *msGp5 = new ByteDefinition(5, 1);
    ByteDefinition *msGp6 = new ByteDefinition(6, 1);
    ByteDefinition *msGp7 = new ByteDefinition(7, 1);
    ByteDefinition *msGp8 = new ByteDefinition(8, 1);
};

extern const GPIO_IRQE_DEF gpio_irqe_def;

struct GPIO_ISTS_DEF
{
    Registry *registry = new Registry(0x05, 0x14, 2);
    ByteDefinition *msGp0 = new ByteDefinition(0, 1);
    ByteDefinition *msGp1 = new ByteDefinition(1, 1);
    ByteDefinition *msGp2 = new ByteDefinition(2, 1);
    ByteDefinition *msGp3 = new ByteDefinition(3, 1);
    ByteDefinition *msGp4 = new ByteDefinition(4, 1);
    ByteDefinition *msGp5 = new ByteDefinition(5, 1);
    ByteDefinition *msGp6 = new ByteDefinition(6, 1);
    ByteDefinition *msGp7 = new ByteDefinition(7, 1);
    ByteDefinition *msGp8 = new ByteDefinition(8, 1);
};

extern const GPIO_ISTS_DEF gpio_ists_def;

struct GPIO_ISEN_DEF
{
    Registry *registry = new Registry(0x05, 0x18, 2);
    ByteDefinition *msGp0 = new ByteDefinition(0, 1);
    ByteDefinition *msGp1 = new ByteDefinition(1, 1);
    ByteDefinition *msGp2 = new ByteDefinition(2, 1);
    ByteDefinition *msGp3 = new ByteDefinition(3, 1);
    ByteDefinition *msGp4 = new ByteDefinition(4, 1);
    ByteDefinition *msGp5 = new ByteDefinition(5, 1);
    ByteDefinition *msGp6 = new ByteDefinition(6, 1);
    ByteDefinition *msGp7 = new ByteDefinition(7, 1);
    ByteDefinition *msGp8 = new ByteDefinition(8, 1);
};

extern const GPIO_ISEN_DEF gpio_isen_def;

struct GPIO_IMODE_DEF
{
    Registry *registry = new Registry(0x05, 0x1C, 2);
    ByteDefinition *msGp0 = new ByteDefinition(0, 1);
    ByteDefinition *msGp1 = new ByteDefinition(1, 1);
    ByteDefinition *msGp2 = new ByteDefinition(2, 1);
    ByteDefinition *msGp3 = new ByteDefinition(3, 1);
    ByteDefinition *msGp4 = new ByteDefinition(4, 1);
    ByteDefinition *msGp5 = new ByteDefinition(5, 1);
    ByteDefinition *msGp6 = new ByteDefinition(6, 1);
    ByteDefinition *msGp7 = new ByteDefinition(7, 1);
    ByteDefinition *msGp8 = new ByteDefinition(8, 1);
};

extern const GPIO_IMODE_DEF gpio_imode_def;

struct GPIO_IBES_DEF
{
    Registry *registry = new Registry(0x05, 0x20, 2);
    ByteDefinition *msGp0 = new ByteDefinition(0, 1);
    ByteDefinition *msGp1 = new ByteDefinition(1, 1);
    ByteDefinition *msGp2 = new ByteDefinition(2, 1);
    ByteDefinition *msGp3 = new ByteDefinition(3, 1);
    ByteDefinition *msGp4 = new ByteDefinition(4, 1);
    ByteDefinition *msGp5 = new ByteDefinition(5, 1);
    ByteDefinition *msGp6 = new ByteDefinition(6, 1);
    ByteDefinition *msGp7 = new ByteDefinition(7, 1);
    ByteDefinition *msGp8 = new ByteDefinition(8, 1);
};

extern const GPIO_IBES_DEF gpio_ibes_def;

struct GPIO_ICLR_DEF
{
    Registry *registry = new Registry(0x05, 0x24, 2);
    ByteDefinition *msGp0 = new ByteDefinition(0, 1);
    ByteDefinition *msGp1 = new ByteDefinition(1, 1);
    ByteDefinition *msGp2 = new ByteDefinition(2, 1);
    ByteDefinition *msGp3 = new ByteDefinition(3, 1);
    ByteDefinition *msGp4 = new ByteDefinition(4, 1);
    ByteDefinition *msGp5 = new ByteDefinition(5, 1);
    ByteDefinition *msGp6 = new ByteDefinition(6, 1);
    ByteDefinition *msGp7 = new ByteDefinition(7, 1);
    ByteDefinition *msGp8 = new ByteDefinition(8, 1);
};

extern const GPIO_ICLR_DEF gpio_iclr_def;

struct GPIO_IDBE_DEF
{
    Registry *registry = new Registry(0x05, 0x28, 2);
    ByteDefinition *msGp0 = new ByteDefinition(0, 1);
    ByteDefinition *msGp1 = new ByteDefinition(1, 1);
    ByteDefinition *msGp2 = new ByteDefinition(2, 1);
    ByteDefinition *msGp3 = new ByteDefinition(3, 1);
    ByteDefinition *msGp4 = new ByteDefinition(4, 1);
    ByteDefinition *msGp5 = new ByteDefinition(5, 1);
    ByteDefinition *msGp6 = new ByteDefinition(6, 1);
    ByteDefinition *msGp7 = new ByteDefinition(7, 1);
    ByteDefinition *msGp8 = new ByteDefinition(8, 1);
};

extern const GPIO_IDBE_DEF gpio_idbe_def;

struct GPIO_RAW_DEF
{
    Registry *registry = new Registry(0x05, 0x2C, 2);
    ByteDefinition *msGp0 = new ByteDefinition(0, 1);
    ByteDefinition *msGp1 = new ByteDefinition(1, 1);
    ByteDefinition *msGp2 = new ByteDefinition(2, 1);
    ByteDefinition *msGp3 = new ByteDefinition(3, 1);
    ByteDefinition *msGp4 = new ByteDefinition(4, 1);
    ByteDefinition *msGp5 = new ByteDefinition(5, 1);
    ByteDefinition *msGp6 = new ByteDefinition(6, 1);
    ByteDefinition *msGp7 = new ByteDefinition(7, 1);
    ByteDefinition *msGp8 = new ByteDefinition(8, 1);
};

extern const GPIO_RAW_DEF gpio_raw_def;