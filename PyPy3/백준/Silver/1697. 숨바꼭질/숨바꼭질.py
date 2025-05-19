from collections import deque
a,b = map(int,input().split())
visit = [0]*100001
q = deque([a])
visit[a] = 1
while q:
    v = q.popleft()
    if v == b:
        break
    if v-1 >= 0 and visit[v-1] == 0:
        visit[v-1] = visit[v] + 1
        q.append(v-1)
    if v+1 <= 100000 and visit[v+1] == 0:
        visit[v+1] = visit[v] + 1
        q.append(v+1)
    if v*2 <= 100000 and visit[v*2] == 0:
        visit[v*2] = visit[v] + 1
        q.append(v*2)
print(visit[b]-1)        