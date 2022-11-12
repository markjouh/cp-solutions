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
  cout << (a[0] < a[n - 1] ? "YES" : "NO") << '\n';
 }
}