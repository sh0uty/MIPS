#include "mux.h"

void MIPS::mux::set(){

    cout << x << " " << y << " " << s << endl;

    if(s.read() == SC_LOGIC_0)
        z.write(x.read());
    else
        z.write(y.read());

}