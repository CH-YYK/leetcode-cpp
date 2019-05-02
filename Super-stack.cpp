#include <stack>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

class superStack {
public:
    stack<int*> content;
    vector<int*> cache;
    superStack() {

    }

    void push(int * num) {
        content.push(num);
        cache.push_back(content.top());
    }

    int pop() {
        if(!content.empty()) {
            int *res = content.top();
            content.pop();
            cache.pop_back();
            return *res;
        }
        return 0;
    }

    int top() {
        return *content.top();
    }

    void inc(int e, int k) {
        for(int i = 0; i < e; i++) 
            *cache[i] += k;
    }
};

int main() {
    vector<int*> vec;
    vector<int*> vec2;

    int a = 1, b =2, c = 3;
    
    // push values to vec
    vec.push_back(&a), vec2.push_back(vec.back());
    vec.push_back(&b), vec2.push_back(vec.back());
    vec.push_back(&c), vec2.push_back(vec.back());

    //
    *vec[0] += 4;
    *vec[1] += 4;
    *vec[2] += 4;

    for(auto i : vec2) {
        cout << *i << endl;
    }

    // test stack
    superStack test = superStack();

    // push 0, 1, 2, 3
    int a = 1;
    
    // cout << *test.content.top();
    
    // inc 3, 1
    // test.inc(3, 1);
}