#include <algorithm> // copy
#include <iostream>  // cin, cout
#include <iterator>  // back_inserter, istream_iterator
#include <sstream>   // istringstream
#include <string>    // getline, string
#include <vector>    // vector
#include <unordered_map>
#include <utility>

using namespace std;

std::string most_common_word(std::string paragraph,
                             std::vector<std::string> banned) {
  int freq = 0;
  string w;

  paragraph.push_back(' ');
  unordered_map<string, int> m;
  for(char c : paragraph) {
    if(isalpha(c)) {
      w += tolower(c);
    }else {
      if(!w.empty()) m[w]++;
      w.clear();
    }
  }

  for(string& s : banned)
    m.erase(s);

  for(auto& p : m) 
    if(p.second > freq) freq = p.second, w = p.first;

  return w;
}

template <typename T> std::vector<T> get_words() {
  std::string line;
  std::getline(std::cin, line);
  std::istringstream ss{line};
  std::vector<T> v;
  std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{},
            std::back_inserter(v));
  return v;
}

int main() {
  std::string paragraph;
  std::getline(std::cin, paragraph);
  std::vector<std::string> banned = get_words<std::string>();
  std::string res = most_common_word(paragraph, banned);
  std::cout << res << '\n';
}
