class Solution(object):
	def findDuplicate(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""

		fast, slow = 0, 0

		while True:
			fast = nums[nums[fast]]
			slow = nums[slow]
			if fast == slow:
				break

		finder = 0
		while True:
			finder = nums[finder]
			slow = nums[slow]
			if finder == slow:
				break

		return finder

def main():
	nums = [1,1,3,2,5,4]
	s = Solution()
	print s.findDuplicate(nums)

if __name__ == '__main__':
	main()