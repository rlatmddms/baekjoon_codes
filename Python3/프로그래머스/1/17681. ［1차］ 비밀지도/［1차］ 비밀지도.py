def solution(n, arr1, arr2):
    answer = []
    for idx,number in enumerate(arr1):
        tmp = ""
        while number != 0:
            if number % 2 ==1:
                tmp += '#'
            else:
                tmp += ' '
            number = number // 2
        tmp = ((tmp + " "*n)[:n])[::-1]
        arr1[idx] = tmp
    for idx,number in enumerate(arr2):
        tmp = ""
        while number != 0:
            if number % 2 == 1:
                tmp += '#'
            else:
                tmp += ' '
            number = number // 2
        tmp = ((tmp + " "*n)[:n])[::-1]
        arr2[idx] = tmp
    print(arr1)
    print()
    print(arr2)
    for s1,s2 in zip(arr1,arr2):
        tmp = ""
        for c1,c2 in zip(s1,s2):
            if c1 == '#' or c2 == '#': tmp += '#'
            else: tmp += ' '
        answer.append(tmp)
    return answer