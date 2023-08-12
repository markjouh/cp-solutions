#include "bits/stdc++.h"

using namespace std;

#define int long long

// each item can handle at most one coupon
// thus, if it is possible to take the highest discount coupon at some state, we always do it
// there is no benifit in saving the item for something better (it can't exist)

// what do we do when two items tie for discount, though?
// idk, I have no time to prove
// let's just submit twice and hope one ACs

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int sum = 0;
  multiset<int> p;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum += x;
    p.insert(x);
  }
  vector<int> l(m);
  for (int i = 0; i < m; i++) {
    cin >> l[i];
  }
  vector<int> d(m);
  for (int i = 0; i < m; i++) {
    cin >> d[i];
  }
  vector<pair<int, int>> coupons(m);
  for (int i = 0; i < m; i++) {
    coupons[i] = {d[i], l[i]};
  }
  sort(coupons.rbegin(), coupons.rend());
  int dis = 0;
  for (int i = 0; i < m; i++) {
    auto lb = p.lower_bound(coupons[i].second);
    if (lb != p.end()) {
      dis += coupons[i].first;
      p.erase(lb);
    }
  }
  cout << sum - dis << '\n';
}
