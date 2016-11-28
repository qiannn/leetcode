class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        result = []
        strlen = len(s)
        wordlen = len(words[0])
        sublen = len(words)

        words.sort()

        if strlen == 0:
            return result
            
        for i in range(0, wordlen):
            k = 0
            startindex = i
            endindex = i + wordlen
            index = startindex
            while startindex <= strlen - wordlen * sublen:
                if k == sublen:
                    substrlist = [s[i:i + wordlen] for i in range(startindex, endindex - wordlen, wordlen)]
                    substrlist.sort()
                    #print substrlist
                    if cmp(substrlist, words) == 0:
                        result.append(startindex)
                    startindex += wordlen
                    k -= 1
                substr = s[index : endindex]
                if substr in words:
                    k += 1
                    index = endindex
                    endindex += wordlen
                else:
                    startindex = endindex
                    index = startindex
                    endindex += wordlen
                    k = 0
        return result

def main():
    s = Solution()
    string = "wordgoodgoodgoodbestword"
    words = ["word","good","best","good"]
    print s.findSubstring(string, words)

if __name__ == '__main__':
    main()
