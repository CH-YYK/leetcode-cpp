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
  int p1 = l, p2 = k+1;
  while(p1 <= k || p2 <= r) {
    if(p1 == k + 1 && p2 <= r)
      cache.push_back(nums[p2++]);
    else if(p1 <= k && p2 == r + 1)
      cache.push_back(nums[p1++]);
    else if(nums[p1] > nums[p2])
      cache.push_back(nums[p2++]), res += k - p1 + 1; 
    else
      cache.push_back(nums[p1++]);
  }
  for(int k = 0; k <= r - l; ++k)
    nums[k+l] = cache[k];
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
