import sys
input = sys.stdin.readline
nm = list(map(int,input().split()))
match = list(map(int,input().split()))
match.sort()
match = [match[0]] + [n for i,n in enumerate(match[1:],1) if n != match[i-1]]
lst = []
def dfs(cnt):
    if cnt == nm[1]:
        print(*lst)
        return
    mm = lst[-1] if lst else 0
    for i in match:
        if i < mm:
            continue
        lst.append(i)
        dfs(cnt+1)
        lst.pop()
dfs(0)