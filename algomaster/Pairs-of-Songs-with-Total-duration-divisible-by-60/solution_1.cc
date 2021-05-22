#include <algorithm> // copy
#include <iostream>  // cin, cout
#include <iterator>  // back_inserter, istream_iterator
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <unordered_map>
#include <vector> // vector

using namespace std;

int num_pairs_divisible_by_60(std::vector<int> times) {
  // if a + b % 60 == 0 -> a mod 60 + b mode 60 = 60
  for (int &num : times)
    num %= 60;
  unordered_map<int, int> m;
  int res = 0;
  for (int num : times) {
    if (num == 0)
      res += m[num];
    else
      res += m[60 - num];
    m[num]++;
  }
  return res;
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

int main() {
  std::vector<int> times = get_words<int>();
  int res = num_pairs_divisible_by_60(times);
  std::cout << res << '\n';
}
