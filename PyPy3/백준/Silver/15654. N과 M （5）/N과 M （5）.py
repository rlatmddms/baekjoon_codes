import sys
input = sys.stdin.readline
nm = list(map(int,input().split()))
match = list(map(int,input().split()))
match.sort()
visit = [0]*10001
for i in match:
    visit[i] += 1
match = [match[0]] + [n for i,n in enumerate(match[1:],1) if n != match[i-1]]
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