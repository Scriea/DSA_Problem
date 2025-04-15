"""

Test - 1
You are given a path on an infinite 2d lattice. The path consists of line segments parallel to either the x or y axis. VVA
Example : 1, 1 to 1, 3 to 6, 3 to 6, 6 to bla bla
Also there is a set of points given . You have to find how many of the given points lie on the path. The input was as follow
N M as two variables
There were n numbers that denoted x coordinates of n points
There were n numbers again which denoted y coordinates of those n points

So total, there is the info of n points in space
Now, there are two more arrays of size m , one consisting of x coordinates and other of y coordinates correspondingly
These points are the turning points in a path.
Examples.
Say I went from 1, 1 to 1, 5 to 2, 5 so the given arrays will be
1, 1, 2
1, 5, 5
In the given path , we have to find how many of the given n points lie.



Example:


Input:

6
5 4
1 2 3 4 5
1 2 3 4 5
1 1 2 2
1 5 5 2
3 3
1 2 3
3 2 1
1 1 2
1 2 2
3 1
1 2 3
1 2 3
1
1
5 4
1 2 3 4 5
1 2 3 4 5
1 1 2 2
1 5 5 2
5 4
1 2 3 4 5
1 2 3 4 5
1 5 5 3
1 1 2 2
5 5
100000 200000 300000 400000 500000
100000 200000 300000 400000 500000
100000 100000 300000 400000 400000
100000 200000 200000 200000 500000

Output:
2
1
0
2
1
3
"""

def merge_intervals(intervals):
    intervals = sorted(intervals)
    merged_intervals = []
    for i in range(len(intervals)):
        if len(merged_intervals)==0:
            merged_intervals.append(intervals[i])
        else:
            top = merged_intervals[-1]
            if top[1]>=intervals[i][0]:
                merged_intervals[-1] = (top[0], max(intervals[i][1], top[1]))
            
            else:
                merged_intervals.append(intervals[i])

    return merged_intervals

def bin_find(point, bins):
    l,r = 0, len(bins)-1
    

    while l<=r:
        mid = l + (r-l)//2
        if bins[mid][0]<= point <= bins[mid][1]:
            return True
        elif point >bins[mid][1]:
            l = mid+1
        else:
            r = mid-1
    
    return False

def solve(n,m, points_x, points_y, edges_x_co, edges_y_co):
    edges_x, edges_y = {}, {}
    for i in range(m-1):
        if edges_x_co[i] == edges_x_co[i+1]:
            if not edges_x_co[i] in edges_y:
                edges_y[edges_x_co[i]] = []

            edges_y[edges_x_co[i]].append((min(edges_y_co[i],edges_y_co[i+1]), max(edges_y_co[i], edges_y_co[i+1])))

        else:
            if not edges_y_co[i] in edges_x:
                edges_x[edges_y_co[i]] = []
            edges_x[edges_y_co[i]].append((min(edges_x_co[i],edges_x_co[i+1] ), max(edges_x_co[i+1], edges_x_co[i])))
    
    
    for key in edges_x.keys():
        edges_x[key] = merge_intervals(edges_x[key])
    
    for key in edges_y.keys():
        edges_y[key] = merge_intervals(edges_y[key])

    count=0

    for i in range(n):

        if points_x[i] in edges_y:
            if bin_find(points_y[i], edges_y[points_x[i]]):
                count+=1
                continue
        
        if points_y[i] in edges_x:
            if bin_find(points_x[i], edges_x[points_y[i]]):
                count+=1
                continue
    

    return count
    


if __name__=="__main__":
    testcases = int(input())
    ans = []
    for t in range(testcases):
        n,m = tuple(map(int, input().strip().split()))
        
        

        points_x, points_y = None, None
        points_x = list(map(int, input().strip().split()))
        points_y = list(map(int, input().strip().split()))


        edges_x_co = list(map(int, input().strip().split()))
        edges_y_co = list(map(int, input().strip().split()))
        ans.append(solve(n,m, points_x, points_y, edges_x_co, edges_y_co))
    

    for item in ans:
        print(item)


    





