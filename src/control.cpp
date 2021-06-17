#include "control.h"

void MIPS::control::assign(){
    switch (opcode.read().to_uint())
    {   
        //R-types 000000
        case 0: 
            reg_dest.write(SC_LOGIC_1);
            jump.write(SC_LOGIC_0);
            branch.write(SC_LOGIC_0);
            mem_read.write(SC_LOGIC_0);
            mem_to_reg.write(SC_LOGIC_0);
            mem_write.write(SC_LOGIC_0);
            alu_src.write(SC_LOGIC_0);
            reg_write.write(SC_LOGIC_1);
            alu_op.write("10");
            break;
        //addi 001000
        case 8: 
            reg_dest.write(SC_LOGIC_0);
            jump.write(SC_LOGIC_0);
            branch.write(SC_LOGIC_0);
            mem_read.write(SC_LOGIC_0);
            mem_to_reg.write(SC_LOGIC_0);
            mem_write.write(SC_LOGIC_0);
            alu_src.write(SC_LOGIC_1);
            reg_write.write(SC_LOGIC_1);
            alu_op.write("00");
            break;
        //beq 000100
        case 4: 
            reg_dest.write(SC_LOGIC_0);
            jump.write(SC_LOGIC_0);
            branch.write(SC_LOGIC_1);
            mem_read.write(SC_LOGIC_0);
            mem_to_reg.write(SC_LOGIC_0);
            mem_write.write(SC_LOGIC_0);
            alu_src.write(SC_LOGIC_0);
            reg_write.write(SC_LOGIC_0);
            alu_op.write("01");
            break;
        //bne 000101
        case 5: 
            reg_dest.write(SC_LOGIC_0);
            jump.write(SC_LOGIC_0);
            branch.write(SC_LOGIC_1);
            mem_read.write(SC_LOGIC_0);
            mem_to_reg.write(SC_LOGIC_0);
            mem_write.write(SC_LOGIC_0);
            alu_src.write(SC_LOGIC_0);
            reg_write.write(SC_LOGIC_0);
            alu_op.write("11");
            break;
        //jump 000010
        case 2: 
            reg_dest.write(SC_LOGIC_0);
            jump.write(SC_LOGIC_1);
            branch.write(SC_LOGIC_0);
            mem_read.write(SC_LOGIC_0);
            mem_to_reg.write(SC_LOGIC_0);
            mem_write.write(SC_LOGIC_0);
            alu_src.write(SC_LOGIC_0);
            reg_write.write(SC_LOGIC_0);
            alu_op.write("00");
            break;
        //lw 100011
        case 35: 
            reg_dest.write(SC_LOGIC_0);
            jump.write(SC_LOGIC_0);
            branch.write(SC_LOGIC_0);
            mem_read.write(SC_LOGIC_1);
            mem_to_reg.write(SC_LOGIC_1);
            mem_write.write(SC_LOGIC_0);
            alu_src.write(SC_LOGIC_1);
            reg_write.write(SC_LOGIC_1);
            alu_op.write("00");
            break;
        //sw 101011
        case 43: 
            reg_dest.write(SC_LOGIC_0);
            jump.write(SC_LOGIC_0);
            branch.write(SC_LOGIC_0);
            mem_read.write(SC_LOGIC_0);
            mem_to_reg.write(SC_LOGIC_0);
            mem_write.write(SC_LOGIC_1);
            alu_src.write(SC_LOGIC_1);
            reg_write.write(SC_LOGIC_0);
            alu_op.write("00");
            break;
    default:
            reg_dest.write(SC_LOGIC_0);
            jump.write(SC_LOGIC_0);
            branch.write(SC_LOGIC_0);
            mem_read.write(SC_LOGIC_0);
            mem_to_reg.write(SC_LOGIC_0);
            mem_write.write(SC_LOGIC_0);
            alu_src.write(SC_LOGIC_0);
            reg_write.write(SC_LOGIC_0);
            alu_op.write("00");
            break;
        break;
    }
}