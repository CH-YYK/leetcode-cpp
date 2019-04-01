#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        stack<string> myStack;
        stringstream ss(path);
        while(getline(ss, tmp, '/')) {
            if(tmp == "" or tmp == ".") continue;
            if(tmp == ".." and !myStack.empty()) myStack.pop();
            else if(tmp != "..") myStack.push(tmp);
        }
        while(!myStack.empty()) {
            res = "/" + myStack.top() + res;
            myStack.pop();
        }
        return res.empty() ? "/" : res;
    }
};

int main() {
    string tes = "dfd";
    string ans = '/' + tes + "fdf";
    cout << ans << "\n";
    return 0;
}