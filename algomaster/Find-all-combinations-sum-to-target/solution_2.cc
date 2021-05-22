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
  int res = 0;
  unordered_map<int, int> m;
  for(int a1 = )
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
