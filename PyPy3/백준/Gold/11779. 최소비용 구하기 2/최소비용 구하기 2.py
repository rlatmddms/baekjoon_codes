import sys
import heapq
input = sys.stdin.readline

n = int(input())
m = int(input())

graph = [[] for _ in range(n+1)]
for i in range(m):
    a,b,c = map(int,input().strip().split())
    graph[a].append((c,b))

distance = [[99999999999,[]] for _ in range(n+1)]

def dijkstra(start, end):
    distance[start][0] = 0
    distance[start][1].append(start)
    heap = [(0,start)]
    
    while heap:
        cost, v = heapq.heappop(heap)
        if cost > distance[v][0]:
            continue
        for c,i in graph[v]:
            if c+cost < distance[i][0]:
                distance[i][0] = c+cost
                distance[i][1] = distance[v][1] + [i]
                heapq.heappush(heap,(c+cost,i))
    print(distance[end][0])
    print(len(distance[end][1]))
    print(*distance[end][1])
start,end = map(int,input().strip().split())
dijkstra(start,end)