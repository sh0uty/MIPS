#ifndef _MUX_H
#define _MUX_H

#include "systemc.h"

namespace MIPS{

    SC_MODULE(mux){

        sc_in<sc_lv<32>> x, y;
        sc_in<sc_logic> s;
        sc_out<sc_lv<32>> z;

        void set();

        SC_CTOR(mux){
            SC_METHOD(set);
        };
    };

}

#endif