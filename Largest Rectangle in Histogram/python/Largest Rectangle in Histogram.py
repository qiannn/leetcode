class Solution(object):
	def largestRectangleArea(self, heights):
		"""
		:type heights: List[int]
		:rtype: int
		"""
		stack = []
		maxArea = 0
		heights.append(0);
		x = 0
		while x < len(heights):
			if (stack and (heights[stack[-1]] > heights[x])):
				index = stack[-1]
				stack.pop()
				area = 0
				if stack:
					area = heights[index] * (x - stack[-1] - 1)
				else:
					area = heights[index] * x
				maxArea = max(area, maxArea)
			else:
				stack.append(x)
				x += 1

		return maxArea

def main():
	s = Solution()
	heights = [2,1,5,6,2,3]
	print s.largestRectangleArea(heights)

if __name__ == '__main__':
	main()