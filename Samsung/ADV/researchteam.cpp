/*
https://www.careercup.com/question?id=5707238197952512
https://practice.geeksforgeeks.org/problems/how-to-solve-this-bfs-problem-asked-in-samsung
https://discuss.codechef.com/t/samsung-question-geeksforgeeks/17092

1 Bsed -> https://sapphireengine.com/@/4q0evk - Ajay Verma
0 Bsed -> https://sapphireengine.com/@/iha4kq - Thusoo
*/

/*
A Research team want to establish a research center in a region where they found some rare-elements.
They want to make it closest to all the rare-elements as close as possible so that they can reduce
overall cost of research over there. It is given that all the rare-element’s location is connected
by roads. It is also given that Research Center can only be build on road. Team decided to assign
this task to a coder. If you feel you have that much potential.

Here is the Task :- Find the shortest of the longest distance of research center from given locations
of rare-elements.

Locations are given in the matrix cell form where 1 represents roads and 0 no road. 
Number of rare-element and their location was also given(number<=5) and order of square matrix
was less than equal to (20).
*/

/*
For this you have to implement bfs for every position where road exist to find the distance of 
every research center or do Vice-versa. for each position store maximum distance of all distances
to research center and the compare each maximum distance to find minimum of them

Input - 
6
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0
5 2
2 1
3 5
1 0 1 1 1
1 1 1 0 1
0 1 1 0 1
0 1 0 1 1
1 1 1 0 1

Output - 
1
2
2
12
15
4
*/


#include<iostream>
#include<climits>
using namespace std;

#define MAXN 20
#define MAXM 5
#define MAXQ 400 // To accommodate the maximum number of elements in the queue (20x20 grid)

struct point {
    int x, y;
};

struct point_dist {
    point src;
    int dist;
};

int locations[MAXN][MAXN];  // Matrix to store road locations
point rare[MAXM];             // Store rare element locations
int N, M;                    // Order of Matrix, Number of Rare elements
int distances[MAXN][MAXN];    // Distance matrix
bool visited[MAXN][MAXN];     // Visited matrix

// For manually managing the queue
point_dist queue[MAXQ];
int front = 0, rear = 0;

// Function to add an element to the queue
void enqueue(point_dist pd) {
    queue[rear] = pd;
    rear = (rear + 1) % MAXQ;
}

// Function to remove an element from the queue
point_dist dequeue() {
    point_dist pd = queue[front];
    front = (front + 1) % MAXQ;
    return pd;
}

bool isQueueEmpty() {
    return front == rear;
}

// Function to reset the queue
void resetQueue() {
    front = rear = 0;
}

// Function to perform multi-source BFS
void bfs(point src) {
       
    enqueue({ src, 0 });
    visited[src.x][src.y] = true;
    if (distances[src.x][src.y]<0)  distances[src.x][src.y] = 0;

    while (!isQueueEmpty()) {
        point_dist top = dequeue();
        point current = top.src;
        int dist = top.dist;
        
        // Check all four neighbors (up, down, left, right)
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && locations[nx][ny]!=0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                
                distances[nx][ny] = max(dist + 1, distances[nx][ny]);
                enqueue({ {nx, ny}, dist + 1 });
                

                
            }
        }
    }
}

// Main function to find the optimal location for the research center
int research() {

    // Reset visited and distances arrays
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
            distances[i][j] = -1;
        }
    }

    // Perform multi-source BFS to calculate distances from all rare elements
   for(int i=0; i<M; i++){
        bfs(rare[i]);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = false;
            }
        }
   }

    // Now, find the minimum of the maximum distances for each road cell
    int ans = INT_MAX;

    // For every road cell (1), find the maximum distance to a rare-element
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (locations[i][j]==1) {
                ans = min(ans, distances[i][j]);
            }
        }
    }
    return ans == INT_MAX ? -1 : ans;
}

int main() {
    int testcases;
    cin >> testcases;
    int answers[testcases];
    for (int t = 0; t < testcases; t++) {
        cin >> N >> M;
        
        // Input rare elements
        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            rare[i] = {x - 1, y - 1};  // Adjust to zero-based indexing
        }
        
        // Input the locations matrix
        int temp;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> temp;
                locations[i][j] = temp == 1 ? true : false;
            }
        }
        // Set locations for rare items
        for(int i=0; i<M;i++){
            locations[rare[i].x][rare[i].y] = 2;
        }

        // Reset the queue for the next test case
        resetQueue();

        int result = research();
        answers[t] = result;
    }

    for(int t=0; t<testcases; t++){
        cout<<answers[t]<<endl;
    }
    
    return 0;
}