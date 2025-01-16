#include "bits/stdc++.h"

using namespace std;

#define FOR(i, L, R) for (int i = L; i < R; ++i)
#define RFOR(i, L, R) for (int i = L; i >= R; --i)
#define BTWN(i, l, r) ((l) <= (i) && (i) <= (r))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef tuple<int, int, int> tiii;

/*
- Tabulation question would be O(nk), where n = target sum and k is number of coins
- given the constraints on this problem, we have n <= 100, 1 <= 10^6 -> so 10^7. So an O(nk) solution is linear in
   this situation -> OK!
*/

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> coins(n);
    FOR(i, 0, n) {
        cin >> coins[i];
    }

    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= target; i++) {
        for (int &coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }

    if (dp[target] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[target] << endl;
    }

    return 0;
}