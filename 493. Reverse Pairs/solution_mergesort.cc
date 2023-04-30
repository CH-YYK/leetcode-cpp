#include <vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
      const int n = nums.size();
      return mergeSort(nums, 0, n-1);
    }
private:
  // total amount of reversed pairs
  int mergeSort(vector<int>& nums, int lo, int hi) {
    if(lo >= hi) return 0;
    int k = lo + (hi - lo) / 2;
    int res = 0;
    res += mergeSort(nums, lo, k);
    res += mergeSort(nums, k+1, hi);
    res += merge(nums, lo, k, hi);
    return res;
  }

  // count pairs and merge nums[lo:mid+1] and nums[mid+1:hi+1]
  int merge(vector<int>& nums, int lo, int mid, int hi) {
    vector<int> tmp(hi - lo + 1);
    int res = 0;

    // 2 pointers take number of reversed pairs for two sorted array.
    int l = lo, r = mid + 1;
    while(l <= mid && r <= hi) {
      if((long)nums[l] > 2 * (long)nums[r]) {
        res += mid - l + 1;
        r++;
      } else l++;
    }

    // merge two sorted arrays into 1 sorted array
    l = lo, r = mid + 1;
    int i = 0;
    while(l <= mid && r <= hi) {
      if(nums[l] <= nums[r])
        tmp[i++] = nums[l++];
      else
        tmp[i++] = nums[r++];
    }
    while(r <= hi) tmp[i++] = nums[r++];
    while(l <= mid) tmp[i++] = nums[l++];

    // copy merged array to sources
    copy(tmp.begin(), tmp.end(), nums.begin() + lo);
    return res;
  }
};
