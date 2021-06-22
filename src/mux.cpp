#include "mux.h"

template<class T>
void MIPS::mux<T>::set(){

    if(s.read() == SC_LOGIC_0)
        z.write(x.read());
    else
        z.write(y.read());
}

template class MIPS::mux<sc_lv<5>>;
template class MIPS::mux<sc_lv<32>>;