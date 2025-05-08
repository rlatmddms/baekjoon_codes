from collections import deque
def solution(queue1, queue2):
    answer = 0
    sum1 = sum(queue1)
    sum2 = sum(queue2)
    length = len(queue1) + len(queue2)
    goal = sum1 + sum2
    if goal % 2 == 1:
        return -1
    else:
        goal //= 2
    q1 = deque(queue1[:])
    q2 = deque(queue2[:])
    while q1 and q2:
        if answer > length+1:
            return -1
        if sum1 < sum2:
            q_pop = q2.popleft()
            sum2 -= q_pop
            sum1 += q_pop
            q1.append(q_pop)
            answer+=1
        elif sum1 > sum2:
            q_pop = q1.popleft()
            sum2 += q_pop
            sum1 -= q_pop
            q2.append(q_pop)
            answer+=1
        else:
            return answer
    return -1