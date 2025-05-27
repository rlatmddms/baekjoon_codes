def is_prime(n): 
    if n == 2:
        return True
    if n < 2 or n%2 == 0:
        return False
    i = 3 
    while i*i <= n: 
        if n % i == 0: 
            return False 
        i+=2 
    return True 

def solution(numbers): 
    answer = [0]
    visit = [False]*len(numbers)
    sett = set()
    s = []
    def dfs(n):
        if n == len(numbers):
            return
        for i in range(len(numbers)):
            if n == 0 and numbers[i] == '0':
                continue
            if not visit[i] and ''.join(s)+numbers[i] not in sett:
                sett.add(''.join(s)+numbers[i])
                if is_prime(int(''.join(s)+numbers[i])):
                    answer[0] += 1
                    # print(''.join(s)+numbers[i])
                visit[i] = True
                s.append(numbers[i])
                dfs(n+1)
                visit[i] = False
                s.pop()
    dfs(0)
    return answer[0]