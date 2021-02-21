class Solution {
public:
  vector<int> minOperations(string boxes) {
    vector<int> _boxes;
    vector<int> res(boxes.size(), 0);
    for(int i = 0; i < boxes.size(); ++i)
      if(boxes[i] == '1') _boxes.push_back(i);
    for(int i = 0; i < boxes.size(); ++i)
      for(int j : _boxes)
        res[i] += abs(j - i);
    return res;
  }
};
