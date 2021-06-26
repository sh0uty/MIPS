#include "mux.h"

template<class T>
void MIPS::mux<T>::set(){
    T temp = x.read();
    if(s.read() == SC_LOGIC_0)
        z.write(temp);
    else
        z.write(temp);
    LOG(INFO) << "MUX "<< this->name() << " >> " << temp;
}

template class MIPS::mux<sc_lv<5>>;
template class MIPS::mux<sc_lv<32>>;