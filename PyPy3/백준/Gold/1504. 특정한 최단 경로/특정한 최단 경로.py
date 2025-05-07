import sys
import heapq
input = sys.stdin.readline
n,m = map(int, input().split())
graph = [[-1]*(n+1) for _ in range(n+1)]


for i in range(m):
    a,b,c = map(int,input().split())
    graph[a][b] = c
    graph[b][a] = c

v1, v2 = map(int, input().split())
def dij(start,end):
    heap = [(0,start)]
    dista = [999999999]*(n+1)
    dista[start] = 0
    while heap:
        c,v = heapq.heappop(heap)
        if dista[v] < c:
            continue
        for i in range(1,n+1):
            if graph[v][i] == -1:
                continue
            if c + graph[v][i] < dista[i]:
                heapq.heappush(heap,(c+graph[v][i],i))
                dista[i] = c + graph[v][i]
    return dista[end]
case1 = dij(1,v1) + dij(v1,v2) + dij(v2,n)
case2 = dij(1,v2) + dij(v2,v1) + dij(v1,n)
if min(case1,case2) >= 999999999:
    print(-1)
else:
    print(min(case1,case2))