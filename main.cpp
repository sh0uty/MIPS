#include "systemc.h"
#include "shifter.h"
#include "sign_extend.h"
#include "registers.h"


int sc_main(int argc, char* argv[]){
/* //Shifter Test
    sc_signal<sc_lv<32>> x;
    sc_signal<sc_lv<32>> y;

    MIPS::shifter *Shifter = new MIPS::shifter("Shifter");

    (*Shifter)(x, y);

    sc_start(1, SC_NS);

    sc_trace_file *tf = sc_create_vcd_trace_file("MIPS");
    sc_trace(tf, x, "x");
    sc_trace(tf, y, "y");

    x = -2;

    sc_start(1, SC_NS);

    x = 16;

    sc_start(1, SC_NS);


    sc_close_vcd_trace_file(tf);
    return 0;
*/

/* //Indexing of sc_lv
    sc_lv<4> test = "1101";

    cout << test[0] << endl; //1
    cout << test[1] << endl; //1
    cout << test[2] << endl; //0
    cout << test[3] << endl; //1

    cout << test(3, 1) << endl; //110


    return 0;
*/

/* //Sign Extender Test
    sc_signal<sc_lv<16>> x;
    sc_signal<sc_lv<32>> y;

    MIPS::sign_extend *Extender = new MIPS::sign_extend("Extender");
    (*Extender)(x, y);

    sc_trace_file *tf = sc_create_vcd_trace_file("MIPS");
    sc_trace(tf, x, "x");
    sc_trace(tf, y, "y");

    x = "0001000100010001";

    sc_start(1, SC_NS);

    x = "1000100010001000";

    sc_start(1, SC_NS);

    sc_close_vcd_trace_file(tf);

    return 0;
*/

    sc_signal<bool> clk;
    sc_signal<sc_logic> reg_write;
    sc_signal<sc_lv<5>> read_reg_1, read_reg_2, write_reg;
    sc_signal<sc_lv<32>> write_data, read_data_1, read_data_2;

    MIPS::registers *Registers = new MIPS::registers("Registers");
    (*Registers)(clk, reg_write, read_reg_1, read_reg_2, write_reg, write_data, read_data_1, read_data_2);

    sc_trace_file *tf = sc_create_vcd_trace_file("MIPS");    
    sc_trace(tf, clk, "clk");
    sc_trace(tf, reg_write, "reg_write");
    sc_trace(tf, read_reg_1, "read_reg_1");
    sc_trace(tf, read_reg_2, "read_reg_2");
    sc_trace(tf, write_reg, "write_reg");
    sc_trace(tf, write_data, "write_data");
    sc_trace(tf, read_data_1, "read_data_1");
    sc_trace(tf, read_data_2, "read_data_2");

    clk = 0;
    reg_write = SC_LOGIC_0;
    read_reg_1 = "00000";
    read_reg_2 = "00000";
    write_reg = "00000";
    write_data = "00000000000000000000000000000000";
    read_data_1 = "00000000000000000000000000000000";
    read_data_2 = "00000000000000000000000000000000";

    Registers->debugRegisters();

    sc_start(1, SC_NS);

    clk = 1;

    sc_start(1, SC_NS);

    reg_write = SC_LOGIC_1;
    write_reg = "00010";
    write_data = "11111111111111111111111111111111";
    clk = 0;

    sc_start(1, SC_NS);


    Registers->debugRegisters();

    sc_close_vcd_trace_file(tf);
    return 0;
}