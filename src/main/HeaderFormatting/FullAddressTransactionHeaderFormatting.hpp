#pragma once

#include "HeaderFormattingDefinition.hpp"

struct FullAddressTransactionHeaderParams
{
    FullAddressTransactionHeaderParams(ReadWriteMode _readWriteMode,
                                       unsigned char _registryAddress,
                                       unsigned char _subRegistryAddress,
                                       bool _m1, bool _m2)
    {
        readWriteMode = _readWriteMode;
        registryAddress = _registryAddress;
        subRegistryAddress = _subRegistryAddress;
        m1 = _m1;
        m2 = _m2;
    }
    ReadWriteMode readWriteMode;
    unsigned char registryAddress;
    unsigned char subRegistryAddress;
    bool m1;
    bool m2;
};

struct FullAddressTransactionHeader
{
    FullAddressTransactionHeader(unsigned char _firstOctet,
                                 unsigned char _secendOctet)
    {
        firstOctet = _firstOctet;
        secendOctet = _secendOctet;
    }

    unsigned char firstOctet;
    unsigned char secendOctet;
    unsigned int headerSize = 2;

    unsigned char *preparePair()
    {
        return new unsigned char[headerSize]{firstOctet, secendOctet};
    };
};

FullAddressTransactionHeader prepareFullTransactionHeader(
    FullAddressTransactionHeaderParams transactionHeaderParams);
