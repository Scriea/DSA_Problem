import math

def solve(n):
    ## Remove trailing zeros
    count = 0
    while n%10==0:
        n= n//10
        count+=1

    digits= int(math.log10(n)) + 1  
    s = str(n)
    i, j = 0,0
    _max = -1
    while i<digits:
        if s[i]==0:
            j = i+1
            while s[j]==0:
                j+=1
            
            _max = max(_max, j-i)

        i = j
        i+=1

    return count + digits - _max 


t = int(input())
for _ in range(t):
    n = int(input().strip())
    print(solve(n))