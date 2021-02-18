class Solution:
  def findMinArrowShots(self, points):
    """
    points: [x_start, x_end]
    """
    if len(points) == 0:
      return 0

    points.sort()  # sort by x_start

    res = 1
    inter = points[0]

    for i in range(1, len(points)):
      if points[i][0] <= inter[1]:
        inter[1] = min(points[i][1], inter[1])
        continue
      inter = points[i]
      res += 1
    return res

