"""
    A beutiful permutation is such that there doesn't exist and index i s.t 
    | per[i] - per[i-1] | = 1 

"""

    
if __name__=="__main__":
    n = int(input())  
    if 1<n<=3:
        print("NO SOLUTION")
    else:
        for i in range(2,n+1,2):
            print(i, end=" ")
        for i in range(1,n+1,2):
            print(i, end=" ")



    
    

       
        


