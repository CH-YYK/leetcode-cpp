#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> res;
        string curString;
        string curnum;

        for(char &c : s) {
            if(c == '['){
                res.push(curString);
                res.push(curnum);
                curString = "", curnum = "";
            }else if(c == ']') {
                int num = stoi(res.top()); 
                res.pop();
                string prevString = res.top();
                res.pop();
                for(int i = 0; i < num; i++) prevString += curString;
                curString = prevString;
            }else if(c-'0' <= 9)
                curnum += c;
            else curString += c;
        }
        return curString;
    }
};