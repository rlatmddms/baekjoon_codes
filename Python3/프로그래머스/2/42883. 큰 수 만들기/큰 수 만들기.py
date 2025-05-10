# def solution(number, k):
#     number = list(number)
#     nlen = len(number)
#     idx = 0
#     answer=''
#     rmv = 0
#     while idx < nlen:
#         if idx+k-rmv < nlen:
#             m = max(number[idx:idx+k+1-rmv])
#         #print(m,number[idx])
#         if number[idx] < m and rmv < k:
#             rmv+=1
#         else:
#             answer += number[idx]
#         idx+=1
#     return answer


def solution(number, k):
    number = list(number)
    
    nlen = len(number)
    number+='0'
    idx = 0
    answer=''
    m = [0]*10
    for i in number[idx:idx+k]:
        m[ord(i)-48] += 1
    rmv = 0
    mx = 0
    while idx < nlen:
        if idx+k-rmv < nlen:
            m[ord(number[idx+k-rmv])-48] += 1
            for i in range(9,-1,-1):
                if m[i] > 0:
                    mx = i
                    break
            #         print(i,":",m[i],end='||')
            # print(mx)
        #print(m,number[idx])
        if ord(number[idx])-48 < mx and rmv < k:
            m[ord(number[idx+k-rmv])-48] -= 1
            rmv+=1
        else:
            answer += number[idx]
        m[ord(number[idx])-48] -= 1
        idx+=1
    return answer