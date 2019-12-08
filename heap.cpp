#include "headers/heap.h"

using s_Port = std::shared_ptr<Port>;
using p_vec = std::vector<s_Port>;

// HNode::HNode(int port_ptr) 
//     : portptr(port_ptr), dvalue(0){/*CONSTRUCTOR*/}

HeapInterface::HeapInterface() {/*CONSTRUCTOR*/}

int HeapInterface::insertPort(p_vec heap_in, s_Port port_in)
{
    //push port on to the bottom of the heap
    heap_in.push_back(port_in);
    //init parent and child indicies for bubble up
    int childi = heap_in.size() - 1;
    //return location of inserted node.
    return this->bubbleUp(heap_in, childi);
}

void HeapInterface::heapify(p_vec heap_in, int node_in)
{
    //assume given node is the smallest of the three being considered
    int smallest = node_in;
    if(this->kary == 2)
    {//if heap is binary
        //get left and right child indicies of current node
        int l = 2*node_in + 1;
        int r = 2*node_in + 2;

        //left index hasn't overflowed the heap and the left child < current smallest node
        if (l < (heap_in.size()-1) && heap_in[l]->splen < heap_in[smallest]->splen)
            smallest = l;
        //right index hasn't overflowed the heap and the right child < current smallest node
        else if (r < heap_in.size() && heap_in[r]->splen < heap_in[smallest]->splen)
            smallest = r;
    }
    if (smallest != node_in)
    { //if a new smallest node was found
        //swap dem nodes
        s_Port temp = heap_in[node_in];
        heap_in[node_in] = heap_in[smallest];
        heap_in[smallest] = temp;
        //recurse with new smallest
        heapify(smallest);
    }
}

s_Port* HeapInterface::extractMin(p_vec heap_in)
{
    s_Port* temp;
    //Swap the last element of the Array with the first
    temp = heap_in.front();
    heap_in.front() = heap_in.back();
    //delete last element from heap
    heap_in.pop_back();
    //restore heap Property
    this->heapify(0, heap_in);
    return temp;
}

void HeapInterface::decreaseKey (p_vec heap_in, p_vec portlist_in, s_Port dest_in)
{
    // dest_in->pheaploc;
    // dest_in->splen;
    int j = ; //j is the position of destination in heap[]
    heap_in[dest_in->pheaploc]->splen = distval; //changed dvalue
    //now let's fix upwards in the heap
    while ((this->heap[j].dvalue < this->heap[(j-1)/2].dvalue) && (j > 0))
    {
        this->swap(heap_pos_in, j, (j-1)/2);
        j = (j - 1)/2;
    }
}
void decrease_key (heap, heap_pos, id, distval) {
    j=heap_pos[id]; //j is the position of id in heap[];
    heap[j].dvalue = distval; //changed dvalue
    // now let's fix upwards in the heap
    while ((heap[j].dvalue < heap[(j-1)/2].dvalue) && (j > 0))
    {
        swap(heap,heap_pos,j,(j-1)/2);
        j=(j-1)/2;
    }
}

int HeapInterface::bubbleUp(p_vec heap_in, int child_index)
{//bubbles a child node up the heap until it reaches its correct place, then returns that location
    childiout = child_index
    int parenti = (childiout - 1) / this->kary;
    s_Port temp;
    //bubble up the inserted node
    while(heap_in[parenti]->splen > heap_in[childiout]->splen)
    {//while the parent's key is greater than the child's key
        //swap parent and child
        temp = heap_in[parenti];
        heap_in[parenti] = heap_in[childiout];
        heap_in[childiout] = temp;
        //move parent and child indicies up the heap
        childiout = parenti;
        parenti = (childiout - 1) / this->kary;
    }
    return childiout;
}

vvoid swap(HeapObject heap[], int heap_pos[], int child, int parent )
{
    //store child node's info
    temp1id = heap[child].vid;
    temp1d = heap[child].dvalue;

    //set child info to parent's info
    heap[child].vid = heap[parent].vid;
    heap[child].dvalue = heap[parent].dvalue;

    //set parent info to child's old info
    heap[parent].vid = temp1id;
    heap[parent].dvalue = temp1d;

    //some bullshit
    heap_pos[heap[child].vid] = child;
    heap_pos[heap[parent].vid] = parent;
} // note the role of dereferencing array heap_pos