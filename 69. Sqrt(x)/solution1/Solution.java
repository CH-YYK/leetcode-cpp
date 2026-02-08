class Solution {
  public int mySqrt(int x) {
    // find m where m^2 <= x
    //   -> looking for the lower bound
    //   -> r = m - 1, l = m
    //   -> round m to upper bound to avoid infinite loop.
    long l = 0, r = x;
    while (l < r) {
      long m = (l + r + 1) / 2;
      if (m * m == (long)x)
        return (int)m;
      else if (m * m > (long)x)
        r = m - 1;
      else
        l = m;
    }
    return (int)l;
  }
}
