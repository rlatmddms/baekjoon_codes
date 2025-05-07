def solution(land):
    xlimit = len(land[0])
    ylimit = len(land)
    oils = [0,0]
    idx = 1
    dx = [0,0,-1,1]
    dy = [1,-1,0,0]
    for x in range(xlimit):
        for y in range(ylimit):
            if land[y][x] != 1:
                continue
            q = [(x,y)]
            oils.append(0)
            idx+=1
            land[y][x] = idx
            while q:
                nx,ny = q.pop()
                oils[idx]+=1
                for i in range(4):
                    ax = nx+dx[i]
                    ay = ny+dy[i]
                    if ax < 0 or ay < 0 or ax == xlimit or ay == ylimit:
                        continue
                    if land[ay][ax] == 1:
                        q.append((ax,ay))
                        land[ay][ax] = idx
    # print(oils)
    # for i in land:
    #     print(i)
    mxsum = 0
    for x in range(xlimit):
        s = set()
        for y in range(ylimit):
            if land[y][x] != 0:
                s.add(land[y][x])
        s = sum(map(lambda x : oils[x], list(s)))
        if s > mxsum:
            mxsum = s
    return mxsum