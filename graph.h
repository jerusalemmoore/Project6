/*
Programmer: Jerusalem Moore
Description: header file for a graph object
*/
#include "minpriority.h"
#include <string>
#include <map>
#include <vector>
using std::string;
using std::map;



class Graph{
public:
  Graph();
  ~Graph();
  void addVertex(string name);
  void addEdge(string from, string to, int weight);
  string getShortestPath(string from, string to);
private:
  string currentSource;
  minPriorityQueue minQ;
  void buildSSPTree(string source);
  void relax(string u, string v, int weight);
  class Vertex{
  public:
    Vertex();//key must stay updated when key decreases, use for path
    ~Vertex();
    Vertex(string pi, int key);
    string pi;//this is used for dijkstra alg
    int key;//this is also for  dijkstra alg
  };
  class Neighbor{
  public:
    Neighbor();
    ~Neighbor();
    Neighbor(string name, int weight);
    bool operator<(const Neighbor& n) const{return name < n.name;};
    string name;
    int weight;
  };
  map<string, Vertex> vertices;//map holds vertex names and a blank vertex
  map<string, vector<Neighbor>> adjList;//map holds a vertex name and a list
                                        //of neighbors
};
