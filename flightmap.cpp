#include "headers/flightmap.h"

using str = std::string;
using s_Port = std::shared_ptr<Port>;
using s_Flight = std::shared_ptr<Flight>;

FlightMap::FlightMap(){/*CONSTRUCTOR*/}

FlightMap::FlightMap(int port_count, int flight_count)
    : portcount(port_count), flightcount(flight_count){/*CONSTRUCTOR*/}
    lkasjdlkfjasdfalksdjf
    asdlfjalsdf
    asldfjalsd
    

void FlightMap::genPorts()
{//generate ports
    s_Port newport;
    for (int i = 0 ; i < this->portcount ; i++){
        str portcode = FlightMap::genCode(3); //generate airport code
        newport = std::make_shared<Port>(portcode, 100); //create airport node with maximum splen
        // newport->pheaploc = this->portlist.size(); //tell the port where it's located in the list
        this->insertPort(newport); //push the port onto the heap
    }
}

void FlightMap::genFlights()
{//generate flights
    s_Flight newflight;
    // int exitflights = (rand() % 3+1);
    // int entryflights = (rand() % 3+1);

    for (int i = 0 ; i < this->flightcount; i++){
        float deptime = FlightMap::genTime(24); //gen random flight deptime less than 24hrs
        float length = FlightMap::genTime(6) + 1; //generate random flight length less than 12hrs this is the weight of the edge
        //randomize ports
        s_Port port1;
        s_Port port2;
        do
        {//get two different random ports from the port list
            port1 = this->portheap.at(rand() % this->portcount);
            port2 = this->portheap.at(rand() % this->portcount);
        } while(port1 == port2);
        //create the new flight
        newflight = std::make_shared<Flight>(port1, port2, deptime, length);
        //store it
        // this->flights.push_back(newflight);
        port1->adjlist.push_back(port2);
        port1->depflights.push_back(newflight); }

}

str FlightMap::genCode(int length_in)
{//generates a random capitalized string of length length_in
    str code = "";
    for(int i=0; i < length_in; i++){
        int num = rand() % 26;
        char letter = 'a' + num;
        code += toupper(letter);
    }
    return code;
}

float FlightMap::genTime(int MAX_HOUR)
{//generates random float representing a time of day
    float min = float(rand() % 61)/60.0;
    // float newmin = min/100.0;
    float time = (rand() % MAX_HOUR) + min;
    return time;
}

int FlightMap::insertPort(s_Port port_in)
{
    //push port on to the bottom of the heap
    if(this->portheap.size() == 0){
        this->portheap.push_back(port_in);
        port_in->pheaploc = 0; //record the location of the port in the heap for future decrease key operations
        return 0;
    }
    this->portheap.push_back(port_in);//add the port to the heap
    port_in->pheaploc = this->portheap.size() - 1;//tell it what it's index in the heap is
    //send port_in off to bubble up and return its settled locatioinlocation of inserted node.
    return this->bubbleUp(port_in->pheaploc);
}

int FlightMap::bubbleUp(int node_in)
{//bubbles a child node up the heap until it reaches its correct place, then returns that location
    // std::cout << "hit bubbleUp" << std::endl;
    int nodeout = node_in;
    int node_inparent= (nodeout - 1) / 2;
    s_Port oldport;
    //bubble up the inserted node if need be
    while(this->portheap[node_inparent]->splen > this->portheap[nodeout]->splen)
    {//while the parent's key is greater than the child's key
        //swap parent and child
        oldport = this->portheap[node_inparent]; //store parent node
        this->portheap[node_inparent] = this->portheap[nodeout]; //move child node up into parent slot
        this->portheap[node_inparent]->pheaploc = node_inparent; //update child pheaploc
        this->portheap[nodeout] = oldport;
        oldport->pheaploc = nodeout;
        //move parent and child indicies up the heap
        nodeout = node_inparent;
        node_inparent= (nodeout - 1) / 2;
    }
    return nodeout;
}

int FlightMap::bubbleDown(int node_in)
{
    // std::cout << "hit bubbleDown" << std::endl;
    //assume given node is the smallest of the three being considered
    int smallest = node_in;
    //get left and right child indicies of current node
    int l = 2*node_in + 1;
    int r = 2*node_in + 2;
    //left index hasn't overflowed the heap and the left child < current smallest node
    if (l < (this->portheap.size()-1) && this->portheap[l]->splen < this->portheap[smallest]->splen)
        smallest = l;
    //right index hasn't overflowed the heap and the right child < current smallest node
    if (r < this->portheap.size() && this->portheap[r]->splen < this->portheap[smallest]->splen)
        smallest = r;

    s_Port oldport;
    if (smallest != node_in)
    { //if a new smallest node was found
        //swap dem nodes
        s_Port oldport = this->portheap[node_in];
        this->portheap[node_in] = this->portheap[smallest]; //move node in the array
        this->portheap[node_in]->pheaploc = node_in; //change node's pheaploc to new location
        this->portheap[smallest] = oldport; //put oldport in it's new location
        oldport->pheaploc = smallest;//update the oldport's pheaploc value
        //recurse with new smallest
        bubbleDown(smallest);
    }
    return smallest;
}

s_Port FlightMap::extractMin()
{//removes the top node on the heap and bubbles down its replacement
    s_Port oldport;
    //Swap the last element of the heap with the first
    oldport = this->portheap.front();
    this->portheap.front() = this->portheap.back();
    this->portheap.front()->pheaploc = 0; //set new pheaploc for new root
    //delete last element from heap
    this->portheap.pop_back();
    //restore heap Property
    this->bubbleDown(0);
    std::cout << "extracting: " << std::endl;
    oldport->prt();
    return oldport;
}

int FlightMap::updateKey(s_Port port_in, float new_splen)
{//changes the key of a node in the heap and begins the process of moving it to the proper location
    std::cout << "hit update key" << std::endl;
    port_in->splen = new_splen;//change port's key in heap
    //now let's fix upwards in the heap
    if(port_in->pheaploc == 0)
    {
        port_in->splen = new_splen;
        return 0;
    }
    if(port_in->splen < this->portheap.at((port_in->pheaploc - 1)/2)->splen)
    {//if port's key is less than it's parent's key
        return this->bubbleUp(port_in->pheaploc); //bubble the port node up the heap
    }
    else
        return this->bubbleDown(port_in->pheaploc);
    
}