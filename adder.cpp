#include "adder.h"

void MIPS::adder::add(){
    sc_uint<32> temp;

    temp = x.read().to_uint() + y.read().to_uint();

    cout << x << " + " << y << " = " << temp << endl;

    z.write(temp);
}