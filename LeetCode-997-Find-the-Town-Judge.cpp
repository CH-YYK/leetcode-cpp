#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<bool> out(N, false);
        unordered_map<int, int> numReached;

        for(int i = 0; i < trust.size(); i++){
            int start = trust[i].front();
            int end = trust[i].back();
            if(numReached.count(end)){
                numReached[end] += 1;
            }else{
                numReached[end] = 1;
            }
            if(!out[start-1]) out[start-1] = true;
        }

        int num = 0;
        int judge = -1;
        for(int i = 0; i < out.size(); i++) {
            if(!out[i] && numReached[i+1] == N-1) {
                num++;
                judge = i+1;
            } 
        }
        return num == 1 ? judge : -1;
    }
};

class Solution2 {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> out(N, 0), in(N, 0);
        for(int num = 0; num < trust.size(); num++) {
            int start = trust[num].front(), end = trust[num].back();
            out[start-1]++;
            in[end-1]++;
        }
        int num = 0;
        int judge = -1;
        for(int i = 0; i < N; i++) {
            if(in[i] == N-1 && out[i] == 0) {
                num++;
                judge = i+1;
            }
        }
        return num == 1 ? judge : -1; 
    }
};

int main() {
    int N = 3;
    vector<vector<int>> trust = {{1,3}, {2,3}};
    int ans = Solution().findJudge(N, trust);
    cout << ans << "\n";
    return 0;
}