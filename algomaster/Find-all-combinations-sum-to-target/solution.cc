#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <queue>
#include <utility>

using namespace std;

int number_of_options(std::vector<int> a, std::vector<int> b, std::vector<int> c, std::vector<int> d, int limit) {
  // WRITE YOUR BRILLIANT CODE HERE
  // Brute force N^4 is trivial, lets break these to several N^2 operations
  vector<int> ab;
  for(int i = 0; i < a.size(); ++i)
    for(int j = 0; j < b.size(); ++j)
      ab.push_back(a[i] + b[j]);
  vector<int> cd;
  for(int i = 0; i < c.size(); ++i)
    for(int j = 0; j < d.size(); ++j)
      cd.push_back(c[i] + d[j]);

  // Find number of pairs (i, j) such that ab[i] + cd[j] <= limit
  // * it can be another N^2 step
  int res = 0;
  for(int i = 0; i < ab.size(); ++i)
    for(int j = 0; j < cd.size(); ++j)
      if(ab[i] + cd[j] <= limit) res++;
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

int main() {
    std::vector<int> a = get_words<int>();
    std::vector<int> b = get_words<int>();
    std::vector<int> c = get_words<int>();
    std::vector<int> d = get_words<int>();
    int limit;
    std::cin >> limit;
    ignore_line();
    int res = number_of_options(a, b, c, d, limit);
    std::cout << res << '\n';
}
