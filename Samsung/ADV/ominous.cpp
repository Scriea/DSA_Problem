/*


Company  A  is discarding product numbers that contain few specific digits a specific number of time or 
more than that. You are given a range and you need to find product numbers that are possible.

Example-

Range: 24 to 12943

Numbers that should not come: 1, 3, 5
Number of times these number should not occur: 3 or more

In above case all two digit numbers are valid.

In three digit: 111, 113, 115, 311, 331, 333, 511, 533, 555 are not valid.

In four digit: All the numbers containing above 3 digit numbers are not valid.

Eg: 11223 is not valid, 11222 is valid.



Input:

2
100 999 3
3
1 3 5
112 999 3
3
1 3 5



Output:

#1 873
#2 872


*/


#include<iostream>
#include<cstring>
using namespace std;

#define MAXN 100

// int arr[MAXN];

int dp[20][20][2][2];
bool forbidden_digits[10] = {false};

/*
Brute Force: 

For every number count the number of ominous digits for each digit in the number...
And flag it that way
*/


void reverse(string &s){
    int right = s.size()-1;

    int left = 0;
    while(left<right){
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

string int_to_string(int num){
    string res = "";
    if (num<0)  {
        res+= "-";
        num = -num;
    }

    while(num){
        res += (num%10) + '0';
        num = num/10;
    }

    reverse(res);
    return res;
}


int ominous(string snum, int pos, int sum_so_far, bool isTight, bool leadingZero, int k){
    // Last digit
    if (pos==snum.size()){
        // if(leadingZero){
        //     return forbidden_digits[0]? (k>0):1;
        // }
        return sum_so_far<k?1:0;
    }

    if(dp[pos][sum_so_far][isTight][leadingZero] != -1) return dp[pos][sum_so_far][isTight][leadingZero];

    int limit = isTight ? snum[pos] - '0' : 9;

    int res = 0;
    for(int d=0; d<=limit; d++){
        bool newtight = isTight && d==limit;
        bool new_leading_zero = leadingZero && (d == 0);
        int new_sum_so_far = sum_so_far;
        
        if (!new_leading_zero){          
            if (forbidden_digits[d]) {
                new_sum_so_far+=1;
            }
        }
        if(new_sum_so_far >= k)  continue;
        res += ominous(snum, pos + 1, new_sum_so_far, newtight, new_leading_zero, k);
    }
    return dp[pos][sum_so_far][isTight][leadingZero] = res;



}

int solve(int left, int right, int k){
    // int ans = right - left + 1;  
    string upper = int_to_string(right), lower = int_to_string(left-1);

    int romin = ominous(upper, 0, 0, true, true, k);
    memset(dp, -1, sizeof(dp));

    int lomin=  ominous(lower, 0, 0, true, true, k);

    return  romin - lomin;
}

int numberOminous(int a, int b, int k){
    int count = 0;
    for(int i = a; i <= b; i++){
        int temp = i;
        int digitArray[10] = {0};

        while(temp){
            digitArray[temp%10]++;
            temp /= 10;
        }
        
        int rougeK = 0;
        for(int i=0; i<10; i++){
            if (forbidden_digits[i])    rougeK += digitArray[i];
        }

        if(rougeK < k){
            count++;
        }

    }
    return count;
}

int main(){
int testcases;
cin>>testcases;
int left, right, k, n, temp;

int answers[testcases];
for(int t=0; t<testcases; t++){
    cin>>left>>right>>k;
    cin>>n;
    memset(forbidden_digits, false, sizeof(forbidden_digits));
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++) {
        cin>>temp;
        forbidden_digits[temp]=true;}
    // answers[t] = solve(left, right, k);
    answers[t] = numberOminous(left, right, k);
}
for(int t=0; t<testcases; t++){
    cout<<"#"<<t+1<<" "<<answers[t]<<endl;
}
}
