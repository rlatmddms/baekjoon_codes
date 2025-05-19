from collections import deque
import sys
sys.setrecursionlimit(100000)
a,b = map(int,input().split())
visit = [0]*100001
before = [0]*100001
q = deque([a])
visit[a] = 1
before[a] = -1
while q:
    v = q.popleft()
    if v-1 >= 0 and visit[v-1] == 0:
        visit[v-1] = visit[v] + 1
        before[v-1] = v
        q.append(v-1)
    if v+1 <= 100000 and visit[v+1] == 0:
        visit[v+1] = visit[v] + 1
        before[v+1] = v
        q.append(v+1)
    if v*2 <= 100000 and visit[v*2] == 0:
        visit[v*2] = visit[v] + 1
        before[v*2] = v
        q.append(v*2)
dis = visit[b]-1
print(dis)
q = deque()
while before[b] != -1:
    q.appendleft(b)
    b = before[b]
q.appendleft(a)
print(*q)