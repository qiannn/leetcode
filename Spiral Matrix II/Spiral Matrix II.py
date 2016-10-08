class Solution(object):
	def generateMatrix(self, n):
		"""
		:type n: int
		:rtype: List[List[int]]
		"""
		if n == 0:
			return [[]]
		#spirallist = range(1, n ** 2 + 1)
		matrix = [[0 for col in range(n)] for row in range(n)]
		startlevel = 0
		num = 1
		while num <= n ** 2:
			x1, y1 = startlevel, startlevel
			x2, y2 = x1, n - 1 - y1
			x3, y3 = n - 1 - x1, y2
			x4, y4 = x3, y1
			for i in range(y1, y2 + 1):
				matrix[x1][i] = num
				num += 1
			for i in range(x1 + 1, x3 + 1):
				matrix[i][y2] = num
				num += 1

			if num > n ** 2:
				return matrix

			for i in range(y3 - 1, y4 - 1, -1):
				matrix[x3][i] = num
				num += 1
			for i in range(x4 - 1, x1, -1):
				matrix[i][y4] = num
				num += 1
			startlevel += 1
		return matrix

def main():
	s = Solution()
	print s.generateMatrix(2)

if __name__ == '__main__':
	main()