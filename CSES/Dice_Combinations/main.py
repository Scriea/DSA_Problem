"""
This is very non trivial problem,
where you have to optimize the space and time complexity
to the minimal.

The expected time complexity to get 
combinations(n) is O(n), not even O(6n) :(


"""

MOD = 10**9 + 7
n = int(input())
dp = [0]*(7)
dp[0] = 1
curr = 1
for i in range(1,7):
    dp[i] = curr
    curr+=dp[i]
for i in range(7,n+1):
    curr = dp[(i-1)%7]  - dp[i%7]
    dp[i%7] = (dp[(i-1)%7] + curr)%MOD
print(dp[n%7])