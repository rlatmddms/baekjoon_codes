def solution(s):
    answer = []
    s = s[2:-2].split('},{')
    s = list(map(lambda x : set(list(map(int,x.split(',')))), s))
    s.sort(key = lambda x : len(x))
    answer.append(s[0].pop())
    s[0].add(answer[-1])
    # print(s)
    idx = 1; slen = len(s)
    while idx < slen:
        tmp = s[idx] - s[idx-1]
        answer.append(tmp.pop())
        # print(tmp.pop())
        idx+=1
    return answer