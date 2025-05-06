def solution(s):
    answer = []
    s = s[2:-2].split('},{')
    s = list(map(lambda x : set(map(int,x.split(','))), s))
    s.sort(key = lambda x : len(x))
    for i in s:
        answer.append((i - set(answer)).pop())
    return answer