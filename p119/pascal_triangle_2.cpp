#include <vector>


class Solution {
private:
  std::vector<std::vector<int>> triangle;
  
  void generate(int numRows) {
    if (triangle.empty()) triangle.push_back(std::vector<int> {1} );

    for (int i = 1; i < numRows; i++) {
      std::vector<int> current_row { 1 };

      for (int j = 0; j < triangle.back().size() - 1; j++) {
	current_row.push_back(triangle.back()[j] + triangle.back()[j+1]);
      }

      current_row.push_back(1);
      triangle.push_back(current_row);
    }
  }

public:
  std::vector<int> getRow(int rowIndex) {
    generate(rowIndex + 1);
    return triangle.back();
  }
};
