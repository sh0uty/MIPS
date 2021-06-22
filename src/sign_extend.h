#ifndef _SIGNEXTEND_H
#define _SIGNEXTEND_H

#include "systemc.h"

#include "LOG.h"

namespace MIPS {

    SC_MODULE(sign_extend){

        sc_in<sc_lv<16>> x;
        sc_out<sc_lv<32>> y;

        void extend();

        SC_CTOR(sign_extend){
            SC_METHOD(extend);
            sensitive << x;
        };

    };

}


#endif