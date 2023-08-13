// Problem: E. String Reversal
// Contest: Codeforces - Educational Codeforces Round 96 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1430/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
 
// we never swap equal adjacent elements, so the first 'a' in s will be the first 'a' in r, etc
// the # of swaps to turn s -> r are the same as r -> s
// find the position that each character of s ends up in
// the number of swaps needed is the number of inversions
// we can count this with a segtree or indexed set
 
const int MXN = 2e5;
 
int tree_sz;
int tree[4 * MXN];
 
void update(int i, int v, int x = 0, int tl = 0, int tr = tree_sz) {
  if (tl + 1 == tr) {
    tree[x] = v;
    return;
  }
  int mid = tl + (tr - tl) / 2;
  if (i < mid) {
    update(i, v, 2 * x + 1, tl, mid);
  } else {
    update(i, v, 2 * x + 2, mid, tr);
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
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  string s;
  cin >> n >> s;
  vector<vector<int>> ind_s(26), ind_r(26);
  for (int i = 0; i < n; i++) {
    ind_s[s[i] - 'a'].push_back(i);
    ind_r[s[n - i - 1] - 'a'].push_back(i);
  }
  vector<int> p(n);
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < (int)ind_s[i].size(); j++) {
      p[ind_s[i][j]] = ind_r[i][j];
    }
  }
  tree_sz = 1;
  while (tree_sz < n) {
    tree_sz *= 2;
  }
  fill(tree, tree + 2 * tree_sz, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += query(p[i] + 1, tree_sz);
    update(p[i], 1);
  }
  cout << ans << '\n';
}