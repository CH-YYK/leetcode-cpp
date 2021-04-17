using namespace std;


/* Use recursion to find all O(logn)
 * pow(x, 2n) = pow(x, n) * pow(x, n)
 * pow(x, 2n+1) = pow(x, n) * pow(x, n) * x
 */
class Solution {
public:
  double myPow(double x, int n) {
    long long N = n;
    if (N < 0) {
      x = 1 / x;
      N = -N;
    }
    return fastpow(x, n);
  }

private:
  double fastpow(double x, long n) {
    if (n == 0)
      return 1.0;
    double half = fastpow(x, n / 2);
    if (n % 2 == 0)
      return half * half;
    else
      return half * x * half;
  }
};
