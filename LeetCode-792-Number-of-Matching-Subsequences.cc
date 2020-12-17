#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  int numMatchingSubseq(string S, vector<string>& words) {
    vector<vector<char*>> heads(26);
    int res;
    for(string& w : words) 
      heads[w[0] - 'a'].push_back(w.data());

    for(char c : S) {
      vector<char*> tmp = heads[c - 'a'];
      heads[c-'a'] = vector<char*>();

      for(char* c : tmp) {
        if(*(++c) == '\0') ++res;
        else {
          heads[*c - 'a'].push_back(c);
        }
      }
    }
    return res;
  }
};