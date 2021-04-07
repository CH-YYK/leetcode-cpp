#include <queue>
#include <algorithm>
using namespace std;


class MedianFinder {
public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) { // make sure leftsize - rightsize >= 1
    if(left.empty()) left.push(num);
    else if (num < left.top()) {
      left.push(num);
    } else if(right.empty()) right.push(-num);
    else if (num > right.top()) {
      right.push(-num);
    } else if(left.size() == right.size())
      left.push(num);
    else right.push(-num);
    arrange(left, right);
  }
  
  double findMedian() {
    if(left.size() > right.size()) return left.top();
    else return (double)(left.top() - right.top()) / 2;
  }
  void arrange(priority_queue<int>& left, priority_queue<int>& right) {
    if(left.size() < right.size()) {
      left.push(-right.top());
      right.pop();
    } else if(left.size() > right.size() + 1) {
      right.push(-left.top());
      left.pop();
    }
    return;
  }
private:
  priority_queue<int> left;  // less<int> -> maxheap
  priority_queue<int> right; // greater<int> -> minheap
};
