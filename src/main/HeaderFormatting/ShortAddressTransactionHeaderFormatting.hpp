#pragma once

#include "HeaderFormattingDefinition.hpp"

struct ShortAddressTransactionHeader {
  unsigned char header;

  ShortAddressTransactionHeader(unsigned char _header) { header = _header; }
};

struct ShortAddressTransactionHeaderParams {
  ReadWriteMode readWriteMode;
  unsigned char baseReqistryAddress;

  ShortAddressTransactionHeaderParams(ReadWriteMode _readWriteMode,
                                      unsigned char _baseReqistryAddress) {
    readWriteMode = _readWriteMode;
    baseReqistryAddress = _baseReqistryAddress;
  };
};

ShortAddressTransactionHeader prepareShortTransactionHeader(
    ShortAddressTransactionHeaderParams transactionHeaderParams);
