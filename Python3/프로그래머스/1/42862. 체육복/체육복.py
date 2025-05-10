def solution(n, lost, reserve):
    answer = 0
    have = [1]*(n+1);
    for i in lost:
        have[i] -= 1
    for i in reserve:
        have[i] += 1
    for i in range(1,n+1):
        if have[i] == 0:
            if i-1 > 0 and have[i-1] == 2:
                have[i] = 1
                have[i-1] = 1
            elif i+1 <= n and have[i+1] == 2:
                have[i] = 1
                have[i+1] = 1
    return sum([1 for i in have if i != 0]) -1