class Solution {
public:
  int mySqrt(int x) {
    // compute sqrt(x) -> a^2 < x
    // 1,2,3,4..x-1.
    if(x == 0) return x;

    int l = 1, r = x, mid, sqrt;
    while(l <= r) {
      int m = l + (r - l) / 2;
      sqrt = x / m;
      if(sqrt == m)
        return m;
      else if(m > sqrt)
        r = m - 1;
      else
        l = m + 1;
    }
    // l > r
    return r;
  }
};
