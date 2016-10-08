class Solution(object):
	def spiralOrder(self, matrix):
		"""
		:type matrix: List[List[int]]
		:rtype: List[int]
		"""
		if len(matrix) == 0:
			return []
		m, n = len(matrix), len(matrix[0])
		spirallist = []
		startlevel = 0
		count = 0
		while count < m * n:
			x1, y1 = startlevel, startlevel
			x2, y2 = x1, n - 1 - y1
			x3, y3 = m - 1 - x1, y2
			x4, y4 = x3, y1
			for i in range(y1, y2 + 1):
				spirallist.append(matrix[x1][i])
				count += 1
			for i in range(x1 + 1, x3 + 1):
				spirallist.append(matrix[i][y2])
				count += 1

			if count == m * n:
				return spirallist

			for i in range(y3 - 1, y4 - 1, -1):
				spirallist.append(matrix[x3][i])
				count += 1
			for i in range(x4 - 1, x1, -1):
				spirallist.append(matrix[i][y4])
				count += 1
			startlevel += 1
		return spirallist

def main():
	s = Solution()
	print s.spiralOrder(
		[
 			[ 1, 2, 3 ],
 			[ 4, 5, 6 ],
 			[ 7, 8, 9 ]
		])
	print s.spiralOrder(
		[[2, 3]])

if __name__ == '__main__':
	main()