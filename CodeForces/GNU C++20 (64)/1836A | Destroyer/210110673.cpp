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
    int N;
    cin >> N;
    vector<int> cnt(100);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    bool ok = true;
    for (int i = 1; i < 100; i++) {
        ok &= cnt[i] <= cnt[i - 1];
    }
    cout << (ok ? "YES\n" : "NO\n");
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