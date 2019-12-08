#pragma once
#include <iostream>
#include <vector>

struct HNode {
    int vid;
    int dvalue = 0;

    //CONSTRUCTOR//
    HNode(int vid_in);
};

class Heap{
    int kary;
    //CONSTRUCTOR//
public:
    Heap(int k_in);
    std::vector<HNode*> heap;
    //FUNCTIONS//
    HNode* extractMin();
    int insert(HNode* node_in);
    void heapify(int start_node);
    // void decrease_key (int heap_pos[],int id, distval);
    // void swap(HeapObject heap[], int heap_pos[], int child, int parent );
};