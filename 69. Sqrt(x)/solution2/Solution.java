class Solution {
  public int mySqrt(int x) {
    // In other words, looking for m where m^2 <= x -> m <= x/m
    // -> lower bound
    int l = 0, r = x;
    while (l < r) {
      int m = (l + r + 1) / 2;

      if (m == x / m)
        return m;
      else if (m > x / m)
        r = m - 1;
      else
        l = m;
    }
    return l;
  }
}