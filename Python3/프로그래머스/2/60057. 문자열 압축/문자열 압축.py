def string_zip(s,n):
    answer = ""
    cutting_s = []
    tmp = ""
    for i,c in enumerate(s,1):
        tmp += c
        if i % n == 0:
            cutting_s.append(tmp)
            tmp = ""
    if tmp:
        cutting_s.append(tmp)
        tmp = ""
    chain = 1
    for c in cutting_s:
        if tmp == c:
            chain+=1
        else:
            if chain == 1:
                answer += tmp
            else:
                answer += str(chain) + tmp
            chain = 1
            tmp = c
    if chain == 1:
        answer += tmp
    else:
        answer += str(chain) + tmp
    return len(answer)
def solution(s):
    slen = len(s)
    answer = 9999
    for i in range(slen,0,-1):
        zipped_size = string_zip(s,i)
        if answer > zipped_size:
            answer = zipped_size
    return answer