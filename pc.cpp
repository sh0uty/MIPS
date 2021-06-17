#include "pc.h"

void MIPS::pc::load_address(){

    current_address.write(address);

}

void MIPS::pc::save_address(){

    address = address_to_load.read();

}