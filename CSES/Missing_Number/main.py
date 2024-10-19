"""
    The idea is to use simple Mathematics
"""

    
if __name__=="__main__":
    n = int(input())  
    
    nums = map(int, input().split())

    _sum = sum(nums)

    print(n*(n+1)//2 - _sum)

    
    

       
        


