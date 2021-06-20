#ifndef _LOG_H
#define _LOG_H

#include <iostream>

using namespace std;

enum LogType{
    DEBUG,
    INFO,
    WARN,
    ERROR
};

struct LogStruct{
    bool headers = false;
    LogType level = WARN;
};

extern LogStruct LogConfig;

class LOG{

private:
    bool opened = false;
    LogType msglevel = DEBUG;

    inline string getLabel(LogType type){
        string label;
        switch(type){
            case DEBUG: label = "DEBUG"; break;
            case INFO: label = "INFO"; break;
            case WARN: label = "WARN"; break;
            case ERROR: label = "ERROR"; break;
        }
        return label;
    }

public:
    LOG(){ }
    LOG(LogType type){
        msglevel = type;
        if(LogConfig.headers)
            operator << ("["+getLabel(type)+"] ");
    }
    ~LOG(){
        if(opened)
            cout << endl;
        opened = false;
    }

    template<class T>
    LOG &operator<<(const T &msg){
        if(msglevel >= LogConfig.level){
            cout << msg;
            opened = true;
        }
        return *this;
    }

};

#endif