#include "pc.h"

void MIPS::pc::load_address(){

    LOG(INFO) << "PC load_address start";
    current_address.write(address);

}

void MIPS::pc::save_address(){

    LOG(INFO) << "PC save_address start";
    address = address_to_load.read();

}