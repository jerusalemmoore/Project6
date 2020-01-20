/*
Programmer: Jerusalem Moore

Implemented functions for the minPriorityQueue

*/
#include "minpriority.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

minPriorityQueue::minPriorityQueue(){

}


minPriorityQueue::~minPriorityQueue(){
//for(unsigned int i = 0; i < minHeap.size(); i++){
//  delete minHeap[i];
//}
}

/*insert function pushes element* into queue containing an id
and a key that defines the elements priority*/
void minPriorityQueue::insert(string id, int key){
  Element newElement = Element(id, key);
  minHeap.push_back(newElement);
  decreaseKey(id, key);
}
/*decreaseKey function takes an id, searches for it in the heap, and changes it's current key to the newKey provided;
 the function also makes sure that the provided newKey is smaller than the elements original key*/
void minPriorityQueue::decreaseKey(string id, int newKey){
  int index;
  for(unsigned int i = 0; i < minHeap.size(); i++){
    if((minHeap[i].id) == id){
      index = i;
    }
  }

  if(newKey > minHeap[index].key){
    std::cout << "Error, new key is bigger than current key\n";
    return;
  }

  minHeap[index].key = newKey;
  while((index > 0) && (minHeap[index].key < minHeap[parent(index)].key)){
    iter_swap(minHeap.begin() + index, minHeap.begin() + parent(index));
    index = parent(index);
  }
 //buildMinHeap();
}

/*extractMin function pulls the element with the smallest
priiority(found in the root of the heap), and pulls it out of the
the queue*/
string minPriorityQueue::extractMin(){
  if(minHeap.size() == 0){
    return "Error, empty heap";
  }
  else{

    for(unsigned int i = minHeap.size(); i > 1; i--){
      minHeapify(0);
    }
  Element min = minHeap[0];
  minHeap[0] = minHeap[minHeap.size() - 1];

  minHeap.pop_back();

  return min.id;
  }
}
/*buildMinHeap function creates a minHeap*/
void minPriorityQueue::buildMinHeap(){
  unsigned int heapSize = minHeap.size();
  for(int i = heapSize/2; i > 0; i--){
    minHeapify(i);
  }
}

/*minHeapify function makes sure the min heap property holds
at node index i*/
void minPriorityQueue::minHeapify(int i){
  unsigned int l = left(i);
  unsigned int r = right(i);
  int smallest = i;
  if (l < minHeap.size() && minHeap[l].key < minHeap[i].key){
    smallest = l;
  }
  if(r < minHeap.size() && minHeap[r].key < minHeap[smallest].key){
    smallest = r;
  }
  if(smallest != i){
    iter_swap(minHeap.begin() + i, minHeap.begin() + smallest);
    minHeapify(smallest);
  }
}

//function returns the parent of the node
//at index i
int minPriorityQueue::parent(int i){
  if((i % 2) == 0){
    return (i / 2) - 1;
  } else{
    return i / 2;
  }
}

//function returns the left child of the node
//at index i
int minPriorityQueue::left(int i){
  return i * 2 + 1;
}

//function returns the right child of the node
//at index i
int minPriorityQueue::right(int i){

  return i * 2 + 2;
}


minPriorityQueue::Element::Element(){
  id = "default";
  key = 0;
}
minPriorityQueue::Element::Element(string id, int key){
  this->id = id;
  this->key = key;
}
minPriorityQueue::Element::~Element(){
  

}
