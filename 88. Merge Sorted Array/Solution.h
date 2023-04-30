#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r1 = (int)(nums1.size() - nums2.size() - 1);
        int r2 = (int)(nums2.size() - 1);
        int curr = (int)(nums1.size() - 1);
        while(r1 >= 0 && r2 >= 0) {
            if(nums1[r1] > nums2[r2]){
                nums1[curr] = nums1[r1];
                r1--;
            }else{
                nums1[curr] = nums2[r2];
                r2--;
            }
            curr--;
        }
        while(r1 >= 0) {
            nums1[curr] = nums1[r1];
            curr--;
            r1--;
        }

        while(r2 >= 0){
            nums1[curr] = nums2[r2];
            curr--;
            r2--;
        }
    }
};