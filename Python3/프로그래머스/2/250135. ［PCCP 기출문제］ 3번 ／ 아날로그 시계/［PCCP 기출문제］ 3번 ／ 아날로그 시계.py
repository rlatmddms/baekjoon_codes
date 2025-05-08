def solution(h1, m1, s1, h2, m2, s2):
    answer = 0
    s1 = h1*3600 + m1*60 + s1
    s2 = h2*3600 + m2*60 + s2
    bef_h = (s1%86400)/120
    bef_h = bef_h - bef_h//360 * 360
    bef_m = (s1%86400)/10
    bef_m = bef_m - bef_m//360 * 360
    bef_s = ((s1%86400) * 6) % 360
    if bef_s == bef_m or bef_s == bef_h:
        answer+=1
    for t in range(s1+1,s2+1):
        sv = 6*t % 360
        if sv == 0:
            sv = 360
        hv = t/120
        hv = hv - hv//360 * 360
        mv = t/10
        mv = mv - mv//360 * 360
        if bef_s < bef_h and sv >= hv: 
            print(t,bef_h,bef_m,bef_s,hv,mv,sv)
            answer+=1
        if bef_s < bef_m and sv >= mv and mv != hv: 
            print(t,bef_h,bef_m,bef_s,hv,mv,sv)
            answer+=1
        bef_s = sv % 360
        bef_h = hv
        bef_m = mv
    return answer
#86400