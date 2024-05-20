#include <unordered_map>

class Solution {
private:
  std::unordered_map<int, int> memo;
  
public:
  int climbStairs(int n) {
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;
    
    for (int i = 3; i <= n; i++) {
      memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
  }
};
