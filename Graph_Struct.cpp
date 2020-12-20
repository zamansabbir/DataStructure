#include<iostream>
#include<list>
#include<vector>
using namespace std;
struct Graph{
    int v;
    list<int> *adj;

};

Graph* createGraph(int number){
    Graph *temp=new Graph();
    temp->v=number;
    temp->adj=new  list<int> [temp->v];
    return temp;
}

void addEdge(Graph *graph, int node, int newNode){
    graph->adj[node].push_back(newNode);
}

void dfsUtil(Graph *graph,int startNode, vector<bool> &visited){
    visited.at(startNode)=true;
    cout<<startNode<<" ";
    for(list<int>::iterator it=graph->adj[startNode].begin();it!=graph->adj[startNode].end();++it){
        if(!visited[*it]){
            dfsUtil(graph,*it,visited);
        }
        
    }

}
void dfs(Graph *graph, int startNode){
    vector<bool> visited(graph->v, false);
    dfsUtil(graph,startNode,visited);

}

int main(){
    int number=4;
    Graph *g=createGraph(number);
     
    addEdge(g,0, 1);
    addEdge(g,0, 2);
    addEdge(g,1, 2);
    addEdge(g,2, 0);
    addEdge(g,2, 3);
    addEdge(g,3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    dfs(g,2);

    return 0;
}