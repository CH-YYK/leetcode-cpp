#include <string>
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        string b;
        // separate item in the string
        vector<string> eval;
        for(auto i : s) {
            if(i == ' ') continue;
            if(eval.empty()) eval.push_back(b + i);
            else if(!isdigit(i)) eval.push_back(b + i);         // literally push if not digit
            else if(is_integer(eval.back())) eval.back() += i;  // append digit if previous item is integer
            else eval.push_back(b + i);  // push digit if the previous item is not integer
        }

        stack<string> cache;
        for(auto i : eval){
            if(cache.empty() || cache.top() == "(" || i == "(") 
                cache.push(i);  // literally push
            else if(is_integer(i)) 
                merge(cache, i); // combine the `op` and `lhs` given a `rhs`
            else if(i == ")") {     // combine items till '('
                string tmp = cache.top();
                cache.pop();
                cache.pop();
                merge(cache, tmp); // push tmp as new `rhs` to combine the `lhs` ans `op`
            }else
                cache.push(i);  // literally push `op` 
        }
        return stoi(cache.top());
    }
private:
    bool is_integer(string str) {
        for(char i : str) 
            if(!isdigit(i)) return false;
        return true;
    }

    void merge(stack<string>& cache, string& right) {
        // if cache has `op` and `lhs`, pop twice and merge
        // if cache is empty, literally push `rhs`
        if(cache.empty()) {
            cache.push(right);
            return;
        }
        string op = cache.top();
        cache.pop();
        int left = stoi(cache.top());
        cache.pop();
        
        if(op == "+") cache.push(to_string(left + stoi(right)));
        else cache.push(to_string(left - stoi(right)));
    }
};


class Solution2 {
public:
    int calculate(string s) {
        stack<string> cache;

        string b;
        for(auto i : s){
            if(i == ' ') continue;
            if(cache.empty() || i == '(' || cache.top() == "(") 
                cache.push(b + i);
            else if(isdigit(i) && is_integer(cache.top()))
                cache.top() += i;
            else if(i == ')') {
                string pre = calculate(cache);
                cache.pop();
                cache.push(pre);
            }else if(!isdigit(i)){
                string pre = calculate(cache);
                cache.push(pre);
                cache.push(b + i);
            }else
                cache.push(b+i);
        }
        return stoi(calculate(cache));
    }
private:
    bool is_integer(string str) {
        for(char i : str) 
            if(!isdigit(i)) return false;
        return true;
    }

    string calculate(stack<string>& cache) {
        if(cache.size() < 2) {
            string tmp = cache.top();
            cache.pop();
            return tmp;
        }
        int right = stoi(cache.top());
        cache.pop();
        string op = cache.top();
        cache.pop();
        int left = stoi(cache.top());
        cache.pop();
        
        if(op == "+") return to_string(left + right);
        else return to_string(left - right);
    }
};

int main() {
    string s = "(1+(4+5+2)-3)+(6+8)";
    auto ans = Solution().calculate(s);
    cout << ans << endl;
}