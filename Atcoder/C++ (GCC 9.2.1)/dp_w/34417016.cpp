#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const long long INF = 0x3f3f3f3f3f3f3f3f;

template<class T> struct segtree {
    int sz; vector<T> st, lz;

    T comb(T a, T b) {
        return max(a, b);
    }
    void init(int n) {
        sz = 1; while (sz < n) sz <<= 1;
        st.assign(2 * sz, 0), lz.assign(2 * sz, 0);
    }
    void pull(int i) {
        st[i] = comb(st[i << 1], st[i << 1 | 1]);
    }
    void push(int i, int l, int r) {
        st[i] += lz[i];
        if (l != r) lz[i << 1] += lz[i], lz[i << 1 | 1] += lz[i];
        lz[i] = 0;
    }
    void update(int ql, int qr, T x, int i, int l, int r) {
        push(i, l, r); if (ql > r || qr < l) return;
        if (ql <= l && qr >= r) { lz[i] += x; return void(push(i, l, r)); }
        int m = (l + r) >> 1; update(ql, qr, x, i << 1, l, m);
        update(ql, qr, x, i << 1 | 1, m + 1, r); pull(i);
    }
    void update(int ql, int qr, T x) {
        update(ql, qr, x, 1, 0, sz - 1);
    }
    T query(int ql, int qr, int i, int l, int r) {
        push(i, l, r); if (ql > r || qr < l) return -INF;
        if (ql <= l && qr >= r) return st[i]; int m = (l + r) >> 1;
        return comb(query(ql, qr, i << 1, l, m), query(ql, qr, i << 1 | 1, m + 1, r));
    }
    T query(int ql, int qr) {
        return query(ql, qr, 1, 0, sz - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> todo(2 * m);
    for (int i = 0; i < 2 * m; i += 2) {
        int l, r, x;
        cin >> l >> r >> x;
        todo[i] = {l, l - 1, x};
        todo[i + 1] = {r + 1, l - 1, -x};
    }
    sort(all(todo));
    
    int pt = 0;
    segtree<ll> st;
    st.init(n + 1);
    for (int i = 1; i <= n + 1; i++) {
        while (pt < 2 * m && todo[pt][0] == i) {
            st.update(0, todo[pt][1], todo[pt][2]);
            pt++;
        }
        st.update(i, i, st.query(0, i - 1));
    }
    cout << st.query(0, n) << '\n';
}