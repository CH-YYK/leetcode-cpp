import collections
from functools import lru_cache


class Solution:
  """
  (what) one-direction BFS and early pruning.
  
  (why) By symmetry, (x, -y) (x, y) (-x, y) (-x, -y) will result in same results.
        For simplicity, we only consider x > 0 && y > 0.
  
  (how) To reach x > 0 && y > 0, we may only need to consider position a >= -1 && b >= -1
        and a <= x+2 && b <= y+2 while (a, b) represent the current position. So we 
        pruned the loop by disregarding locations outside [-1, x+2] and [-1, y+2]
  """
  def minKnightMoves(self, x: int, y:int) -> int:
    dirs = [(1,2), (2,1), (1,-2), (2,-1), (-1,2), (-2,1)]
    q = collections.deque([(0, 0, 0)])
    x, y, visited = abs(x), abs(y), set([(0, 0)])
    while q:
      a, b, step = q.popleft()
      if (a, b) == (x, y):
        return step
      for dx, dy in dirs:
        if self.isLocValid(a + dx, b + dy, x+2, y+2):
          visited.add((a+dx, b+dy))
          q.append((a+dx, b+dy, step+1))
    return -1
  
  def isLocValid(self, x, y, endx, endy):
    if x < -1 and endx < x:
      return False
    if y < -1 and endy < y:
      return False
    return True

class Solution2:
  """
  (what) DFS with memoization 
  
  (why) By symmetry, (x, -y) (x, y) (-x, y) (-x, -y) will result in same results.
        For simplicity, we only consider x > 0 && y > 0.

  (how) Search for the answer by top-down manner and by symmetry, we only consider 
        a > 0 && b > 0. Given some edge cases, 
        1.  x + y = 1 -> (1, 0), (0, 1) -> 2
        2.  x + y = 0 -> (0, 0)         -> 0
  """
  def minKnightMoves(self, x:int, y:int) -> int:
    @lru_cache(None)
    def dp(x, y):
      if x + y == 0:
        return 0
      elif x + y == 2:
        return 2
      return min(dp(abs(x-1), abs(y-2)), dp(abs(x-2), abs(y-1))) + 1
    return dp(abs(x), abs(y))
      
