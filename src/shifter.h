#ifndef _SHIFTER_H
#define _SHIFTER_H

#include "systemc.h"

#include "LOG.h"

namespace MIPS{
    template<class T, class U>
    class shifter : public sc_module{
    public:

        sc_in<T> x;
        sc_out<U> y;
        
        void shift_left();

        SC_CTOR(shifter){
            SC_METHOD(shift_left);
            dont_initialize();
            sensitive << x;
        };

    };

}
#endif