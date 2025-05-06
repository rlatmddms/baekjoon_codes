def solution(msg):
    answer = []
    last_number = 27
    dic = {};
    ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    for i,abc in enumerate(ALP,1):
        dic[abc] = i
    msg_len = len(msg)
    idx = 0
    before = ""
    while idx < msg_len:
        s = msg[idx]
        i = 0
        while s in dic:
            i += 1
            if idx+i == msg_len:
                break
            s += msg[idx+i]
        if s not in dic:
            dic[s] = last_number
            # print(s, "저장")
            last_number+=1
            s = s[:-1]
            idx = idx+i
            answer.append(dic[s])
        else:
            answer.append(dic[s])
            idx = idx+i
    return answer