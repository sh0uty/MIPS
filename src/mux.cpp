#include "mux.h"

void MIPS::mux::set(){

    if(s.read() == SC_LOGIC_0)
        z.write(x.read());
    else
        z.write(y.read());

}