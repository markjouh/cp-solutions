#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
 
#define VE vector
#define AR array
 
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
 
VE<LL> sum;
VE<VE<int>> G;
 
LL res = 0, ans = 0;
 
void dfs1(int u, int p) {
    for (int v : G[u]) {
        if (v != p) {
            dfs1(v, u);
            sum[u] += sum[v];
        }
    }
    if (u != 0) {
        res += sum[u];
        ans = res;
    }
}
 
void dfs2(int u, int p) {
    for (int v : G[u]) {
        if (v != p) {
            sum[u] -= sum[v];
            res += sum[u];
            res -= sum[v];
            sum[v] += sum[u];
            ans = max(ans, res);
            dfs2(v, u);
            sum[v] -= sum[u];
            res += sum[v];
            res -= sum[u];
            sum[u] += sum[v];
        }
    }
}
 
void solve() {
    int N;
    cin >> N;
    sum.resize(N);
    F0R(i, N) {
        cin >> sum[i];
    }
    G.resize(N);
    REP(N - 1) {
        int U, V;
        cin >> U >> V;
        U--;
        V--;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    dfs1(0, -1);
    dfs2(0, -1);
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