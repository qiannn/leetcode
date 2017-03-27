# Definition for an interval.
class Interval(object):
    def __init__(self, s = 0, e = 0):
        self.start = s
        self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """

        intervals.sort(key=lambda x:x.start)
        rlist = []
        for interval in intervals:
            if len(rlist) == 0:
                rlist.append(interval)
            else:
                newInterval = self.merge2Interval(rlist[-1], interval)
                if newInterval == False:
                   rlist.append(interval)
        return rlist

    def merge2Interval(self, interval1, interval2):
        if (interval1.end >= interval2.start):
            interval1.start, interval1.end = min(interval1.start, interval2.start), max(interval1.end, interval2.end)
            return True
        else:
            return False

def main():
    #collection = [[2,3],[5,5],[2,2],[3,4],[3,4]]
    collection = [[1,3],[2,6],[8,10],[15,18]]
    #collection = [[1,4],[1,4]]
    intervals = [Interval(pair[0], pair[1]) for pair in collection]
    s = Solution()
    rlist = s.merge(intervals)
    for interval in rlist:
        print interval.start
        print interval.end

if __name__ == '__main__':
    main()


