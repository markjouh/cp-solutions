#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
 
struct segtree {
  int sz;
  vector<int> t;
 
  void init(int n) {
    sz = 1;
    while (sz < n) {
      sz *= 2;
    }
    t.resize(2 * sz);
  }
 
  void upd(int i, int v, int x, int l, int r) {
    if (l + 1 == r) {
      t[x] += v; // Apply difference instead of overwriting
      return;
    }
    int mid = l + (r - l) / 2;
    if (i < mid) {
      upd(i, v, 2 * x + 1, l, mid);
    } else {
      upd(i, v, 2 * x + 2, mid, r);
    }
    t[x] = t[2 * x + 1] + t[2 * x + 2];
  }
 
  void upd(int i, int v) {
    upd(i, v, 0, 0, sz);
  }
 
  void build(vector<int> &a, int x, int l, int r) {
    if (l + 1 == r) {
      if (l < (int)a.size()) {
        t[x] = a[l];
      }
      return;
    }
    int mid = l + (r - l) / 2;
    build(a, 2 * x + 1, l, mid);
    build(a, 2 * x + 2, mid, r);
    t[x] = t[2 * x + 1] + t[2 * x + 2];
  }
 
  void build(vector<int> &a) {
    build(a, 0, 0, sz);
  }
 
  int query(int l, int r, int x, int lx, int rx) {
    if (lx >= r || rx <= l) {
      return 0;
    }
    if (lx >= l && rx <= r) {
      return t[x];
    }
    int mid = lx + (rx - lx) / 2;
    return query(l, r, 2 * x + 1, lx, mid) + query(l, r, 2 * x + 2, mid, rx);
  }
 
  int query(int l, int r) {
    return query(l, r, 0, 0, sz);
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b = a;
  sort(all(b));
  b.resize(unique(all(b)) - b.begin()); 
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(all(b), a[i]) - b.begin();
  }
  segtree pref, suf;
  pref.init(sz(b));
  suf.init(sz(b));
  long long cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    cnt += suf.query(0, a[i]);
    suf.upd(a[i], 1);
  }
  long long ans = 0;
  int l = 0;
  for (int r = 0; r < n; r++) {
    while (l < r) {
      int increase = pref.query(a[l] + 1, sz(b)) + suf.query(0, a[l]);
      if (cnt + increase <= k) {
        cnt += increase;
        pref.upd(a[l], 1);
        l++;
      } else {
        break;
      }
    }
    ans += l;
    cnt -= pref.query(a[r] + 1, sz(b)) + suf.query(0, a[r]);
    suf.upd(a[r], -1);
  } 
  cout << ans;
}