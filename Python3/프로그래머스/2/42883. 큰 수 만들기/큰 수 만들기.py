## 풀이 1 : 내 꼴리는대로 만든 코드
## 오류가 있으나 정답처리 됨...???
# def solution(number, k):
#     number = list(number)
#     nlen = len(number)
#     number.append('0')
#     number
#     idx = 0
#     answer=''
#     m = [0]*10
#     for i in number[idx:idx+k]:
#         m[ord(i)-48] += 1
#     rmv = 0
#     mx = 0
#     while idx < nlen:
#         if idx+k-rmv < nlen:
#             m[ord(number[idx+k-rmv])-48] += 1
#             for i in range(9,-1,-1):
#                 if m[i] > 0:
#                     mx = i
#                     break
#             #         print(i,":",m[i],end='||')
#             # print(mx)
#         #print(m,number[idx])
#         if ord(number[idx])-48 < mx and rmv < k:
#             m[ord(number[idx+k-rmv])-48] -= 1
#             rmv+=1
#         else:
#             answer += number[idx]
#         m[ord(number[idx])-48] -= 1
#         idx+=1
#     return answer
def solution(number, k):
    rmv = 0
    number = number[:]
    stack = []
    for n in number:
        while stack and n > stack[-1] and rmv < k :
            stack.pop()
            rmv+=1
        stack.append(n)
    while stack and rmv < k:
        stack.pop()
        rmv+=1
    return ''.join(stack)