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


        sc_buffer<sc_lv<32>> instr_address{"instr_address", 0b0}, next_address{"next_address", 0b0}, instruction{"instruction", 0b0};

        sc_buffer<sc_lv<32>> read_data_1{"read_data_1", 0b0},
              read_data_2{"read_data_2", 0b0},
              write_data{"write_data", 0b0},
              extended_immediate{"extended_immediate", 0b0},
              shifted_immediate{"shifted_immediate", 0b0},
              alu_in_2{"alu_in_2", 0b0},
              alu_result{"alu_result", 0b0},
              last_instr_address{"last_instr_address", 0b0},
              incremented_address{"incremented_address", 0b0},
              add2_result{"add2_result", 0b0},
              mux4_result{"mux4_result", 0b0},
              concatenated_pc_and_jump_address{"concatenated_pc_and_jump_address", 0b0},
              mem_read_data{"mem_read_data", 0b0};

        sc_buffer<sc_lv<28>> shifted_jump_address{"shifted_jump_address", 0b0};
        sc_buffer<sc_lv<26>> jump_address{"jump_address", 0b0};
        sc_buffer<sc_lv<16>> immediate{"immediate", 0b0};
        sc_buffer<sc_lv<6>> opcode{"opcode", 0b0}, funct{"funct", 0b0};
        sc_buffer<sc_lv<5>> rs{"rs", 0b0}, rt{"rt", 0b0}, rd{"rd", 0b0}, shampt{"shampt", 0b0}, write_reg{"write_reg", 0b0};
        sc_buffer<sc_lv<4>> alu_control_fuct{"alu_control_funct", 0b0};
        sc_buffer<sc_lv<2>> alu_op{"alu_op", 0b0};
        sc_buffer<sc_logic> reg_dest{"reg_dest", SC_LOGIC_0}, jump{"jump", SC_LOGIC_0}, branch{"branch", SC_LOGIC_0}, mem_read{"mem_read", SC_LOGIC_0}, 
                mem_to_reg{"mem_to_reg", SC_LOGIC_0}, mem_write{"mem_write", SC_LOGIC_0}, alu_src{"alu_src", SC_LOGIC_0},
                reg_write{"reg_write", SC_LOGIC_0}, alu_zero{"alu_zero", SC_LOGIC_0}, branch_and_alu_zero{"branch_and_alu_zero", SC_LOGIC_0};

        sc_buffer<sc_lv<32>> hard_code{"hard_code", 0b00000000000000000000000000000100};

        enum STATE{
            LOADING,
            RUNNING,
            DONE
        };
        STATE s = LOADING;

        sc_signal<bool> en{"en", 0};   

        pc *Prog_Count;
        instruction_memory *IM;
        control *CONTROL1;
        mux<sc_lv<5>> *MUX1;
        registers *REG;
        alu_control *ALU_CONTRL;
        sign_extend *SGN_EXT;
        mux<sc_lv<32>> *MUX2;
        alu *ALU1;
        mux<sc_lv<32>> *MUX3;
        shifter<sc_lv<32>, sc_lv<32>> *SHIFT1;
        adder *ADD1;
        mux<sc_lv<32>> *MUX4;
        adder *ADD2;
        shifter<sc_lv<26>, sc_lv<28>> *SHIFT2; 
        mux<sc_lv<32>> *MUX5;
        data_memory *MEM;

        //*-----------------------------------------------------------------------------------------------//

        SC_CTOR(MIPS){

            init();
            LOG(INFO) << "Initialized Modules";

            SC_METHOD(set_clock);
            dont_initialize();
            sensitive << clk;

            LOG(INFO) << "Set clock";

            SC_METHOD(convert_instruction);
            dont_initialize();
            sensitive << instruction;

            LOG(INFO) << "Set instruction";

            SC_METHOD(set_branch_and_alu_zero);
            dont_initialize();
            sensitive << branch << alu_zero;
            
            LOG(INFO) << "Set branch and alu zero";

            SC_METHOD(set_pc_and_jump_address);
            dont_initialize();
            sensitive << incremented_address << shifted_jump_address;
        
            LOG(INFO) << "Set pc and jump address";
        }

        void init();
        void set_clock();
        void convert_instruction();
        void set_branch_and_alu_zero();
        void set_pc_and_jump_address();


    };
}

#endif