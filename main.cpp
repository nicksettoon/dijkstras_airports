#include "headers/main.h"
#include "headers/flightmap.h"

using str = std::string;
using s_Port = std::shared_ptr<Port>;
using s_Flight = std::shared_ptr<Flight>;

int main()
{
    //declare map sizes
    int portcount = 10;
    int flightcount = 30;
    //instantiate flight map
    std::shared_ptr<FlightMap> map = std::make_shared<FlightMap>(portcount, flightcount);
    map->genPorts();
    map->genFlights();
    // std::cout << map; //print map
    // startport = map->portlist.at(0); //starting port is the first port in the list
    // actual djikstras
    while(map->portheap.size() > 0)
    {//while there are ports left in the heap
        s_Port cport = map->extractMin();//grab the port with the smallest splen
        // int x = cport->pheaploc;
        float t;
        float newsp;
        for (int i = 0; i < cport->depflights.size(); i++)
        {//for each flight leaving the current port
            s_Flight e = cport->depflights.at(i); //get flight object
            s_Port w = e->dest; //get dest port
            //calc edge weight (flight time cost)
            float t = (e->arrtime - e->deptime) + 1; //(arrival - departure) + 1 hour layover
            float newsp = t + cport->splen; //get possible new shortest path to next port
            if((newsp < w->splen))
            {//if this flight is a shorter path from startport to w than what w already has stored
                //change the destination's splen value to the newsp, bubbling up or down as needed
                map->updateKey(w, newsp);
            }
        }
    }
    // print()
    return 1;
}