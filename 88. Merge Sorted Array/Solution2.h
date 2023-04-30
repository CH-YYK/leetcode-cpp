#include <vector>

using namespace std;

class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = m-1, n2 = n-1, tar = m + n - 1;
        while(n2 >= 0){
            nums1[tar--] = n1 >= 0 && nums1[n1] > nums2[n2] ? nums1[n1--] : nums2[n2--];
        }
    }
};