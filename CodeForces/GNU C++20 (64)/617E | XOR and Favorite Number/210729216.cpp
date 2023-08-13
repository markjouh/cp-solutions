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
    int N, M, K;
    cin >> N >> M >> K;
    VE<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    VE<int> pref(N + 1);
    for (int i = 0; i < N; i++) {
        pref[i + 1] = pref[i] ^ A[i];
    }
    VE<AR<int, 3>> Q(M);
    for (int i = 0; i < M; i++) {
        cin >> Q[i][0] >> Q[i][1];
        Q[i][0]--;
        Q[i][2] = i;
    }
    int blk = 1;
    while (blk * blk < N) {
        blk++;
    }
    sort(ALL(Q), [&](AR<int, 3> a, AR<int, 3> b) {
        if (a[0] / blk != b[0] / blk) {
            return a[0] / blk < b[0] / blk;
        }
        return a[1] < b[1];
    });
    VE<LL> freq(2e6);
    LL res = 0;
    auto add = [&](int x) {
        res += freq[x ^ K];
        freq[x]++;
    };
    auto del = [&](int x) {
        freq[x]--;
        res -= freq[x ^ K];
    };
    for (int i = Q[0][0]; i <= Q[0][1]; i++) {
        add(pref[i]);
    }
    vector<LL> ans(M);
    ans[Q[0][2]] = res;
    int l = Q[0][0], r = Q[0][1];
    for (int i = 1; i < M; i++) {
        while (l < Q[i][0]) {
            del(pref[l++]);
        }
        while (l > Q[i][0]) {
            add(pref[--l]);
        }
        while (r < Q[i][1]) {
            add(pref[++r]);
        }
        while (r > Q[i][1]) {
            del(pref[r--]);
        }
        ans[Q[i][2]] = res;
    }
    for (int i = 0; i < M; i++) {
        cout << ans[i] << '\n';
    }
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