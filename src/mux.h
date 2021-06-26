#ifndef _MUX_H
#define _MUX_H

#include "systemc.h"

#include "LOG.h"

namespace MIPS{

    template<class T>
    class mux : public sc_module{
        public:

        sc_in<T> x, y;
        sc_in<sc_logic> s;
        sc_out<T> z;

        void set();

        SC_CTOR(mux){
            SC_METHOD(set);
            dont_initialize();
            sensitive << x << y << s;
        };
    };

}

#endif