#include <algorithm> // copy
#include <iostream>  // cin, cout, streamsize
#include <iterator>  // back_inserter, istream_iterator
#include <limits>    // numeric_limits
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector

using namespace std;

vector<vector<int>> memo;

/* Minimum sum diffculty
 */
int dfs(vector<int>& jobs, int i, int d) {
  if(d == 1) return *max_element(jobs.begin() + i, jobs.end());
  int res = 1e9;
  int cummax = 0;
  if(memo[i][d] >= 0) return memo[i][d];
  for(int j = i; j < jobs.size() - 1; ++j) {
    cummax = max(cummax, jobs[j]);
    res = min(res, cummax + dfs(jobs, j + 1, d - 1));
  }
  return memo[i][d] = res;
}

int min_difficulty(std::vector<int> job_difficulty, int d) {
  int n = job_difficulty.size();
  if(n < d) return -1;
  memo = vector<vector<int>> (n, vector<int>(d + 1, -1));
  return dfs(job_difficulty, 0, d);
}

template <typename T> std::vector<T> get_words() {
  std::string line;
  std::getline(std::cin, line);
  std::istringstream ss{line};
  std::vector<T> v;
  std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{},
            std::back_inserter(v));
  return v;
}

void ignore_line() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
  std::vector<int> job_difficulty = get_words<int>();
  int d;
  std::cin >> d;
  ignore_line();
  int res = min_difficulty(job_difficulty, d);
  std::cout << res << '\n';
}
