def solution(numbers, hand):
    answer = ""
    pos = [(3,1),(0,0),(0,1),(0,2),(1,0),(1,1),(1,2),(2,0),(2,1),(2,2)]
    k2580 = [2,5,8,0]
    k147 = [1,4,7]
    left = (3,0)
    right = (3,2)
    for n in numbers:
        if n in k2580:
            Ldis = abs(pos[n][0] - left[0]) + abs(pos[n][1] - left[1])
            Rdis = abs(pos[n][0] - right[0]) + abs(pos[n][1] - right[1])
            # print(Rdis,Ldis,end="  ")
            if Ldis == Rdis:
                Rdis += -10 if hand == 'right' else 10
            if Rdis < Ldis:
                right = pos[n]
                answer += 'R'
            else:
                left = pos[n]
                answer += 'L'
        elif n in k147:
            left = pos[n]
            answer += 'L'
        else:
            right = pos[n]
            answer += 'R'
        # print(right, left)
    return answer
        