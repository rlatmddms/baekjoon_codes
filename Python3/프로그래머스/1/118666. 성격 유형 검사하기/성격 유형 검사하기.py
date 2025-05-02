def solution(survey, choices):
    answer = []
    MBTI = [0,0,0,0]
    #     RT CF JM AN
    dic = {"R" : 0, "C" : 1, "J" : 2, "A" : 3}
    for AB,score in zip(survey, choices):
        if AB[0] in dic:
            MBTI[dic[AB[0]]] += score-4
        else:
            MBTI[dic[AB[1]]] += 4-score
    answer.append('R' if MBTI[0] <= 0 else 'T')
    answer.append('C' if MBTI[1] <= 0 else 'F')
    answer.append('J' if MBTI[2] <= 0 else 'M')
    answer.append('A' if MBTI[3] <= 0 else 'N')
    return ''.join(answer)