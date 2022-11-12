#include <bits/stdc++.h>
using namespace std;
 
int q(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  int res;
  cin >> res;
  return res;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int l = 1, r = n;
  map<pair<int, int>, int> mp;
  while (l+1 < r) {
    int mid = l+(r-l)/2;
    int full = (mp.count({l,r}) ? mp[{l, r}] : q(l,r));
    mp[{l,r}] = full;
    if (full <= mid) {
      int left = q(l,mid);
      mp[{l,mid}] = left;
      (left == full ? r : l) = mid;
    } else {
      int right = q(mid,r);
      mp[{mid,r}] = right;
      (right == full ? l : r) = mid;
    }
  }
  int ans = q(l,r) == l ? r : l;
  cout << "! " << ans << endl;
}