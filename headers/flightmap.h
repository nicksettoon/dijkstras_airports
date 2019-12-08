#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
// #include <ostream>
#include <cmath>

struct Flight;
struct Port {//struct for airport info (vertexes)
public:
    std::string code;
    std::vector<Port*> adjlist; //list of destination airports that are one flight from the current port
    std::vector<Flight*> depflights; //list of flights departing from this airport
    int dval;
    // int parentid;

    //CONSTRUCTOR//
    Port(std::string code, int d_in);
    friend std::ostream& operator <<(std::ostream& os, Port const* prt)
    {
        return os << "Airport Code: " << prt->code << '\n'
                  << "dval: " << prt->dval << '\n';
    };
};

struct Flight{//struct for flight data (edges)
    static int fltcount;
    int fltnum;
    Port* origin;
    Port* dest;
    float deptime; //departure time
    float arrtime; //arrival time

    Flight(Port* orig_in, Port* dest_in, int time_in, float length_in);

    void prt()
    {
        std::cout << "Num: " << this->fltnum << "\n\t"
                  << "Origin: " << this->origin->code << "\n\t"
                  << "Destination: " << this->dest->code << "\n\t";
        printf("Departure Time: %02.f:%02.f\n\t",floor(this->deptime), (this->deptime - floor(this->deptime))*100);
        printf("Arrival Time: %02.f:%02.f",floor(this->arrtime), (this->arrtime - floor(this->arrtime))*100);
        // << "Departure Time: " << floor(flt->deptime) << ":" << std::setw(2) << (flt->deptime - floor(flt->deptime))*100 << "\n\t"
        // << "Arrival Time: " << floor(flt->arrtime) << ":" << (flt->arrtime - floor(flt->deptime))*100;
    };
    // friend std::ostream& operator <<(std::ostream& os, Flight const* flt)
    // {
    //     os << "Num: " << flt->fltnum << "\n\t"
    //         << "Origin: " << flt->origin->code << "\n\t"
    //         << "Destination: " << flt->dest->code << "\n\t";
    //     printf("Departure Time: %02.f:%02.f\n\t",floor(flt->deptime), (flt->deptime - floor(flt->deptime))*100);
    //     printf("Arrival Time: %02.f:%02.f",floor(flt->arrtime), (flt->arrtime - floor(flt->arrtime))*100);
    //     return os << "\n";
    //     // << "Departure Time: " << floor(flt->deptime) << ":" << std::setw(2) << (flt->deptime - floor(flt->deptime))*100 << "\n\t"
    //     // << "Arrival Time: " << floor(flt->arrtime) << ":" << (flt->arrtime - floor(flt->deptime))*100;
    // };
};
