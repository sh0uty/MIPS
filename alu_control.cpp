#include "alu_control.h"

void MIPS::alu_control::control(){
    if(alu_op.read()=="00" or (alu_op.read()=="10" and function.read()=="100000")){
        alu_control_funct.write(add);
    }
    else if(alu_op.read()=="01" or (alu_op.read()=="10" and function.read()=="100010")){
        alu_control_funct.write(subtract);
    }
    else if(alu_op.read()=="11"){
        alu_control_funct.write(subtract_not_equal);
    }
    else if(alu_op.read()=="10" and function.read()=="100100"){
        alu_control_funct.write(and_op);
    }
    else if(alu_op.read()=="10" and function.read()=="100101"){
        alu_control_funct.write(or_op);
    }
    else if(alu_op.read()=="10" and function.read()=="101010"){
        alu_control_funct.write(set_on_less_than);
    }
    else{
        alu_control_funct.write("0000");
    }
}