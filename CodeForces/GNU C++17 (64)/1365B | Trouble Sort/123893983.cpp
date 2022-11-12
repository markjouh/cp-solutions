#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
   int x;
   cin >> x;
   sum += x;
  }
  cout << (is_sorted(a.begin(), a.end()) || (sum != 0 && sum != n) ? "YES" : "NO") << '\n';
 }
}