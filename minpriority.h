/*Programmer: Jerusalem Moore

functions used in order to implement a minPriorityQueue

*/


#include <string>
#include <vector>
using std::string;
using std::vector;
class minPriorityQueue{
  public:
    minPriorityQueue();//constructor
    ~minPriorityQueue();//destructor
    void insert(string id, int key);//insert elements function
    void decreaseKey(string id, int newKey);//decrease key priority of element
    string extractMin();//extract id with smallest priority
    bool isMember(string id);
  private:

    void buildMinHeap();
    void minHeapify(int i);
    int parent(int i);//parent of node at index i
    int left(int i);//left child of node at index i
    int right(int i);//right child of node at index i
    class Element{
      public:
        Element();//constructor
        ~Element();//destructor
        string id;//element identifier
        int key;//element key to decide priority
        Element(string id, int key);//overloaded constructor
    };
    vector<Element> minHeap;
};
