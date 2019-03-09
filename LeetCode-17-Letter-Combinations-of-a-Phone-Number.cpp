#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
    // iterative solutions
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        corpus = unordered_map<char, string>({{'2',"abc"}, {'3', "def"}, 
        {'4',"ghi"}, {'5', "jkl"}, {'6',"mno"},{'7', "pqrs"}, {'8',"tuv"}, {'9',"wxyz"}});
        
        string firstdigit(corpus[digits[0]]);
        stack<string> Stack({""});

        while(!Stack.empty()) {
            string cur_string = Stack.top();
            Stack.pop();
            if(cur_string.size() == digits.size()) 
                res.push_back(cur_string);
            string temp = corpus[digits[cur_string.size()]];
            for(string::iterator it = temp.end()-1; it >= temp.begin(); it--)
                Stack.push(cur_string + *it);
        }

        return res;
    };
private:
    unordered_map<char, string> corpus;
    vector<string> res;
};

class Solution2 {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        corpus = unordered_map<char, string>({{'2',"abc"}, {'3', "def"}, 
        {'4',"ghi"}, {'5', "jkl"}, {'6',"mno"},{'7', "pqrs"}, {'8',"tuv"}, {'9',"wxyz"}});

        return helper(digits, 0);
        
    };
private:
    unordered_map<char, string> corpus;
    vector<string> res;
    vector<string> helper(string digits, int i) {
        if(i == digits.size()) return vector<string>({""});
        
        vector<string> res;
        vector<string> rest = helper(digits, i+1);
        
        string b = "";
        for(string &j:rest){
            for(char &k : corpus[digits[i]])
                res.push_back(b + k + j);
        }
        
        return res;
    }
};

int main() {
    string digits = "23";
    vector<string> ans = Solution2().letterCombinations(digits);
    for(string i : ans) cout << i << " ";
    cout << "\n";
    char i = '3';
    string b = "";
    string a = b + i + " dfdf ";
    cout << a;
    return 0;
}