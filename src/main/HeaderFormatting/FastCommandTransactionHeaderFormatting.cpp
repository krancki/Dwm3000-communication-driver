#include "FastCommandTransactionHeaderFormatting.hpp"

//   static unsigned char readModeMask = 0b10000000;
//   static unsigned char shortAddressModeMask = 0b01000000;
static unsigned char baseAddressMask = 0b00111110;

char prepareHeaderOctet(char comand) {
  unsigned char readMode = 0b10000000;
  unsigned char shortAddressMode = 0b00000000;
  unsigned char correctCommand = (comand << 1) & baseAddressMask;

  unsigned char lastBitOfFirstOktetForFastCommand = 0b00000001;

  return readMode | shortAddressMode | correctCommand |
         lastBitOfFirstOktetForFastCommand;
}

FastCommandTransactionHeader prepareFastTransactionHeader(
    FastCommandDefinition fastCommandDefinition) {
  return FastCommandTransactionHeader(
      prepareHeaderOctet(fastCommandDefinition.code));
}
