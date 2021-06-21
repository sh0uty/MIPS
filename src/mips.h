#ifndef _MIPS_H
#define _MIPS_H

#include "systemc.h"

namespace MIPS {
    
    SC_MODULE(MIPS){
        sc_in_clk clk;

        void set_clock();
        void run();
        void convert_instruction();

        SC_CTOR(MIPS){
            SC_METHOD(set_clock);
            sensitive << clk;

            SC_METHOD(run);
            sensitive << clk.pos();

            SC_METHOD(convert_instruction);
            sensitive << instruction;
        }

        sc_signal<sc_lv<32>> instruction{0};

/*
        sc_signal<sc_lv<32>> instr_address, next_address, instruction,
              read_data_1 = "00000000000000000000000000000000",
              read_data_2 = "00000000000000000000000000000000",
              write_data = "00000000000000000000000000000000",
              extended_immediate = "00000000000000000000000000000000",
              shifted_immediate = "00000000000000000000000000000000",
              alu_in_2 = "00000000000000000000000000000000",
              alu_result = "00000000000000000000000000000000",
              last_instr_address = "00000000000000000000000000000000",
              incremented_address = "00000000000000000000000000000000",
              add2_result = "00000000000000000000000000000000",
              mux4_result = "00000000000000000000000000000000",
              concatenated_pc_and_jump_address = "00000000000000000000000000000000",
              mem_read_data = "00000000000000000000000000000000";
*/
        sc_signal<sc_lv<28>> shifted_jump_address;
        sc_signal<sc_lv<26>> jump_address;
        sc_signal<sc_lv<16>> immediate;
        sc_signal<sc_lv<6>> oppcode, funct;
        sc_signal<sc_lv<5>> rs, rt, rd, shampt, write_reg;
        sc_signal<sc_lv<4>> alu_control_fuct;
        sc_signal<sc_logic> reg_dest {0}, jump {0}, branch {0}, mem_read {0}, 
                mem_to_reg {0}, mem_write {0}, alu_src {0},
                reg_write {0}, alu_zero {0}, branch_and_alu_zero {0};

        enum STATE{
            LOADING,
            RUNNING,
            DONE
        };
        STATE s = LOADING;

        sc_logic en = SC_LOGIC_0;   

        //*-----------------------------------------------------------------------------------------------//





    };
}

#endif