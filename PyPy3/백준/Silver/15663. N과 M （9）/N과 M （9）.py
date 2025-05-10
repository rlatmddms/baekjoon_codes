import sys
input = sys.stdin.readline
nm = list(map(int,input().split()))
lst = list(map(int,input().split()))
lst.sort()
visit = [0]*10001
for i in lst:
    visit[i] += 1
match = [lst[0],]
for i,n in enumerate(lst[1:],1):
    if n != lst[i-1]:
        match.append(n)
lst = []
def dfs(cnt):
    if cnt == nm[1]:
        print(*lst)
        return
    for i in match:
        if visit[i] == 0:
            continue
        visit[i] -= 1
        lst.append(i)
        dfs(cnt+1)
        visit[i] += 1
        lst.pop()
dfs(0)