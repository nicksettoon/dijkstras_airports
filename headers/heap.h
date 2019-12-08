#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

#include "flightmap.h"

class HeapInterface{
    //CONSTRUCTOR//
public:
    HeapInterface();
    int bubbleUp(std::vector<std::shared_ptr<Port>> heap_in, int start_node);
    int bubbleDown(std::vector<std::shared_ptr<Port>> heap_in, int start_node);
    //FUNCTIONS//
    std::shared_ptr<Port> extractMin(std::vector<std::shared_ptr<Port>> heap_in);
    int insertPort(std::vector<std::shared_ptr<Port>> heap_in, std::shared_ptr<Port> port_in);
    int updateKey(std::vector<std::shared_ptr<Port>> heap_in, std::shared_ptr<Port> port_in, float new_key);
    // void swap(HeapObject heap[], int heap_pos[], int child, int parent );
};