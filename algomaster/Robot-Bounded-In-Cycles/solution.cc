#include <iostream> // boolalpha, cin, cout
#include <vector>
#include <string> // getline, string

using namespace std;
// Final direction can be either perpendicular to original direction or anti or
// same if the final direction is same, then it will keep diverging if it didn't
// get back to initial point if the final direction is perpendicular with the
// initial one, it will get back in 4 cycles if the final direction is anti,
// then it will get back in 2 cycles.
bool is_robot_bounded(std::string movements) {
  // WRITE YOUR BRILLIANT CODE HERE
  vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int x = 0, y = 0, d = 0;
  for(char c : movements) {
    if(c == 'S')
      x += dirs[d][0], y += dirs[d][1];
    else if(c == 'L')
      d--;
    else
      d++;
    if(d == 4) d = 0;
    else if(d == -1) d = 3;
  }
  if(d == 0) return x == 0 && y == 0;
  else return true;
}

int main() {
  std::string movements;
  std::getline(std::cin, movements);
  bool res = is_robot_bounded(movements);
  std::cout << std::boolalpha << res << '\n';
}
