class Solution(object):
    def __init__(self):
        self.stack = []
        self.tmpboard = []
        self.col = [set() for i in range(9)]
        self.row = [set() for i in range(9)]
        self.grid = [set() for i in range(9)]
#        for line in board:
#           tmpboard.append(list(line))
 
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    self.col[j].add(int(board[i][j]))
                    self.row[i].add(int(board[i][j]))
                    self.grid[i / 3 * 3 + j / 3].add(int(board[i][j]))

        self.helper(0, 0, board)

    def helper(self, i, j, board):
        if i == 9:
            return True

        nexti = nextj = 0
        if j == 8:
            nexti, nextj = i + 1, 0
        else:
            nexti, nextj = i, j + 1

        if board[i][j] != '.':
            return self.helper(nexti, nextj, board)
            
        gridindex = i / 3 * 3 + j / 3
        for value in range(1, 10):
            if value not in self.col[j] and value not in self.row[i] and value not in self.grid[gridindex]:
                board[i] = board[i][:j] + str(value) + board[i][j + 1:]
                self.col[j].add(value)
                self.row[i].add(value)
                self.grid[gridindex].add(value)
                if self.helper(nexti, nextj, board):
                    return True
                else:
                    board[i] = board[i][:j] + '.' + board[i][j + 1:]
                    self.col[j].remove(value)
                    self.row[i].remove(value)
                    self.grid[gridindex].remove(value)

        return False

def main():
    s = Solution()
    board = ["..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."]
    print board
    s.solveSudoku(board)
    print board

if __name__ == '__main__':
    main()
            
