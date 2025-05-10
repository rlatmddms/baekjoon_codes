import sys
input = sys.stdin.readline
nm = list(map(int,input().split()))
lst = []
visit = [False]*(nm[0]+1)

def dfs(cnt):
    if cnt == nm[1]:
        print(*lst)
        return
    for i in range(1,nm[0]+1):
        if not visit[i]:
            visit[i] = True
            lst.append(i)
            dfs(cnt+1)
            visit[i] = False
            lst.pop()
dfs(0)