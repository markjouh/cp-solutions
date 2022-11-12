#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully!
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  vector<int> done(n+1);
  for (auto &x : a) {
   if (x <= n && !done[x]) {
    done[x] = true;
    x = -1;
   }
  }
  a.erase(remove(a.begin(), a.end(), -1), a.end());
  sort(a.begin(), a.end());
  bool ok = true;
  int id = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
   if (!done[i]) {
    ok &= a[id++] > i*2;
    ans++;
   }
  }
  cout << (ok ? ans : -1) << '\n';
 }
}