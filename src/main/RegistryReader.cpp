#include "RegistryReader.hpp"

#include <cstring>

void fastOperation(FastCommandDefinition fastCommandDefinition)
{
    FastCommandTransactionHeader fastCommandTransactionHeader =
        prepareFastTransactionHeader(fastCommandDefinition);

    int bufforSize = 1;
    unsigned char buffor[bufforSize] = {fastCommandTransactionHeader.octet};

    exchangeData(buffor, bufforSize);
}

static const int BUFFOR_SIZE = 1000;
static unsigned char buffor[BUFFOR_SIZE];

ReadedRegistryData readValue(ReadOperand readOperand)
{
    FullAddressTransactionHeader transactionHeader =
        prepareFullTransactionHeader(
            FullAddressTransactionHeaderParams(
                READ,
                readOperand.registry->registryAddress,
                readOperand.registry->subRegistryAddress,
                false,
                false));

    int transactionSize = transactionHeader.headerSize + readOperand.registry->registryOctecsNumber;

    unsigned char *headers = transactionHeader.preparePair();

    memcpy(buffor, headers, transactionHeader.headerSize);
    delete[] headers;

    exchangeData(buffor, transactionSize);

    unsigned char *readedBuffor = new unsigned char[readOperand.registry->registryOctecsNumber];

    memcpy(readedBuffor, buffor + transactionHeader.headerSize,
           readOperand.registry->registryOctecsNumber);

    return ReadedRegistryData(readedBuffor, readOperand.registry->registryOctecsNumber);
}