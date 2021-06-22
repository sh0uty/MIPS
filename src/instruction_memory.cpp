#include "instruction_memory.h"

void MIPS::instruction_memory::read_file(){

    LOG(INFO) << "IM start";

    ifstream stream("instructions.txt");

    if(stream.is_open()){

        int index = 0;

        for(std::string line; getline(stream, line); ){

            for(int i = 0; i < 32; i++){

                data_mem[index][31-i] = line[i];                
            }
            LOG(INFO) << data_mem[index];
            index++;
        }
        if(index > 0){
            last_instr_address.write((index-1)*4);
        }
        else
            last_instr_address.write("00000000000000000000000000000000");
    }
    stream.close();

}

void MIPS::instruction_memory::set_instruction(){
    LOG(INFO) << "IM read @" << read_address.read().range(31, 2).to_uint() << " -> " << data_mem[read_address.read().range(31, 2).to_uint()];
    instruction.write(data_mem[read_address.read().range(31, 2).to_uint()]);
    LOG(INFO) << "IM instruction written with " << instruction.read();
}