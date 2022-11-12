#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> a(n), b(n);
 for (int &x : a) {
  cin >> x;
 }
 for (int &x : b) {
  cin >> x;
 }
 map<int, int> mp;
 for (int i = 0; i < n; i++) {
  mp[b[i]] = i;
 }
 vector<int> c(n);
 for (int i = 0; i < n; i++) {
  c[i] = mp[a[i]];
 }
 int mx = 0, ans = 0;
 for (int i = 0; i < n; i++) {
  ans += c[i] < mx;
  mx = max(mx, c[i]);
 }
 cout << ans << '\n';
}