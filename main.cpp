// #include <iostream>
// #include <vector>
#include "headers/heap.h"
#include "headers/flightmap.h"

using str = std::string;
// auto& out = std::cout;
// auto& end = std::endl;

int main()
{
    int portcount = 10;
    int flightcount = 30;
    std::shared_ptr<FlightMap> map = std::make_shared<FlightMap>(portcount, flightcount);

    std::cout << map;
    // actual djikstras
    // while(heap->heap.size() > 0){
    //     HNode* extnode = heap->extractMin();
    //     int x = extnode->vid;
    //     for (int i = 0; i < n; i++){
    //         int w = verts[x]->adjlist[i];
    //     }
    // }
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