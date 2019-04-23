#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> vec;
        string res;
        for(char &c : S) {
            if(c == '(') {
                if(!vec.empty()) res += c;
                vec.push(c);
            }else if(c == ')') {
                vec.pop();
                if(!vec.empty()) res += c;
            }
        }
        return res;
    }
};