#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> numbers, int zerosToOne) {
    int n = numbers.size();
    int onesCount = 0;
    int onesIdx = 0;
    int zeroCount = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] == 0) {
            zeroCount++;
        } else {
            onesCount++;
            onesIdx++;
        }
    }
    int time = 0;
    bool add = false;
    while (zeroCount > zerosToOne || onesCount > 0) {

        if (zeroCount > zerosToOne) {
            for (int i = 0; i < zerosToOne; i++) {
                numbers.pop_back();
                zeroCount--;
                add = true;
            }
            if (add) {
                numbers.push_back(1);
                add = false;
            }
        } else if (onesCount > 0) {
            numbers.back() = 0;
        } else {
            break;
        }
        time++;
    }
    return time;
}

int main() {
}