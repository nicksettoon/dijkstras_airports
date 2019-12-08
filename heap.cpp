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

void HeapInterface::bubbleDown(p_vec heap_in, int node_in)
{
    //assume given node is the smallest of the three being considered
    int smallest = node_in;
    //get left and right child indicies of current node
    int l = 2*node_in + 1;
    int r = 2*node_in + 2;
    //left index hasn't overflowed the heap and the left child < current smallest node
    if (l < (heap_in.size()-1) && heap_in[l]->splen < heap_in[smallest]->splen)
        smallest = l;
    //right index hasn't overflowed the heap and the right child < current smallest node
    if (r < heap_in.size() && heap_in[r]->splen < heap_in[smallest]->splen)
        smallest = r;

    s_Port oldport;
    if (smallest != node_in)
    { //if a new smallest node was found
        //swap dem nodes
        s_Port oldport = heap_in[node_in];
        heap_in[node_in] = heap_in[smallest]; //move node in the array
        heap_in[node_in]->pheaploc = node_in; //change node's pheaploc to new location
        heap_in[smallest] = oldport; //put oldport in it's new location
        oldport->pheaploc = smallest;//update the oldport's pheaploc value
        //recurse with new smallest
        bubbleDown(smallest);
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
    this->bubbleDown(0, heap_in);
    return temp;
}

int HeapInterface::updateKey(p_vec heap_in, p_vec port_in, float new_splen)
{
    port_in->splen = new_splen;//change port's key in heap
    //now let's fix upwards in the heap
    if(port_in->splen < heap_in.at((port_in->pheaploc - 1)/2)->splen)
    {//if port's key is less than it's parent's key
        return this->bubbleUp(heap_in, port_in->pheaploc); //bubble the port node up the heap
    }
    else
        this->bubbleDown(heap_in, port_in->pheaploc);
}

int HeapInterface::bubbleUp(p_vec heap_in, int child_index)
{//bubbles a child node up the heap until it reaches its correct place, then returns that location
    int childiout = child_index
    int parenti = (childiout - 1) / 2;
    s_Port oldport;
    //bubble up the inserted node if need be
    while(heap_in[parenti]->splen > heap_in[childiout]->splen)
    {//while the parent's key is greater than the child's key
        //swap parent and child
        oldport = heap_in[parenti]; //store parent node
        heap_in[parenti] = heap_in[childiout]; //move child node up into parent slot
        heap_in[parenti]->pheaploc = parenti; //update child pheaploc
        heap_in[childiout] = oldport;
        oldport->pheaploc = childiout;
        //move parent and child indicies up the heap
        childiout = parenti;
        parenti = (childiout - 1) / 2;
    }
    return childiout;
}