#include <cmath>
#include <vector>

using namespace std;

class Solution {
    private:
        vector<int> new_cuts;
        int **_memo;

        int cost(int left, int right) {
            if (right - left == 1) return 0;

            if (_memo[left][right] != -1) return _memo[left][right];

            int res = 

        }

    public:
        int minCost(int n, vector<int>& cuts) {
            new_cuts.push_back(0);

            for (auto x : cuts) new_cuts.push_back(x);

            _memo = new int*[new_cuts.size()];

            for (int i = 0; i < new_cuts.size(); i++) {
                _memo[i] = new int[new_cuts.size()];

                for (int j = 0; j < new_cuts.size(); j++) _memo[i][j] = -1;
            }

            new_cuts.push_back(n);

            return _memo[0][n];
        }
};
