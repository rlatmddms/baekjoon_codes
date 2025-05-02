def solution(participant, completion):
    dic = dict()
    for i in completion:
        if i not in dic:
            dic[i] = 1
        else:
            dic[i] += 1
    for i in participant:
        if i not in dic or dic[i] == 0:
            return i
        dic[i] -= 1
            