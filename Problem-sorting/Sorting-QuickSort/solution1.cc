#include <vector>
#include <iostream>

using namespace std;

/**
 * quickly sort nums in [l, r]
 */
void quick_sort(vector<int>& nums, int l, int r) {
  if(l + 1 >= r) return;

  // use first as pivot index
  int first = l, last = r - 1, key = nums[first];
  while(first < last) {
    /* Use `first` as pivot and save to k
     * Find next last with nums[last] < key, and assign to `first`
     * Find next first with nums[first] > key, and assign to `last`
     * Move pivot to the current `first`
     */
    while(first < last && nums[last] >= key)
      --last;
    nums[first] = nums[last];
    while(first < last && nums[first] <= key)
      ++first;
    nums[last] = nums[first];
  }
  /* put pivot to the correct place where
   *  * all nums left to it are smaller than pivot value
   *  * all nums right to it are greater than pivot
   */
  nums[first] = key;
  quick_sort(nums, l, first); // [l, first)  : pivot is not included in both as it has been correctly placed
  quick_sort(nums, first+1, r); // [first+1, r) : pivot value would be repeated if using first
}

void quick_sort2(vector<int>& nums, int l, int r) {
  if(l + 1 >= r) return; // 1-element subarray for [l, r)
  int first = l, last = r - 1, m = (first + last) / 2, key = nums[m];

  /* Use middle value as pivot to rearrang
   *  -> right position of pivot index (first -> pivot)
   */
  while(first < last) {
    while(nums[first] < key) ++first;
    while(nums[last] > key) --last;
    if(first <= last)
      swap(nums[first++], nums[last--]);
  }
  /* edge case exist
   *  * `first` might stop at 'pivot + 1' or `pivot`
   */
  quick_sort2(nums, l, first); // [l, first)
  quick_sort2(nums, first, r); // [first, r)  : edge case handled and repeated pivot could be avoided
}

void quick_sort3(vector<int>& nums, int l, int r) {
  if(l + 1 >= r) return ;
  int first = l+1, last = r - 1, key = nums[l];
  while(true) {
    while(first < r && nums[first] <= key) ++first;
    while(l < last && nums[last] >= key) --last;
    if(first >= last) break;
    swap(nums[first], nums[last]);
  }
  swap(nums[l], nums[last]);  // last is the index of pivot (nums[last] < key)
  quick_sort3(nums, l, last);
  quick_sort3(nums, last + 1, r);
}

int main() {
  vector<int> nums = {2, 3,1,5, 4};
  quick_sort3(nums, 0, nums.size());
  for(int i : nums)
    cout << i << "\n";
}
