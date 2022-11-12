#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.tie(0);
 cin.sync_with_stdio(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  if (is_sorted(a.begin(), a.end())) {
   cout << 0 << '\n';
  } else if(a[0] == n && a[n - 1] == 1) {
   cout << 3 << '\n';
  } else if (a[0] == n || a[n - 1] == 1 || (a[0] != 1 && a[n - 1] != n)) {
   cout << 2 << '\n';
  } else {
   cout << 1 << '\n';
  }
 }
}