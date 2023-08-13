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
VE<int> leaves;
 
void dfs(int u, int p) {
    bool leaf = true;
    for (int v : G[u]) {
        if (v != p) {
            leaf = false;
            dfs(v, u);
            leaves[u] += leaves[v];
        }
    }
    if (leaf) {
        leaves[u] = 1;
    }
}
 
void solve() {
    int N;
    cin >> N;
    G = VE<VE<int>>(N);
    leaves = VE<int>(N);
    REP(N - 1) {
        int U, V;
        cin >> U >> V;
        U--;
        V--;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    dfs(0, -1);
    int Q;
    cin >> Q;
    REP(Q) {
        int X, Y;
        cin >> X >> Y;
        X--;
        Y--;
        cout << 1ll * leaves[X] * leaves[Y] << '\n';
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