#ifndef _DATAMEMORY_H
#define _DATAMEMORY_H

#include "systemc.h"

namespace MIPS{

    SC_MODULE(data_memory){

        sc_in<sc_lv<32>> address, write_data;
        sc_in<sc_logic> MemWrite, MemRead;
        sc_in_clk clock;
        sc_out<sc_lv<32>> read_data;

        sc_lv<32> data_mem[32];

        void read();
        void write();

        SC_CTOR(data_memory){ 
            for(int i = 0; i < 32; i++){
                data_mem[i] = "0x00000000";
            }           

            SC_METHOD(read);
            dont_initialize();
            sensitive << address << MemRead;

            SC_METHOD(write);
            dont_initialize();
            sensitive << address << write_data << clock.neg();
        }

    };

}

#endif