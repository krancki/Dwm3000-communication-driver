
#include "FastCommandDefinition.hpp"

// Puts the device into IDLE state and clears any events.
FastCommandDefinition CMD_TXRXOFF = {0x0};

// Immediate start of transmission
FastCommandDefinition CMD_TX = {0x1};

// Enable RX immediately
FastCommandDefinition CMD_RX = {0x2};

// Delayed TX w.r.t. DX_TIME
FastCommandDefinition CMD_DTX = {0x3};

// Delayed RX w.r.t. DX_TIME
FastCommandDefinition CMD_DRX = {0x4};

// Delayed TX w.r.t. TX timestamp + DX_TIME
FastCommandDefinition CMD_DTX_TS = {0x5};

// Delayed RX w.r.t. TX timestamp + DX_TIME
FastCommandDefinition CMD_DRX_TS = {0x6};

// Delayed TX w.r.t. RX timestamp + DX_TIME
FastCommandDefinition CMD_DTX_RS = {0x7};

// Delayed RX w.r.t. RX timestamp + DX_TIME
FastCommandDefinition CMD_DRX_RS = {0x8};

// Delayed TX w.r.t. DREF_TIME + DX_TIME
FastCommandDefinition CMD_DTX_REF = {0x9};

// Delayed RX w.r.t. DREF_TIME + DX_TIME
FastCommandDefinition CMD_DRX_REF = {0xA};

// TX if no preamble detected
FastCommandDefinition CMD_CCA_TX = {0xB};

// Start TX immediately, then when TX is done, enable the receiver
FastCommandDefinition CMD_TX_W4R = {0xC};

// Delayed TX w.r.t. DX_TIME, then enable receiver
FastCommandDefinition CMD_DTX_W4R = {0xD};

// Delayed TX w.r.t. TX timestamp + DX_TIME, then enable receiver
FastCommandDefinition CMD_DTX_TS_W4R = {0xE};

// Delayed TX w.r.t. RX timestamp + DX_TIME, then enable receiver
FastCommandDefinition CMD_DTX_RS_W4R = {0xF};

// Delayed TX w.r.t. DREF_TIME + DX_TIME, then enable receiver
FastCommandDefinition CMD_DTX_REF_W4R = {0x10};

// TX packet if no preamble detected, then enable receiver
FastCommandDefinition CMD_CCA_TX_W4R = {0x11};

// Clear all interrupt events
FastCommandDefinition CMD_CLR_IRQS = {0x12};

// Toggle double buffer pointer / notify the device that the host has finished
// processing the received buffer/data.
FastCommandDefinition CMD_DB_TOGGLE = {0x13};
