/*
Mr. Lee has to travel various offices abroad to assist branches of each place. But he has a problem. 
The airfare would be real high as all offices he has to visit are in foreign countries. He wants to visit every 
location only one time and return home with the lowest expense. Help this company-caring man calculate the lowest expense.


Input format
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. 
After that, the test cases as many as T (T ≤ 30) are given in a row. N, the number of offices to visit is given on 
the first row per each test case. At this moment, No. 1 office is regarded as his company (Departure point). 
(1 ≤ N ≤ 12) Airfares are given to move cities in which branches are located from the second row to N number rows.
i.e. jth number of ith row is the airfare to move from ith city to jth city. If it is impossible to move between 
two cities, it is given as zero.

Output format
Output the minimum airfare used to depart from his company, visit all offices, and then return his company on the 
first row per each test case.

Example of Input

3
5
0 14 4 10 20
14 0 7 8 7
4 5 0 7 16
11 7 9 0 2
18 7 17 4 0
5
9 9 2 9 5
6 3 5 1 5
1 8 3 3 3
6 0 9 6 8
6 6 9 4 8
3
0 2 24
3 0 2
0 4 0

Example of Output

30
18
CUSTOM - 31 <- 4
*/


#include<iostream>
#include<climits>
#include<math.h>

using namespace std;

#define MAXN 12

int expenses[MAXN][MAXN];
bool visited[MAXN];

class Solution{
    public:

        int visited_state(int n){
            int state = 0;
            for(int i=0; i<n; i++){
                if (visited[i])
                    state+= int(1<<i);
            }
            return state;
        }
        int mrLee(int src, int cost, int len, int n, int **dp ){
            // Base Case
            if (len==n-1){
                if(expenses[src][0]!=0){
                    return cost + expenses[src][0];
                }
                else return INT_MAX;
            }



            int state = this->visited_state(n);
            if (dp[state][src] !=-1){
                return dp[state][src];
            }

            int ans = INT_MAX;
            for (int i=0; i<n; i++){
                if(!visited[i] && expenses[src][i]!=0){
                    visited[i] = true;
                    int state  = this->visited_state(n);
                    ans = min(this->mrLee(i, cost + expenses[src][i], len+1, n, dp), ans);
                    visited[i] = false;
                }
            }
            return dp[state][src] = ans;
            
        }

};



int main(){
    int testcases;
    cin>>testcases;
    Solution sol;
    int out[testcases];
    for(int t=0; t<testcases; t++){
        int n;
        cin>>n;

        for(int i=0; i<n; i++){
            visited[i]= false;
            for(int j=0; j<n; j++)
                cin>>expenses[i][j];
        }
        visited[0] = true;
        int **dp = new int*[int(1<<n)];
        for(int i=0; i<int(1<<n); i++){
            dp[i] = new int[n];
            for(int j=0; j<n; j++)
                dp[i][j] = -1;
        }

        int result = sol.mrLee(0, 0, 0, n, dp);
        // cout<<result<<endl;
        out[t] = result;
    }


    cout<<"OUTPUT:"<<endl;

    for(int t=0; t<testcases; t++){
        cout<<out[t]<<endl;    
    }


}
