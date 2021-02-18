class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    // find a sequence of 0 before next 1
    // 1*0 takes 1 flower
    // 2*0 takes 1 flower
    // 3*0 takes 2 flower
    // 4*0 takes 2 flower
    // ... -> n / 2 + n % 2
    int num0;
    
    if(flowerbed[0] == 0) num0 = -1;
    else num0 = -2;
    
    for(int i : flowerbed) {
      if(i == 0) ++num0;
      else {
        if(num0 == 1) n -= 1;
        else if(num0 > 1) {
          n -= (num0 / 2 + num0 % 2);
        }
        num0 = -2;
      }
    }
    if(num0++ >= 0)
      n -= (num0 / 2 + num0 % 2);
    return n <= 0;
  }
};

class Solution2 {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    /* get the maximum number of flowers that can be planted.
      keep finding local maximum will get global maximum in the end.
    */
    if(flowerbed.empty()) return false;
    int i = 0;
    int size = flowerbed.size();
    while(i < size) {
      if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == size-1 || flowerbed[i+1] == 0)) {
        n -= 1;
        flowerbed[i] = 1;
      }
      i += 1;
    }
    return n <= 0;
  }
};