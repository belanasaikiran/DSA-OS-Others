#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph{
    private:
    unordered_map<string, unordered_set<string> > adjList;

    public:
        bool addVertex(string vertex){
            if(adjList.count(vertex) == 0){
                adjList[vertex];
                return true;
            }
            return false;
        }


        bool addEdge(string vertex1, string vertex2){
            if(adjList.count(vertex1) && adjList.count(vertex2)){
                adjList.at(vertex1).insert(vertex2);
                adjList.at(vertex2).insert(vertex1);
                return true;
            }
            return false;
        }

        bool removeEdge(string vertex1, string vertex2){
            if(adjList.count(vertex1) && adjList.count(vertex2)){
                adjList.at(vertex1).erase(vertex2);
                adjList.at(vertex2).erase(vertex1);
                return true;
            }
            return false;
        }

        bool removeVertex(string vertex){
            if(!adjList.count(vertex)) return false;

            for(auto otherVertex : adjList[vertex]){
                adjList[otherVertex].erase(vertex);
            }
            adjList.erase(vertex);
            return true;
        }

        void printGraph(){
            for(auto [vertex, edges] : adjList){
                cout << vertex << ": [";
                for(auto edge : edges){
                    cout << edge << " ";
                }
                cout << "]" << endl;
            }
        }
};
int main(){

    Graph* myGraph = new Graph();
    myGraph->addVertex("A");
    myGraph->addVertex("B");
    myGraph->addVertex("C");
    myGraph->addEdge("A", "B");
    myGraph->addEdge("C", "B");
    myGraph->addEdge("A", "C");
    myGraph->removeEdge("A", "B");
    myGraph->removeVertex("B");
    myGraph->printGraph();
    return 0;
}
