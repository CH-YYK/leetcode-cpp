#include <list>
#include <iostream>
#include <vector>
using namespace std;



class MovingAverage {
public:
    /** Initialize your data structure here. */
    double _cum_sum;
    int _size;
    int _num;
    std::vector<int> _list;
    vector<int>::iterator _begin;
    vector<int>::iterator _end;
  
    MovingAverage(int size) {
      _size = size;
      _cum_sum = 0;
      _num = 0;

      _begin = _list.begin();
      _end = _list.end();
    }
    
    double next(int val) {
      _list.push_back(val), _end++;
      if(++_num <= _size) _cum_sum += val;
      else {
        _cum_sum -= *(_begin++);
        _cum_sum += *_end;
      }
      return _cum_sum / min(_size, _num);
    }
};


int main() {
  MovingAverage obj(3);
  std::cout << obj.next(1) << std::endl; 
  std::cout << obj.next(2) << std::endl;
  std::cout << obj.next(5) << std::endl;
  std::cout << obj.next(10) << std::endl;
  return 0;
}