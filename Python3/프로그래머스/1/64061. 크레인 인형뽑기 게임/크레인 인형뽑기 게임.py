def solution(board, moves):
    cnt = 0
    board.append([-1]*len(board[0]))
    stack = []
    stack_size = 0
    for m in moves:
        m -= 1
        i = 0
        while board[i][m] == 0:
            i+=1
        if board[i][m] == -1:
            continue
        stack_size += 1
        stack.append(board[i][m])
        board[i][m] = 0
        while stack_size > 1 and stack[-1] == stack[-2]:
            stack.pop()
            stack.pop()
            stack_size -= 2
            cnt+=2
    return cnt