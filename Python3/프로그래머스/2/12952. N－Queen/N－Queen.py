def can_put(x,y,lst):
    for ax,ay in lst:
        if x == ax or y == ay or x-y == ax-ay or ax+ay == x+y:
            return False
    return True

def solution(n):
    answer = [0]
    lst = []
    def dfs(n,cnt):
        if n == cnt:
            # print(lst)
            answer[0] += 1
            return
        for y in range(n):
            if can_put(cnt,y,lst):
                lst.append((cnt,y))
                dfs(n,cnt+1)
                lst.pop()
                
    dfs(n,0)
    return answer[0]