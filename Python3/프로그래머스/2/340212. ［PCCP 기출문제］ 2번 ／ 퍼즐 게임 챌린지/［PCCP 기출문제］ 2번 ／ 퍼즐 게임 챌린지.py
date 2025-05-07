def solution(diffs, times, limit):
    answer = 0
    left = 1
    right = 100000
    stages = len(times)
    while left < right:
        level = (left+right)//2
        s = 0
        for i in range(stages):
            if diffs[i] <= level:
                s += times[i]
            else:
                time_prev = 0 if i == 0 else times[i-1]
                s += (times[i]+time_prev) * (diffs[i] - level) + times[i]
        if s <= limit:
            right = level
        else:
            left = level+1
        # print(level,s)
    return right