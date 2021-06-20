#include "shifter.h"

void MIPS::shifter::shift_left(){
    y.write(x.read() << 2);
}