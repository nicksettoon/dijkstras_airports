#include "headers/main.h"
#include "headers/flightmap.h"

using str = std::string;
using s_Port = std::shared_ptr<Port>;
using s_Flight = std::shared_ptr<Flight>;
using s_Map = std::shared_ptr<FlightMap>;

void startPrompt(s_Map map)
{
    unsigned int usrinpt;
    std::cout << "\nHow many airports would you like?"
              << "\nIf you don't enter an integer, it will be turned into a 0."
              << "\nThis is a prompt: ";
    std::cin >> map->portcount;
    std::cout << "How many flights would you like?"
              << "\nThis is a prompt: ";
    std::cin >> map->flightcount;
    map->genPorts();
    map->genFlights();

    std::cout << "\nPlease pick a starting airport from the list."
              << "\nInput the airport's id."
              << " Between 0 and " << map->portcount - 1
              << "\nThis is a prompt: ";
    std::cin >> usrinpt;
    std::cout << usrinpt << std::endl;
    map->startport = map->portheap.at(usrinpt); //get starting port
        
    std::cout << "\nPlease pick an ending airport from the list."
              << "\nInput the airport's id."
              << "( Between 0 and " << map->portcount - 1
              << "\nThis is a prompt: ";
    std::cin >> usrinpt;
    std::cout << usrinpt << std::endl;
    map->endport =  map->portheap.at(usrinpt); //get ending port

    std::cout << "Please enter a starting time in 24hr form:"
              << "\nHours(max:23): ";
    std::cin >> usrinpt;
    map->starttime = float(usrinpt);
    std::cout << "Minutes(max:60): ";
    std::cin >> usrinpt;
    map->starttime = map->starttime + (float(usrinpt)/60.0); //convert time to float

    map->updateKey(map->startport, 0); //give first airport a shortest path of 0 since you're already there
    std::cout << "\nStarting Airport:";
    map->startport->prt();
    std::cout << "\nEnding Airport:";
    map->endport->prt();
    std::cout << "\nStarting time: " << map->starttime <<std::endl;
    std::cout << "Press any key, then enter, to start." <<std::endl;    
    std::cin >> usrinpt;
    std::cout << "Starting Dijkstra's Algorithm"<< std::endl;
}

s_Flight checkFlights(s_Map map, s_Port cport)
{//for loop to check all departing flights from a given airport
    float t;
    float newsp;
    s_Flight spflight = cport->depflights.at(0); //assume first flight is shortest path flight
    s_Port W = spflight->dest;
    for (int i = 0; i < cport->depflights.size(); i++)
    {//for each flight leaving the current port
        s_Flight e = cport->depflights.at(i); //get flight object
        s_Port w = e->dest; //get dest port

        //calc edge weight (flight time cost)
        if (e->arrtime < e->deptime)
            t = (24 - e->deptime) + e->arrtime + 1; //(full day - dep) + morning + 1 hour layover
        else
            t = (e->arrtime - e->deptime) + 1; //(arrival - departure) + 1 hour layover

        float newsp = t + cport->splen; //get possible new shortest path to next port
        //print flight data
        // std::cout   << "\n\tFlight: " << e->fltnum << "\t"
        //             << "\tDest: " << w->code << "\t" 
        //             << "\tWeight: " << t << "\t"
        //             << "\tNewPossibleSP: " << newsp; 
        //check shortest path at w vs current shortest path
        if((newsp < w->splen))
        {//if this flight is a shorter path from startport to w than what w already has stored
            // std::cout << "\n\tChanging destination's splen to: " << newsp; 
            //change the destination's splen value to the newsp, bubbling up or down as needed
            int heaploc = map->updateKey(w, newsp);
            // std::cout << "\n\tNode moved to:" << w->pheaploc << " with splen:" << newsp << std::endl; 
        }
        else
            // std::cout << "\n\tDid not update splen for :" << w->code;
        //final comparison of shortest flight after all destination splens have been updated
        if(W->splen > w->splen)
        {//if current shortest flight is longer than current destination's flight
            spflight = e;
        }
    }
    return spflight;
}

int main()
{
    //declare map sizes
    int portcount = 15;
    int flightcount = 30;
    //instantiate flight map
    std::shared_ptr<FlightMap> map = std::make_shared<FlightMap>(portcount, flightcount);
    map->genPorts();
    map->genFlights();
    map->startport = map->portheap.at(1); //get starting port
    map->endport = map->portheap.at(13); //get starting port
    map->starttime = 4.20; //yoloswag420blazeit
    // std::shared_ptr<FlightMap> map = std::make_shared<FlightMap>();
    std::cout << map; //print the initial map
    // startPrompt(map);

    s_Port cport = map->startport; //set current port to start port
    while(map->portheap.size() > 0)
    {//while there are ports left in the heap
        // std::cout << "\nAssessing airport: " << cport->code
                //   << "\nIt has " << cport->depflights.size() << " departing flights." << std:: endl;
        s_Flight spflight = checkFlights(map, cport);
        cport = map->extractMin();//grab the port with the smallest splen
        if(spflight->dest == cport) 
        {//Destination extracted from heap was the destination of the shortest length flight
            std::cout << map->spset.size() << ". Success!" << std::endl;
            spflight->prt();
            std::cout << "Adding flight to trip." << std::endl;
            map->spset.push_back(spflight); //add flight to path vector
        }
        else
            std::cout << "Failure. Kill yourself." <<std::endl;
    }
    return 1;
}