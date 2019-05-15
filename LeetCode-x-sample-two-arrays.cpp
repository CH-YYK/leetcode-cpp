#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int sumK(vector<int> & A, vector<int>& B, int K, int N) {
        int sum = 0;
        for(int i = 0; i < N; i++) {
            if(i < K) sum += A[i];
            else sum += B[i];
        }

        priority_queue<int, vector<int>, less<int>> diff;
        for(int i = 0; i < N; i++) 
            diff.push(B[i] - A[i]);

        for(int j = K; j < N; j++) {
            int newsum = sum + diff.top() + A[j] - B[j];
            if(newsum > sum) {
                diff.pop(), diff.push(B[j]-A[j]);
                sum = newsum;
            }
        }

        return sum;
    }
};

int main() {
    vector<int> A({4, 2, 1, 6});
    vector<int> B({2, 5, 3, 4});
    int ans = Solution().sumK(A, B, 3, 4);
    cout << ans << endl;
}