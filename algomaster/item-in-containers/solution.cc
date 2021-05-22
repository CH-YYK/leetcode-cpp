#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <stack>  // stack

using namespace std;

std::vector<int> number_of_items(std::string s, std::vector<std::vector<int>> ranges) {
    std::vector<int> ans;
    // WRITE YOUR BRILLIANT CODE HERE
    for(auto& range : ranges) {
        int res = 0;
        stack<int> stk;
        for(int i = range[0]; i <= range[1]; ++i) {
            if(s[i] == '*') {
              if(stk.empty()) continue;
              stk.top() += 1;
            }
            else if(s[i] == '|') {
              if(stk.empty()) stk.push(0);
              else res += stk.top(), stk.top() = 0;
            }
        }
        ans.push_back(res);
    }
    return ans;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    int ranges_length;
    std::cin >> ranges_length;
    ignore_line();
    std::vector<std::vector<int>> ranges;
    for (int i = 0; i < ranges_length; i++) {
        ranges.emplace_back(get_words<int>());
    }
    std::vector<int> res = number_of_items(s, ranges);
    put_words(res);
}
