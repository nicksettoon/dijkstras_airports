#include "headers/heap.h"

HNode::HNode(int vid_in) 
    : vid(vid_in), dvalue(0){/*CONSTRUCTOR*/}

Heap::Heap(int k_in) 
    : kary(k_in) {/*CONSTRUCTOR*/}

int Heap::insert(HNode* node_in)
{
    if(this->heap.size() == 0)
    {
        this->heap.push_back(node_in);
    }
    else
        this->heap.push_back(node_in);

    // bool flag = true;
    int childi = this->heap.size() - 1;
    int parenti = (childi - 1) / this->kary;
    HNode* temp;

    // while(flag == true && parenti != childi){
        // if(this->heap[parenti] > this->heap[childi]){
    while(this->heap[parenti] > this->heap[childi]){
        temp = this->heap[parenti];
        this->heap[parenti] = this->heap[childi];
        this->heap[childi] = temp;
        childi = parenti;
        parenti = (childi - 1) / this->kary;
    }
    //return location of inserted node.
    return 1;
}

void Heap::heapify(int parent_node)
{
    int smallest = parent_node;
    if(this->kary == 2)
    {
        int l = 2*parent_node + 1;
        int r = 2*parent_node + 2;

        if (l < this->heap.size() && this->heap[l] < this->heap[smallest])
            smallest = l;
        if (r < this->heap.size() && this->heap[r] < this->heap[smallest])
            smallest = r;
    }
    //Swap values if necessary
    if (smallest != parent_node)
    {
        HNode* temp = this->heap[parent_node];
        this->heap[parent_node] = this->heap[smallest];
        this->heap[smallest] = temp;
        heapify(smallest);
    }
}

HNode* Heap::extractMin()
{
    //Swap the last element of the Array with the first
    HNode* temp;
    temp = this->heap[0];
    this->heap[0] = this->heap[this->heap.size() - 1];
    // this->heap[this->heap.size - 1] = temp;
    this->heap.pop_back(); //delete last element from heap  

    //restore heap Property
    this->heapify(0);
    return temp;
}

// void Heap::decrease_key (int heap_pos_in, int id, int distval) {
//     int j = heap_pos_in[id]; //j is the position of id in heap[];
//     this->heap[j].dvalue = distval; //changed dvalue
//     //now let's fix upwards in the heap
//     while ((this->heap[j].dvalue < this->heap[(j-1)/2].dvalue) && (j > 0))
//     {
//         this->swap(heap_pos_in, j, (j-1)/2);
//         j = (j - 1)/2;
//     }
// }

// void Heap::swap(int heap_pos_in[], int child_in, int parent_in)
// {
//     int temp1id = this->heap[child_in]->vid;
//     int temp1d = this->heap[child_in]->dvalue;

//     this->heap[child_in]->vid = this->heap[parent_in]->vid;
//     this->heap[child_in]->dvalue = this->heap[parent_in]->dvalue;
//     this->heap[parent_in]->vid = temp1id;
//     this->heap[parent_in]->dvalue = temp1d;

//     heap_pos_in[this->heap[child_in]->vid] = child_in;
//     heap_pos_in[this->heap[parent_in]->vid = parent_in;
// } // note the role of dereferencing array heap_pos_in