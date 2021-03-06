#ifndef _PC_H
#define _PC_H

#include "systemc.h"

#include "LOG.h"

namespace MIPS {

    SC_MODULE(pc){

        sc_in_clk clk;
        sc_in<sc_lv<32>> address_to_load;
        sc_out<sc_lv<32>> current_address;

        sc_lv<32> address;

        void load_address();
        void save_address();

        void set_address();

        SC_CTOR(pc){

            address = "00000000000000000000000000000000";

            SC_METHOD(set_address);
            //dont_initialize();
            sensitive << clk.pos() << clk.neg();

/*
            SC_METHOD(load_address);
            dont_initialize();
            // ! Not sure
            sensitive << clk.pos() << clk.neg();

            SC_METHOD(save_address);
            dont_initialize();
            sensitive << clk.neg();
*/
        };
    };

}

#endif