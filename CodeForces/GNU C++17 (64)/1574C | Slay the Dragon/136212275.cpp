#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 long long sum = 0;
 vector<long long> str(n);
 for (long long& x : str) {
  cin >> x;
  sum += x;
 }
 int m;
 cin >> m;
 vector<long long> def(m), att(m);
 for (int i = 0; i < m; ++i) {
  cin >> def[i] >> att[i];
 }
 sort(str.begin(), str.end());
 for (int i = 0; i < m; ++i) {
  int l = 0, r = n;
  while (l + 1 < r) {
   int mid = l + (r - l) / 2;
   if (str[mid] <= def[i]) {
    l = mid;
   } else {
    r = mid;
   }
  }
  long long ans = max(0ll, def[i] - str[l]) + max(0ll, att[i] - sum + str[l]);
  l = -1; r = n - 1;
  while (l + 1 < r) {
   int mid = l + (r - l) / 2;
   if (str[mid] >= def[i]) {
    r = mid;
   } else {
    l = mid;
   }
  }
  ans = min(ans, max(0ll, def[i] - str[r]) + max(0ll, att[i] - sum + str[r]));
  cout << ans << '\n';
 }
}