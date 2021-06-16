#ifndef _ADDER_H
#define _ADDER_H

#include "systemc.h"

namespace MIPS{

    SC_MODULE(adder){

        sc_in<sc_lv<32>> x,y;
        sc_out<sc_lv<32>> z;

        void add();

        SC_CTOR(adder){
            SC_METHOD(add);
            sensitive << x,y;
        }

    };

}



#endif