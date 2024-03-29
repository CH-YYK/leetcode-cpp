// Hello, this is a CPP leetcode snippet.

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <set>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

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