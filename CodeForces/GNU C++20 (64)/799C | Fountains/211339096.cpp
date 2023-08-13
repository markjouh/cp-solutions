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
 
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define F first
#define S second
 
int tree_sz;
VE<int> tree;
 
void update(int i, int v, int x = 0, int tl = 0, int tr = tree_sz) {
    if (tl + 1 == tr) {
        tree[x] = max(tree[x], v);
        return;
    }
    int mid = tl + (tr - tl) / 2;
    if (i < mid) {
        update(i, v, 2 * x + 1, tl, mid);
    } else {
        update(i, v, 2 * x + 2, mid, tr);
    }
    tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
}
 
int query(int l, int r, int x = 0, int tl = 0, int tr = tree_sz) {
    if (tl >= r || tr <= l) {
        return -1e9;
    }
    if (tl >= l && tr <= r) {
        return tree[x];
    }
    int mid = tl + (tr - tl) / 2;
    return max(query(l, r, 2 * x + 1, tl, mid), query(l, r, 2 * x + 2, mid, tr));
}
 
void solve() {
    int N, C, D;
    cin >> N >> C >> D;
 
    AR<int, 2> bal = {C, D};
 
    VE<VE<PII>> items(2);
    F0R(i, N) {
        int B, P;
        char C;
        cin >> B >> P >> C;
        bool type = C == 'D';
        if (P <= bal[type]) {
            items[type].push_back({B, P});
        }
    }
 
    int ans = 0;
    if (SZ(items[0]) && SZ(items[1])) {
        F0R(i, 2) {
            int mx = 0;
            F0R(j, SZ(items[i])) {
                mx = max(mx, items[i][j].F); 
            }
            ans += mx;
        }
    }
    tree_sz = 1;
    while (tree_sz < 1e5 + 1) {
        tree_sz *= 2;
    }
    F0R(i, 2) {
        tree.resize(2 * tree_sz, -1e9);
        F0R(j, SZ(items[i])) {
            ans = max(ans, items[i][j].F + query(0, bal[i] - items[i][j].S + 1));
            update(items[i][j].S, items[i][j].F);
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