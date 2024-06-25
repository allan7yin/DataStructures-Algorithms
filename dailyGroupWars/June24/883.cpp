#include <vector>

class Solution {
public:
  int projectionArea(std::vector<std::vector<int>> &grid) {
    int area = 0; // Initialize the total projection area
    for (int i = 0; i < grid.size(); i++) {
      int z = 0, x = 0, y = 0; // Initialize the projections for the current row/column
      for (int j = 0; j < grid.size(); j++) {
        if (grid[i][j]) {
          z++; // Count the number of non-zero cells for the top-down projection
        }

        x = std::max(x, grid[i][j]); // Find the maximum value in the current row for the side projection
        y = std::max(y, grid[j][i]); // Find the maximum value in the current column for the front projection
      }
      area += (z + x + y); // Add the projections of the current row/column to the total area
    }
    return area; // Return the total projection area
  }
};