#include "alu.h"

void MIPS::alu::compute(){
    sc_uint<32> temp_1, temp_2;
    sc_lv<4> temp_control;

    temp_1 = in_1.read().to_uint();
    temp_2 = in_2.read().to_uint();
    temp_control = alu_control_func.read();

    LOG(INFO) << "ALU: " << temp_1 << " " << temp_2 << " " << temp_control;

    if(temp_control==add){
        alu_result.write(temp_1 + temp_2);
    }
    else if(temp_control==subtract || temp_control==subtract_not_equal){
        alu_result.write(temp_1 - temp_2);
    }
    else if(temp_control==and_op){
        alu_result.write(temp_1 & temp_2);
    }
    else if(temp_control==or_op){
        alu_result.write(temp_1 | temp_2);
    }
    else if(temp_control==set_on_less_than && temp_1 < temp_2){
        alu_result.write("00000000000000000000000000000001");
    }
    else if(temp_control==set_on_less_than){
        alu_result.write("00000000000000000000000000000000");
    }

    if(temp_1 != temp_2 && temp_control==subtract_not_equal){
        zero.write(SC_LOGIC_1);
    }
    else if(temp_1 == temp_2 && temp_control==subtract_not_equal){
        zero.write(SC_LOGIC_0);
    }
    else if(temp_1 == temp_2){
        zero.write(SC_LOGIC_1);
    }
    else{
        zero.write(SC_LOGIC_0);
    }
}