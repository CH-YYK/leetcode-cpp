#include <iostream>
#include <queue>
#include <functional>
using namespace std;

class MedianFinder {
    priority_queue<int, vector<int>, less<int>> low;
    priority_queue<int, vector<int>, greater<int>> high;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(this->low.size() == this->high.size()) this->low.push(num);
        else this->high.push(num);

        if(this->low.empty() || this->high.empty()) 
            return;
        
        if(this->low.top() > this->high.top()) {
            int tmp = this->high.top();
            this->high.pop();
            this->high.emplace(this->low.top());
            this->low.pop();
            this->low.emplace(tmp);            
        }
    }
    
    double findMedian() {
        if(this->low.size() == this->high.size()) 
            return this->low.top() + (double)(this->high.top() - this->low.top())/2;
        else return this->low.top();
    }
};