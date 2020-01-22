/*
Programmer: Jerusalem Moore
Description: graph functions implementation
*/
#include "graph.h"

#include <string>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using std::string;
using std::map;
using std::sort;

/**
  public Graph functions:
  Graph interface for creation and finding shortest path
*/
const int INFINITY = 99;
//Graph constructor creates graph with no currentSource
Graph::Graph(){
  currentSource = "default";
  //Graph has a minPriorityQueue
  //Graph has a map named vertices
  //Graph has a map named adjList

}
//Graph destructor
Graph::~Graph(){

}

/**
  Create a new vertex and add to vertices map and adjList map with empty
  list of neighbors

  @param: name of the vertex to be added to the graph
*/
void Graph::addVertex(string name){
  Vertex newVertex;//instantiate a default vertex
  /*create a newVertexPair, a pair of string and Vertex, to insert
   into map vertices*/
  std::pair <string,Vertex> newVertexPair(name, newVertex);
  vertices.insert(newVertexPair);
}

/**
  Add an edge by going to start vertex in adjList and pushing
  end vertex into the neighbor list

  @param: starting vertex,the end vertex, the weight of the edge
*/
void Graph::addEdge(string from, string to, int weight){
  Neighbor newNeighbor;//create new neighbor
  newNeighbor = Neighbor(to, weight); //assign the name and weight
  map<string, vector<Neighbor>>::iterator it;/*create iterator to search
  the map*/
  it = adjList.find(from);//have iterator find the from vertex
  if(it !=adjList.end()){//if the vertex being searched exists in the adjList
    it-> second.push_back(newNeighbor);/*push newNeighbor into that vertexes
    Neighbor vector*/
  } else {//if vertex being searched doesn't exist yet in the adjList
    std::vector<Neighbor> neighborList;//create an empty neighbor vector
    //create an adjListPair with name and empty Neighbor vector to insert into
    //adjList
    std::pair<string, vector<Neighbor>> adjListPair(from, neighborList);
    adjList.insert(adjListPair);//place pair into adjList
    adjList[from].push_back(newNeighbor);//push that newNeighbor into adjList at
    //index from
    //for loop used to sort the adjList
    for(auto it = adjList.begin(); it != adjList.end(); it++){
      std::sort(it->second.begin(), it->second.end());
    }
  }
}

/**
  get the shortest from start vertex to end Vertex

  @param: starting vertex and ending vertex
*/
string Graph::getShortestPath(string from, string to){
//Next Step
  if(currentSource == from){
    vector<string> vertexNames;
    map<string, Vertex>::iterator it1;
    map<string, Vertex>::iterator it2;
    it1 = vertices.find(to);
    string vertexPredecessor1;
    vertexPredecessor1 = it1->second.pi;
    std::cout << from << "->";
    string vertexPredecessor2;
    while(vertexPredecessor1 != from){
      vertexNames.push_back(vertexPredecessor1);
      it2 = vertices.find(vertexPredecessor1);
      vertexPredecessor2 = it2->second.pi;
      vertexPredecessor1 = vertexPredecessor2;
    }
    for(int i = vertexNames.size(); i > 0; i--){
      std::cout << vertexNames[i] << "->";
    }
    int fullWeight = it1->second.key;
    std::cout << to << " with length " << fullWeight << std::endl;
    vertexNames.clear();
  }
  else {
    currentSource = from;
    buildSSPTree(from);
    vector<string> vertexNames;
    map<string, Vertex>::iterator it1;
    map<string, Vertex>::iterator it2;
    it1 = vertices.find(to);
    string vertexPredecessor1;
    vertexPredecessor1 = it1->second.pi;
    std::cout << from << "->";
    string vertexPredecessor2;
    while(vertexPredecessor1 != from){
      vertexNames.push_back(vertexPredecessor1);
      it2 = vertices.find(vertexPredecessor1);
      vertexPredecessor2 = it2->second.pi;
      vertexPredecessor1 = vertexPredecessor2;
    }
    for(int i = vertexNames.size(); i > 0; i--){
      std::cout << vertexNames[i] << "->";
    }
    int fullWeight = it1->second.key;
    std::cout << to << " with length " << fullWeight << std::endl;
  }
  return to;
}

/**
  private Graph functions:
  buildSSPTree function and relax helper functions

*/

/**
  build a shortest path graph using the relax function
  and minPriorityQueue. buildSSPTree will also initialize the
  source vertex to key = 0 and predecessor = "nil"

  @param: name of the source vertex
*/
void Graph::buildSSPTree(string source){
  Neighbor neighborVertex;
  map<string, Vertex>::iterator it1;
  map<string, vector<Neighbor>>::iterator it2;
  vector<Neighbor>::iterator it3;
  for(it1 = vertices.begin(); it1 != vertices.end(); it1++){
    if(it1->first == source){
      it1->second.pi = "nil";
      it1->second.key = 0;
    }
    else{
      it1->second.pi = "nil";
      it1->second.key = INFINITY;
      minQ.insert(it1->second.pi, it1->second.key);
    }
    while(minQ.extractMin() != "Error"){
      string minPString;
      minPString = minQ.extractMin();
      for(it2 = adjList.begin(); it2 != adjList.end(); it2++){
        if(it2->first == minPString){
          for(it3 = it2->second.begin(); it3 != it2->second.end(); it3++){
            neighborVertex = *it3;
            relax(minPString, neighborVertex.name, neighborVertex.weight);
          }
        }
      }
    }
  }
}
void Graph::relax(string u, string v, int weight){
/**
create vertices map iterator
create a second vertices map iterator
set the first iterator to find u
set the second iterator to find v
if(the second iterators vertex key is greater the the first iterators vertex
key plus its weight)
  the second iterators vertex key is set to the first iterators key plus weight
  the second iterators predecessor is set to u
  decreaseKey of v with second iterataor vertex key
  */
  map<string, Vertex>::iterator it1; 
  map<string, Vertex>::iterator it2;
  it1 = vertices.find(u);
  it2 = vertices.find(v);
  if((it2->second.key) > it1->second.key + weight){
    it2->second.key = it1->second.key + weight;
    it2->second.pi = u;
    minQ.decreaseKey(v, it2->second.key);
  }
}

//private nested class Vertex and it's constructor functions
Graph::Vertex::Vertex(){
  pi = "default";
  key = 9999;
}

Graph::Vertex::~Vertex(){

}

Graph::Vertex::Vertex(string pi, int key){
  this->pi = pi;
  this->key = key;
}

//private nested class Neighbor and it's constructor functions
Graph::Neighbor::Neighbor(){
  name = "unnamed";
  weight = 9999;
}

Graph::Neighbor::~Neighbor(){

}

Graph::Neighbor::Neighbor(string name, int weight){
  this->name = name;
  this->weight = weight;
}
