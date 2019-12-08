// #include <iostream>
// #include <vector>
#include "headers/heap.h"
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
    // std::cout << map; //print map
    // startport = map->portlist.at(0); //starting port is the first port in the list
    // actual djikstras
    while(map->portheap.size() > 0)
    {//while there are ports left in the heap
        s_Port* cport = map->extractMin(map->portheap);//grab the port with the smallest splen
        int x = cport->pheaploc;
        for (int i = 0; i < cport->depflights.size(); i++)
        {//for each flight leaving the current port
            s_Flight e = cport->depflights.at(i); //get flight object
            s_Port w = e->dest //get dest port
            //calc edge weight (flight time cost)
            float t = (e->arrtime - e->deptime) + 1; //(arrival - departure) + 1 hour layover
            float newsp = t + cport->splen; //get possible new shortest path to next port
            if((newsp < w->splen)
            {//if this flight is a shorter path from startport to w than what w already has stored
                w->splen = t + cport->splen;
                // w->pheaploc = x; why is this necessary?
                map->decreaseKey(map->portheap, w, )

            }
        }
    }

    print()
    return 1;
}
//n=Readsize(inputfile);

// Vertex* verts[n];
// HeapObject* heap[n]; //initialize all to infinity and source is assumed to be

// vertex id = 0;
// heap[0].dvalue=0;

// int heap_pos[n]; //initialize to heap_pos[i]=i;
// //dereferencing array to get a handle on arbitrary node in the heap.
// int heap_size=n;
// //assume inputfile list adacency list for each vertex...one line per vertex ...
// // ..... within each line space delimited for list of edges
// // parallel list for edge weights

// for (i=0;i<n;i++){
//     verts[i]->adj_list;
//     verts[i]->edgeweights;
//     // read_line(V[i].adj_list,V[i].weights);  //also takes care of allocating appropriate memory to V[i].adj_list and V[i].weights
// }

// //real algorithm starts below
// while (heapsize > 0)
// {
//     HeapObject h = extract_min(heap);
// ........int x = h.vid;
// ........for (i=0;i<n;i++)
// ........{
// ................int e=V[x].adj_list[i];
// ................if (V[x].weight[i] + V[x].dvalue < V[e].dvalue) {
// ........................V[e].dvalue=V[x].weight + V[x].dvalue;
// ........................V[e].pheaploc = x;
// ........................decrease_key(heap, heap_pos, e, V[e].dvalue);
// ................}
// ........} //for loop for x's adjacency list ends
// }
// HeapObject extract_min(heap){
// //outputs a tuple <vid, dvalue> with smallest dvalue .... allocates memory separately
// //it erases the tuple from heap and decrements heapsize
// //uses swap function below

// .....
// }