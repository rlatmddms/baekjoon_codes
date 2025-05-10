import sys
input = sys.stdin.readline
n = int(input())
s = [0]
row_visit = [False]*n
col_visit = [False]*n
cro1_visit = [False]*(2*n)
cro2_visit = [False]*(2*n)

def dfs(r,n):
    if r == n:
        s[0] += 1
        return
    for c in range(n):
        if row_visit[r] or col_visit[c] or cro1_visit[r+c] or cro2_visit[n+r-c]:
            continue
        row_visit[r] = True
        col_visit[c] = True
        cro1_visit[r+c] = True
        cro2_visit[n+r-c] = True
        dfs(r+1,n)
        row_visit[r] = False
        col_visit[c] = False
        cro1_visit[r+c] = False
        cro2_visit[n+r-c] = False
dfs(0,n)
print(s[0])