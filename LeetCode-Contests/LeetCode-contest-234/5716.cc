class Solution {
public:
  int maxNiceDivisors(int primeFactors) {
    unsigned long long m = 0;
    return decode(primeFactors, 3);
  }

private:
  vector<vector<int>> memo;
  unsigned long long decode(int num, int n) {
    if (num == 0)
      return 1;
    if(memo[num][n] >= 0) return memo[num][n];
    return memo[num][n] = decode(num - num / n, n - 1) * (num / n);
  }
};
