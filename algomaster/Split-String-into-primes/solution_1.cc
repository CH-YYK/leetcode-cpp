#include <iostream> // cin, cout
#include <string>   // getline, string
#include <vector>

using namespace std;

void get_primes(vector<int>& vec) { // vec(1001)
  for(int i = 4; i <= 1000; i += 2)
    vec[i] = 0;
  for(int i = 3; i <= 1000; i += 2) {
    if(vec[i] == 0) continue;
    for(int j = 2 * i; j <= 1000; j += i)
      vec[j] = 0;
  }
}

int split_primes(std::string input_str) {
  vector<int> vec(1001, 1);
  vec[0] = 0;
  vec[1] = 0;
  get_primes(vec);
  // dp[i]: number of ways we can divide input_str[:i] into primes (right exclusive)
  // dp[i] = dp[i-1] if vec[s[i]] + dp[i-2] if vec[s[i-1:i]] + dp[i-3] if vec[s[i-2:i]]
  int n = input_str.size();
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  int num = 0;
  for(int i = 1; i <= n; ++i) {
    num = 10 * num + (input_str[i-1] - '0');
    num %= 1000;
    int numcpy = num;
    if(i > 2 && vec[numcpy] && numcpy > 100) dp[i] += dp[i-3];
    numcpy %= 100;
    if(i > 1 && vec[numcpy] && numcpy > 10) dp[i] += dp[i-2];
    numcpy %= 10;
    if(i > 0 && vec[numcpy] && numcpy > 0) dp[i] += dp[i-1];
  }
  return dp[n];
}

int main() {
  std::string input_str;
  std::getline(std::cin, input_str);
  int res = split_primes(input_str);
  std::cout << res << '\n';
}
