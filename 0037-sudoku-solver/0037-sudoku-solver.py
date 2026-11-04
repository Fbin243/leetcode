class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        rows = [[False] * 10 for _ in range(9)]
        cols = [[False] * 10 for _ in range(9)]
        boxes = [[False] * 10 for _ in range(9)]
        empties = []

        for r in range(9):
            for c in range(9):
                if board[r][c] != '.':
                    num = int(board[r][c])
                    rows[r][num] = cols[c][num] = boxes[r // 3 * 3 + c // 3][num] = True
                else:
                    empties.append((r, c))

        def backtrack(idx):
            if idx == len(empties):
                return True
            r, c = empties[idx]
            box_idx = r // 3 * 3 + c // 3

            for num in range(1, 10):
                if not rows[r][num] and not cols[c][num] and not boxes[box_idx][num]:

                    board[r][c] = str(num)
                    rows[r][num] = cols[c][num] = boxes[box_idx][num] = True

                    if backtrack(idx + 1):
                        return True

                    board[r][c] = '.'
                    rows[r][num] = cols[c][num] = boxes[box_idx][num] = False
            return False

        backtrack(0)