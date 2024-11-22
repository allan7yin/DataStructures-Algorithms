#include <string>
#include <vector>

using namespace std;

/*
This problem is very annoying -> just need to become faster at solving LC prblems -> faster and thinking!!

*/
class Solution {
  public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> result;
        int n = words.size();

        vector<string> rowV;
        int length = 0;
        for (int i = 0; i < n; i++) {
            if (rowV.size() + length + words[i].size() > maxWidth) {
                string row = "";
                int intervals = rowV.size() - 1;
                int spaces = maxWidth - length;
                if (intervals > 0) {
                    int int_space = spaces / intervals;
                    int extra_space = spaces % intervals;

                    for (int j = 0; j < rowV.size(); j++) {
                        row += rowV[j];
                        if (j != rowV.size() - 1) {
                            int space_to_add = int_space + (j < extra_space ? 1 : 0);
                            row += string(space_to_add, ' ');
                        }
                    }
                } else {
                    row += rowV[0];
                    row += string(spaces, ' ');
                }
                result.push_back(row);
                rowV.clear();
                length = 0;
            }

            rowV.push_back(words[i]);
            length += words[i].size();
        }

        string lastRow = "";
        for (int j = 0; j < rowV.size(); j++) {
            lastRow += rowV[j];
            if (j != rowV.size() - 1) {
                lastRow += ' ';
            }
        }

        lastRow += string(maxWidth - lastRow.size(), ' ');
        result.push_back(lastRow);
        return result;
    }
};