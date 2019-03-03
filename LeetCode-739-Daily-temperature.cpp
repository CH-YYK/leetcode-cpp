#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> Stack;
        vector<int> res(T.size(), 0);
        for(int i=0; i<T.size(); i++){
            while(!Stack.empty()){
                int curr = Stack.top();
                if(T[i] > T[curr]){
                    res[curr] = i - curr;
                    Stack.pop();
                } else break;
            }
            Stack.push(i);
        }
        return res;
    }
};


int main() {
    vector<int> T({73,74,75,71,69,72,76,73});
    vector<int> ans = Solution().dailyTemperatures(T);
    for(auto &i : ans) cout << i << " ";
    cout << "\n";
    return 0;
}