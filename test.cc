#include <vector>
#include <iostream>

int main() {
  std::vector<int> _vec;
  std::vector<int>::iterator _end = _vec.begin();
  std::vector<int>::iterator _begin = _vec.begin();

  _vec.push_back(1);
  std::cout << *(++_begin) << std::endl;
  std::cout << *_end << std::endl;

  _vec.push_back(4);
  std::cout << *(++_end) << std::endl;  
  return 0;
}