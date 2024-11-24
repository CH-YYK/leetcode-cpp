#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  long long maxMatrixSum(vector<vector<int>> &matrix) {
    // To make the sum as large as possible, each multiplication with -1 only
    // impact two numbers.
    //
    // By continously applying multiplication with -1, we can make any two pair
    // of numbers in the matrix to be multiplied by -1.
    //
    // So we'll try to make all negative number to positive if there are even
    // amount of them, otherwise make the minimum positive negative or ignore a
    // max negative number.
    //
    // Time: O(n^2)
    // Space: O(n^2)
    vector<int> negatives, positives;
    int min_positive = INT_MAX;
    int max_negative = INT_MIN;
    long long negative_sum = 0, positive_sum = 0;
    for (const auto &row : matrix) {
      for (const auto &num : row) {
        if (num < 0) {
          negatives.push_back(num);
          negative_sum += num;
          max_negative = max(max_negative, num);
        } else {
          positives.push_back(num);
          positive_sum += num;
          min_positive = min(min_positive, num);
        }
      }
    }
    if (negatives.size() & 1) {
      return max(positive_sum - 2ll * min_positive - negative_sum,
                 positive_sum - negative_sum + 2ll * max_negative);
    }
    return positive_sum - negative_sum;
  }
};