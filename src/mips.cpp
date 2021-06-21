#include "mips.h"

void MIPS::MIPS::set_clock(){

    switch (s)
    {
    case RUNNING:
        en.write(clk.read());
        break;
    
    default:
        en = 0;
        break;
    }
    LOG(INFO) << "Set clock to: " << clk.read();
}

void MIPS::MIPS::run(){

    switch (s)
    {
    case LOADING:
        s = RUNNING;
        break;
    
    case RUNNING:
        if (instr_address.read().to_uint() > last_instr_address.read().to_uint()){
            s = DONE;
            en = 0;
        }
        break;

    case DONE:
        break;

    default:
        break;
    }
    LOG(INFO) << "State is now: " << s; 
}

void MIPS::MIPS::convert_instruction(){

    LOG(INFO) << "Instruction is: " << instruction.read();

    opcode.write(instruction.read().range(31, 26));
    rs.write(instruction.read().range(25, 21));
    rt.write(instruction.read().range(20, 16));
    rd.write(instruction.read().range(15, 11));
    shampt.write(instruction.read().range(10, 6));
    funct.write(instruction.read().range(5, 0));
    immediate.write(instruction.read().range(15, 0));
    jump_address.write(instruction.read().range(25, 0));

}

void MIPS::MIPS::set_branch_and_alu_zero(){

    branch_and_alu_zero.write(branch.read() & alu_zero.read());

}

void MIPS::MIPS::set_pc_and_jump_address(){

    sc_lv<32> temp{0};
    temp.range(31, 28) = incremented_address.read().range(31, 28);
    temp.range(27, 0) = shifted_jump_address.read().range(27, 0);
    concatenated_pc_and_jump_address.write(temp);

}