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
    ll ans = 0;
    map<char, int> first, second;
    map<string, int> both;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      ans += first[s[0]] + second[s[1]] - both[s] * 2;
      first[s[0]]++;
      second[s[1]]++;
      both[s]++;
    }
    cout << ans << '\n';
  }
}