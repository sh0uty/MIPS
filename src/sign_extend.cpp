#include "sign_extend.h"

void MIPS::sign_extend::extend(){
    //y <= std_logic_vector(resize(signed(x), y'length));
    sc_lv<32> temp;

    if(x.read()[15] == "1"){
        LOG(INFO) << "Sign_Extend sign Bit is 1";
        temp.range(31, 16) = "1111111111111111";
    }else{
        LOG(INFO) << "Sign_Extend sign Bit was 0";
        temp.range(31, 16) = "0000000000000000";
    }

    temp.range(15, 0) = x.read();

    y.write(temp);

}