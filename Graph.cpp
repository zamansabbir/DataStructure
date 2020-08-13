#include<iostream>
#include<list>

class Graph{
        int V; // number of vertices in the graph
        std::list<int> *adj; //a pointer to vectors
    public:
        Graph(int v);
        void addEdge(int u,int v);//(u,v)
        void BFS(int startNode); // Breadth First search
};

Graph::Graph(int v){
    this->V=v;
    this->adj= new std::list<int>[V]; //Array of list, firt Array is pointed by adj

}
void Graph::addEdge(int u,int v){
    adj[u].push_back(v);// directed graph only one push
}

//as we traverse, we printing as we go

void Graph::BFS(int startNode){
    //create an one dimensional array to keep track of nodes already visited.
    bool *visited= new bool[this->V];
    for(int i=0;i<V;i++){
        *(visited+i)=false;
    }
    // For BFS traveral we should maintain a queue. 
    std::list<int> queue;
    queue.push_back(startNode);
    *(visited+startNode)=true;
    while(!queue.empty()){
       startNode=queue.front();
       queue.pop_front();
       std::cout<<startNode<<" ";
       std::list<int>:: iterator it; 
       for(it=adj[startNode].begin();it!=adj[startNode].end();++it){
           if(!*(visited+*it))
           queue.push_back(*it);
           *(visited+*it)=true;
       }
    }
}
int main(){
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    int startVertex=2;
    std::cout<<"Breadth First Traversal from "<<startVertex<<std::endl;
    g.BFS(startVertex);
    return 0;
}