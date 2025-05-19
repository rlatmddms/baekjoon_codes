from collections import deque
a,b = map(int,input().split())
visit = [0]*100001
q = deque([a])
visit[a] = 1
i = 2
if a != 0:
    while a*i <= 100000:
        visit[a*i] = 1
        q.append(a*i)
        i*=2
while q:
    v = q.popleft()
    if v == b:
        break
    if v-1 >= 0 and visit[v-1] == 0:
        visit[v-1] = visit[v] + 1
        q.append(v-1)
        i = 2
        while (v-1)*i <= 100000 and visit[(v-1)*i] == 0:
            visit[(v-1)*i] = visit[v] + 1
            q.append((v-1)*i)
            i*=2
    if v+1 <= 100000 and visit[v+1] == 0:
        visit[v+1] = visit[v] + 1
        q.append(v+1)
        i = 2
        while (v+1)*i <= 100000 and visit[(v+1)*i] == 0:
            visit[(v+1)*i] = visit[v] + 1
            q.append((v+1)*i)
            i*=2
    # print(q)
dis = visit[b]-1
print(dis)