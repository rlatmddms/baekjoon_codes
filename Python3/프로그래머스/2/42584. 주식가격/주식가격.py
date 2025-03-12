def solution(prices):
    l = len(prices)
    a = [0]*l
    for i,p in enumerate(prices,1):
        for j in range(i,l):
            a[i-1]+=1
            if p > prices[j]:
                break
    return a