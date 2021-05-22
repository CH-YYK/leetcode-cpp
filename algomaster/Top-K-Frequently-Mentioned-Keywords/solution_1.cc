#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // ostream_iterator, prev
#include <limits> // numeric_limits
#include <string> // getline, string
#include <utility> // move
#include <vector> // vector
#include <utility>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

std::vector<std::string> top_mentioned(int k, std::vector<std::string> keywords, std::vector<std::string> reviews) {
  // count strings/words and save counts in a hashtable
  unordered_map<string, int> m;
  for(string review : reviews) {
    string w;
    unordered_set<string> s;
    review.push_back(' ');
    for(char c : review) {
      if(isalpha(c)) w += tolower(c);
      else if(w.empty()) continue;
      else {
        if(!s.count(w)) m[w]++;  // save the word only once for each review
        s.insert(w);
        w.clear();
      }
    }
  }
  // minheap; maxheap<-cnt, w>, top() : minimum freq, and word with smallest
  // alphabetical order
  priority_queue<pair<int, string>> pq;
  for(string& w : keywords) {
    if(!m.count(w)) continue;
    // put <-freq, str> in heap
    if(pq.size() < k) pq.push({-m[w], w});
    else if(m[w] > -pq.top().first)
      pq.pop(), pq.push({-m[w], w});
    else if(m[w] == -pq.top().first)
      if(w < pq.top().second)
        pq.pop(), pq.push({-m[w], w});
  }

  vector<string> res;
  while(!pq.empty())
    res.push_back(pq.top().second), pq.pop();
  reverse(res.begin(), res.end());
  return res;
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
  int k;
  std::cin >> k;
  ignore_line();
  int keywords_length;
  std::cin >> keywords_length;
  ignore_line();
  std::vector<std::string> keywords;
  for (int i = 0; i < keywords_length; i++) {
    std::string line;
    std::getline(std::cin, line);
    keywords.emplace_back(std::move(line));
  }
  int reviews_length;
  std::cin >> reviews_length;
  ignore_line();
  std::vector<std::string> reviews;
  for (int i = 0; i < reviews_length; i++) {
    std::string line;
    std::getline(std::cin, line);
    reviews.emplace_back(std::move(line));
  }
  std::vector<std::string> res = top_mentioned(k, keywords, reviews);
  put_words(res);
}
