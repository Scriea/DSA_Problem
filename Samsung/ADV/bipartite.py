"""

Given a graph print either of the set of the vertices that are colored with the same color. And if the graph
is not bipartite print “-1”. Test cases also included the cases when a graph is not connected.

"""


def is_bipartite(graph, n):
    pass

if __name__=="__main__":
    n = int(input())
    graph = {i:[] for i in range(n)}

    

    for i in range(n):
        temp = list(map(int, input().split()))
        graph[i] = temp

    print(n,graph)