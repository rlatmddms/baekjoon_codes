def solution(X, Y):
    answer = ''
    Xarr = [0]*10
    Yarr = [0]*10
    for i in X:
        Xarr[ord(i)-48]+=1
    for i in Y:
        Yarr[ord(i)-48]+=1
    for i in range(9,0,-1):
        while Xarr[i] > 0 and Yarr[i] > 0:
            answer += str(i)
            Xarr[i] -= 1
            Yarr[i] -= 1
    if answer == "":
        if Xarr[0] > 0 and Yarr[0] > 0:
            return "0"
        return "-1"
    while Xarr[0] > 0 and Yarr[0] > 0:
        answer += '0'
        Xarr[0] -= 1
        Yarr[0] -= 1
    return answer