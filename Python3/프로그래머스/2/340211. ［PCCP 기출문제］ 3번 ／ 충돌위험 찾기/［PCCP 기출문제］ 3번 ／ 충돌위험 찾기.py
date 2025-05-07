def solution(points, routes):
    answer = 0
    routes_len = []
    for i,r in enumerate(routes):
        route = []
        start = points[r[0]-1][:]
        route.append(start[:])
        l = 1
        for goal in r:
            
            while start != points[goal-1]:
                if start[0] < points[goal-1][0]:
                    start[0] += 1
                elif start[0] > points[goal-1][0]:
                    start[0] -= 1
                elif start[1] < points[goal-1][1]:
                    start[1] += 1
                elif start[1] > points[goal-1][1]:
                    start[1] -= 1
                route.append(start[:])
                l+=1
        routes[i] = route
        routes_len.append(l)
    max_len = max(routes_len)
    routelen = len(routes)
    # for i in routes:
    #     print(i)
    for i in range(max_len):
        dic = dict()
        for j in range(routelen):
            if i >= routes_len[j]:
                continue
            k = str(routes[j][i])
            if k not in dic:
                dic[k] = 1
            else:
                dic[k] += 1
        for v in dic.values():
            if v >= 2:
                answer+=1
        # print(answer,end=", ")
    return answer