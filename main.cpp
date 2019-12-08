// #include <iostream>
// #include <vector>
#include "headers/heap.h"
#include "headers/flightmap.h"

using str = std::string;
// auto& out = std::cout;
// auto& end = std::endl;

int Flight::fltcount = 0; 
float genTime(int MAX_HOUR)
{
    float min = float(rand() % 61)/100.0;
    // float newmin = min/100.0;
    float time = (rand() % MAX_HOUR) + min;
    return time;
}

int main()
{
    int size = 10;
    Port* ports[size];
    Flight* flights[size*2];
    Heap* heap =  new Heap(2);
    str arr[size] = {"SAN", "ASE", "DAB", "MCO", "AUG", "BOS", "BTL", "BTR", "ACY", "ALB"}; 

    //fill ports
    for (int i = 0 ; i < size ; i++){
        Port* newport = new Port(arr[i], 0);
        ports[i] = newport;
    }
    //fill flights
    for (int i = 0 ; i < 2*size ; i++){
        float deptime = genTime(24); //gen random flight deptime less than 24hrs
        float length = genTime(12) + 1; //generate random flight length less than 12hrs
        //randomize ports
        Port* port1;
        Port* port2;
        do
        { 
            port1 = ports[rand() % size];
            port2 = ports[rand() % size];
        } while(port1 == port2);

        Flight* newflight = new Flight(port1, port2, deptime, length);
        flights[i] = newflight;
        port1->adjlist.push_back(port2);
        port1->depflights.push_back(newflight);
    }

    while(heap->heap.size() > 0){
        HNode* extnode = heap->extractMin();
        int x = extnode->vid;
        for (int i = 0; i < n; i++){
            int w = verts[x]->adjlist[i];
        }
    }
    // for (int i = 0 ; i < size ; i++){
    //     HNode* node = heap->extractMin();
    //     std::cout << node->vid << ":" << node->dvalue << "\t";
    // }


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
// ................int w=V[x].adj_list[i];
// ................if (V[x].weight[i] + V[x].dvalue < V[w].dvalue) {
// ........................V[w].dvalue=V[x].weight + V[x].dvalue;
// ........................V[w].pid = x;
// ........................decrease_key(heap, heap_pos, w, V[w].dvalue);
// ................}
// ........} //for loop for x's adjacency list ends
// }
// HeapObject extract_min(heap){
// //outputs a tuple <vid, dvalue> with smallest dvalue .... allocates memory separately
// //it erases the tuple from heap and decrements heapsize
// //uses swap function below

// .....
// }