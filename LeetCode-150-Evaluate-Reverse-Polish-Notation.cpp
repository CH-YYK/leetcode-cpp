#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> vec;
        for(auto i : tokens) {
            if(vec.empty() || (i != "+" && i!="/" && i != "*" && i != "-"))
                vec.push(stoi(i));
            else{
                int m = vec.top();
                vec.pop();
                if(i == "+") vec.top() += m;
                if(i == "/") vec.top() /= m;
                if(i == "-") vec.top() -= m;
                if(i == "*") vec.top() *= m;
            }
        }
        return vec.top();
    }
};