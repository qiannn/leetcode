# -*- coding: utf-8 -*-
class Solution(object):
	def reverseWords(self, s):
		"""
		:type s: str
		:rtype: str
		"""
		s = s.strip()
		stack = ['']
		word = ''
		for i in range(0, len(s)):
			if s[i] == ' ':
				if s[i-1] != s[i]:
					stack.append(word)
					stack.append(s[i])
					word = ''
			else :
				word += s[i]
		stack.append(word)

		reversestr = ''
		for i in reversed(stack):
			reversestr += i

		return reversestr


def main():
	solution = Solution()

	print solution.reverseWords("   a   b  c d   e  ")

if __name__ == '__main__':
	main()