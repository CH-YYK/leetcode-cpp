// Iterative binary search method

#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int> &array, int target) {
        int left = 0, right = (int)array.size() - 1;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(array[mid] == target) return mid;
            else if(array[mid] < target) left = mid + 1;
            else right = mid;
        }
        return -1;
    }
};