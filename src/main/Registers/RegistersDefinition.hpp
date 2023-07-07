#pragma once

// 0x00-0x1 – General configuration registers and AES
#include "GeneralConfigurationRegistersAndAESDefinition.hpp"

// 0x02 – STS configuration and status registers
#include "STSConfigurationAndStatusRegistersDefinition.hpp"

// 0x03 – Receiver tuning parameters
#include "ReceiverTuningParametersDefinition.hpp"

// 0x04 – External sync control and RX calibration
#include "ExternalSyncControlAndRxCalibrationDefinition.hpp"

//  0x05 – GPIO control and status
#include "GpioControlAndStatusDefinition.hpp"

//  0x06 – Digital receiver configuration
#include "DigitalReceiverConfigurationDefinition.hpp"

// 0x07 – Analog RF configuration block
#include "AnalogRfConfigurationBlockDefinition.hpp"

// 8.2.8.6
// 0x08 – Transmitter calibration block
#include "TransmitterCalibrationBlockDefinition.hpp"

// 0x09 – Frequency synthesiser control block
#include "FrequencySynthesiserControlBlockDefinition.hpp"

// 0x0A – Always-on system control interface
#include "AlwaysOnSystemControlInterfaceDefinition.hpp"