#ifndef _REGISTERS_H
#define _REGISTERS_H

#include "systemc.h"

namespace MIPS{

    SC_MODULE(registers){

        sc_in_clk clk;
        sc_in<sc_logic> reg_write;
        sc_in<sc_lv<5>> read_reg_1, read_reg_2, write_reg;
        sc_in<sc_lv<32>> write_data;
        sc_out<sc_lv<32>> read_data_1, read_data_2;

        void read();
        void write();
        void debugRegisters();

        sc_lv<32> reg_mem[32];
        int test[2];
        SC_CTOR(registers){

            // ? Not sure
            for(auto& reg : reg_mem)
                reg = "0000000000000000000000000000000000";

            SC_METHOD(read);

            SC_METHOD(write);
            sensitive << clk.neg();

        };

    };

}



#endif