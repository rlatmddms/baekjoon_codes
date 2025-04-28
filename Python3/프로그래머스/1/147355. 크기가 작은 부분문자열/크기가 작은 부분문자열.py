def solution(t, p):
    answer = 0
    plen = len(p)
    p = int(p)
    for i in range(len(t) - plen+1):
        # print(t[i:i+plen])
        if int(t[i:i+plen]) <= p:
            answer+=1;
    return answer