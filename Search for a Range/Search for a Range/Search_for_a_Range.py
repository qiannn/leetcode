class Solution(object):
	def searchRange(self, nums, target):
		"""
		:type nums: List[int]
		:type target: int
		:rtype: List[int]
		"""
		rightflag = len(nums) - 1
		leftflag = 0
		while leftflag <= rightflag:
			mid = (leftflag + rightflag)/2
			if nums[mid] == target:
				return self.Range(nums, target, mid)
			elif nums[mid] > target:
				rightflag = mid - 1
			else:leftflag = mid + 1
		return [-1, -1]

	def Range(self, nums, target, index):
		left = index
		right = index
		while left > 0:
			if (nums[left - 1] == target):left -= 1
			else:break
		while right < len(nums) - 1:
			if (nums[right + 1] == target):right += 1
			else:break
		return [left, right]

def main():
	solution = Solution()
	nums = [5, 7, 7, 8, 8, 10]
	print solution.searchRange(nums, 8)

if __name__ == '__main__':
	main()