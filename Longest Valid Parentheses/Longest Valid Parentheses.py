class Solution(object):
	def longestValidParentheses(self, s):
		"""
		:type s: str
		:rtype: int
		"""
		maxlen = 0
		dp = [0] * len(s)
		for i in xrange(1, len(dp)):
			if s[i] == ')':
				if dp[i - 1] == '(':
					dp[i] = 2
					if i > 1:
						dp[i] += dp[i - 2]
				else: 
					index = i - dp[i - 1] - 1
					if index >= 0 and s[index] == '(':
						dp[i] = dp[i - 1] + 2
						if index > 0:
							dp[i] += dp[index - 1]
			maxlen = max(dp[i], maxlen) 

		return maxlen

def main():
	str = "))(())(())((())))()((())()(()))())(((())))((())((((()()))()()((()())(()))))((((()()((())())())()))()))))(()))))()((())))())((()()))))(()))((((()(()))))(((((()("
	s = Solution()
	print s.longestValidParentheses(str)

if __name__ == '__main__':
	main()
		