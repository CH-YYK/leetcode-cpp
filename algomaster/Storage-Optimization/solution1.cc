#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

using namespace std;

int maxnum(vector<int>& vec) {
  // get longest subarray s.t vec[i] - vec[i-1] == 1
  int l = 0, len = 0;
  for(int r = 0; r <= vec.size(); ++r) {
    if(r == vec.size() || r > 0 && vec[r] - vec[r-1] > 1) {
      if(r - l > len) len = r - l;
      l = r;
    }
  }
  return len;
}

int storage_optimization(int n, int m, std::vector<int> h, std::vector<int> v) {
  // get the maximum length of consecutive numbers in h, say y, -> max vertical gap y+1
  // get the maximum length of consecutive numbers in v, say x, -> max horizontal gap x+1
  // return (x + 1) * (y + 1)
  sort(h.begin(), h.end());
  sort(v.begin(), v.end());
  return (maxnum(h) + 1) * (maxnum(v) + 1);
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    int m;
    std::cin >> m;
    ignore_line();
    std::vector<int> h = get_words<int>();
    std::vector<int> v = get_words<int>();
    int res = storage_optimization(n, m, h, v);
    std::cout << res << '\n';
}
