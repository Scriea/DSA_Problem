/*
There is one spaceship. X and Y co-odinate of source of spaceship and destination spaceship is given.
There are N number of warmholes; each warmhole has 5 values. First 2 values are starting co-ordinate
of warmhole and after that value no. 3 and 4 represents ending co-ordinate of warmhole and last 5th 
value is represents cost to pass through this warmhole. Now these warmholes are bi-directional. Now 
the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2). The main problem here is to find minimum 
distance to reach spaceship from source to destination co-ordinate using any number of warm-hole. 
It is ok if you wont use any warmhole.




Input:

1
0 0
100 100
2
1 1 99 99 100
-100 -100 100 100 0

Output:

#1 104


*/


#include<iostream>
using namespace std;
#define MAXN 22

int wormholes[MAXN][5];
int graph[MAXN][MAXN];
bool visited[MAXN];


struct point{
    int x,y;
};

struct wormhole
{
    int enter_x, enter_y, exit_x, exit_y, dist;
};

int distance(int a, int b, int c, int d){
    return abs(a-c) + abs(b-d);
}

int min_dist(point src, point dest, int sum, int N){

    int ans = distance(src.x, src.y, dest.x, dest.y);
    for(int i=0; i<N; i++){
        //Enter from front
        if(!visited[i]){
            ans = min(ans, distance(src.x, src.y, wormholes[i].enter_x, wormholes[i].enter_y) +
             min_dist({wormhole[i].enter_x, wormholes[i].enter_y}, dest,  ))
        }
        
        
        // Enter from back


    }


}

int main(){
    int testcases;
    cin>>testcases;
    int answers[testcases];
    int N;
    int x,y;
  
    for(int t=0; t<testcases; t++){
        cin>>N;
        point src, dest;
        cin>>x>>y;
        src = {x,y};

        cin>>x>>y;
        dest = {x,y};

        for(int i=0; i<N; i++){
            for(int j=0; j<5;j++){
                cin>>wormholes[i][j];
            }
            if (wormholes[i][4]> distance(wormholes[i][0], wormholes[i][1], wormholes[i][2], wormholes[i][3])  
                wormholes[i][4] =distance(wormholes[i][0], wormholes[i][1], wormholes[i][2], wormholes[i][3]);
        }
    }

}