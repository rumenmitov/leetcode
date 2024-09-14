#include <cmath>
#include <deque>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
      int x_memo = x;
      
      if (x < 0) return false;

      deque<int> digits;
      
      while (x > 0) {
	digits.push_back(x % 10);
	x /= 10;
      }
      
      long long int reversed = 0;
      for (int i = 0; i < digits.size(); i++) {
	reversed += digits[i] * pow(10, digits.size() - 1 - i);
      }

      return reversed == x_memo;
    }
};
