#include "alu_control.h"

void MIPS::alu_control::control(){

    LOG(INFO) << "ALU_CONTROL funct - " << function.read();

    if(alu_op.read()=="00" || (alu_op.read()=="10" && function.read()=="100000")){
        alu_control_func.write(add);
    }
    else if(alu_op.read()=="01" || (alu_op.read()=="10" && function.read()=="100010")){
        alu_control_func.write(subtract);
    }
    else if(alu_op.read()=="11"){
        alu_control_func.write(subtract_not_equal);
    }
    else if(alu_op.read()=="10" && function.read()=="100100"){
        alu_control_func.write(and_op);
    }
    else if(alu_op.read()=="10" && function.read()=="100101"){
        alu_control_func.write(or_op);
    }
    else if(alu_op.read()=="10" && function.read()=="101010"){
        alu_control_func.write(set_on_less_than);
    }
    else{
        alu_control_func.write("0000");
    }
}