class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        i = 0
        for x in xrange(1, size):
        	if nums[size - x] > nums[size - x - 1]:
        		i = size - x - 1
        		break
        k = 0
        for x in xrange(i + 1, size):
        	if (nums[x] > nums[i]) : k = x

        if k == 0 and i == 0 :
        	nums.reverse()
        else :
        	nums[i], nums[k] = nums[k], nums[i]
        	while i + 1< size - 1:
        		nums[i + 1], nums[size - 1] = nums[size - 1], nums[i + 1]
        		i += 1
        		size -= 1
        print nums

def main():
	solution = Solution();
	solution.nextPermutation([1,3,2])

if __name__ == '__main__':
	main()