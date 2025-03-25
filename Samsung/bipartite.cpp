#include <bits/stdc++.h>
using namespace std;



// Using STL Vector
// class Solution {
//     public:
//         bool dfs(int node, int color, vector<vector<int>>& graph, set<int>& visited, vector<int>& colors){
//             visited.insert(node);
//             colors[node] = color;
//             for(auto x:graph[node]){
//                 if (colors[x]==-1){                  
//                     if (! dfs(x, 1-color, graph, visited, colors))  return false;
//                 }
//                 else if(colors[x]==colors[node])            
//                     return false;
//             }
//             return true;
//         }
//         bool isBipartite(vector<vector<int>>& graph) {
//             int n = graph.size();
//             vector<int> colors(n, -1);  // -1 means uncolored
//             set<int> visited;
        
//             for (int i = 0; i < n; i++) {
//                 if (colors[i] == -1) {  // If the node is not colored yet
//                     if (! this->dfs(i, 0, graph, visited, colors)) {  // Start DFS with color 0
//                         return false;
//                     }
//                 }
//             }
//             return true;
//         }
    
//     };


// Without Using STL
#define MAX_N 100

class Solution{
    public:
        bool isBipartite(int graph[MAX_N][MAX_N]){
            return true;
        }
};



int main(){

    Solution solu;
    int n;
    cin>>n;
    cin.ignore();
    vector<vector<int>> graph(n);

    for(int i=0; i<n; i++){
        string line;
        getline(cin, line);
        stringstream ss(line);
        int temp;
        while(ss>>temp){
            graph[i].push_back(temp);
        }
    }
    for(int i=0; i<n; i++){
        for(auto x: graph[i]){
            cout<<x;
        }
        cout<<endl;
    }
    cout<<endl;
    
    if (solu.isBipartite(graph))
        cout << "Graph is Bipartite" << endl;
    else
        cout << "Graph is NOT Bipartite" << endl;

return 0;

}