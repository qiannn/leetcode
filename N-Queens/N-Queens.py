class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        queen = [0] * n
        x = y = 0
        col = [True] * n + [False]
        diagonal1 = [True] * n * 2
        diagonal2 = [True] * n * 2
        answer = []
        while True:
            if (col[y] and diagonal1[x + y] and diagonal2[y - x + n]):
                col[y] = diagonal1[x + y] = diagonal2[y - x + n] = False
                queen[x] = y;
                x += 1
                y = 0
                if (x == n):
                    answer.append(['.' * i + 'Q' + '.' * (n - i - 1) for i in queen])
            else:
                if (x == n or y == n):
                    if (x == 0):
                        return answer
                    x -= 1
                    y = queen[x]
                    col[y] = diagonal1[x + y] = diagonal2[y - x + n] = True
                y += 1

def main():
    solution = Solution()
    nqueens = solution.solveNQueens(4)
    for chessboard in nqueens:
        for chessline in chessboard:
            print chessline
        print '\n'

if __name__ == '__main__':
    main()