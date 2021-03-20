#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int tmp;
        for(string& t : tokens) {
            if(t == "+" || t == "*" || t == "-" || t == "/") {
                tmp = operate(s, t);
                s.push(tmp);
            } else {
                s.push(stringtoi(t));
            }
        }
        return s.top();
    }
private:
    int stringtoi(string& num) {
        int res = 0;
        int sign = num[0] == '-' ? -1 : 1;
        for(char c : num)  {
            if(isdigit(c))
            res = 10 * res + (c-'0');
        }
        return res * sign;
    }
    int operate(stack<int>& s, string& op) {
        if(s.size() < 2) return -1;
        int num1, num2;
        num1 = s.top();
        s.pop();
        num2 = s.top();
        s.pop();
        if(op == "+") return num2 + num1;
        if(op == "-") return num2 - num1;
        if(op == "/") return num2 / num1;
        if(op == "*") return num2 * num1;
        return -1;
    }
};
