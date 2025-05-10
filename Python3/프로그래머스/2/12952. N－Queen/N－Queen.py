

def solution(n):
    answer = [0]
    lst = []
    def can_put(x,y):
        for ax,ay in lst:
            if x == ax or y == ay or x-y == ax-ay or ax+ay == x+y:
                return False
        return True
    def dfs(n,x):
        if n == x:
            # print(lst)
            answer[0] += 1
            return
        for y in range(n):
            if can_put(x,y):
                lst.append((x,y))
                dfs(n,x+1)
                lst.pop()
        
    dfs(n,0)
    return answer[0]