#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
// if b becomes the complement of a, or if b becomes the same as a, we can always get them to both become 0
// from the samples, it looks like one of these conditions must be fufilled for the answer to be yes (I can't prove this)
 
// if b is the complement, take each 1 from a and perform the operation on [i, i]
// if b is the same, perform the operation on [1, n], then use the strategy above
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string a, b;
    cin >> n >> a >> b;
    
    bool comp = true;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        comp = false;
        break;
      }
    }
 
    if (!comp && a != b) {
      cout << "NO\n";
      continue;
    }
 
    cout << "YES\n";
    vector<pair<int, int>> ans;
    if (!comp) {
      ans.push_back({0, n - 1});
      for (int i = 0; i < n; i++) {
        a[i] = (a[i] == '0' ? '1' : '0');
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1') {
        cnt++;
        ans.push_back({i, i});
      }
    }
    if (cnt % 2 == 0) {
      ans.push_back({0, 0});
      ans.push_back({1, n - 1});
      ans.push_back({0, n - 1});
    }
    cout << ans.size() << '\n';
    for (auto [f, s] : ans) {
      cout << f + 1 << ' ' << s + 1 << '\n';
    }
  }
}