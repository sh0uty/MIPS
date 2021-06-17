#ifndef _ALU_H
#define _ALU_H

#include "systemc.h"

namespace MIPS{

    SC_MODULE(alu){

        sc_in<sc_lv<32>> in_1, in_2;
        sc_in<sc_lv<4>> alu_control_func;
        sc_out<sc_logic> zero;
        sc_out<sc_lv<32>> alu_result;

        sc_lv<4> and_op = "0000";
        sc_lv<4> or_op = "0001";
        sc_lv<4> add = "0010";
        sc_lv<4> subtract_not_equal = "0011";
        sc_lv<4> subtract = "0110";
        sc_lv<4> set_on_less_than = "0111";

        void compute();

        SC_CTOR(alu){
            SC_METHOD(compute);
            sensitive << in_1, in_2, alu_control_func;
        }

    };

}



#endif