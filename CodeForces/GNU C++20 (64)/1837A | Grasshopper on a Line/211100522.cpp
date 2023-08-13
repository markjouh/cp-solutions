#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
 
using namespace std;
 
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define F first
#define S second
 
#define VE vector
#define AR array
 
typedef long long LL;
typedef pair<int, int> PII;
 
void solve() {
    int X, K;
    cin >> X >> K;
    VE<int> dp(X + 1, 1e9), from(X + 1);
    dp[0] = 0;
    for (int i = 1; i <= X; i++) {
        for (int j = 0; j < i; j++) {
            if ((i - j) % K && dp[j] + 1 < dp[i]) {
                dp[i] = dp[j] + 1;
                from[i] = j;
            }
        }
    }
    cout << dp[X] << '\n';
    int pos = X;
    while (pos > 0) {
        cout << pos - from[pos] << ' ';
        pos = from[pos];
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
 
// Read the statement carefully, take your time
// Don't be intimidated, the solution is probably simpler than you think
// CM soon :pray: