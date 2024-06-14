#include <climits>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
private:
  int findMidpoint(int n, vector<int>& cuts) {
    std::pair<int, int> m(INT_MAX, -1);

    for (int cut : cuts) {
      int cut_prox = std::abs((n / 2) - cut);
      
      if (cut_prox < m.first) {
	m.first = cut_prox;
	m.second = cut;
      }
    }

    return m.second;
  }
  
public:
    int minCost(int n, vector<int>& cuts) {
      if (n <= 1 || cuts.empty()) return 0;

      int m = findMidpoint(n, cuts);

      vector<int> before;
      vector<int> after;

      for (int cut : cuts) {
	if (cut < m) before.push_back(cut);
	if (cut > m) after.push_back(cut - m);
      }

      return n + minCost(m, before) + minCost(n - m, after);
    }
};
