class Solution(object):
	def totalNQueens(self, n):
		"""
		:type n: int
		:rtype: int
		"""
		queen = [0] * n
		x = y = 0
		col = [True] * n + [False]
		diagonal1 = [True] * n * 2
		diagonal2 = [True] * n * 2
		answer = 0
		while True:
			if (col[y] and diagonal1[x + y] and diagonal2[y - x + n]):
				col[y] = diagonal1[x + y] = diagonal2[y - x + n] = False
				queen[x] = y;
				x += 1
				y = 0
				if (x == n):
					answer += 1
			else:
				if (x == n or y == n):
					if (x == 0):
						return answer
					x -= 1
					y = queen[x]
					col[y] = diagonal1[x + y] = diagonal2[y - x + n] = True
				y += 1
		return answer

def main():
	s = Solution()
	print s.totalNQueens(8)

if __name__ == '__main__':
	main()