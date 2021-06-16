#ifndef _CONTROL_H
#define _CONTROL_H

#include "systemc.h"

namespace MIPS{

    SC_MODULE(control){

        sc_in<sc_lv<6>> opcode;
        sc_out<sc_logic> reg_dest, jump, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write;
        sc_out<sc_lv<2>> alu_op;

        void assign();

        SC_CTOR(control){
            SC_METHOD(assign);
            sensitive << opcode;
        }

    };

}



#endif