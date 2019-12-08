#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

#include "flightmap.h"

// struct HNode {
//     std::shared_ptr<Port> portptr;
//     int dvalue = 0;

//     //CONSTRUCTOR//
//     HNode(int port_ptr);
// };

class HeapInterface{
    //CONSTRUCTOR//
    HeapInterface();
    void heapify(std::vector<std::shared_ptr<Port>> heap_in, int start_node);
public:
    //FUNCTIONS//
    std::shared_ptr<Port> extractMin(std::vector<std::shared_ptr<Port>> heap_in);
    int insertPort(std::vector<std::shared_ptr<Port>> heap_in, std::shared_ptr<Port> port_in);
    void decreaseKey (std::vector<std::shared_ptr<Port>> heap_in, int heap_pos[],int id, float distval);
    // void swap(HeapObject heap[], int heap_pos[], int child, int parent );
};