def solution(m, n, board):
    answer = 0
    board = [list(s) for s in board]
    while True:
        p = []
        for y in range(m-1):
            for x in range(n-1):
                if board[y][x] == '0':
                    continue
                if board[y][x] == board[y][x+1] and board[y][x] == board[y+1][x] and board[y][x] == board[y+1][x+1]:
                    p.append((x,y))
        if not p:
            break
        while p:
            x,y = p.pop()
            board[y][x] = "0"
            board[y+1][x] = "0"
            board[y][x+1] = "0"
            board[y+1][x+1] = "0"
        for y in range(m-2,-1,-1):
            for x in range(n):
                if board[y][x] == '0':
                    continue
                change_y = y
                while change_y < m-1 and board[change_y+1][x] == '0':
                    change_y+=1
                if change_y != y:
                    board[change_y][x] = board[y][x]
                    board[y][x] = "0"
    for y in range(m):
        for x in range(n):
            if board[y][x] == '0':
                answer+=1
    for i in board:
        print(''.join(i))
    return answer