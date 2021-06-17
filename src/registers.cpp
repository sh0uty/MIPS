#include "registers.h"

void MIPS::registers::read(){
    read_data_1.write(reg_mem[read_reg_1.read().to_uint()]);
    read_data_2.write(reg_mem[read_reg_2.read().to_uint()]);
}

void MIPS::registers::write(){

    if(reg_write.read() == SC_LOGIC_0)
        return;

    reg_mem[write_reg.read().to_uint()] = write_data.read();
    cout << "Writing REG " << write_reg.read() << " with value " << write_data.read() << endl;
}

void MIPS::registers::debugRegisters(){
    cout << "DEBUGGED REGISTERS" << endl;
    for(size_t i = 0; i < 32; i++){
        if (i < 10){
            cout << "REG " << i << "  - " << reg_mem[i] << endl;
        }else{
            cout << "REG " << i << " - " << reg_mem[i] << endl;
        }
    }

}