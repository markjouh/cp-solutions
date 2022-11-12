#include <bits/stdc++.h>
using namespace std;
 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<array<int, 3>> ranges;
    for (int i = 0; i < n; i++) {
      int lo, hi;
      int l = 0, r = n;
      while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        ((i + 1) / mid <= b[i] ? r : l) = mid; 
      }
      lo = r;
      l = 1, r = n + 1;
      while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        ((i + 1) / mid >= b[i] ? l : r) = mid;
      }
      hi = l;
      ranges.push_back({lo, hi, i});
    }
    sort(all(ranges));
    reverse(all(ranges));
    set<pair<int, int>> ends;
    vector<int> res(n, -1);
    for (int i = 1; i <= n; i++) {
      while (sz(ranges) && ranges.back()[0] == i) {
        ends.insert({ranges.back()[1], ranges.back()[2]});
        ranges.pop_back();
      }
      int id = (*ends.begin()).second;
      ends.erase(ends.begin());
      res[id] = i;
    }
    for (int i = 0; i < n; i++) {
      cout << res[i] << ' ';
    }
    cout << '\n';
  }
}
 