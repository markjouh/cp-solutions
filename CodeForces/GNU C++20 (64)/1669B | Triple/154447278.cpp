#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mp[x]++;
    }
    vector<pair<int, int>> flip;
    for (auto [f, s] : mp) {
      flip.push_back({s, f});
    }
    sort(flip.begin(), flip.end());
    cout << (flip.back().first < 3 ? -1 : flip.back().second) << '\n';
  }
}