#include "headers/flightmap.h"

using str = std::string;
using s_Flight = std::shared_ptr<Flight>;

// unsigned int Port::prtcount = 0; 
Port::Port(str code_in, float d_in)
    : code(code_in), splen(d_in) {/*CONSTRUCTOR*/}
//PRINT FUNCTION//
void Port::prt()
{
    std::cout << "\nAirport Code: " << this->code << '\n'
                << "Airport id: " << this->pheaploc << '\n'
                << "Current shortest time trip from start to this node: " << this->splen << '\n';
    if (this->depflights.size() == 0){
        std::cout << "There are no flights leaving " << this->code << std:: endl;
    }
    for(s_Flight flt : this->depflights){
        flt->prt();
    }
}
