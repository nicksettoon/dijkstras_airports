#include "headers/flightmap.h"

using str = std::string;
using s_Port = std::shared_ptr<Port>;
using s_Flight = std::shared_ptr<Flight>;

unsigned int Flight::fltcount = 0; 
Flight::Flight(s_Port orig_in, s_Port dest_in, unsigned int time_in, float length_in)
    : fltnum(fltcount++), origin(orig_in), dest(dest_in), deptime(time_in), length(length_in)
    {/*CONSTRUCTOR*/
        float endtime = this->deptime + length_in;
        if (endtime > 24){
            this->arrtime = endtime - 24;
        }
        else
            this->arrtime = endtime;
    }
//PRINT FUNCTION//
void Flight::prt()
{
    std::cout << "Flight num: " << this->fltnum << "\n\t"
                << "Origin: " << this->origin->code << "\n\t"
                << "Destination: " << this->dest->code << "\n\t";
    printf("Departure Time: %02.f:%02.f\n\t",floor(this->deptime), (this->deptime - floor(this->deptime))*60);
    printf("Arrival Time: %02.f:%02.f\n\t",floor(this->arrtime), (this->arrtime - floor(this->arrtime))*60);
    printf("Length: %02.f:%02.f\n",floor(this->length), (this->length - floor(this->length))*60);
};
