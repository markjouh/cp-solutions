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
 
VE<VE<int>> graph;
VE<int> weight;
VE<VE<PII>> queries;
VE<int> ans;
 
void dfs(int u, int sum, int mn, int mx, int mn_seg, int mx_seg) {
    sum += weight[u];
    ckmin(mn, sum);
    ckmax(mx_seg, sum - mn);
    ckmax(mx, sum);
    ckmin(mn_seg, sum - mx);
    for (auto [k, idx] : queries[u]) {
        ans[idx] = mn_seg <= k && k <= mx_seg;
    }
    for (int v : graph[u]) {
        dfs(v, sum, mn, mx, mn_seg, mx_seg);
    }
}
 
void solve() {
    int N;
    cin >> N;
    graph = VE<VE<int>>(N + 1);
    weight = VE<int>(N + 1);
    weight[0] = 1;
    queries = VE<VE<PII>>(N + 1);
    ans = VE<int>(N);
    int v_cnt = 1, q_cnt = 0;
    REP(N) {
        char type;
        cin >> type;
        if (type == '+') {
            int v, x;
            cin >> v >> x;
            v--;
            graph[v].push_back(v_cnt);
            weight[v_cnt] = x;
            v_cnt++;
        } else {
            int u, v, k;
            cin >> u >> v >> k;
            u--;
            v--;
            queries[v].push_back({k, q_cnt++});
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