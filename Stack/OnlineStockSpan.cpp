#include <vector>

using namespace std;

class StockSpanner {
public:
    StockSpanner() {
        history_length = 0;
    }
    
    int next(int price) {
        int result = 0;
        history.push_back(price);
        history_length++;
        int temp = history_length - 1;
        while(temp >= 0 && history[temp] <= price) {
            result++;
            temp--;
        }
        return result;
    }
private:
    vector<int> history;
    int history_length;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {}