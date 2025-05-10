

def solution(n):
    answer = [0]
    lst = []
    col_visit = [False]*n
    cro1_visit = [False]*(2*n)
    cro2_visit = [False]*(2*n)
    def dfs(r,x):
        if r == x:
            # print(lst)
            answer[0] += 1
            return
        for c in range(n):
            if col_visit[c] or cro1_visit[r+c] or cro2_visit[n+r-c]:
                continue
            col_visit[c] = True
            cro1_visit[r+c] = True
            cro2_visit[n+r-c] = True
            dfs(r+1,x)
            col_visit[c] = False
            cro1_visit[r+c] = False
            cro2_visit[n+r-c] = False
        
    dfs(0,n)
    return answer[0]