// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
ios_base::sync_with_stdio(0);
cin.tie(NULL);
*/

class Solution {
 public:
  vector<int> sortArray(vector<int> &nums) {
    // quick sort
    // use mid as pivot
    int n = nums.size();
    quickSort(nums);
    return nums;
  }

 private:
  void quickSort(vector<int> &array) {
    quickSort(array, 0, (int)array.size() - 1);
  }

  void quickSort(vector<int> &array, int left, int right) {
    int index = partition(array, left, right);
    if (left < index - 1) quickSort(array, left, index - 1);
    if (right > index) quickSort(array, index, right);
  }

  int partition(vector<int> &array, int left, int right) {
    // Use middle point as pivot
    int pivot = array[(left + right) / 2];

    // make sure every element left to pivot less than pivot
    // make sure every element right to pivot greater than pivot
    while (left <= right) {
      while (array[left] < pivot) left++;
      while (array[right] > pivot) right--;

      if (left <= right) swap(array[left++], array[right--]);
    }

    // left stop at the one left to pivot
    return left;
  }
};