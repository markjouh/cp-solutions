#include "bits/stdc++.h"
 
using namespace std;
 
#define int int64_t
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) { 
    int n;
    cin >> n;
    vector<pair<int ,int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i].second >= a[j].first) {
          b.push_back({max(a[i].second, a[j].second), a[i].first});
        }
      }
    }
    sort(b.begin(), b.end());
    int pairs = 0, r = -1;
    for (int i = 0; i < (int)b.size(); i++) {
      if (b[i].second > r) {
        pairs++;
        r = b[i].first;
      }
    }
    cout << n - 2 * pairs << '\n';
  }
}