class Solution(object):
	def findDuplicate(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""

		fast = slow = 0
		while nums[fast] != nums[slow]:
			fast = nums[nums[fast]]
			slow = nums[slow]

		finder = 0
		while nums[finder] != nums[slow]:
			finder = nums[finder]
			slow = nums[slow]

		return finder

def main():
	nums = [1,2,3,4,5,4]
	s = Solution()
	print s.findDuplicate(nums)

if __name__ == '__main__':
	main()