#include <stack>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<string> ops;
        string b;
        for(auto c : s) {
            if(c == ' ') continue;
            if(ops.empty() || !isdigit(c)) 
                ops.push_back(b + c);
            else if(isdigit(c) && isdigit(ops.back()[0]))
                ops.back() += c;
            else ops.push_back(b + c);
        }

        vector<string> comops;
        for(auto c : ops) {
            if(comops.empty()) comops.push_back(c);
            else if(comops.back() == "*" || comops.back() == "/"){
                string op = comops.back();
                comops.pop_back();
                int lhs = stoi(comops.back());

                if(op == "*") comops.back() = to_string(lhs*stoi(c));
                else comops.back() = to_string(lhs / stoi(c));
            } else comops.push_back(c);
        }

        int res = 0;
        int sign = 1;
        for(auto c: comops) {
            if(isdigit(c[0])) res += sign * stoi(c);
            else if(c == "+") sign = 1;
            else sign = -1;
        }
        return res;        
    }
};