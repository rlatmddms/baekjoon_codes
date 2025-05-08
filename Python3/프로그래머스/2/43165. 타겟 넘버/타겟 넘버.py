answer = 0
def solution(numbers, target):
    global answer
    l = len(numbers)
    visit = [0]*l
    arr = []
    def dfs(i,s,tt):
        if i == l:
            if s == tt:
                global answer
                answer+=1
                print(arr,tt)
            return
        visit[i] = 1
        dfs(i+1,s+numbers[i],tt)
        dfs(i+1,s-numbers[i],tt)
        visit[i] = 0
    
    dfs(0,0,target)
    return answer