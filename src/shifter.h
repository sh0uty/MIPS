#ifndef _SHIFTER_H
#define _SHIFTER_H

#include "systemc.h"

namespace MIPS{

    SC_MODULE(shifter){

        sc_in<sc_lv<32>> x;
        sc_out<sc_lv<32>> y;
        
        void shift_left();

        SC_CTOR(shifter){
            SC_METHOD(shift_left);
        };

    };

}
#endif