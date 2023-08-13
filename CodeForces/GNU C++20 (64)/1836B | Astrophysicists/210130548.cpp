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
 
void solve() {
    LL N, K, G;
    cin >> N >> K >> G;
    LL d = (G + 1) / 2 - 1;
    LL save = (N - 1) * d;
    if ((K * G - save) % G < (G + 1) / 2) {
        save += (K * G - save) % G;
    } else {
        save -= G - (K * G - save) % G;
    }
    if ((K * G - save) % G < (G + 1) / 2) {
        save += (K * G - save) % G;
    } else {
        save -= G - (K * G - save) % G;
    }
    cout << min(K * G, save) << '\n';
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