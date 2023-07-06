#pragma once

struct FastCommandDefinition
{
    char code;
};

extern FastCommandDefinition CMD_TXRXOFF;
extern FastCommandDefinition CMD_TX;
extern FastCommandDefinition CMD_RX;
extern FastCommandDefinition CMD_DTX;

extern FastCommandDefinition CMD_DRX;
extern FastCommandDefinition CMD_DTX_TS;
extern FastCommandDefinition CMD_DRX_TS;
extern FastCommandDefinition CMD_DTX_RS;

extern FastCommandDefinition CMD_DRX_RS;
extern FastCommandDefinition CMD_DTX_REF;
extern FastCommandDefinition CMD_DRX_REF;
extern FastCommandDefinition CMD_CCA_TX;

extern FastCommandDefinition CMD_TX_W4R;
extern FastCommandDefinition CMD_DTX_W4R;
extern FastCommandDefinition CMD_DTX_TS_W4R;
extern FastCommandDefinition CMD_DTX_RS_W4R;

extern FastCommandDefinition CMD_DTX_REF_W4R;
extern FastCommandDefinition CMD_CCA_TX_W4R;
extern FastCommandDefinition CMD_CLR_IRQS;
extern FastCommandDefinition CMD_DB_TOGGLE;
