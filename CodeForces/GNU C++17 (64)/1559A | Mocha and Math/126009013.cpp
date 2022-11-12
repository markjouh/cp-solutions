#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
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
  for (int i = 1; i < n; i++) {
   a[i] = a[i] & a[i - 1];
  }
  cout << a[n - 1] << '\n';
 }
}