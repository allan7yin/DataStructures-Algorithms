#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    unordered_map<string, vector<string>> mp;
    unordered_map<string, int> distance;

  public:
    void createEdges(vector<string> &wordList) {
        unordered_map<string, vector<string>> allComboDict;
        int L = wordList[0].size();

        for (string word : wordList) {
            for (int i = 0; i < L; i++) {
                string newWord = word.substr(0, i) + '*' + word.substr(i + 1, L - i - 1);
                allComboDict[newWord].push_back(word);
            }
        }

        for (auto &combo : allComboDict) {
            for (string word1 : combo.second) {
                for (string word2 : combo.second) {
                    if (word1 != word2) {
                        mp[word1].push_back(word2);
                    }
                }
            }
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        wordList.push_back(beginWord);
        createEdges(wordList);

        queue<string> q;
        q.push(beginWord);
        distance[beginWord] = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string front = q.front();
                q.pop();
                int dist = distance[front];

                for (auto &neighbour : mp[front]) {
                    if (distance.find(neighbour) == distance.end()) {
                        distance[neighbour] = dist + 1;
                        q.push(neighbour);
                        if (neighbour == endWord) {
                            return distance[neighbour];
                        }
                    }
                }
            }
        }

        return 0;
    }
};