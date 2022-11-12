#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n, m;
 cin >> n >> m;
 vector<int> b(n), g(m);
 int mxb = -1, smxb = -1;
 for (int &x : b) {
  cin >> x;
  if (x > mxb) {
   smxb = mxb;
   mxb = x;
  } else if (x > smxb) {
   smxb = x;
  }
 }
 int mng = 1e9;
 for (int &x : g) {
  cin >> x;
  mng = min(mng, x);
 }
 if (mxb > mng) {
  cout << -1 << '\n';
  return 0;
 }
 long long ans = 1ll * accumulate(b.begin(), b.end(), 0ll) * m;
 for (int x : g) {
  ans += x - mxb; 
 }
 if (mng > mxb) {
  ans += mxb - smxb;
 }
 cout << ans << '\n';
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 