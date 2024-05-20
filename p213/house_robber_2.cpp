#include <vector>
#include <deque>

class Solution {
private:
  std::vector<int> memo;

  int rob1(std::vector<int>& nums) {
    memo.push_back(nums[0]);

    if (nums.size() > 1) memo.push_back(nums[1]);
    if (nums.size() > 2) memo.push_back(nums[2] + memo[0]);
    
    for (int i = 3; i < nums.size(); i++) {
      memo.push_back(nums[i] + std::max(memo[i - 2], memo[i - 3]));
    }

    int max = 0;

    for (auto x : memo) max = std::max(x, max);

    while (!memo.empty()) memo.pop_back();
    return max;
  }
  
public:
  int rob(std::vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    
    std::deque<int> lo, hi;
    for (auto x : nums) {
      lo.push_back(x);
      hi.push_back(x);
    }

    lo.pop_back();
    hi.pop_front();

    std::vector<int> lo_v, hi_v;
    for (auto x : lo) lo_v.push_back(x);
    for (auto x : hi) hi_v.push_back(x);
    
    return std::max( rob1(lo_v), rob1(hi_v) );
  }
};
