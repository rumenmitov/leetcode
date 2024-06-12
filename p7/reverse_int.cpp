#include <cmath>
#include <cstdlib>
#include <cstring>


class Solution {
private:
  bool is_positive = true;
  int answer       = 0;
  
public:
  int reverse(int x) {
    if (x == 0) return 0;

    int* reversed = new int[32];
    memset(reversed, -1, 32);

    if (x < 0) is_positive = false;

    x = abs(x);

    for (int i = 31; i >= 0; i--) {
      reversed[i] = x % 10;
      x /= 10;

      if (x == 0) break;
    }

    int digits = -1;
    for (int i = 31; i >= 0; i--) {
      if (reversed[i] < 0) break;
      digits++;
    }

    for (int i = 31; i >= 0; i--) {
      if (reversed[i] < 0) break;

      if (answer + reversed[i] * pow(10, digits) > pow(2, 31))
	return 0;
      
      answer += reversed[i] * pow(10, digits--);
    }

    if (!is_positive) answer *= -1;
    
    return answer;
  }
};
