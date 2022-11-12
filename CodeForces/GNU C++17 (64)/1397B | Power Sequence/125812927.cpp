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
 sort(a.begin(), a.end());
 ll ans = LLONG_MAX;
 for (int i = 1; i <= a[n - 1]; i++) {
  ll cur = 0;
  for (int j = 0; j < n; j++) {
   cur += abs(a[j] - pow(i, j));
  }
  if (cur >= 0 && cur < ans) {
   ans = cur;
  } else {
   break;
  }
 }
 cout << ans << '\n';
}