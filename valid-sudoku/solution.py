from typing import List
from collections import Counter
import itertools

class Solution:
    def eval_counter(self, c):
        #print(set(c))
        #print([len(set(x)) != len(x) for x in c])
        return [len(set(z)) != len(z) for z in c]

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        if any(self.eval_counter([[y for y in x if y != '.'] for x in board])):
            return False
        if any(self.eval_counter([[y for y in x if y != '.'] for x in zip(*board)])):
            return False
        squares = []
        for x in range(0,9,3):
            rows = board[x:x+3]
            for y in range(0,9,3):
                squares.append(list(itertools.chain.from_iterable([i[y:y+3] for i in rows])))
        if any(self.eval_counter([[y for y in x if y != '.'] for x in squares])):
            return False
        return True
    
Solution().isValidSudoku([["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]])
Solution().isValidSudoku([["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]])

lol = {"hello": "gdbye"}

any([x > 1 for x in Counter(["5","3",".",".","7",".",".",".","."]).values()])

zip([["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]])