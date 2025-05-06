def make_minute(s):
    h,m = s.split(':')
    return int(h) * 60 + int(m)

def solution(fees, records):
    cars = [[] for _ in range(10000)]
    answer = []
    for log in records:
        t, car_id, inout = log.split()
        t = make_minute(t)
        car_id = int(car_id)
        if inout == 'IN':
            cars[car_id].append([t])
        else:
            cars[car_id][-1].append(t)
    for i in range(0,10000):
        if not cars[i]:
            continue
        if len(cars[i][-1]) == 1:
            cars[i][-1].append(make_minute("23:59"))
        t = 0
        for IN,OUT in cars[i]:
            t += OUT - IN
        print(i,t)
        t -= fees[0]
        fee = fees[1]
        if t <= 0: 
            answer.append(fee)
            continue
        fee += (t//fees[2] + (1 if t%fees[2] != 0 else 0)) * fees[3]
        answer.append(fee)
    return answer