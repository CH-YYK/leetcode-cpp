#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

using namespace std;

std::vector<std::vector<int>> get_pairs(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b, int target) {
  vector<vector<int>> A;
  vector<vector<int>> B;
  for(auto& p : a)
    A.push_back({p[1], p[0]});
  for(auto& p : b)
    B.push_back({p[1], p[0]});
  sort(B.begin(), B.end());

  vector<vector<int>> res;
  int target_sum = 1e9;

  for(auto& p : A) {
    auto it_l = lower_bound(B.begin(), B.end(), vector<int>{target - p[0], 0}); // >= target - numA
    auto it_h = upper_bound(B.begin(), B.end(), vector<int>{target - p[0], 10000000});  // > target - numA

    if(it_h != B.end()) it_h = next(it_h);
    if(it_l != B.begin()) it_l = prev(it_l);
    for(auto it = it_l; it != it_h; ++it) {
      int sum_ = (*it)[0] + p[0];
      if(sum_ > target) break;
      vector<int> ids = { p[1], (*it)[1] };
      if (abs(sum_ - target) < abs(target_sum - target))
        target_sum = sum_, res = {ids};
      else if (abs(sum_ - target) == abs(target_sum - target))
        res.push_back(ids);
    }
  }
  return res;
}

template<typename T>
std::vector<T> get_words() {
  std::string line;
  std::getline(std::cin, line);
  std::istringstream ss{line};
  std::vector<T> v;
  std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
  return v;
}

void ignore_line() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template<typename T>
void put_words(const std::vector<T>& v) {
  if (!v.empty()) {
    std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
    std::cout << v.back();
  }
  std::cout << '\n';
}

int main() {
  int a_length;
  std::cin >> a_length;
  ignore_line();
  std::vector<std::vector<int>> a;
  for (int i = 0; i < a_length; i++) {
    a.emplace_back(get_words<int>());
  }
  int b_length;
  std::cin >> b_length;
  ignore_line();
  std::vector<std::vector<int>> b;
  for (int i = 0; i < b_length; i++) {
    b.emplace_back(get_words<int>());
  }
  int target;
  std::cin >> target;
  ignore_line();
  std::vector<std::vector<int>> res = get_pairs(a, b, target);
  for (const std::vector<int>& row : res) {
    put_words(row);
  }
}
