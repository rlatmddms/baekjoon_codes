import sys
import heapq
input = sys.stdin.readline

dx = [-1,1,0,0]
dy = [0,0,-1,1]
test = 0
while True:
    test+=1
    n = int(input())
    if n == 0:
        break
    board = []
    visit = [[2000000]*n for _ in range(n)]
    for i in range(n):
        board.append(list(map(int,input().split())))
    
    heap = [(board[0][0],0,0)]
    visit[0][0] = board[0][0]
    while heap:
        cost,x,y = heapq.heappop(heap)
        if visit[x][y] < cost:
            continue
        for d in zip(dx,dy):
            ax = x+d[0]
            ay = y+d[1]
            if ax < 0 or ay < 0 or ax >= n or ay >= n:
                continue
            if visit[ax][ay] > cost + board[ax][ay]:
                visit[ax][ay] = cost + board[ax][ay]
                heapq.heappush(heap, (cost + board[ax][ay], ax, ay))
    print(f"Problem {test}:",visit[n-1][n-1])
            