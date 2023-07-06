#pragma once

#include "../Commands/FastCommandDefinition.hpp"

struct FastCommandTransactionHeader {
  char octet;
  FastCommandTransactionHeader(char _octet) { octet = _octet; }
};

FastCommandTransactionHeader prepareFastTransactionHeader(
    FastCommandDefinition fastCommandDefinition);
