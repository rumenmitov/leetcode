#include <climits>
#include <string>
#include <vector>

class Solution {
private:
  int getMin(std::vector<int> arr) {
    int min = INT_MAX;

    for (auto n : arr) {
      if (n <= min) std::swap(min, n);
    }

    return min;
  }
  
public:
  int minDistance(std::string word1, std::string word2) {
    if (word1 == word2) return 0;

    if (word1.empty()) return word2.size();
    if (word2.empty()) return word1.size();

    int res = 0;
    
    int** grid = new int*[word2.size() + 1];

    for (size_t i = 0; i < word2.size() + 1; i++) {
      int* row = new int[word1.size() + 1];

      if (i == 0) {
	for (size_t j = 0; j < word1.size() + 1; j++) row[j] = j;
      }

      row[0] = i;
      
      grid[i] = row;
    }


    for (size_t i = 1; i < word2.size() + 1; i++) {
      for (size_t j = 1; j < word1.size() + 1; j++) {
	int above = grid[i - 1][j];
	int diag = grid[i - 1][j - 1];
	int left = grid[i][j - 1];

	int minDist = getMin(std::vector<int> { above, diag, left });

	if (word2[i - 1] == word1[j - 1]) grid[i][j] = diag;
	else grid[i][j] = 1 + minDist;
      }
    }

    res = grid[word2.size()][word1.size()];

    for (size_t i = 0; i < word2.size() + 1; i++) delete[] grid[i];

    delete[] grid;

    return res;
  }
};
