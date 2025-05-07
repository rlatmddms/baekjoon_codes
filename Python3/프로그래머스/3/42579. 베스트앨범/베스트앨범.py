def solution(genres, plays):
    answer = []
    data = [[idx,g,p] for idx,(g,p) in enumerate(zip(genres,plays))]
    # print(data)
    genre_number = {"numbering" : 0}
    genre_play = []
    for idx,g,p in data:
        if g not in genre_number:
            genre_number[g] = genre_number["numbering"]
            genre_number["numbering"] += 1
            genre_play.append([0])
        genre_play[genre_number[g]][0] += p
        genre_play[genre_number[g]].append([idx,p])
    genre_play.sort(key=lambda x:-x[0])
    genre_play = [i[1:] for i in genre_play]
    print(genre_play)
    for row in genre_play:
        row.sort(key=lambda x:(-x[1],x[0]))
        for cnt,val in enumerate(row):
            if cnt == 2:
                break
            answer.append(val[0])
    return answer