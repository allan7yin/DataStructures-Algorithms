#include <unordered_set>
using namespace std;

unordered_set<ll> res;
void f(vll &a, int i, ll mask, ll last) {
  if (i == a.size()) {
    res.insert(mask);
    return;
  }
  if (a[i] > last) {
    f(a, i + 1, mask | a[i], a[i]);
  }
  f(a, i + 1, mask, last);
}