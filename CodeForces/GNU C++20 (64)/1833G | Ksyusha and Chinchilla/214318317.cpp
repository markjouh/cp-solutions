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
#define PB push_back
#define F first
#define S second
 
// we can root the tree at an arbitrary vertex and solve greedily from the leaves
 
// firstly, why does rooting arbitrarily work?
// assiging an arbitary root to an unrooted tree doesn't actually change anything, it's just an alternative way to view the tree
// thus, the answer to "is there a valid answer" for all possible roots is logically equivalent
// so solving for one root is sufficient
// now, we just need an algorithm that always finds an answer for a rooted tree if it exists
 
// let's look at an arbitrary leaf u
// since it has no children, it must be part of a branch connected upwards
// if its parent has exactly one child, the branch must go u -> par[u] -> par[par[i]]
// if its parent has 2 children,
// let the other child be v
// it must go u -> par[u] -> v
// if its parent has more than 2 children, it is impossible
 
VE<VE<PII>> G;
VE<bool> cut;
 
bool ok;
 
int go(int u, int par, int from_e) {
    int cnt = 0;
    for (auto [v, to_e] : G[u]) {
        if (v != par) {
            cnt += go(v, u, to_e);
        }
    }
    if (cnt == 0) {
        return 1;
    } else if (cnt == 1) {
        return 2;
    } else if (cnt == 2) {
        if (from_e != -1) {
            cut[from_e] = true;
        }
        return 0;
    } else {
        ok = false;
        return 0;
    }
}
 
void solve() {
    int N;
    cin >> N;
    G = VE<VE<PII>>(N);
    F0R(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].PB({v, i});
        G[v].PB({u, i});
    }
    
    cut = VE<bool>(N);
    ok = true;
    ok &= go(0, -1, -1) == 0;
    if (!ok) {
        cout << -1 << '\n';
        return;
    }
    VE<int> ans;
    F0R(i, N) {
        if (cut[i]) {
            ans.PB(i);
        }
    }
    cout << SZ(ans) << '\n';
    F0R(i, SZ(ans)) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
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