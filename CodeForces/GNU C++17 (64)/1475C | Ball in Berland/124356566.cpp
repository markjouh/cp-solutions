#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int A, B, k;
  cin >> A >> B >> k;
  vector<int> a(k), b(k);
  for (int &x : a) {
   cin >> x;
  }
  for (int &x : b) {
   cin >> x;
  }
  ll cnt = 0, ans = 0;
  map<int, int> aused, bused;
  for (int i = 0; i < k; i++) {
   ans += cnt - aused[a[i]] - bused[b[i]];
   aused[a[i]]++;
   bused[b[i]]++;
   cnt++;
  }
  cout << ans << '\n';
 }
}