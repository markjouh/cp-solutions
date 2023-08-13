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
#define MP make_pair
#define F first
#define S second
 
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
 
constexpr array<LL, 7> P = {1, 10, 100, 1'000, 10'000, 100'000, 1'000'000};
 
void solve() {
    LL A, B, C;
    LL K;
    cin >> A >> B >> C >> K;
    if (C < max(A, B)) {
        cout << -1 << '\n';
        return;
    }
    LL passed = 0;
    for (LL i = P[A - 1]; i < P[A]; i++) { // Fix a
        LL mx_tot = P[C] - 1; // Maximum value of a + b
 
        LL mx_b = mx_tot - i; // Maximum value of b
        mx_b = min(mx_b, P[B] - 1);
 
        LL mn_b = P[B - 1]; // Minimum value of b
        if (C > B) {
            mn_b = max(mn_b, P[C - 1] - i);
        }
 
        LL valid_b = mx_b - mn_b + 1; // # of valid values for b
        valid_b = max(0ll, valid_b);
 
        if (passed + valid_b >= K) {
            LL at_k = mn_b + (K - passed - 1);
            cout << i << " + " << at_k << " = " << i + at_k << '\n';
            return;
        }
        passed += valid_b;  
    }
    cout << -1 << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
 
/*
    Don't be intimidated, the solution is probably simpler than you think
    Try your algorithm on the samples first when possible
    READ THE STATEMENT VERY CAREFULLY, TAKE YOUR TIME
*/