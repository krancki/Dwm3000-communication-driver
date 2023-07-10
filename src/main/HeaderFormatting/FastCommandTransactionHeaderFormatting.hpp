#pragma once

#include "../Commands/FastCommandDefinition.hpp"

struct FastCommandTransactionHeader
{
    unsigned char octet;
    FastCommandTransactionHeader(unsigned char _octet) { octet = _octet; }
};

FastCommandTransactionHeader prepareFastTransactionHeader(
    FastCommandDefinition fastCommandDefinition);
