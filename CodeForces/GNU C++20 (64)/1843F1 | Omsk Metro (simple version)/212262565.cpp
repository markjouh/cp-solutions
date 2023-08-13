#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
using LL = long long;
using PII = pair<int, int>;
template<class T> using VE = vector<T>;
template<class T, size_t SZ> using AR = array<T, SZ>;
 
#define FOR(i, A, B) for (int i = A; i < B; i++)
#define F0R(i, N) FOR(i, 0, N)
#define RFOR(i, A, B) for (int i = B - 1; i >= A; i--)
#define RF0R(i, N) RFOR(i, 0, N)
#define REP(N) F0R(_, N)
 
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define F first
#define S second
 
template<typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
VE<VE<int>> G;
VE<int> wt;
VE<VE<PII>> queries;
VE<int> ans;
 
void dfs(int u, int sum, int mn, int mx, int mn_seg, int mx_seg) {
    sum += wt[u];
    ckmin(mn, sum);
    ckmax(mn_seg, sum - mn);
    ckmax(mx, sum);
    ckmin(mx_seg, sum - mx);
    for (auto [k, idx] : queries[u]) {
        if (k >= 0) {
            ans[idx] = mn_seg >= k;
        } else {
            ans[idx] = mx_seg <= k;
        }
    }
    for (int v : G[u]) {
        dfs(v, sum, mn, mx, mn_seg, mx_seg);
    }
}
 
void solve() {
    int N;
    cin >> N;
    G = VE<VE<int>>(N + 10);
    wt = VE<int>(N + 10);
    wt[0] = 1;
    queries = VE<VE<PII>>(N + 10);
    ans = VE<int>(N + 10);
    int v_cnt = 1, q_cnt = 0;
    REP(N) {
        char type;
        cin >> type;
        if (type == '+') {
            int V, X;
            cin >> V >> X;
            V--;
            G[V].push_back(v_cnt);
            wt[v_cnt] = X;
            v_cnt++;
        } else {
            int U, V, K;
            cin >> U >> V >> K;
            U--;
            V--;
            queries[V].push_back({K, q_cnt++});
        }
    }
    dfs(0, 0, 0, 0, 0, 0);
    F0R(i, q_cnt) {
        cout << (ans[i] ? "YES\n" : "NO\n");
    }
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