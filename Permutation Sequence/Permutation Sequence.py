class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        s = ''
        factorial = reduce(self.multiple, range(1, n + 1))
        nums = range(1, n + 1)
        for x in xrange(0, n):
            factorial /= (n - x)
            quotient = k / factorial
            remainer = k % factorial
            if remainer != 0:
                quotient += 1
            s += str(nums[quotient - 1])
            nums.pop(quotient - 1)
            k = remainer
        return s

    def multiple(self, x, y):
    	return x * y

def main():
	solution = Solution()
	print solution.getPermutation(1, 1)

if __name__ == '__main__':
	main()