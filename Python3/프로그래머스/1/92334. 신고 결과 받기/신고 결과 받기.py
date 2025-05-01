def solution(id_list, report, k):
    answer = []
    name_idx = {}
    id_len = len(id_list)
    for idx,name in enumerate(id_list):
        name_idx[name] = idx
    report_log = [[0]*id_len for _ in range(id_len)]
    for s in report:
        a,b = s.split()
        report_log[name_idx[a]][name_idx[b]] = 1
    is_banned = set()
    for i in range(id_len):
        s = 0
        for j in range(id_len):
            s += report_log[j][i]
        if s >= k:
            is_banned.add(i)
    for i in range(id_len):
        s = 0
        for j in range(id_len):
            if report_log[i][j] == 1 and j in is_banned:
                s+=1
        answer.append(s)
    return answer