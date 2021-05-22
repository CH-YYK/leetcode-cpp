#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

using namespace std;
// greedy thinking, we want numbers in A as less as possible and we want sum(A) > sum(B)
// We keep adding larger number to A until sum(A) > S - sum(A)
// O(NlogN + N), O(1)
std::vector<int> optimizing_box_weights(std::vector<int> arr) {
  int sum = 0;
  for(int& num : arr)
    sum += num;
  sort(arr.begin(), arr.end(), greater<int>());

  vector<int> res;
  int sumA = 0;

  for(int& num : arr) {
    res.push_back(num), sumA += num;
    if(sumA > sum - sumA) break;
  }
  reverse(res.begin(), res.end());
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> arr = get_words<int>();
    std::vector<int> res = optimizing_box_weights(arr);
    put_words(res);
}
