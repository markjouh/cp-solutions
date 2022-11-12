#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n, m;
 cin >> n;
 vector<int> a(n);
 for (int &x : a) {
  cin >> x;
 }
 cin >> m;
 vector<int> b(m);
 for (int &x : b) {
  cin >> x;
 }
 if (accumulate(a.begin(), a.end(), 0ll) != accumulate(b.begin(), b.end(), 0ll)) {
  cout << -1 << '\n';
  return 0;
 } 
 int ida = 0, idb = 0, ans = 0;
 long long suma = 0, sumb = 0;
 while (ida < n || idb < m) {
  if (suma <= sumb) {
   suma += a[ida++];
   while (suma < sumb) {
    suma += a[ida++];
   }
  } else {
   sumb += b[idb++];
   while (sumb < suma) {
    sumb += b[idb++];
   }
  }
  ans += suma == sumb;
 }
 cout << ans << '\n';
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/