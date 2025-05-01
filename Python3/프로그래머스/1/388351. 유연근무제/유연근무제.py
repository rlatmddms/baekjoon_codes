def solution(schedules, timelogs, startday):
    answer = len(schedules)
    for set_time, timelog in zip(schedules,timelogs):
        set_time = (set_time // 100) * 60 + set_time % 100
        print(timelog)
        for d,t in enumerate(timelog):
            t = (t // 100) * 60 + t % 100
            # print(set_time,t)
            if (d+startday) % 7 == 0 or (d+startday) % 7 == 6:
                continue
            if set_time+10 < t:
                answer -= 1
                break
    return answer