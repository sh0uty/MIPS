#include "shifter.h"

template<class T, class U>
void MIPS::shifter<T, U>::shift_left(){
    y.write(x.read() << 2);
}

template class MIPS::shifter<sc_lv<32>, sc_lv<32>>;
template class MIPS::shifter<sc_lv<26>, sc_lv<28>>;