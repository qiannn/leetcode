class Solution(object):
	def isMatch(self, s, p):
		"""
		:type s: str
		:type p: str
		:rtype: bool
		"""
		if (len(s) == 0 and len(p) == 0) or s == p : return True
		if len(p) == 0 : return False

		dp = [[False for col in xrange(len(p) + 1)] for row in xrange(len(s) + 1)]
		dp[0][0] = True

		for j in xrange(len(p)) :
			if p[j] == '*' and dp[0][j - 1] : dp[0][j + 1] = True
			for i in xrange(len(s)):
				if p[j] == '*':
					if p[j - 1] == '.' and dp[i][j]:
						for tmp in xrange(i, len(s)):
							dp[tmp + 1][j + 1] = True		
					if dp[i + 1][j - 1] : dp[i + 1][j + 1] = True
					elif dp[i + 1][j] : dp[i + 1][j + 1] = True
					elif dp[i][j] and (p[j - 1] == s[i] or p[j - 1] == '.') : dp[i + 1][j + 1] = True
				else:
					if (p[j] == s[i] or p[j]  == '.') and dp[i][j]:
						dp[i + 1][j + 1] = True
		
		return dp[len(s)][len(p)]

def main():
	solution = Solution()
	print solution.isMatch('aa', 'a')
	print solution.isMatch('aa', 'aa')
	print solution.isMatch('aaa', 'aa')
	print solution.isMatch('aa', 'a*')
	print solution.isMatch('aa', '.*')
	print solution.isMatch('ab', '.*')
	print solution.isMatch('aab', 'c*a*b')
	print solution.isMatch('ab', '.*..')
	print solution.isMatch('', '.*')
	print solution.isMatch('a', '.*..a*')
	print solution.isMatch('aab', 'b.*')


if __name__ == '__main__':
	main()