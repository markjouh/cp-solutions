#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
struct segtree {
    int sz;
    vector<ll> tree;
    vector<ll> lazy;
 
    void init(int n) {
        sz = 1;
        while (sz < n) {
            sz *= 2;
        }
        tree.resize(2 * sz);
        lazy.resize(2 * sz);
    }
 
    void build(vector<int> &a, int x, int l, int r) {
        if (l == r - 1) {
            if (l < (int)a.size()) {
                tree[x] = a[l];
            }
            return;
        }
        int mid = l + (r - l) / 2;
        build(a, 2 * x + 1, l, mid);
        build(a, 2 * x + 2, mid, r);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
 
    void build(vector<int> &a) {
        build(a, 0, 0, sz);
    }
 
    void update(int L, int R, int x, int l, int r, int v) {
        if (lazy[x] != 0) {
            tree[x] += (r - l) * lazy[x];
            if (l != r - 1) {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if (l >= R || r <= L) {
            return;
        }
        if (l >= L && r <= R) {
            tree[x] += 1ll * (r - l) * v;
            if (l != r - 1) {
                lazy[2 * x + 1] += v;
                lazy[2 * x + 2] += v;
            }
            return;
        }
        int mid = l + (r - l) / 2;
        update(L, R, 2 * x + 1, l, mid, v);
        update(L, R, 2 * x + 2, mid, r, v);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
 
    void update(int L, int R, int v) {
        update(L, R, 0, 0, sz, v);
    }
 
    int query(int L, int R, int x, int l, int r) {
        if (lazy[x] != 0) {
            tree[x] += (r - l) * lazy[x];
            if (l != r - 1) {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if (l >= R || r <= L) {
            return 0;
        }
        if (l >= L && r <= R) {
            return tree[x];
        }
        int mid = l + (r - l) / 2;
        return query(L, R, 2 * x + 1, l, mid) + query(L, R, 2 * x + 2, mid, r);
    }
 
    int query(int L, int R) {
        return query(L, R, 0, 0, sz);
    }
};
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(all(a));
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(all(b));
 
        vector<int> suf_l(n);
        for (int i = n - 2; i >= 0; i--) {
            suf_l[i] = a[i] <= b[i + 1];
            suf_l[i] += suf_l[i + 1];
        }
 
        vector<int> pref_r(n);
        for (int i = 1; i < n; i++) {
            pref_r[i] = a[i] <= b[i - 1];
            pref_r[i] += pref_r[i - 1];
        }
 
        // if we want to move index i to index j where i > j, a[i] <= b[i + 1] must be true for all indices [j, ..., i - 1].
        for (int i = 0; i < n; i++) {
            int l = -1, r = i;
            while (l + 1 < r) {
                int mid = l + (r - l) / 2;
                (suf_l[mid] - suf_l[i] == i - mid && b[mid] >= a[i] ? r : l) = mid;
            }
            cout << b[r] - a[i] << ' ';
        }
        cout << '\n';
 
        // if we want to move index i to index j where i < j, a[i] <= b[i - 1] must be true for all indices [i + 1, ..., j].
        for (int i = 0; i < n; i++) {
            int l = i, r = n;
            while (l + 1 < r) {
                int mid = l + (r - l) / 2;
                (pref_r[mid] - pref_r[i] == mid - i ? l : r) = mid;
            }
            cout << b[l] - a[i] << ' ';
        }
 
        cout << '\n';
    }
}