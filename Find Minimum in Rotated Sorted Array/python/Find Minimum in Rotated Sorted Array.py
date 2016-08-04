class Solution(object):
	def findMin(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""

		#print nums
		if nums[0] < nums[-1] or len(nums) == 1:
			return nums[0]
		else:
			mid = (len(nums) - 1) / 2

			if nums[mid] < nums[mid - 1] and nums[mid] < nums[mid + 1]:
				return nums[mid]

			if nums[0] < nums[mid]:
				return self.findMin(nums[mid : ])
			elif nums[0] > nums[mid]:
				return self.findMin(nums[0 : mid + 1])
			else:
				return self.findMin(nums[mid + 1 : ])

def main():
	s = Solution()
	nums = [3,0]
	print s.findMin(nums)

if __name__ == '__main__':
	main()