#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> vect = split(preorder);
        int n = vect.size();
        
        if(n == 1 && vect.front() == "#") return true;
        if(vect.front() == "#" || vect.back() != "#") return false;
        stack<string> Stack({vect.front()});

        for(int i = 1; i < n; i++) {
            if(Stack.empty()) return false;
            if(vect[i] == "#" && Stack.top() == "#") {
                while(!Stack.empty && Stack.top() == "#") 
                    Stack.pop(), Stack.pop();
                if(!Stack.empty()) Stack.push(vect[i]);
            }else Stack.push(vect[i]);
        }
        return Stack.empty();
    }
    
    vector<string> split(string preorder) {
        vector<string> res;
        int i = 0, j = 0, n = preorder.size();
        while(i <= n) {
            if(i == n) {
                res.push_back(preorder.substr(j, i-j));
                break;    
            }
            if(preorder[i] == ',') {
                res.push_back(preorder.substr(j, i-j));
                i++;
                j = i;
            }
            i++;
        }
        return res;
    }
};


int main() {
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    vector<string> ans =  Solution().split(preorder);
    cout << ans.size();
    for(auto i:ans) cout << i << ' ';

    bool ans2 = Solution().isValidSerialization(preorder);
}