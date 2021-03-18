#include <iostream>
#include <vector>

using namespace std;

namespace KMP {

  vector<int> Build(const string& p) {
    // nxt[i]: len of longest prefix which is also postfix in p[:i]
    const int m = p.length();
    vector<int> nxt{0, 0}; // p at least size of 2 (p.len + 1)
    for(int i = 1, j = 0; i < m; ++i){
      while(j > 0 && p[i] != p[j])
        j = nxt[j];
      if(p[i] == p[j])
        ++j;
      nxt.push_back(j);
    }
    return nxt;
  }

  vector<int> Match(const string& s, const string& p) {
    vector<int> nxt(Build(p));
    vector<int> ans;
    const int n = s.length();
    const int m = p.length();

    for(int i = 0, j = 0; i < n; ++i) {
      while(j > 0 && s[i] != p[j])
        j = nxt[j];
      if(s[i] == p[j])
        ++j;
      if(j == m) {
        ans.push_back(i - m + 1); // i-x+1=m -> x = i-m+1
        j = nxt[j];
      }
    }
    return ans;
  }

};


void CheckEQ(const vector<int>& actual, const vector<int>& expected) {
  if (actual != expected) {
    std::cout << "expected:";
    for (int v : expected)
      std::cout << " " << v;
    std::cout << " actual:";
    for (int v : actual)
      std::cout << " " << v;
    std::cout << std::endl;
  } else {
    std::cout << "PASS" << std::endl;
  }
}
 
int main(int argc, char** argv) {
  CheckEQ(KMP::Build("ABCDABD"), {0, 0, 0, 0, 0, 1, 2, 0});
  CheckEQ(KMP::Build("AB"), {0, 0, 0});
  CheckEQ(KMP::Build("A"), {0, 0});
  CheckEQ(KMP::Build("AA"), {0, 0, 1});
  CheckEQ(KMP::Build("AAA"), {0, 0, 1, 2});
  CheckEQ(KMP::Build("AABA"), {0, 0, 1, 0, 1});
  CheckEQ(KMP::Match("ABC ABCDAB ABCDABCDABDE", "ABCDABD"), {15});
  CheckEQ(KMP::Match("ABC ABCDAB ABCDABCDABDE", "AB"), {0, 4, 8, 11, 15, 19});
  CheckEQ(KMP::Match("ABC ABCDAB ABCDABCDABDE", "B"), {1, 5, 9, 12, 16, 20});
  CheckEQ(KMP::Match("AAAAA", "A"), {0, 1, 2, 3, 4});
  CheckEQ(KMP::Match("AAAAA", "AA"), {0, 1, 2, 3});
  CheckEQ(KMP::Match("AAAAA", "AAA"), {0, 1, 2});
  CheckEQ(KMP::Match("ABC", "ABC"), {0});
  return 0;
}
