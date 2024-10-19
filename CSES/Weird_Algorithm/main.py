"""
    Straight Forward:
        - Recursion : Uses recursion stack space (Not optimal)
        - Iteration : Uses constant space
"""


if __name__=="__main__":
    n = int(input())

    while n!=1:
        print( n, end=" ")
        if n%2==0:
            n = n//2
        else:
            n = 3*n +1
    print(n)