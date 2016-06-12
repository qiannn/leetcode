class Solution(object):
	def search(self, nums, target):
		"""
		:type nums: List[int]
		:type target: int
		:rtype: int
		"""
		left, right = 0, len(nums) - 1
		return self.helper(left, right, nums, target)

	def helper(self, left, right, nums, target):
		if left > right or nums is False:
			return -1

		mid = (right + left) / 2
		if nums[mid] == target:
			return mid	

		if nums[mid] >= nums[left]:
			if target < nums[mid] and target >= nums[left]:
				return self.helper(left, mid - 1, nums, target)
			else:
				return self.helper(mid + 1, right, nums, target)
		else:
			if target <= nums[right] and target > nums[mid]:
				return self.helper(mid + 1, right, nums, target)
			else:
				return self.helper(left, mid - 1, nums, target)
		return -1

def main():
	nums = [3,1,1,1,1]
	s = Solution()
	print s.search(nums, 3)

if __name__ == '__main__':
	main()