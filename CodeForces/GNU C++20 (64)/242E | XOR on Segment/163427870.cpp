#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
 
struct segtree {
  int sz;
  vector<int> tree;
  vector<int> lazy; // Flips in the current segment
 
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
      if (l < sz(a)) {
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
 
  void update(int L, int R, int x, int l, int r) {
    if (lazy[x] != 0) {
      tree[x] = (r - l) - tree[x];
      if (l != r - 1) {
        lazy[2 * x + 1] ^= 1;
        lazy[2 * x + 2] ^= 1;
      }
      lazy[x] = 0;
    }
    if (l >= R || r <= L) {
      return;
    }
    if (l >= L && r <= R) {
      tree[x] = (r - l) - tree[x];
      if (l != r - 1) {
        lazy[2 * x + 1] ^= 1;
        lazy[2 * x + 2] ^= 1;
      }
      return;
    }
    int mid = l + (r - l) / 2;
    update(L, R, 2 * x + 1, l, mid);
    update(L, R, 2 * x + 2, mid, r);
    tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
  }
 
  void update(int L, int R) {
    update(L, R, 0, 0, sz);
  }
 
  int query(int L, int R, int x, int l, int r) {
    if (lazy[x] != 0) {
      tree[x] = (r - l) - tree[x];
      if (l != r - 1) {
        lazy[2 * x + 1] ^= 1;
        lazy[2 * x + 2] ^= 1;
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
  int n;
  cin >> n;
  vector<vector<int>> on(20, vector<int>(n));
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int bit = 0; bit < 20; bit++) {
      on[bit][i] = (x >> bit) & 1;
    }
  }
  vector<segtree> st(20);
  for (int i = 0; i < 20; i++) {
    st[i].init(n);
    st[i].build(on[i]);
  }
  int m;
  cin >> m;
  while (m--) {
    int op, l, r;
    cin >> op >> l >> r;
    l--;
    if (op == 1) {
      long long ans = 0;
      for (int i = 0; i < 20; i++) {
        ans += (1ll << i) * st[i].query(l, r);
      }
      cout << ans << '\n';
    } else {
      int x;
      cin >> x;
      for (int i = 0; i < 20; i++) {
        if ((x >> i) & 1) {
          st[i].update(l, r);
        }
      }
    }
  }
}
 