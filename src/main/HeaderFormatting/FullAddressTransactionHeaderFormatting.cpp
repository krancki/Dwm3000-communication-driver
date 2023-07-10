#include "FullAddressTransactionHeaderFormatting.hpp"

char prepareFirstOctet(ReadWriteMode readWriteMode, char registryAddress,
                       char subRegistryAddress);

char prepareSecondOctet(char subRegistryAddress, bool m1, bool m2);

FullAddressTransactionHeader prepareFullTransactionHeader(
    FullAddressTransactionHeaderParams transactionHeaderParams)
{
    return FullAddressTransactionHeader(
        prepareFirstOctet(transactionHeaderParams.readWriteMode,
                          transactionHeaderParams.registryAddress,
                          transactionHeaderParams.subRegistryAddress),
        prepareSecondOctet(transactionHeaderParams.subRegistryAddress,
                           transactionHeaderParams.m1,
                           transactionHeaderParams.m2));
}

static unsigned char registryAddressMask = 0b00111110;

char prepareFirstOctet(ReadWriteMode readWriteMode, char registryAddress,
                       char subRegistryAddress)
{
    unsigned char readMode = readWriteMode == READ ? 0b00000000 : 0b10000000;

    //   unsigned char readModeMask = 0b10000000;

    unsigned char fullAddressMode = 0b01000000;
    //   unsigned char fullAddressModeMask = 0b01000000;

    unsigned char correctRegistryAddress =
        (registryAddress << 1) & registryAddressMask;

    unsigned char subRegistryAddressMaskFirstOctet = 0b01000000;
    unsigned char lastBitOfFirstOktetForSubmaskAddress =
        (subRegistryAddress & subRegistryAddressMaskFirstOctet) >> 6;

    return readMode | fullAddressMode | correctRegistryAddress |
        lastBitOfFirstOktetForSubmaskAddress;
}

static unsigned char M1Mask = 0b00000010;
static unsigned char M2Mask = 0b00000001;

char prepareSecondOctet(char subRegistryAddress, bool m1, bool m2)
{
    unsigned char subRegistryAddressMastSecendOctect = 0b00111111;
    unsigned char secondOctetSubAddress =
        (subRegistryAddress & subRegistryAddressMastSecendOctect) << 2;

    unsigned char M1 = m1 == true ? 0b00000010 : 0b00000000;
    unsigned char M2 = m2 == true ? 0b0000001 : 0b00000000;

    unsigned char finalM1 = M1 & M1Mask;
    unsigned char finalM2 = M2 & M2Mask;

    return secondOctetSubAddress | finalM1 | finalM2;
}
