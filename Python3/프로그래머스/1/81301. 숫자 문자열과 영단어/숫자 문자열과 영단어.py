def solution(s):
    answer = 0
    numberdic = {"zero":0,"one":1,"two":2,"three":3,"four":4,"five":5,"six":6,"seven":7,"eight":8,"nine":9}
    # idx = 0; length = len(s)
    tmp = ""
    for c in s:
        if 'a' <= c <= 'z':
            tmp += c
            if tmp in numberdic:
                answer = answer*10 + numberdic[tmp]
                tmp = ""
        else:
            answer = answer*10 + ord(c) - 48
    return answer