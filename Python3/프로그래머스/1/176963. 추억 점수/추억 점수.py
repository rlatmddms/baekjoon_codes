def solution(name, yearning, photo):
    answer = []
    dic = {}
    for i in range(len(name)):
        dic[name[i]] = yearning[i]
    for p in photo:
        s = 0
        for n in p:
            if n in dic:
                s += dic[n]
        answer.append(s)
    return answer