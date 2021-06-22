#ifndef _INSTRUCTIONMEMORY_H
#define _INSTRUCTIONMEMORY_H

#include "systemc.h"
#include <fstream>
#include <string>

#include "LOG.h"

namespace MIPS{

    // ! Not Tested
    // ? Test with different instruction set

    SC_MODULE(instruction_memory){

        sc_in<sc_lv<32>> read_address;
        sc_out<sc_lv<32>> instruction, last_instr_address;

        sc_lv<32> data_mem[32];

        void read_file();
        void set_instruction();

        SC_CTOR(instruction_memory){
            
            // ? Not sure
            for(auto& data : data_mem)
                data = "00000000000000000000000000000000";


            SC_METHOD(read_file);
            //sensitive << read_address;

            SC_METHOD(set_instruction);
            sensitive << read_address;
        };

    };

}

#endif