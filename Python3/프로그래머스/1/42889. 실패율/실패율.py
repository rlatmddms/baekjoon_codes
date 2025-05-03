def solution(N, stages):
    answer = []
    stages.sort(reverse=True) 
    tryer = [[i,0,0] for i in range(1,N+2)]
    
    for i in stages:
        tryer[i-1][1] += 1
    idx = N-1
    l = 0
    print(tryer)
    while idx > -1:
        l += tryer[idx+1][1]
        tryer[idx][2] = l + tryer[idx][1]
        idx -= 1
    # print(tryer)
    tryer.pop()
    
    tryer = list(map(lambda x : (x[0],x[1]/x[2] if x[2] != 0 else 0),tryer))
    tryer.sort(key= lambda x : -x[1]) 
    # print(tryer)
    tryer = list(map(lambda x : x[0],tryer))
    return tryer