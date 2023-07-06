#include "ShortAddressTransactionHeaderFormatting.hpp"

//   static unsigned char readModeMask = 0b10000000;
//   static unsigned char shortAddressModeMask = 0b01000000;
static unsigned char baseAddressMask = 0b00111110;

char prepareHeaderOctet(ReadWriteMode readWriteMode, char baseAddress) {
  unsigned char readMode = readWriteMode == READ ? 0b00000000 : 0b10000000;
  unsigned char shortAddressMode = 0b00000000;
  unsigned char correctBaseAddress = (baseAddress << 1) & baseAddressMask;

  unsigned char lastBitOfFirstOktetForFastCommand = 0b00000000;

  return readMode | shortAddressMode | correctBaseAddress |
         lastBitOfFirstOktetForFastCommand;
}

ShortAddressTransactionHeader prepareShortTransactionHeader(
    ShortAddressTransactionHeaderParams transactionHeaderParams) {
  return ShortAddressTransactionHeader(
      prepareHeaderOctet(transactionHeaderParams.readWriteMode,
                         transactionHeaderParams.baseReqistryAddress));
}
