#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

/* Min operations to make a sequence be arithmetic squence
 *
 */
int min_operations(vector<int> nums, int x) {
  // possible a0
  unordered_map<int, int> m;
  int n = nums.size();
  int max_ = 0;
  for(int i = 0; i < n; ++i) {
    // a0 = ai - i*x
    if(++m[nums[i] - i * x] > max_) 
      max_ = m[nums[i] - i * x];
  }
  return n - max_;
}

int main() {
  int x = 2;
  vector<int> nums = {2, 4, 5, 6, 8};
  cout << min_operations(nums, 2) << endl;
  return 0;
}
