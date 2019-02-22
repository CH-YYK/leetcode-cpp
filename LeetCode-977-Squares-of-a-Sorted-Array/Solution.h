#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int k = 0;
        while(k < A.size() && A[k] < 0) k++; // make sure the array didn't overflow
        k--;
        for(int &j:A) j = j*j;

        int left = k, right = k+1;
        vector<int> res;
        while(left >= 0 && right < A.size()) {
            if (A[left] < A[right]) res.push_back(A[left--]);
            else res.push_back(A[right++]);
        }

        while(left >= 0) {res.push_back(A[left--]);}
        while(right < A.size()) res.push_back(A[right++]);
        return res;
    }
};