#include <algorithm> // copy
#include <iostream>  // cin, cout
#include <iterator>  // back_inserter, istream_iterator
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector

using namespace std;

// merge {4,5} and {1,2},
/* 1. pick 1, (4,1)(5,4) -> {1,4,5,2}
 * 2. pick 2, (4,2)(5,4) -> {1,2,4,5}
 4 intotal-> pick num in arr2 , res += # of rest values in arr1
 */

int merge_sort(vector<int> &nums, int l, int r) {
  if(l >= r) return 0;
  int k = (l + r) / 2;
    int res = 0;
  res += merge_sort(nums, l, k);
  res += merge_sort(nums, k+1, r);

  vector<int> cache;
  int lo = l, hi = k + 1;
  while(lo <= k && hi <= r) {
    if(nums[hi] < nums[lo])
      cache.push_back(nums[hi++]), res += k - lo + 1;
    else
      cache.push_back(nums[lo++]);
  }
  while(lo <= k)
    cache.push_back(nums[lo++]);
  while(hi <= r)
    cache.push_back(nums[hi++]);

  for(int i = 0; i <= r - l; ++i)
    nums[i+l] = cache[i];
  return res;
}

int number_of_swaps_to_sort(std::vector<int> nums) {
  // WRITE YOUR BRILLIANT CODE HER
  int res = merge_sort(nums, 0, nums.size() - 1);
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

int main() {
    std::vector<int> nums = get_words<int>();
    int res = number_of_swaps_to_sort(nums);
    std::cout << res << '\n';
}
