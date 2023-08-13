#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
 
int n;
vector<int> prio;
vector<int> nxt;
 
int next(int i) {
    if (nxt[i] == n || prio[nxt[i]] == -1) {
        return nxt[i];
    }
    return nxt[i] = next(nxt[i]);
}
 
int tree_sz;
vector<int> tree;
 
void update(int i, int x = 0, int tl = 0, int tr = tree_sz) {
    if (tl + 1 == tr) {
        tree[x] = 1 - tree[x];
        return;
    }
    int mid = tl + (tr - tl) / 2;
    if (i < mid) {
        update(i, 2 * x + 1, tl, mid);
    } else {
        update(i, 2 * x + 2, mid, tr);
    }
    tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
}
 
int query(int l, int r, int x = 0, int tl = 0, int tr = tree_sz) {
    if (tl >= r || tr <= l) {
        return 0;
    }
    if (tl >= l && tr <= r) {
        return tree[x];
    }
    int mid = tl + (tr - tl) / 2;
    return query(l, r, 2 * x + 1, tl, mid) + query(l, r, 2 * x + 2, mid, tr);
}
 
void solve() {
    int m, q;
    string s;
    cin >> n >> m >> q >> s;
    prio.resize(n, -1);
    nxt.resize(n);
    for (int i = 0; i < n; i++) {
        nxt[i] = i + 1;
    }
    int cont = 0;
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--;
        for (int j = l; j < r; j = next(j)) {
            if (prio[j] == -1) {
                prio[j] = cont++;
            }
        }
    }
 
    tree_sz = 1;
    while (tree_sz < cont) {
        tree_sz *= 2;
    }
    tree.resize(2 * tree_sz);
 
    vector<bool> on(n);
    int ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            on[i] = true;
            ones++;
            if (prio[i] != -1) {
                update(prio[i]);
            }
        }
    }
 
    while (q--) {
        int x;
        cin >> x;
        x--;
        ones -= on[x];
        on[x] = 1 - on[x];
        ones += on[x];
        if (prio[x] != -1) {
            update(prio[x]);
        }
        int bound = min(ones, cont);
        cout << bound - query(0, bound) << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}