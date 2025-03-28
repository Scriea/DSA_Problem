/*  
You’ll be given a grid as below:

    0 1 0 2 0
    0 2 2 2 1
    0 2 1 1 1
    1 0 1 0 0
    0 0 1 2 2
    1 1 0 0 1
    x x S x x

In the grid above,
  1: This cell has a coin.
  2: This cell has an enemy.
  0: It contains nothing.

  The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get 
  maximum coins.
  Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move.
  At each time, the non-highlighted part of the grid will move down by one unit.
  We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone 
  will be killed.
  If we use a bomb at the very beginning, the grid will look like this:

    0 1 0 2 0
    0 0 0 0 1
    0 0 1 1 1
    1 0 1 0 0
    0 0 1 0 0
    1 1 0 0 1
    x x S x x

  As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends.
  For example,
  At the very first instance, if we want to collect a coin we should move left( coins=1). This is because when the 
  grid comes down by 1 unit we have a coin on the second position and by moving left we can collect that coin. 
  Next, we should move right to collect another coin (coins=2).
  After this, remain at the same position (coins=4).
  This is the current situation after collecting 4 coins.

    0 1 0 2 0 0 1 0 0 0
    0 2 2 2 1 -->after using 0 0 0 0 1
    x x S x x -->bomb x x S x x

   Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.




Input:

1
8
0 1 0 2 0
0 2 2 2 1
0 2 1 1 1
1 0 1 0 0
0 0 1 2 2
2 2 2 2 2
1 1 0 0 1
x x S x x


Output:

#1 : 5


*/


#include <iostream>
using namespace std;

void updateMatrix(int n, char **matrix) {
    if (n <= 0) return;

    for (int i = max(n - 5, 0); i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == '2') {
                matrix[i][j] = '0';  
            }
        }
    }
}
int max_coins(int x, int y, int bombs, char **matrix){
    if(x<0 || y<0 || y>=5){
        return 0;
    }
    
    int result = 0, answer=0;
    
    for(int i=-1; i<2; i++){
        if (y+i>=0 && y+i<5 && x>0 && matrix[x-1][y+i]!='2'){
            result = max(max_coins(x-1, y+i, bombs, matrix), result);
        }
    }
    switch (matrix[x][y])
        {
        case 'S':
            answer = result;
            break;
        case '0':
            answer = result;
            break;
        case '1':
            answer = 1 + result;
            break;
        case '2':
            if (bombs>0 && result==0){
                updateMatrix(x, matrix);
                answer = max_coins(x, y, bombs-1, matrix);
            }
            else answer = result;
            break;
        default:
            answer = result;
            break;
    }
    return answer;

}

int main(){
    int testcases,N;
    cin >> testcases;
    int answers[testcases];
    for(int t=0; t<testcases; t++){    
        cin >> N;
        char ** matrix=new char*[N];
        for(int i=0; i<N; i++){
            matrix[i]=new char[5];
            for(int j=0;j<5;j++){
                cin>>matrix[i][j];
            }
        }
        answers[t] = max_coins(N-1, 2, 0, matrix);
    }
    for(int t=0; t<testcases; t++){
        cout<< "#" << t+1 << " : " << answers[t] << endl;        

    }
    
    
    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;
// void updateMatrix(int row,char ** matrix){
//     if(row<0){
//         return;
//     }
//     int upLimit=max(0,row-4);
//     for(int i=row;i>=upLimit;i--){
//         for(int j=0;j<=4;j++){
//             if(matrix[i][j]=='2'){
//                 matrix[i][j]='0';
//             }
//         }
//     }
// }
// int findMaxPoints(int row,int col,int bombs,char ** matrix){
//     if(row<=0 || col<0 || col>=5){
//         return 0;
//     }
//     int answer=0;
//     if(row>0 && matrix[row-1][col]!='2'){
//         answer=max(answer,(matrix[row-1][col]=='1'?1:0)+findMaxPoints(row-1,col,bombs,matrix));
//     }
//     if(col>0 && row>0 && matrix[row-1][col-1]!='2'){
//         answer=max(answer,(matrix[row-1][col-1]=='1'?1:0)+findMaxPoints(row-1,col-1,bombs,matrix));
//     }
//     if(col<4 && row>0 && matrix[row-1][col+1]!='2'){
//         answer=max(answer,(matrix[row-1][col+1]=='1'?1:0)+findMaxPoints(row-1,col+1,bombs,matrix));
//     }

//     if(answer==0 && bombs>0){
//         updateMatrix(row-1,matrix);
//         answer=findMaxPoints(row,col,bombs-1,matrix);
//     }

//     return answer;
// }
// int main(){
//     int t, row;
//     cin >> t;
//     int tNo = 0;
//     while(t--){
//         cin >> row;
//         char ** matrix=new char*[row + 2];
//         for(int i=0; i<row; i++){
//             matrix[i]=new char[5];
//             for(int j=0;j<5;j++){
//                 cin>>matrix[i][j];
//             }
//         }
//         tNo++;
//         cout<< "#" << tNo << " : " << findMaxPoints(row,2,1,matrix) << endl;        
//     }
//     return 0;
// }