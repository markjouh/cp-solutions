#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> a(n);
 for (int &x : a) {
  cin >> x;
 }
 int ans = 0;
 ll sum = 0;
 set<ll> s;
 s.insert(0);
 for (int i = 0; i < n; i++) {
  sum += a[i];
  if (s.count(sum)) {
   ans++;
   s.clear();
   s.insert(0);
   sum = a[i];
  }
  s.insert(sum);
 }
 cout << ans << '\n';
}