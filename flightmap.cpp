#include "headers/flightmap.h"

using str = std::string;

Port::Port(str code_in, int d_in)
    : code(code_in), dval(d_in) {/*CONSTRUCTOR*/}

Flight::Flight(Port* orig_in, Port* dest_in, int time_in, float length_in)
    : fltnum(fltcount++), origin(orig_in), dest(dest_in), deptime(time_in)
    {/*CONSTRUCTOR*/
        float endtime = this->deptime + length_in;
        if (endtime > 24){
            this->arrtime = endtime - 24;
        }
        else
            this->arrtime = endtime;
    }

// Flight::prt()
// {//prints flight information
//     out <<
// }