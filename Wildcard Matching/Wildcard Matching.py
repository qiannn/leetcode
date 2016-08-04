class Solution(object):
	def isMatch(self, s, p):
		"""
		:type s: str
		:type p: str
		:rtype: bool
		"""
		length = len(s)
		if len(p) - p.count('*') > len(s) : return False
		dp = [True] + [False] * len(s)

		for i in p:
			if i != '*':
				for n in reversed(range(length)):
					dp[n+1] = dp[n] and (i == s[n] or i == '?')
			else:
				for n in range(1, length+1):
					dp[n] = dp[n-1] or dp[n]
			dp[0] = dp[0] and i == '*'
		return dp[-1]

def main():
	solution = Solution()
	print solution.isMatch('aa', 'a')
	print solution.isMatch('aa', 'aa')
	print solution.isMatch('aaa', 'a')
	print solution.isMatch('aa', '*')
	print solution.isMatch('aa', 'a*')
	print solution.isMatch('ab', '?*')
	print solution.isMatch('aab', 'c*a*b')

if __name__ == '__main__':
	main()


