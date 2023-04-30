#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        unordered_map<char, char> hashmap = {{'{', '}'}, {'[', ']'}, {'(', ')'}};
        for(char i:s){
            if(i=='{' || i == '[' || i == '(')
                stack.push_back(i);
            else{
                if((stack.empty()) || (i != hashmap[stack.back()])) return false;
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};