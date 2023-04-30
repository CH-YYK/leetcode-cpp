#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        sort(A.begin(), A.end());
        int j = 1;
        for(int i = 0; i < A.size() - 1; i += 2) {
            if(A[i] % 2 != 0) {
                while (A[j] % 2 != 0) j += 2;
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};