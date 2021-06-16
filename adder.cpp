#include "adder.h"

void MIPS::adder::add(){

    sc_int<32> temp;

    temp = x.read() + y.read();

    cout<<x<<" + "<<y<< " = "<<temp<<endl;
    z.write(temp);
}