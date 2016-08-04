# -*- coding: utf-8 -*-
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle == haystack or len(needle) == 0: 
        	return 0
        elif len(haystack) == 0 :
        	return -1
        return haystack.find(needle)
        #return self.KMP(haystack, needle)
        
    def KMP(self, pattern, substr):
        p, q = 0, 0
        index = -1
        Next = self.GetNext(substr)
        while p < len(pattern) :
        	if (substr[q] == pattern[p]):
        		q += 1
        		p += 1
        	elif q == 0:
        		p += 1
        	else :
        		q = Next[q]

        	if (q == len(substr)) : 
        		index = p - len(substr)
        		return index
        return index

    def GetNext(self, substr):
    	Next = [0] * len(substr)
    	#Next[0] = -1
    	for x in xrange(1,len(substr)):
    		flag = Next[x - 1]
    		if flag != x - 1 and substr[flag] == substr[x - 1]:
    			Next[x] = flag + 1
    		else :
    			Next[x] = 0
    	return Next

def main():
	pattern = 'mississippi'
	substr = 'issip'
	solution = Solution()
	print solution.strStr(pattern, substr)

if __name__ == '__main__':
	main()