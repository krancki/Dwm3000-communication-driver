

#include <iomanip>
#include <iostream>

#include "./Registers/RegistersDefinition.hpp"
#include "Dwm3000.hpp"
#include "RegistryLoader.hpp"
#include "RegistryReader.hpp"

void printData(unsigned char *data, int size)
{
    std::cout << "Otrzymane dane: ";
    for (int i = size - 1; i >= 0; i--)
    {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)data[i]
                  << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void displayValue(const T &value)
{

    std::cout << "Otrzymane dane: ";
    std::cout << static_cast<unsigned>(value);
    std::cout << std::endl;
}

int main()
{
    unsigned char registryAddress = 0x00;
    unsigned char subRegistryAddress = 0x00;

    int registryLength = 4;

    Dwm3000 *dwm = new Dwm3000();

    load(dwm->dev_id);
    load(dwm->panadr);
    load(dwm->sysCfg);
    load(dwm->ffCfg);
    load(dwm->spiRdCrc);
    load(dwm->sysTime);
    load(dwm->txFctrl);
    load(dwm->dxTime);
    load(dwm->drefTime);
    load(dwm->rxFwto);
    load(dwm->sysCtr);
    load(dwm->sysEnable);
    load(dwm->sysStatus);
    load(dwm->rxFinfo);
    load(dwm->rxTime);

    // ReadedRegistryData readedData = readValue(
    //     ReadOperand());

    // fastOperation(CMD_TXRXOFF);

    displayValue(dwm->dev_id->model);
    // printData(readedData.dataBuffor, readedData.size);

    // delete[] readedData.dataBuffor;

    return 0;
}
