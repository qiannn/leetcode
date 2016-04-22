class Solution(object):
	def isValidSudoku(self, board):
		"""
		:type board: List[List[str]]
		:rtype: bool
		"""
		col = [set() for x in range(9)]
		row = [set() for x in range(9)]
		grid = [set() for x in range(9)]
		for i in range(9):
			for j in range(9):
				if board[i][j] == '.':
					continue
				if board[i][j] in col[j]: 
					print board[i][j]
					return False
				if board[i][j] in row[i]: 
					return False

				g = i / 3 * 3 + j / 3
				if board[i][j] in grid[g]: return False

				col[j].add(board[i][j])
				row[i].add(board[i][j])
				grid[g].add(board[i][j])

		return True;


def main():
	solution = Solution()
	board = ["..5.....6","....14...",".........",".....92..","5....2...",".......3.","...54....","3.....42.","...27.6.."]
	print solution.isValidSudoku(board)

if __name__ == '__main__':
	main()