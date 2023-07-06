#include <wiringPi.h>
#include <wiringPiSPI.h>

#include "SpiConnector.hpp"

const int DWM3000_SS_PIN = 8;
const int DWM3000_SPI_CHANNEL = 0;
const int DWM3000_SPI_SPEED = 500000;

bool initialized = false;

void init()
{
    if (initialized == false)
    {
        wiringPiSetup();
        wiringPiSPISetup(DWM3000_SPI_CHANNEL, 1000000);
        pinMode(DWM3000_SS_PIN, OUTPUT);
        digitalWrite(DWM3000_SS_PIN, HIGH);

        initialized = true;
    }
}

void exchangeData(unsigned char *buffor, int bufforSize)
{
    init();
    digitalWrite(DWM3000_SS_PIN, LOW);

    wiringPiSPIDataRW(DWM3000_SPI_CHANNEL, buffor, bufforSize);

    digitalWrite(DWM3000_SS_PIN, HIGH);
}