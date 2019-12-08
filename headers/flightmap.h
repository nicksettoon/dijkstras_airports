#pragma once
#include "main.h"

struct Flight;
struct Port {//struct for airport info (vertexes)
    static unsigned int prtcount;
    unsigned int pheaploc; //port id (its index in the flightmap's portlist)
    std::string code; //the airport code
    std::vector<std::shared_ptr<Port>> adjlist; //list of destination airports that are one flight from the current port
    std::vector<std::shared_ptr<Flight>> depflights; //list of flights departing from this airport
    float splen;
    // int parentid; what this for?
    //CONSTRUCTOR//
    Port(std::string code, float d_in);
    void prt();
};

struct Flight{//struct for flight data (edges)
    static unsigned int fltcount;
    unsigned int fltnum;
    std::shared_ptr<Port> origin;
    std::shared_ptr<Port> dest;
    float deptime; //departure time
    float arrtime; //arrival time
    float length;  //weight of the edge

    //CONSTRUCTOR//
    Flight(std::shared_ptr<Port> orig_in, std::shared_ptr<Port> dest_in, unsigned int time_in, float length_in);
    void prt();
};

class FlightMap
{//class for creating and holding all the travel data related to a graph of airports and flights
public:
    int portcount;
    int flightcount;
    std::vector<std::shared_ptr<Port>> portheap{}; //vector of port pointers for use with heap functions
    //Algorithm starting conditions//
    float starttime;
    std::shared_ptr<Port> startport;
    std::shared_ptr<Port> endport;
    //set of flights to get to endport in fastest time
    std::vector<std::shared_ptr<Flight>> spset{}; //vector of flight pointers

    //CONSTRUCTOR//
    FlightMap();
    FlightMap(int port_count, int flight_count);
    
    //GENERATOR FUNCTIONS//
    void genPorts();
    void genFlights();
    static float genTime(int MAX_HOURS);
    static std::string genCode(int code_length);

    //HEAP FUNCTIONS//
    int bubbleUp(int start_node);
    int bubbleDown(int start_node);
    std::shared_ptr<Port> extractMin();
    int insertPort(std::shared_ptr<Port> port_in);
    int updateKey(std::shared_ptr<Port> port_in, float new_key);

    //PRINT FUNCTION//
    friend std::ostream& operator <<(std::ostream& os, std::shared_ptr<FlightMap> const fltmp)
    {
        for(std::shared_ptr<Port> p : fltmp->portheap){
            p->prt();
        }
        return os << "\n";
    };
};
