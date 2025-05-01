def solution(triangle):
    answer = 0
    l = len(triangle)
    for i in range(l-2,-1,-1):
        for j in range(i+1):
            # print(triangle[i][j])
            triangle[i][j] = triangle[i][j] + max(triangle[i+1][j], triangle[i+1][j+1])
    return triangle[0][0]