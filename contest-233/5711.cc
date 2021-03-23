class Solution {
public:
  // hit and trial: always binary search
  int maxValue(int n, int index, int maxSum) {
    int l = 1, r = maxSum, m, ret = 0;
    while (l <= r) {
      m = (l + r) / 2;
      long tmp = getsum(index, n, m);
      if (tmp > maxSum) {
        r = m - 1;
      } else {
        ret = max(ret, m);
        l = m + 1;
      }
    }
    return ret;
  }

private:
  long getsum(int i, int n, int m) {
    int cnt_l = i, cnt_r = n - i - 1;
    long l_val =
        m * (m - 1) / 2 - max(0l, m - cnt_l - 1) * max(0l, m - cnt_l) / 2;
    long r_val =
        m * (m - 1) / 2 - max(0l, m - cnt_r - 1) * max(0l, m - cnt_r) / 2;
    return l_val + r_val;
  }
};
