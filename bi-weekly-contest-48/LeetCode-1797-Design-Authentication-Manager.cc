#include <string>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

class AuthenticationManager {
private:
  // O(NlogN)
  set<pair<int, string>> tokens;  // indexed by endTime
  unordered_map<string, int> tokenIds;  // search by ids and get startTime
  int duration;
public:
  AuthenticationManager(int timeToLive) {
    duration = timeToLive;
  }

  void generate(string tokenId, int currentTime) {
    clear(currentTime);
    tokens.insert({currentTime + duration, tokenId});
    tokenIds[tokenId] = currentTime;
  }

  void renew(string tokenId, int currentTime) {
    clear(currentTime);
    if(!tokenIds.count(tokenId)) return;
    tokens.erase({tokenIds[tokenId] + duration, tokenId});
    tokenIds[tokenId] = currentTime;
    tokens.insert({currentTime + duration, tokenId});
  }

  int countUnexpiredTokens(int currentTime) {
    clear(currentTime);
    return tokenIds.size();
  }

  void clear(int currentTime) {
    while(!tokens.empty() && tokens.begin()->first <= currentTime) {
      tokenIds.erase(tokens.begin()->second);
      tokens.erase(tokens.begin());
    }
  }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
