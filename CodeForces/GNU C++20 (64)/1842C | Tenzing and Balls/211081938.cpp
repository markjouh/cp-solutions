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
    int N;
    cin >> N;
    VE<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    VE<int> dp(N + 1, 1e9), store(N + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        dp[i] = min(store[A[i - 1]], dp[i - 1] + 1);
        store[A[i - 1]] = min(store[A[i - 1]], dp[i - 1]);
    }
    cout << N - dp[N] << '\n';
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