class Solution(object):
	def sortColors(self, nums):
		"""
		:type nums: List[int]
		:rtype: void Do not return anything, modify nums in-place instead.
		"""
		i, left, right = 0, 0, len(nums) - 1
		while i <= right :
			if nums[i] == 0 :
				nums[left], nums[i] = nums[i], nums[left]
				left += 1
			if nums[i] == 2 :
				nums[right], nums[i] = nums[i], nums[right]
				right -= 1
				continue
			i += 1

def main():
	nums = [0,1,2,1,2,1,1,0]
	s = Solution()
	s.sortColors(nums)
	print nums

if __name__ == '__main__':
	main()