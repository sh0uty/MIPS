#ifndef _MIPS_H
#define _MIPS_H

#include "systemc.h"

namespace MIPS {
    
    SC_MODULE(MIPS){
        sc_in_clk clk;

        void set_clock();
        void run();

        SC_CTOR(MIPS){
            SC_METHOD(set_clock);
            sensitive << clk;

            SC_METHOD(run);
            sensitive << clk.pos();
        }

        sc_lv<32> instr_address, next_address, instruction,
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

        sc_lv<28> shifted_jump_address;
        sc_lv<26> jump_address;
        sc_lv<16> immediate;
        sc_lv<6> oppcode, funct;
        sc_lv<5> rs, rt, rd, shampt, write_reg;
        sc_lv<4> alu_control_fuct;
        sc_logic reg_dest = SC_LOGIC_0, jump = SC_LOGIC_0, branch = SC_LOGIC_0, mem_read = SC_LOGIC_0, 
                mem_to_reg = SC_LOGIC_0, mem_write = SC_LOGIC_0, alu_src = SC_LOGIC_0,
                reg_write = SC_LOGIC_0, alu_zero = SC_LOGIC_0, branch_and_alu_zero = SC_LOGIC_0;

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