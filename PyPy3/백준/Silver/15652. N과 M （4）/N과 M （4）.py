import sys
input = sys.stdin.readline
nm = list(map(int,input().split()))
lst = []
visit = [False]*(nm[0]+1)

def dfs(cnt):
    if cnt == nm[1]:
        print(*lst)
        return
    start = lst[-1] if lst else 1
    for i in range(start,nm[0]+1):
        lst.append(i)
        dfs(cnt+1)
        lst.pop()
dfs(0)