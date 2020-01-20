/*
Programmer: Jerusalem Moore
Description: graph functions implementation
*/
#include "graph.h"
#include <string>
#include<map>
#include <vector>
using std::string;
using std::map;

/**
  public Graph functions:
  Graph interface for creation and finding shortest path
*/
const int INFINITY = 99;
//Graph constructor creates graph with no currentSource
Graph::Graph(){
  currentSource = "default";
  //Graph has a minPriorityQueu
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
  }
}

/**
  get the shortest from start vertex to end Vertex

  param: starting vertex and ending vertex
*/
string Graph::getShortestPath(string from, string to){
//Next Step
  if(currentSource == from){
    sting
  }
}

/**
  private Graph functions:
  buildSSPTree function and relax helper function
*/

void buildSSPTree(string source){
//initialize stringSource
//set all new vertices
}
Graph::Vertex::Vertex(){

}
