#include "data_memory.h"

void MIPS::data_memory::read(){
    if(MemRead.read() == SC_LOGIC_1){
        cout << "Read:" << data_mem[address.read().range(6,2).to_uint()] << " From data_mem at:" << address.read().range(6,2).to_uint() << endl; 
        read_data.write(data_mem[address.read().range(6,2).to_uint()]);
    }
    else{
        read_data.write("0x00000000");
    }
}

void MIPS::data_memory::write(){
    if(MemWrite.read() == SC_LOGIC_1){
        cout << "Write:" << write_data.read() << " Into data_mem at:" << address.read().range(6,2).to_uint() << endl;
        data_mem[address.read().range(6,2).to_uint()] = write_data.read();
    }
}