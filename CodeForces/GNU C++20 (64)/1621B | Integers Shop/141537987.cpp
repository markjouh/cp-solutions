#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    // for the first set, we need a low left, then low cost, then high right.
    // for the second set, we need a high right, then low cost, then low left.
    // for the third set, we need a low left, then high right, then low cost.
    auto cmpl = [](const vector<int> a, const vector<int> b) {
      if (a[0] != b[0]) {
        return a[0] < b[0];
      }
      if (a[1] != b[1]) {
        return a[1] < b[1];
      }
      return a[2] > b[2];
    };
    set<vector<int>, bool(*)(const vector<int> a, const vector<int> b)> lst(cmpl);
    auto cmpr = [](const vector<int> a, const vector<int> b) {
      if (a[2] != b[2]) {
        return a[2] > b[2];
      }
      if (a[1] != b[1]) {
        return a[1] < b[1];
      }
      return a[0] < b[0];
    };
    set<vector<int>, bool(*)(const vector<int> a, const vector<int> b)> rst(cmpr);
    auto cmplr = [](const vector<int> a, const vector<int> b) {
      if (a[0] != b[0]) {
        return a[0] < b[0];
      }
      if (a[2] != b[2]) {
        return a[2] > b[2];
      }
      return a[1] < b[1];
    };
    set<vector<int>, bool(*)(const vector<int> a, const vector<int> b)> lrst(cmplr);
    for (int i = 0; i < n; i++) {
      int l, r, c;
      cin >> l >> r >> c;
      lst.insert({l, c, r});
      rst.insert({l, c, r});
      lrst.insert({l, c, r});
      auto lv = *lst.begin(), rv = *rst.begin(), lrv = *lrst.begin();
      int cost = lv[1]+rv[1];
      if (rv[0] >= lv[0] && rv[2] <= lv[2]) {
        cost = min(cost, lv[1]);
      }
      if (lv[0] >= rv[0] && lv[2] <= rv[2]) {
        cost = min(cost, rv[1]);
      }
      if (lrv[0] == lv[0] && lrv[2] == rv[2]) {
        cost = min(cost, lrv[1]);
      }
      cout << cost << '\n';
    }
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/