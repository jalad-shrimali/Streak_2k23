class Solution(object):
    def snakesAndLadders(self, board):
        length = len(board)
        # reverse the board, so our code is more straight forward
        board.reverse()
        # help func
        def intToPos(square):
            # minus 1, since idx usually start from 0
            r = (square - 1) // length
            c = (square - 1) % length
            # special handling for odd row
            if r % 2 == 1:
                c = length - 1 - c
            return [r, c]
        q = deque()
        q.append([1,0]) # [square, moves]
        visited = set()
        while q:
            square, moves = q.popleft()
            # simulate dice throw
            for i in range(1, 7):
                nextSquare = square + i
                r, c = intToPos(nextSquare)
                # if no short cut (ladder)
                if board[r][c] != -1:
                    nextSquare = board[r][c]
                # if meet the end point
                if nextSquare == length * length:
                    return moves + 1
                # if meet short cut (ladder) and not visited yet
                if  nextSquare not in visited:
                    visited.add(nextSquare)
                    q.append([nextSquare, moves+1])
        return -1
