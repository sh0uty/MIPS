#include "mips.h"

void MIPS::MIPS::set_clock(){

    switch (s)
    {
    case RUNNING:
        en = clk;
        break;
    
    default:
        en = SC_LOGIC_0;
        break;
    }

}

void MIPS::MIPS::run(){

    switch (s)
    {
    case LOADING:
        s = RUNNING;
        break;
    
    case RUNNING:
        if (instr_address.to_uint() > last_instr_address.to_uint()){
            s = DONE;
            en = SC_LOGIC_0;
        }
        break;

    case DONE:
        break;

    default:
        break;
    }

}