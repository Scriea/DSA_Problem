/*
You are busy to promote a newly released film in a movie theater.
The title is ‘Biochemical Laughing Bomb’ which is about terror.
Guerrillas drop a biochemical laughing bomb in the middle of a city.
Once exposed, you have to laugh all your life. 
The bomb will contaminate four people around it during 1 second, and another four around each of them during
another one second. However, you won’t be contaminated if you are not in the adjacent four directions. 
as the below shows the location of the bomb and affected people, and shows contamination process in seconds and
you can figure out that the whole city is contaminated in 8 seconds.
In order to protect the city from the epidemic, 
create a program that figures out when the city will be contaminated by the bomb for the last.




[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ≤ 30) are given in a row.
The row and column of the city, N and M are given by being separated with a blank on the first row of each test case. (1 ≤ N, M ≤ 100)
The status within city is given by being separated with a blank from the second row to N number rows. 1 means people exist and 0 means people do not exist.
The coordinate of the row and column on which the bomb fall is given by being separated with a blank on the last row.

[Output]
For each test case, you should print "Case #T" in the first line where T means the case number. For each test case, you should output how long does it take to contaminate al people on the first row of each test case.





Input
2
7 8
0 0 1 1 0 0 0
1 1 1 1 0 1 0
0 0 1 1 1 1 1
0 1 1 1 1 1 1
0 1 0 0 1 1 0
0 1 1 1 1 0 0
0 0 1 0 1 1 1
0 0 0 0 1 0 0
2 5
10 10
1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 1 0 1 1 0
0 0 1 1 0 1 0 1 1 1
0 1 1 1 1 1 0 0 1 1
0 1 0 1 0 1 1 1 1 0
0 0 0 0 0 1 1 0 0 0
1 0 1 0 1 0 1 1 0 0
0 0 1 1 1 1 1 1 1 1
1 0 1 0 0 1 0 1 1 0
1 1 1 0 0 0 0 1 1 1
2 2

Output
Case #1

8

Case #2
21


*/

#include<iostream>

using namespace std;

#define MAXN 100
#define MAXM 100
#define MAXQ 10000
struct Point{
    int x, y;

};

struct q_data{
    Point point;
    int time;
};



int graph[MAXN][MAXM];
int M,N, bomb_x, bomb_y;

class Queue{
    const int capacity = MAXQ;
    int _size, _rear, _front;
    q_data *Q;

    public:
    Queue() {
        Q = new q_data[capacity];
        _front =0; _rear =0;
        _size=0;
    }

    ~Queue() {
        delete[] Q;
    }


    bool empty(){
        return _size==0;
    }
    void push(q_data element){
        if (_size==capacity) {
            cout<<"Queue is full !";
            return;
        }
        else{
            Q[_rear]=element;
            
            _rear = (_rear+1)%MAXQ;
        }
        _size++;
    }
    void pop(){
        if (_size==0) {cout<<"Queue is empty!"<<endl; return;}
        _front = (_front+1)%MAXQ;
        _size--;
    }
    int size(){
        return _size;
    }

    q_data front(){
        if(_size>0)  return Q[_front];
        else {cout<<"Queue is empty !"<<endl; return q_data{};} 
    }
};


bool isValid(int x, int y){
    return (x>=0 && x<N && y>=0 && y<M);
}


int solve(){
    Queue q;
    Point Bomb = {bomb_x, bomb_y};
    q_data temp = {Bomb, 1};
    q.push(temp);
    int _max = 1;

    int dx[] = {-1,0,0,1};
    int dy[] = {0,-1, 1, 0};

    while(!q.empty()){

        q_data top = q.front();
        q.pop();
 
        _max= max(top.time, _max);
        for(int i=0; i<4; i++){
            int x = top.point.x  + dx[i], y = top.point.y + dy[i];

            if (isValid(x, y)){

                if(graph[x][y]==1){
                    q_data temp = {{x,y}, top.time+1};
                    q.push(temp);
                    graph[x][y]=2;
                
                }
                // elif (granph[x][y]==2){

                }
                
            }

        }

    return _max;
    
}


int main(){
int testcases;
cin>>testcases;
int answers[testcases];
for(int t=0; t<testcases; t++){
    
    cin>>M>>N;

    for(int i=0; i<N;i++){
        for(int j=0; j<M; j++){
            cin>>graph[i][j];
        }
    }
    cin>>bomb_x>>bomb_y;
    bomb_x--;
    bomb_y--;
    graph[bomb_x][bomb_y]=2;

    answers[t] = solve();

}

for(int t=0; t<testcases; t++){
    cout<<"Case #"<<t+1<<endl;
    cout<<answers[t]<<endl<<endl;
}
}