#include <vector>

using namespace std;

class Solution {  
public:
  int maxProfit(vector<int>& prices) {      
    int l = 0, r = 1;

    int profit = 0;
    
    while (r < prices.size()) {
      if (prices[l] > prices[r]) {
	l = r;
	r++;
	continue;
      }

      profit = std::max(profit, prices[r] - prices[l]);
      r++;
    }

    return profit;
  }
};
