#include "mips.h"

void MIPS::MIPS::init(){

    LOG(INFO) << "MIPS init:start";

    IM = new instruction_memory("IM");
    (*IM)(instr_address, instruction, last_instr_address);

    CONTROL1 = new control("CONTROL1");
    (*CONTROL1)(opcode, reg_dest, jump, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write, alu_op);

    MUX1 = new mux<sc_lv<5>>("MUX1");
    (*MUX1)(rt, rd, reg_dest, write_reg);

    REG = new registers("REG");
    (*REG)(en, reg_write, rs, rt, write_reg, write_data, read_data_1, read_data_2);

    ALU_CONTRL = new alu_control("ALU_CONTRL");
    (*ALU_CONTRL)(funct, alu_op, alu_control_fuct);    

    SGN_EXT = new sign_extend("SGN_EXT");
    (*SGN_EXT)(immediate, extended_immediate);

    MUX2 = new mux<sc_lv<32>>("MUX2");
    (*MUX2)(read_data_2, extended_immediate, alu_src, alu_in_2);

    ALU1 = new alu("ALU1");
    (*ALU1)(read_data_1, alu_in_2, alu_control_fuct, alu_zero, alu_result);

    MUX3 = new mux<sc_lv<32>>("MUX3");
    (*MUX3)(alu_result, mem_read_data, mem_to_reg, write_data);

    SHIFT1 = new shifter<sc_lv<32>, sc_lv<32>>("SHIFT1");
    (*SHIFT1)(extended_immediate, shifted_immediate);

    ADD1 = new adder("ADD1");
    (*ADD1)(instr_address, hard_code, incremented_address);

    MUX4 = new mux<sc_lv<32>>("MUX4");
    (*MUX4)(incremented_address, add2_result, branch_and_alu_zero, mux4_result);

    ADD2 = new adder("ADD2");
    (*ADD2)(incremented_address, shifted_immediate, add2_result);

    SHIFT2 = new shifter<sc_lv<26>, sc_lv<28>>("SHIFT2");
    (*SHIFT2)(jump_address, shifted_jump_address);

    MUX5 = new mux<sc_lv<32>>("MUX5");
    (*MUX5)(mux4_result, concatenated_pc_and_jump_address, jump, next_address);

    MEM = new data_memory("MEM");
    (*MEM)(alu_result, read_data_2, mem_write, mem_read, en, mem_read_data);

    Prog_Count = new pc("Prog_Count");
    (*Prog_Count)(en, next_address, instr_address);

    LOG(INFO) << "MIPS init:end";
    
}

void MIPS::MIPS::set_clock(){
    switch (s)
    {
    case RUNNING:
        en = clk.read();
        LOG(INFO) << "Clock dm read " << clk.read();
        break;
    
    default:
        en = 0;
        LOG(INFO) << "Clock 0 dm";
        break;
    }

    if(clk.read() == 1){

         switch (s)
            {
            case LOADING:
                s = RUNNING;
                break;
            
            case RUNNING:
                if (instr_address.read().to_uint() > last_instr_address.read().to_uint()){
                    s = DONE;
                    en = 0;
                    LOG(INFO) << "Clock m 0";
                }
                break;

            case DONE:
                break;

            default:
                break;
            }
    }
    LOG(INFO) << "State is now: " << s; 

}

void MIPS::MIPS::convert_instruction(){

    LOG(INFO) << "MIPS instruction is: " << instruction.read();

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
    LOG(INFO) << "MIPS branch and alu zero: " << (branch.read() & alu_zero.read());
}

void MIPS::MIPS::set_pc_and_jump_address(){

    sc_lv<32> temp{0b0};
    temp.range(31, 28) = incremented_address.read().range(31, 28);
    temp.range(27, 0) = shifted_jump_address.read().range(27, 0);
    concatenated_pc_and_jump_address.write(temp);
    LOG(INFO) << "MIPS set_pc_and_jump_address " << incremented_address.read().range(31, 28) << " + " << shifted_jump_address.read().range(27, 0) << " = "<< temp;

}