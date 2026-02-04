
#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
// Quadtree is a tree data structure in which each internal node either is a
// leaf node or has exactly 4 children.
// Quadtrees are most often used to partition a two-dimensional space by
// recursively subdividing it into four quadrants or regions.
// One of the common use cases of quadtree is image compression.
// Design the quadtree data structure and write a function that builds a
// quadtree for an input image, where image will be given as a 2D array
// of integers.
// Implement:
// 1. QuadTree makeQuadTree(int[][] img)
// 2. void printQuadTree(QuadTree root)
Example 1: Square

// Input Image:
//   int[][]{
//     {2, 2, 3, 3},
//     {2, 2, 3, 3},
//     {4, 2, 5, 5},
//     {2, 3, 5, 5}
//   }
// +---+---+---+---+
//  | 2  |  2  |  3  |  3 |
// +---+---+---+---+
//  | 2  |  2  |  3  |  3 |
// +---+---+---+---+
//  | 4  |  2  |  5  |  5 |
// +---+---+---+---+
//  | 2  |  3  |  5  |  5 |
// +---+---+---+---+
*/

class QuadTree {
  public:
    int val;
    vector<QuadTree *> children;

    QuadTree(int val) : val(val) {}
};

bool is_leaf_node(vector<vector<int>> &grid, int x_s, int x_e, int y_s, int y_e) {
    int val = grid[x_s][y_s];
    for (int i = x_s; i <= x_e; i++) {
        for (int j = y_s; j <= y_e; j++) {
            if (grid[i][j] != val) return false;
        }
    }

    return true;
}

QuadTree *makeQuadTree(vector<vector<int>> &img, int x_s, int x_e, int y_s, int y_e) {
    // invalid region
    if (x_s > x_e || y_s > y_e) return nullptr;

    // leaf
    if (is_leaf_node(img, x_s, x_e, y_s, y_e)) {
        return new QuadTree(img[x_s][y_s]);
    }

    QuadTree *curr = new QuadTree(-1);
    curr->children.resize(4, nullptr); // nw, ne, sw, se

    int x_m = x_s + (x_e - x_s) / 2;
    int y_m = y_s + (y_e - y_s) / 2;

    // nw
    curr->children[0] = makeQuadTree(img, x_s, x_m, y_s, y_m);
    // ne
    curr->children[1] = makeQuadTree(img, x_s, x_m, y_m + 1, y_e);
    // sw
    curr->children[2] = makeQuadTree(img, x_m + 1, x_e, y_s, y_m);
    // se
    curr->children[3] = makeQuadTree(img, x_m + 1, x_e, y_m + 1, y_e);

    return curr;
}

void printQuadTree(QuadTree *root, int depth = 0, const string &label = "ROOT") {
    for (int i = 0; i < depth; i++)
        cout << "    ";

    if (root == nullptr) {
        cout << label << ": null\n";
        return;
    }

    if (root->children.empty()) {
        cout << label << ": " << root->val << "\n";
        return;
    }

    cout << label << "\n";

    static vector<string> dirs = {"nw", "ne", "sw", "se"};
    for (int i = 0; i < 4; i++) {
        printQuadTree(root->children[i], depth + 1, dirs[i]);
    }
}

int main() {
    cout << "EXAMPLE 1:" << endl;
    vector<vector<int>> img = {
        {2, 2, 3, 3},
        {2, 2, 3, 3},
        {4, 2, 5, 5},
        {2, 3, 5, 5}};

    auto root = makeQuadTree(img, 0, img.size() - 1, 0, img[0].size() - 1);
    printQuadTree(root);

    cout << "EXAMPLE 2:" << endl;
    vector<vector<int>> img2 = {
        {2, 2, 2, 3, 1},
        {2, 2, 2, 3, 1},
        {4, 2, 5, 5, 1},
        {2, 3, 5, 5, 6}};

    auto root2 = makeQuadTree(img2, 0, img2.size() - 1, 0, img2[0].size() - 1);
    printQuadTree(root2);
}