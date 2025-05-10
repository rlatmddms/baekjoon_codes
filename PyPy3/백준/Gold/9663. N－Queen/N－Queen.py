import sys
input = sys.stdin.readline
n = int(input())
s = [0]
col_visit = [False]*n
cro1_visit = [False]*(2*n)
cro2_visit = [False]*(2*n)

def dfs(r,n):
    if r == n:
        s[0] += 1
        return
    for c in range(n):
        if col_visit[c] or cro1_visit[r+c] or cro2_visit[n+r-c]:
            continue
        col_visit[c] = True
        cro1_visit[r+c] = True
        cro2_visit[n+r-c] = True
        dfs(r+1,n)
        col_visit[c] = False
        cro1_visit[r+c] = False
        cro2_visit[n+r-c] = False
dfs(0,n)
print(s[0])