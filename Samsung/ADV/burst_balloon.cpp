/*
There are n balloons and n bullets and each balloon is assigned with a particular number (point).
Whenever a particular balloon is shot the no of points increases by
1.the multiplication of point assigned to balloon on left and that of right side.
2.point assigned to left if no right exists
3.point assigned to right if no left exists.
4.the point assigned to itself if no other balloon exists.
 
You have to output the maximum no of points possible.
 
Input
4
1
2
3
4
 
Output
20




Input 
4
8
2
5
1


Output
64

Input
4
2
2
2
2


Output



*/

#include <iostream>
#include<cstring>
using namespace std;


class Solution{

    public:
        int max_burst_balloon(int a[], int n){
            int b[n+2];
            b[0]=1;
            b[n+1] = 1;
            for(int i=1; i <= n; i++){
                b[i] = a[i-1];
            }
            
            for(int i=0; i<n+2; i++)    cout<<b[i];
            int dp[n+2][n+2];
            memset(dp,0, sizeof(dp));

            for(int siz = 1; siz<=n; siz++){
                for(int left=0; left<n+1-siz; left++){
                    int right = left+siz+1;
                    for(int j=left+1; j<right; j++){

                        if(left==0 && right==n-1) dp[left][right] = max(b[left]*b[j]*b[right] + dp[left][j] + dp[j][right],dp[left][right]);
                        else    dp[left][right] = max(dp[left][right], dp[left][j] + dp[j][right] +  max(b[left]*b[right], b[j]));

                        // if(siz==1)  dp[left][right] = max(dp[left][right], dp[left][j] + dp[j][right] +  b[j]);

                        
                    }
                }   
                cout<<"DP MATRIX:"<<endl;
                for(int i=0; i<n+2;i++){
                    for(int k=0; k<n+2;k++){
                        cout<<dp[i][k]<<" ";
                    }
                    cout<<endl;
    
                }
            }
            return dp[0][n+1];
    }

};

int main(){

    int siz;
    Solution solution;
    cin >> siz;
    int A[siz];
    for(int i=0;i<siz;i++)
        cin >> A[i]; 
    int ans = solution.max_burst_balloon(A, siz);
    cout << ans << endl;
    return 0;
}