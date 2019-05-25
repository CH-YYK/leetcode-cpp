#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int clumsy(int N) {
        vector<int> buffer({N});
        int ops = 1;
        while(N-- > 1) {
            if(ops % 4 == 1) 
                buffer.back() *= N;
            else if(ops % 4 == 2) 
                buffer.back() /= N;
            else if(ops % 4 == 0)
                buffer.push_back(-N);
            else {
                if(buffer.size() == 2){
                    buffer.front() += buffer.back();
                    buffer.pop_back();
                }
                buffer.back() += N;
            }
            ops++;
        }
        return buffer.size() == 2 ? buffer.front() + buffer.back() : buffer.back();
    }
};