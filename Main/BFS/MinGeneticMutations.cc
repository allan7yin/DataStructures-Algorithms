#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  // this is O(n)
  int minMutation(string startGene, string endGene, vector<string> &bank) {
    char choices[] = {'A', 'C', 'G', 'T'};
    unordered_set<string> valid_genes(bank.begin(), bank.end());

    if (valid_genes.find(endGene) == valid_genes.end()) {
      return -1;
    }

    queue<string> q;
    q.push(startGene);
    int mutations = 0;

    while (!q.empty()) {
      for (int i = 0; i < q.size(); i++) {
        string word = q.front();
        q.pop();
        if (word == endGene) {
          return mutations;
        }
        for (int j = 0; j < word.size();
             j++) { // this is always 8, so this inner
                    // for for loop is constant time
          char save = word[j];
          for (int k = 0; k < 4; k++) {
            word[j] = choices[k];
            if (valid_genes.find(word) != valid_genes.end()) {
              valid_genes.erase(word);
              q.push(word);
            }
          }
          word[j] = c;
        }
      }
      mutations += 1;
    }

    return -1;
  }

  // this works, but TLE
  int minMutation2(string startGene, string endGene, vector<string> &bank) {
    if (bank.size() == 0) {
      return -1;
    }
    // populate the hashmap -> the graph
    unordered_map<string, vector<string>> graph;
    bank.push_back(startGene);
    bank.push_back(endGene);
    for (int i = 0; i < bank.size(); i++) {
      for (int j = 0; j < bank.size(); j++) {
        if (i != j) {
          int diff = 0;
          for (int k = 0; k < 8; k++) {
            if (bank[i][k] != bank[j][k]) {
              diff += 1;
            }
          }

          if (diff == 1) {
            // add it to the map
            graph[bank[i]].push_back(bank[j]);
            graph[bank[j]].push_back(bank[i]);
          }
        }
      }
    }

    // now, we do BFS
    deque<pair<string, int>> queue;
    queue.push_back(make_pair(startGene, 0));
    while (!queue.empty()) {
      pair<string, int> top = queue.front();
      queue.pop_front();

      if (top.first == endGene) {
        return top.second;
      } else if (graph.find(top.first) != graph.end()) {
        for (auto &next : graph[top.first]) {
          queue.push_back(make_pair(next, top.second + 1));
        }
      }
    }
    return -1;
  }
};
}
;
