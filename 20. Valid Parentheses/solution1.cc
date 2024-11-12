#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if(stk.empty()) stk.push(c);
            else if(stk.top() == '(' && c == ')') stk.pop();
            else if(stk.top() == '[' && c == ']') stk.pop();
            else if(stk.top() == '{' && c == '}') stk.pop();
            else stk.push(c);
        }
        return stk.empty();
    }
};