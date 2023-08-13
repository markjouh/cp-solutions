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
 
// For each prefix, find the minimal prefix before it
// A prefix can exclude a suffix of the final mini-array
// For the positive/large prefix, this means adding the maximal prefix of the last element
// For the negative/small prefix, this means adding the minimal prefix of the last element
// Bruteforce all prefixes of B, storing the minimal prefix that came before it
 
// Another case to cover is the minimal answer within each mini-array
 
// Finally, another case is to cover when the optimal array is empty
// We must pick an element
 
void solve() {
    int N, M;
    cin >> N >> M;
    VE<VE<int>> A(N);
    VE<LL> sum(N), pref_mn(N), pref_mx(N), single(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        A[i].resize(L);
        for (int j = 0; j < L; j++) {
            cin >> A[i][j];
            sum[i] += A[i][j];
            pref_mn[i] = min(pref_mn[i], sum[i]);
            pref_mx[i] = max(pref_mx[i], sum[i]);
            single[i] = max(single[i], sum[i] - pref_mn[i]);
        }
    }
    VE<int> B(M);
    VE<bool> has(N);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
        B[i]--;
        has[B[i]] = true;
    }
    LL ans = 0;
    for (int i = 0; i < N; i++) {
        if (has[i]) {
            ans = max(ans, single[i]);
        }
    }
    LL rem = 0, pref = 0;
    for (int i = 0; i < M; i++) {
        ans = max(ans, pref + pref_mx[B[i]] - rem);
        rem = min(rem, pref + pref_mn[B[i]]);
        pref += sum[B[i]];
    }
    if (ans == 0) {
        ans = -1e18;
        for (int i = 0; i < N; i++) {
            if (has[i]) {
                for (int j = 0; j < SZ(A[i]); j++) {
                    ans = max(ans, (LL)A[i][j]);
                }
            }
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}
 
// Read the statement carefully, take your time
// Don't be intimidated, the solution is probably simpler than you think
// CM soon :pray: