def solution(dartResult):
    answer = 0
    l = len(dartResult)
    dartdict = {'S' : 1, 'D' : 2, 'T' : 3}
    dartlist = []
    tmp = ""
    for idx, c in enumerate(dartResult):
        if c in "*#":
            continue
        if c in "SDT":
            tmp += c
            if idx+1 < l and dartResult[idx+1] in "*#":
                tmp += dartResult[idx+1]
            else:
                tmp += '-'
            dartlist.append(tmp)
            tmp = ""
            continue
        tmp += c
    before = 0
    for dart in dartlist:
        if dart[-1] == '*':
            answer += before + pow(int(dart[:-2]), dartdict[dart[-2]]) * 2
            before = pow(int(dart[:-2]), dartdict[dart[-2]]) * 2
        elif dart[-1] == '#':
            answer -= pow(int(dart[:-2]), dartdict[dart[-2]])
            before = -1 * pow(int(dart[:-2]), dartdict[dart[-2]])
        else:
            before = pow(int(dart[:-2]), dartdict[dart[-2]])
            answer += pow(int(dart[:-2]), dartdict[dart[-2]])
            
    print(dartlist)
        
    return answer