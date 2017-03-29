class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        if len(intervals) == 0:
            intervals.append(newInterval)
            return intervals
        flag = False
        for i in range(len(intervals)):
            if (intervals[i].start > newInterval.start):
                intervals.insert(i, newInterval)
                flag = True
                break

        if flag == False:
            intervals.append(newInterval)
        rlist = []
        for interval in intervals:
            if len(rlist) == 0:
                rlist.append(interval)
            else:
                mergeInterval = self.merge2Interval(rlist[-1], interval)
                if mergeInterval == False:
                    rlist.append(interval)
        return rlist

    def merge2Interval(self, interval1, interval2):
        if interval1.end >= interval2.start:
            interval1.start, interval1.end = min(interval1.start, interval2.start), max(interval1.end, interval2.end)
            return True
        else:
            return False

def main():
    #print 'hello world'
    collection = [[1,5]]
    intervals = [Interval(pair[0], pair[1]) for pair in collection]
    s = Solution()
    rlist = s.insert(intervals, Interval(2,7))
    for interval in rlist:
        print ("[%d, %d]" % (interval.start, interval.end))

if __name__ == '__main__':
    main();
