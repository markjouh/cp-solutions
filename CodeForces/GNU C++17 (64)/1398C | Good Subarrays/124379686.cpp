#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  string s;
  cin >> n >> s;
  map<int, int> mp;
  mp[0]++;
  ll sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
   sum += s[i] - '0';
   ans += mp[sum - i - 1];
   mp[sum - i - 1]++;
  }
  cout << ans << '\n';
 }
}