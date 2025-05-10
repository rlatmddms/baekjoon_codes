import sys,heapq
input = sys.stdin.readline
n,m = map(int,input().split())
graph = [[] for _ in range(n+1)]
start = int(input())
for _ in range(m):
    a,b,c = map(int,input().split())
    graph[a].append((c,b))
dist = ["INF"]*(n+1)
heap = [(0,start)]
dist[start] = 0
while heap:
    cost,v = heapq.heappop(heap)
    if dist[v] < cost:
        continue
    for c,i in graph[v]:
        if dist[i] == "INF" or dist[i] > dist[v]+c:
            dist[i] = dist[v]+c
            heapq.heappush(heap,(dist[i],i))

for i in range(1,n+1):
    print(dist[i])