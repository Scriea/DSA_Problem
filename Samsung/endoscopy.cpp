// /*  


// Input:


// 2 
// 5 6 2 1 3 
// 0 0 5 3 6 0 
// 0 0 2 0 2 0 
// 3 3 1 3 7 0 
// 0 0 0 0 0 0 
// 0 0 0 0 0 0 
// 5 6 2 2 6 
// 3 0 0 0 0 3 
// 2 0 0 0 0 6 
// 1 3 1 1 3 1 
// 2 0 2 0 0 2 
// 0 0 4 3 1 1


// Output:

// 5
// 15




// 1
// 5 6 2 2 6 
// 3 0 0 0 0 3 
// 2 0 0 0 0 6 
// 1 3 1 1 3 1 
// 2 0 2 0 0 2 
// 0 0 4 3 1 1

// */



// #include <iostream>
// #include<cstring>
// using namespace std;

// #define MAXN 1000

// int graph[MAXN][MAXN];
// bool visited[MAXN][MAXN];


// struct Point{
//     int x;
//     int y;
// };

// bool isValid(int x, int y, int dx, int dy, int n, int m){
//     int p = x+dx, q = y+dy;
//     if (!(p >= 0 && p < n && q >= 0 && q < m ))    return false;

//     switch (graph[x][y]) {
//         case 0:
//             return false;
//         case 1: // All directions
//             if (dx*dy==1)   return false;
//             break;

//         case 2: // Vertical
//             if (dy!=0)  return false;
//             break;        
//         case 3: // Horizontal
//             if (dx!=0)  return false;
//             break;
//         case 4: // Up-Right
//             if (dx==1 || dy==-1)  return false;
//             break;
//         case 5: // Right-Down
//            if (dy==-1 || dx==-1 )   return false;
//            break;
//         case 6: // Left-Down
//             if (dy==1|| dx==-1) return false;
//             break;
//         case 7: // Up-Left
//             if( dx==1 || dy==1) return false;
//             break;
            
//         default:
//             break;
//     }

//     return true;
        



// }


// int solve(int x, int y, int n, int m, int budget) {
//     if (budget <= 0) return 0;
//     if (visited[x][y]) return 0;

//     int ans = 1;
//     visited[x][y] = true;

//     switch (graph[x][y]) {
//         case 1: // All directions
//         for (int i = -1; i <= 1; i += 2) {
//             int p = x + i, q = y;
//             if (!visited[p][q] && isValid(x,y,i,0,n,m) && isValid(p,q,-i, 0, n,m)) {
//                 if (graph[p][q] != 0) {
//                     ans += solve(p, q, n, m, budget - 1);
//                 }
//             }
//         }
        
//         for (int j = -1; j <= 1; j += 2) {
//             int p = x, q = y + j;
//             if (!visited[p][q] && isValid(x,y,0,j,n,m) && isValid(p,q,0, -j, n,m)) {
//                 if (graph[p][q] != 0) {
//                     ans += solve(p, q, n, m, budget - 1);
//                 }
//             }
//         }
//         break;

//         case 2: // Vertical
//             for (int i = -1; i <= 1; i += 2) {
//                 int p = x + i, q = y;
//                 if (!visited[p][q] && isValid(x,y,i,0,n,m) && isValid(p,q,-i, 0, n,m)) {
//                     if (graph[p][q] != 0) {
//                         ans += solve(p, q, n, m, budget - 1);
//                     }
//                 }
//             }
//             break;
            
//         case 3: // Horizontal
//             for (int j = -1; j <= 1; j += 2) {
//                 int p = x, q = y + j;
//                 if (!visited[p][q] && isValid(x,y,0,j,n,m) && isValid(p,q,0, -j, n,m)) {
//                     if (graph[p][q] != 0) {
//                         ans += solve(p, q, n, m, budget - 1);
//                     }
//                 }
//             }
//             break;

//         case 4: // Up-Right
//             if (!visited[x - 1][y] && isValid(x,y,-1,0,n,m) && isValid(x-1,y,1, 0, n,m)) 
//                 ans += solve(x - 1, y, n, m, budget - 1);

//             if (!visited[x][y + 1] && isValid(x,y,0,1,n,m) && isValid(x,y+1, 0, -1, n,m)) 
//                 ans += solve(x, y + 1, n, m, budget - 1);
//             break;

            
//         case 5: // Right-Down
//             if (!visited[x + 1][y] && isValid(x,y,-1,0,n,m) && isValid(x-1,y,1, 0, n,m)) 
//                 ans += solve(x + 1, y, n, m, budget - 1);
//             if (!visited[x][y + 1] && isValid(x,y,-1,0,n,m) && isValid(x-1,y,1, 0, n,m)) 
//                 ans += solve(x, y + 1, n, m, budget - 1);
//             break;

//         case 6: // Left-Down
//             if (x + 1 < n && !visited[x + 1][y] && isValid(x,y,1,0,n,m) && isValid(x+1,y, -1, 0, n,m)) 
//                 ans += solve(x + 1, y, n, m, budget - 1);
//             if (y - 1 >= 0 && !visited[x][y - 1] && isValid(x,y,0,-1,n,m) && isValid(x,y-1,0,1, n,m)) 
//                 ans += solve(x, y - 1, n, m, budget - 1);
//             break;

//         case 7: // Up-Left
//             if (x - 1 >= 0 && !visited[x - 1][y] && isValid(x,y,-1,0,n,m) && isValid(x-1,y,1, 0, n,m)) 
//                 ans += solve(x - 1, y, n, m, budget - 1);
//             if (y - 1 >= 0 && !visited[x][y - 1] && isValid(x,y,0,-1,n,m) && isValid(x,y-1,0,1, n,m)) 
//                 ans += solve(x, y - 1, n, m, budget - 1);
//             break;
            
//         default:
//             break;
//     }

//     // cout<<"X:"<<x<<" Y:"<<y<<" Budget:"<<budget<<" Ans:"<<ans<<endl;
//     return ans;
// }


// int main() {

// 	int t;
// 	cin>>t;
//     int output[t];
// 	for(int g=0; g<t; g++){
// 		int m,n, r,c,l;
// 		cin>>n>>m>>r>>c>>l;

// 		for(int i=0; i<n;i++){
// 			for(int j=0;j<m;j++){
// 				int temp; cin>>temp;
// 				graph[i][j] = temp;
// 			}
// 		}
//         memset(visited, 0, sizeof(visited));
//         cout<<endl;
// 		if (graph[r][c]==0)	output[g] = 0;
// 		else output[g] = solve(r,c,n,m,l);
// 	}
//     for(int g=0; g<t;g++)  cout<<output[g]<<endl;
// }













