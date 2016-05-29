class Solution(object):
	def search(self, nums, target):
		"""
		:type nums: List[int]
		:type target: int
		:rtype: bool
		"""
		return self.helper(0, len(nums) - 1, nums, target)

	def helper(self, left, right, nums, target):
		if left > right or nums is False:
			return False

		mid = (right + left) / 2
		if nums[mid] == target:
			return True	

		if nums[mid] > nums[left]:
			if target < nums[mid] and target >= nums[left]:
				return self.helper(left, mid - 1, nums, target)
			else:
				return self.helper(mid + 1, right, nums, target)
		elif nums[mid] < nums[left]:
			if target <= nums[right] and target > nums[mid]:
				return self.helper(mid + 1, right, nums, target)
			else:
				return self.helper(left, mid - 1, nums, target)
		else:
			return self.helper(left + 1, right, nums, target)
		return False

def main():
	nums = [1,3,1,1,1]
	s = Solution()
	print s.search(nums, 3)

if __name__ == '__main__':
	main()