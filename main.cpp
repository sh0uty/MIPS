#include "systemc.h"
#include "shifter.h"
#include "sign_extend.h"
#include "registers.h"
#include "adder.h"
#include "alu_control.h"
#include "alu.h"
#include "control.h"
#include "data_memory.h"

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

    /*sc_signal<bool> clk;
    sc_signal<sc_logic> reg_write;
    sc_signal<sc_lv<5>> read_reg_1, read_reg_2, write_reg;
    sc_signal<sc_lv<32>> write_data, read_data_1, read_data_2;

    MIPS::registers *Registers = new MIPS::registers("Registers");
    (*Registers)(clk, reg_write, read_reg_1, read_reg_2, write_reg, write_data, read_data_1, read_data_2);*/


/*    sc_trace_file *tf = sc_create_vcd_trace_file("MIPS");    
    sc_trace(tf, clk, "clk");
    sc_trace(tf, reg_write, "reg_write");
    sc_trace(tf, read_reg_1, "read_reg_1");
    sc_trace(tf, read_reg_2, "read_reg_2");
    sc_trace(tf, write_reg, "write_reg");
    sc_trace(tf, write_data, "write_data");
    sc_trace(tf, read_data_1, "read_data_1");
    sc_trace(tf, read_data_2, "read_data_2");*/

    /*clk = 0;
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


    Registers->debugRegisters();*/


        
    /*//Adder Test
    sc_signal<sc_lv<32>> x,y;
    sc_signal<sc_lv<32>> z;

    MIPS::adder  *Adder = new MIPS::adder("Adder");
    (*Adder)(x,y,z);

    sc_trace_file *tf = sc_create_vcd_trace_file("MIPS");   
    sc_trace(tf, x, "x");
    sc_trace(tf, y, "y");
    sc_trace(tf, z, "z");

    x = "00000000000000000000000000000001";
    y = "11111111111111111111111111111101";
    sc_start(1, SC_NS);
    cout<<z.read()<<endl;*/

    /*//Alu Control Test
    sc_signal<sc_lv<6>> function;
    sc_signal<sc_lv<2>> alu_op;
    sc_signal<sc_lv<4>> output;

    MIPS::alu_control *AluControl = new MIPS::alu_control("AluControl");
    (*AluControl)(function, alu_op, output);

    sc_trace_file *tf = sc_create_vcd_trace_file("MIPS");  
    sc_trace(tf, function, "function");
    sc_trace(tf, alu_op, "alu_op");
    sc_trace(tf, output, "output");

    function = "101011";
    alu_op = "11";
    sc_start(1, SC_NS);
    cout<<output.read()<<endl;*/

    /*//Alu Test
    sc_signal<sc_lv<32>> in_1, in_2;
    sc_signal<sc_lv<4>> alu_control_func;
    sc_signal<sc_logic> zero;
    sc_signal<sc_lv<32>> alu_result;

    MIPS::alu *Alu = new MIPS::alu("Alu");
    (*Alu)(in_1, in_2, alu_control_func, zero, alu_result);

    sc_trace_file *tf = sc_create_vcd_trace_file("MIPS");  
    sc_trace(tf, in_1, "in_1");
    sc_trace(tf, in_2, "in_2");
    sc_trace(tf, alu_control_func, "alu_control_func");
    sc_trace(tf, zero, "zero");
    sc_trace(tf, alu_result, "alu_result");

    in_1 = "00000000000000000000000000000011";
    in_2 = "00000000000000000000000000000011";
    alu_control_func = "0011";
    sc_start(1, SC_NS);
    cout << zero.read() << " and " << alu_result.read() << endl;*/
    
    /*//Control Test
    sc_signal<sc_lv<6>> opcode;
    sc_signal<sc_logic> reg_dest, jump, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write;
    sc_signal<sc_lv<2>> alu_op;

    MIPS::control *Control = new MIPS::control("Control");
    (*Control)(opcode, reg_dest, jump, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write, alu_op);

    sc_trace_file *tf = sc_create_vcd_trace_file("MIPS");
    sc_trace(tf, opcode, "opcode");
    sc_trace(tf, reg_dest, "reg_dest");
    sc_trace(tf, jump, "jump");
    sc_trace(tf, branch, "branch");
    sc_trace(tf, mem_read, "mem_read");
    sc_trace(tf, mem_to_reg, "mem_to_reg");
    sc_trace(tf, mem_write, "mem_write");
    sc_trace(tf, alu_src, "alu_src");
    sc_trace(tf, reg_write, "reg_write");
    sc_trace(tf, alu_op, "alu_op");

    opcode = "111111";
    sc_start(1, SC_NS);
    cout << reg_dest<<jump<<branch<<mem_read<<mem_to_reg<<mem_write<<alu_src<<reg_write<<":"<<alu_op << endl;*/

    //Data Memory Test
    sc_signal<sc_lv<32>> address, write_data;
    sc_signal<sc_logic> MemWrite, MemRead;
    sc_signal<bool> clock;
    sc_signal<sc_lv<32>> read_data;

    MIPS::data_memory *DataMemory = new MIPS::data_memory("DataMemory");
    (*DataMemory)(address, write_data, MemWrite, MemRead, clock, read_data);
    
    sc_trace_file *tf = sc_create_vcd_trace_file("MIPS");
    sc_trace(tf, address, "address");
    sc_trace(tf, write_data, "write_data");
    sc_trace(tf, MemWrite, "MemWrite");
    sc_trace(tf, MemRead, "MemRead");
    sc_trace(tf, clock, "clock");
    sc_trace(tf, read_data, "read_data");

    address = "00000000000000000000000000001100";
    MemRead = SC_LOGIC_1;
    clock = 1;
    sc_start(1, SC_NS);
    cout << "Old Data:" << read_data << endl;
    MemRead = SC_LOGIC_0;

    sc_start(1, SC_NS);
    MemWrite = SC_LOGIC_1;
    write_data = "00000000000000000000000000101101";
    clock = 0;
    sc_start(1, SC_NS);
    clock = 1;
    MemWrite = SC_LOGIC_0;
    write_data = "0x00000000";

    MemRead = SC_LOGIC_1;
    sc_start(1, SC_NS);
    cout << "New Data:" << read_data << endl;
    MemRead = SC_LOGIC_0;


    sc_close_vcd_trace_file(tf);
    return 0;
}