#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;


# define MAX_N 100

class Solution{
    public:
        bool dfs_undirected(int node, int parent, bool visited[], int graph[][MAX_N],int n){
            visited[node] = true;
            for(int neigh=0; neigh < n; neigh++){
                if (graph[node][neigh] !=0 || graph[neigh][node]!=0) {
                    if (neigh == parent) continue; 
                    if(!visited[neigh]){
                        if (this->dfs_undirected(neigh, node, visited, graph, n))
                            return true;
                    
                    }
                    
                    else    return true;
                }
            }
            return false;
        }

        bool dfs_directed(int node, bool visited[], int graph[][MAX_N], int n, bool in_stack[]){
            visited[node] = true;
            in_stack[node] = true;
            for(int neigh= 0; neigh<n; neigh++){
                if(graph[node][neigh]!=0 ){
                    if(!visited[neigh]){
                        if (this->dfs_directed(neigh, visited, graph, n, in_stack)) return true;
                    }
                    else if(in_stack[neigh])    return true;
                }
            }
            in_stack[node] = false;
            return false;
        }


        bool detectCycleUndirected(int graph[MAX_N][MAX_N], int n){
            bool visited[MAX_N];
            memset(visited, false, sizeof(visited));    
            for(int i=0; i<n;i++){
                if (!visited[i]){
                    if (this->dfs_undirected(i, -1, visited, graph, n))    return true;
                }
                
            }   
            return false;
        }


        bool detectCycleDirected(int graph[MAX_N][MAX_N], int n){
            bool in_stack[n] = {false};
            bool visited[n] = {false};
            for(int node=0; node <n; node++){
                if (!visited[node]){  
                    if(this->dfs_directed(node, visited, graph, n,in_stack)) return true;
                }
            }
            return false;

        }
};




int main(){
    int graph[MAX_N][MAX_N];
    memset(graph, 0, sizeof(graph));

    int n;
    cin>>n;

    cin.ignore();
    for(int i=0; i<n; i++){
        string line;
        getline(cin, line);
        stringstream ss(line);
        int temp;

        while(ss>>temp){
            graph[i][temp] = 1; // Set adjacency for neighbors
        }

    }

    Solution solution;
    if (solution.detectCycleUndirected(graph, n))  cout<<"Undiredted graph has cycle";
    else cout<<"Undirected Graph has no cycle";


    if (solution.detectCycleDirected(graph,n)) cout<<"Directed graph has cycle";
    else cout<<"Directed Graph has no cycle";

}
