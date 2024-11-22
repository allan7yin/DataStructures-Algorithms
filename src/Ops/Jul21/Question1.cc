#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

using CustomerId = int64_t;
using LineNumber = int64_t;

class SupermarketCheckout {
public:
  void OnCustomerEnter(CustomerId customerId, LineNumber lineNumber,
                       int64_t numItems) {
    // push the customer onto their line's queue
    lines[lineNumber].push_back(customerId);

    // adjust the count for customer
    customerItemCount[customerId] = numItems;
    customerToLine[customerId] = lineNumber;
  }

  void OnBasketChange(CustomerId customerId, int64_t newNumItems) {
    int change = newNumItems - customerItemCount[customerId];
    LineNumber lineNumber = customerToLine[customerId];

    // if positive, need to add to end of line, else, leave it
    if (change > 0) {
      // remove it
      lines[lineNumber].remove(customerId);
      lines[lineNumber].push_back(customerId);
      customerItemCount[customerId] = newNumItems;
    } else {
      customerItemCount[customerId] = newNumItems;
    }
  }

  void OnLineService(LineNumber lineNumber, int64_t numProcessedItems) {
    while (numProcessedItems > 0 && !lines[lineNumber].empty()) {
      CustomerId customerId = lines[lineNumber].front();

      if (numProcessedItems - customerItemCount[customerId] < 0) {
        // means, we cannot fully process this customer, take what we can
        customerItemCount[customerId] -= numProcessedItems;
        numProcessedItems = -1;
      } else {
        numProcessedItems -= customerItemCount[customerId];
        lines[lineNumber].pop_front();
      }
    }
  }

  void OnLinesService() {
    // just call the above
    for (auto &kv : lines) {
      OnLineService(kv.first, 1);
    }
  }

private:
  unordered_map<LineNumber, list<CustomerId>> lines;
  unordered_map<CustomerId, int64_t> customerItemCount;
  unordered_map<CustomerId, LineNumber> customerToLine;

  void OnCustomerExit(CustomerId customerId) {
    // Don't change this implementation.
    std::cout << customerId << "\n";
  }
};

int main() { return 0; }
