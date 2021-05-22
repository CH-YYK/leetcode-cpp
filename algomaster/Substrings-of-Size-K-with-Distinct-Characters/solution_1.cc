#include <algorithm> // copy
#include <iostream>  // cin, cout, streamsize
#include <iterator>  // ostream_iterator, prev
#include <limits>    // numeric_limits
#include <string>    // getline, string
#include <vector>    // vector
#include <unordered_map>
#include <unordered_set>

using namespace std;

std::vector<std::string> substrings(std::string s, int k) {
  unordered_set<string> res;
  vector<string> ans;
  // sliding window find all substrings with K distinct characters
  unordered_map<char, int> window;
  int l = 0;
  for(int r = 0; r < s.size(); ++r) {
    window[s[r]]++;
    while(r - l + 1 > k) {
      if(--window[s[l]] == 0) window.erase(s[l]);
      l++;
    }
    if(window.size() == k && r - l + 1 == k) {
      string str = s.substr(l, k);
      if(res.count(str)) continue;
      ans.push_back(str);
      res.insert(str);
    }
  }
  return ans;
}

void ignore_line() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T> void put_words(const std::vector<T> &v) {
  if (!v.empty()) {
    std::copy(v.begin(), std::prev(v.end()),
              std::ostream_iterator<T>{std::cout, " "});
    std::cout << v.back();
  }
  std::cout << '\n';
}

int main() {
  std::string s;
  std::getline(std::cin, s);
  int k;
  std::cin >> k;
  ignore_line();
  std::vector<std::string> res = substrings(s, k);
  put_words(res);
}
