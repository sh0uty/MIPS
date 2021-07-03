#include "mux.h"

template<class T>
void MIPS::mux<T>::set(){
    T temp;
    if(s.read() == SC_LOGIC_0){
        temp = x.read();
        z.write(temp);
    }
    else{
        temp = y.read();
        z.write(temp);
    }
    LOG(INFO) << "MUX "<< this->name() << " - in1: " << x.read() << " - in2: " << y.read() << " - s: " << s.read() << " - out: " << temp;
}

template class MIPS::mux<sc_lv<5>>;
template class MIPS::mux<sc_lv<32>>;