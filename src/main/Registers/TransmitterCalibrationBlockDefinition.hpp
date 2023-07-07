#pragma once

#include "../RegistryReader.hpp"
#include "ByteDefinition.hpp"

struct SAR_CTRL_DEF
{
    Registry *registry = new Registry(0x08, 0x00, 1);
    ByteDefinition *sarStart = new ByteDefinition(0, 1);
};

extern const SAR_CTRL_DEF sar_ctrl_def;

struct SAR_STATUS_DEF
{
    Registry *registry = new Registry(0x08, 0x04, 1);
    ByteDefinition *sarDone = new ByteDefinition(0, 1);
};

extern const SAR_STATUS_DEF sar_status_def;

struct SAR_READING_DEF
{
    Registry *registry = new Registry(0x08, 0x08, 3);
    ByteDefinition *sarLvbat = new ByteDefinition(0, 8);
    ByteDefinition *sarLtemp = new ByteDefinition(8, 8);
};

extern const SAR_READING_DEF sar_reading_def;

struct SAR_WAKE_RD_DEF
{
    Registry *registry = new Registry(0x08, 0x0C, 2);
    ByteDefinition *sarWvbat = new ByteDefinition(0, 8);
    ByteDefinition *sarWtemp = new ByteDefinition(8, 8);
};

extern const SAR_WAKE_RD_DEF sar_wake_rd_def;

struct PGC_CTRL_DEF
{
    Registry *registry = new Registry(0x08, 0x10, 2);
    ByteDefinition *pgStart = new ByteDefinition(0, 1);
    ByteDefinition *pgcAutoCal = new ByteDefinition(1, 1);
    ByteDefinition *pgcTmeas = new ByteDefinition(2, 4);
};

extern const PGC_CTRL_DEF pgc_ctrl_def;

struct PGC_STATUS_DEF
{
    Registry *registry = new Registry(0x08, 0x14, 2);
    ByteDefinition *pgDelayCnt = new ByteDefinition(0, 12);
    ByteDefinition *autocalDone = new ByteDefinition(12, 1);
};

extern const PGC_STATUS_DEF pgc_status_def;

struct PG_TEST_DEF
{
    Registry *registry = new Registry(0x08, 0x18, 2);
    ByteDefinition *value = new ByteDefinition(0, 16);
};

extern const PG_TEST_DEF pg_test_def;

struct PG_CAL_TARGET_DEF
{
    Registry *registry = new Registry(0x08, 0x1C, 2);
    ByteDefinition *pgTarget = new ByteDefinition(0, 12);
};

extern const PG_CAL_TARGET_DEF pg_cal_target_def;
