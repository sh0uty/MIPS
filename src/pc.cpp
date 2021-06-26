#include "pc.h"

void MIPS::pc::load_address(){

    LOG(INFO) << "PC load_address " << address;
    current_address.write(address);

}

void MIPS::pc::save_address(){

    LOG(INFO) << "PC save_address " << address_to_load.read();
    address = address_to_load.read();

}

void MIPS::pc::set_address(){

    if(clk.read() == 0){

        LOG(INFO) << "PC save_address " << address_to_load.read();
        address = address_to_load.read();

    }

    LOG(INFO) << "PC load_address " << address;
    current_address.write(address);

}