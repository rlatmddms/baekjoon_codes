def solution(str1, str2):
    str1 = str1.upper(); str2 = str2.upper()
    s1 = [str1[i-1:i+1] for i in range(1,len(str1)) if 'A' <= str1[i] <= 'Z' and 'A' <= str1[i-1] <= 'Z']
    s2 = [str2[i-1:i+1] for i in range(1,len(str2)) if 'A' <= str2[i] <= 'Z' and 'A' <= str2[i-1] <= 'Z']
    # print(s1,s2)
    uset = []
    s1dict = {}
    s2dict = {}
    for i in s1:
        if i in s1dict:
            s1dict[i] += 1
        else:
            s1dict[i] = 1
    for i in s2:
        if i in s2dict:
            s2dict[i] += 1
        else:
            s2dict[i] = 1
    for key1 in s1dict.keys():
        for key2 in s2dict.keys():
            if key1 == key2:
                for i in range(min(s1dict[key1], s2dict[key2])):
                    uset.append(key1)
                    
    # print(uset)
    if not s1 and not s2:
        return 65536
    ans = int(len(uset) * 65536 / (len(s1)+len(s2)-len(uset)))
    return ans