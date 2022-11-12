#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
struct segtree {
  int sz;
  vector<ll> tree;
 
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
    build(a, 0, 0, sz);
  }
 
  long long query(int L, int R, int x, int l, int r) {
    if (l >= R || r <= L) {
      return 0;
    }
    if (l >= L && r <= R) {
      return tree[x];
    }
    int mid = l + (r - l) / 2;
    return max(query(L, R, 2 * x + 1, l, mid), query(L, R, 2 * x + 2, mid, r));
  }
 
  long long query(int l, int r) {
    return query(l, r, 0, 0, sz);
  }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    segtree st;
    st.init(m);
    st.build(a);
    int q;
    cin >> q;
    while (q--) {
        int sr, sc, fr, fc, k;
        cin >> sr >> sc >> fr >> fc >> k;
 
        if (abs(sr - fr) % k || abs(sc - fc) % k) {
          cout << "NO\n";
          continue;
        }
 
        int ceil = sr + (n - sr) / k * k;
 
        if (sc > fc) {
          swap(sc, fc);
        }
 
        cout << (st.query(sc - 1, fc) < ceil ? "YES\n" : "NO\n");
    }
}