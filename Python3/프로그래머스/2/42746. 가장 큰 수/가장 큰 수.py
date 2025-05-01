def solution(numbers):
    for i,n in enumerate(numbers):
        tmp1 = str(n)
        tmp2 = str(n) * 4
        numbers[i] = (tmp1, tmp2)
    numbers.sort(key = lambda x : x[1])
    # print(numbers)
    answer = ''
    # answer = ''.join(numbers)
    for i in reversed(numbers):
        answer += i[0]
    if(answer.count('0') == len(answer)): return '0'
    return answer