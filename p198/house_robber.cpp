#include <vector>

class Solution {
private:
  std::vector<int> memo;
  
public:
  int rob(std::vector<int>& nums) {
    memo.push_back(nums[0]);

    if (nums.size() > 1) memo.push_back(nums[1]);
    if (nums.size() > 2) memo.push_back(nums[2] + memo[0]);
    
    for (int i = 3; i < nums.size(); i++) {
      memo.push_back(nums[i] + std::max(memo[i - 2], memo[i - 3]));
    }

    int max = 0;

    for (auto x : memo) max = std::max(x, max);

    return max;
  }
};
