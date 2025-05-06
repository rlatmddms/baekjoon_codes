def solution(wallpaper):
    minx = 51
    miny = 51
    maxx = -1
    maxy = -1
    
    for y,s in enumerate(wallpaper):
        for x,c in enumerate(s):
            if c == "#":
                if minx > x:
                    minx = x
                if miny > y:
                    miny = y
                if maxx < x:
                    maxx = x
                if maxy < y:
                    maxy = y
    
    return [miny,minx,maxy+1,maxx+1]