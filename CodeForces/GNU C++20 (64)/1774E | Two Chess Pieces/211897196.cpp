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
 
VE<VE<int>> G;
VE<bool> A, B;
VE<int> dep, deep_a, deep_b;
 
void dfs(int u) {
    if (A[u]) {
        deep_a[u] = dep[u];
    }
    if (B[u]) {
        deep_b[u] = dep[u];
    }
    for (int v : G[u]) {
        if (dep[v] == -1) {
            dep[v] = dep[u] + 1;
            dfs(v);
            deep_a[u] = max(deep_a[u], deep_a[v]);
            deep_b[u] = max(deep_b[u], deep_b[v]);
        }
    }
}
 
void solve() {
    int N, D;
    cin >> N >> D;
    G.resize(N);
    REP(N - 1) {
        int U, V;
        cin >> U >> V;
        U--;
        V--;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    int M1;
    cin >> M1;
    A.resize(N);
    REP(M1) {
        int v;
        cin >> v;
        v--;
        A[v] = true;
    }
    int M2;
    cin >> M2;
    B.resize(N);
    REP(M2) {
        int v;
        cin >> v;
        v--;
        B[v] = true;
    }
    dep.resize(N, -1);
    dep[0] = 0;
    deep_a.resize(N, -1);
    deep_b.resize(N, -1);
    dfs(0);
    int ans = 0;
    FOR(i, 1, N) {
        if (deep_a[i] != -1 || (deep_b[i] - dep[i] >= D)) {
            ans += 2;
        }
        if (deep_b[i] != -1 || (deep_a[i] - dep[i] >= D)) {
            ans += 2;
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