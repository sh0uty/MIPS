#ifndef _MIPS_H
#define _MIPS_H

#include "systemc.h"

#include "LOG.h"

#include "pc.h"
#include "instruction_memory.h"
#include "control.h"
#include "mux.h"
#include "registers.h"
#include "alu_control.h"
#include "sign_extend.h"
#include "alu.h"
#include "shifter.h"
#include "adder.h"
#include "memory.h"
#include "data_memory.h"


namespace MIPS {
    
    SC_MODULE(MIPS){
        sc_in_clk clk;

        void set_clock();
        void run();
        void convert_instruction();
        void set_branch_and_alu_zero();
        void set_pc_and_jump_address();

        sc_signal<sc_lv<32>> instr_address, next_address, instruction;

        sc_signal<sc_lv<32>> read_data_1 {0},
              read_data_2 {0},
              write_data {0},
              extended_immediate {0},
              shifted_immediate {0},
              alu_in_2 {0},
              alu_result {0},
              last_instr_address {0},
              incremented_address {0},
              add2_result {0},
              mux4_result {0},
              concatenated_pc_and_jump_address {0},
              mem_read_data {0};

        sc_signal<sc_lv<28>> shifted_jump_address;
        sc_signal<sc_lv<26>> jump_address;
        sc_signal<sc_lv<16>> immediate;
        sc_signal<sc_lv<6>> opcode, funct;
        sc_signal<sc_lv<5>> rs, rt, rd, shampt, write_reg;
        sc_signal<sc_lv<4>> alu_control_fuct;
        sc_signal<sc_lv<2>> alu_op;
        sc_signal<sc_logic> reg_dest {0}, jump {0}, branch {0}, mem_read {0}, 
                mem_to_reg {0}, mem_write {0}, alu_src {0},
                reg_write {0}, alu_zero {0}, branch_and_alu_zero {0};

        enum STATE{
            LOADING,
            RUNNING,
            DONE
        };
        STATE s = LOADING;

        sc_signal<bool> en {0};   

        //*-----------------------------------------------------------------------------------------------//

        SC_CTOR(MIPS){
            SC_METHOD(set_clock);
            sensitive << clk;

            SC_METHOD(run);
            sensitive << clk.pos();

            SC_METHOD(convert_instruction);
            sensitive << instruction;

            // ! IMPORTANT ORDER

            pc *Prog_Count = new pc("Prog_Count");
            (*Prog_Count)(en, next_address, instr_address);

            instruction_memory *IM = new instruction_memory("IM");
            (*IM)(instr_address, instruction, last_instr_address);

            control *CONTROL1 = new control("CONTROL1");
            (*CONTROL1)(opcode, reg_dest, jump, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write, alu_op);

            mux<5> *MUX1 = new mux<5>("MUX1");
            (*MUX1)(rt, rd, reg_dest, write_reg);

            registers *REG = new registers("REG");
            (*REG)(en, reg_write, rs, rt, write_reg, write_data, read_data_1, read_data_2);

            alu_control *ALU_CONTRL = new alu_control("ALU_CONTRL");
            (*ALU_CONTRL)(funct, alu_op, alu_control_fuct);    

            sign_extend *SGN_EXT = new sign_extend("SGN_EXT");
            (*SGN_EXT)(immediate, extended_immediate);

            mux<32> *MUX2 = new mux<32>("MUX2");
            (*MUX2)(read_data_2, extended_immediate, alu_src, alu_in_2);

            alu *ALU1 = new alu("ALU1");
            (*ALU1)(read_data_1, alu_in_2, alu_control_fuct, alu_zero, alu_result);

            mux<32> *MUX3 = new mux<32>("MUX3");
            (*MUX3)(alu_result, mem_read_data, mem_to_reg, write_data);

            shifter *SHIFT1 = new shifter("SHIFT1");
            (*SHIFT1)(extended_immediate, shifted_immediate);

            sc_signal<sc_lv<32>> hard_code;
            hard_code.write("00000000000000000000000000000100");
            adder *ADD1 = new adder("ADD1");
            (*ADD1)(instr_address, hard_code, incremented_address);

            SC_METHOD(set_branch_and_alu_zero);
            sensitive << branch << alu_zero;

            // ! IMPORTANT ORDER

            mux<32> *MUX4 = new mux<32>("MUX4");
            (*MUX4)(incremented_address, add2_result, branch_and_alu_zero, mux4_result);

            adder *ADD2 = new adder("ADD2");
            (*ADD2)(incremented_address, shifted_immediate, add2_result);

            shifter *SHIFT2 = new shifter("SHIFT2");
            (*SHIFT2)(jump_address, shifted_jump_address);

            SC_METHOD(set_pc_and_jump_address);
            sensitive << incremented_address << shifted_jump_address;

            // ! IMPORTANT ORDER

            mux<32> *MUX5 = new mux<32>("MUX5");
            (*MUX5)(mux4_result, concatenated_pc_and_jump_address, jump, next_address);

            data_memory *MEM = new data_memory("MEM");
            (*MEM)(alu_result, read_data_2, mem_write, mem_read, en, mem_read_data);
        }




    };
}

#endif