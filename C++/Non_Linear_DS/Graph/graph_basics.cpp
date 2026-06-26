#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Graph{
    unordered_map<int, vector<int>> adj;
    
public:
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);  // For undirected
    }
    
	void display(){
    	cout<<"Graph:\n";  // Header
    
    	for(auto& pair : adj){  // For EACH vertex in adjacency list
        	cout<<pair.first<<" -> ";  // Print the vertex (pair.first = key)
        
        	for(int num : pair.second){  // For EACH neighbor of that vertex
            	cout<<num<<" ";  // Print the neighbor
        	}
        	cout<<endl;  // New line
    	}
	}
    
    void dfs(int start){
    	unordered_set<int> visited;
    	dfsHelper(start, visited);
    	cout << endl;
	}

	void dfsHelper(int vertex, unordered_set<int>& visited){
    
    	visited.insert(vertex);  // Mark visited
    	cout << vertex << " ";   // Process
    
    	for(int neighbour : adj[vertex]){
        	// Check NEIGHBOUR, not vertex!
        	if(visited.find(neighbour) == visited.end()){
            	dfsHelper(neighbour, visited);
        	}
    	}
	}
	
	void bfs(int start){
    	unordered_set<int> visited;
    	queue<int> q;
    
    	visited.insert(start);
    	q.push(start);
    
    	while(!q.empty()){
        	int vertex = q.front();
        	q.pop();
        
        	cout << vertex << " ";
        
        	for(int neighbour : adj[vertex]){
            	// Check NEIGHBOUR, not vertex!
            	if(visited.find(neighbour) == visited.end()){
                	visited.insert(neighbour);
                	q.push(neighbour);
            	}
        	}
    	}
    	cout << endl;
	}
};

int main(){
    Graph g;
    
	g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    
    g.display();
    
    cout << "DFS: ";
    g.dfs(1);
    
    cout << "BFS: ";
    g.bfs(1);
    
    return 0;
}
