#pragma once

#include "HeaderFormatting/FastCommandTransactionHeaderFormatting.hpp"
#include "HeaderFormatting/FullAddressTransactionHeaderFormatting.hpp"
#include "HeaderFormatting/ShortAddressTransactionHeaderFormatting.hpp"
#include "Spi/SpiConnector.hpp"

struct Registry
{
    char registryAddress;
    char subRegistryAddress;
    int registryOctecsNumber;

    Registry(
        char _registryAddress,
        char _subRegistryAddress,
        int _registryOctetsNumber)
    {
        registryAddress = _registryAddress;
        subRegistryAddress = _subRegistryAddress;
        registryOctecsNumber = _registryOctetsNumber;
    }
};

struct ReadOperand
{
    Registry *registry;

    ReadOperand(Registry *_registry)
    {
        registry = _registry;
    }
};

struct ReadedRegistryData
{
    unsigned char *dataBuffor;
    int size;

    ReadedRegistryData(unsigned char *_dataBuffor, int _size)
    {
        dataBuffor = _dataBuffor;
        size = _size;
    }
};

ReadedRegistryData readValue(ReadOperand readOperand);

void fastOperation(FastCommandDefinition fastCommandDefinition);
