#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  int prefix = 0, suffix = n - 1;
  for (int i = 1; i < n; i++) {
   if (a[i] >= i) {
    prefix++;
   } else break;
  }
  for (int i = 0; i < n; i++) {
   if (a[n - i - 1] >= i) {
    suffix--;
   } else break;
  }
  cout << (prefix > suffix ? "YES" : "NO") << '\n'; 
 }
}