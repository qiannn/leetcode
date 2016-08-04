class Solution(object):
	def combinationSum(self, candidates, target):
		"""
		:type candidates: List[int]
		:type target: int
		:rtype: List[List[int]]
		"""
		candidates.sort()
		Solution.ret = []
		self.helper(candidates, target, 0, [])
		return Solution.ret

	def helper(self, candidates, target, start, combinations):
		length = len(candidates)

		if target == 0:
			Solution.ret.append(combinations)
			return
		for i in xrange(start, length):			
			if candidates[i] > target:
				return
			self.helper(candidates, target - candidates[i], i, combinations + [candidates[i]])


def main():
	s = Solution()
	candidates = [49,21,42,38,44,24,35,27,20,41,23,29,31,47,28,22,48,25,33,32,26,46,40,36,45]

	print s.combinationSum(candidates, 69)

if __name__ == '__main__':
	main()