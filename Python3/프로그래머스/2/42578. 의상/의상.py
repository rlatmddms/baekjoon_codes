def solution(clothes):
    answer = 1
    clothedict = {}
    for name, category in clothes:
        if category not in clothedict:
            clothedict[category] = 0
        clothedict[category] += 1
        
    for key,val in clothedict.items():
        answer *= (val+1)
    
    return answer-1