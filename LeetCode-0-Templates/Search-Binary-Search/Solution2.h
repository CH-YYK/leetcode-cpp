#include <vector>

using namespace std;

class Solution2 {
public:
    int binarySearch(vector<int> &array, int target) {
        return recurHelper(array, target, 0, (int)array.size()-1);
    }

    int recurHelper(vector<int> &array, int target, int left, int right) {
        if(left > right) return -1;
        int mid = (left + right) / 2;
        if(array[mid] == target) return mid;
        else if(array[mid] < target) return recurHelper(array, target, mid+1, right);
        else return recurHelper(array, target, left, mid);
    }
};