#ifndef _ALUCONTROL_H
#define _ALUCONTROL_H

#include "systemc.h"

namespace MIPS{

    SC_MODULE(alu_control){

        sc_in<sc_lv<6>> function;
        sc_in<sc_lv<2>> alu_op;
        sc_out<sc_lv<4>> alu_control_func;

        sc_lv<4> and_op = "0000";
        sc_lv<4> or_op = "0001";
        sc_lv<4> add = "0010";
        sc_lv<4> subtract_not_equal = "0011";
        sc_lv<4> subtract = "0110";
        sc_lv<4> set_on_less_than = "0111";
        
        void control();

        SC_CTOR(alu_control){
            SC_METHOD(control);
            sensitive << function, alu_op;
        }

    };

}

#endif