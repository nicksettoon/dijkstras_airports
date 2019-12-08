#include "headers/main.h"
#include "headers/flightmap.h"

using str = std::string;
using s_Port = std::shared_ptr<Port>;
using s_Flight = std::shared_ptr<Flight>;

int main()
{
    //declare map sizes
    int portcount = 5;
    int flightcount = 10;
    //instantiate flight map
    std::shared_ptr<FlightMap> map = std::make_shared<FlightMap>(portcount, flightcount);
    map->genPorts();
    map->genFlights();
    map->updateKey(map->portheap.at(0), 0); //give first airport have a shortest path of 0
    std::cout << map; //print map
    s_Port startport = map->portheap.at(0); //starting port is the first port in the list
    std::cout << "Starting Dijkstra's Algorithm"<< std::endl;
    while(map->portheap.size() > 0)
    {//while there are ports left in the heap
        s_Port cport = map->extractMin();//grab the port with the smallest splen
        std::cout << "Airport: " << cport->code << std::endl;
        float t;
        float newsp;
        for (int i = 0; i < cport->depflights.size(); i++)
        {//for each flight leaving the current port
            s_Flight e = cport->depflights.at(i); //get flight object
            s_Port w = e->dest; //get dest port
            //calc edge weight (flight time cost)
            float t = (e->arrtime - e->deptime) + 1; //(arrival - departure) + 1 hour layover
            float newsp = t + cport->splen; //get possible new shortest path to next port
            std::cout << "\tFlight: " << e->fltcount << "\t"
                      << "\tDest: " << w->code << "\t" 
                      << "\tWeight: " << t << "\t"
                      << "\tNewPossibleSP: " << newsp << std::endl; 
            if((newsp < w->splen))
            {//if this flight is a shorter path from startport to w than what w already has stored
                std::cout << "\n\tChanging destination's splen to: " << newsp; 
                //change the destination's splen value to the newsp, bubbling up or down as needed
                int heaploc = map->updateKey(w, newsp);
                std::cout << "\n\tNode moved to: " << w->pheaploc << " with splen: " << newsp << std::endl; 
            }
        }
    }
    return 1;
}