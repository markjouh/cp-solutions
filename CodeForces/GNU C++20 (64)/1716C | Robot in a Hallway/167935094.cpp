#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
struct segtree {
    int sz;
    vector<int> tree;
 
    void init(int n) {
        sz = 1;
        while (sz < n) {
            sz *= 2;
        }
        tree.resize(2 * sz);
    }
 
    void upd(int i, int v, int x, int l, int r) {
        if (l + 1 == r) {
            tree[x] = v;
            return;
        }
        int mid = l + (r - l) / 2;
        if (i < mid) {
            upd(i, v, 2 * x + 1, l, mid);
        } else {
            upd(i, v, 2 * x + 2, mid, r);
        }
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }
 
    void upd(int i, int v) {
        upd(i, v, 0, 0, sz);
    }
 
    void build(vector<int> &a, int x, int l, int r) {
        if (l + 1 == r) {
            if (l < sz(a)) {
                tree[x] = a[l];
            }
            return;
        }
        int mid = l + (r - l) / 2;
        build(a, 2 * x + 1, l, mid);
        build(a, 2 * x + 2, mid, r);
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }
 
    void build(vector<int> &a) {
        init(sz(a));
        build(a, 0, 0, sz);
    }
 
    int query(int L, int R, int x, int l, int r) {
        if (l >= R || r <= L) {
            return 0;
        }
        if (l >= L && r <= R) {
            return tree[x];
        }
        int mid = l + (r - l) / 2;
        return max(query(L, R, 2 * x + 1, l, mid), query(L, R, 2 * x + 2, mid, r));
    }
 
    int query(int l, int r) {
        return query(l, r, 0, 0, sz);
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int m;
        cin >> m;
        vector<vector<int>> a(2, vector<int>(m));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
 
        vector<vector<int>> b = a, c = a;
        for (int i = 0; i + 1 < m; i++) {
            b[0][i + 1] -= i;
            c[1][i + 1] -= i;
        }
        for (int i = 0; i < m; i++) {
            b[1][m - i - 1] -= m - 1 + i;
            c[0][m - i - 1] -= m - 1 + i;
        }
 
        vector<segtree> bst(2), cst(2);
        bst[0].build(b[0]);
        bst[1].build(b[1]);
        cst[0].build(c[0]);
        cst[1].build(c[1]);
 
        int moves = 0, time = 0, ans = INT_MAX;
        int row = 0, col = 0;
        while (col < m) {
            int travel = 2 * (m - 1 - col) + (moves % 2 == 0);
            int row1 = (row ? cst : bst)[row].query(col + 1, m);
            int row2 = (row ? cst : bst)[1 - row].query(col + 1 - (moves % 2 == 0), m);
            ans = min(ans, travel + max(time, max(row1, row2) + col));
 
            if (moves % 4 == 0) {
                row++;
            }
            if (moves % 4 == 1 || moves % 4 == 3) {
                col++;
            }
            if (moves % 4 == 2) {
                row--;
            }
            moves++;
            if (col < m) {
                time = max(time, a[row][col]);
            }
            time++;
        }
        cout << ans << '\n';
    }
}