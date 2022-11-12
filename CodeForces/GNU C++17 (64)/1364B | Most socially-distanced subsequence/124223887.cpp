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
  vector<int> a(n), b(n);
  for (int &x : a) {
   cin >> x;
  }
  int cnt = 0;
  for (int i = 1; i < n - 1; i++) {
   if ((a[i] > a[i - 1]) != (a[i] > a[i + 1])) {
    b[i] = 1;
    cnt++;
   }
  }
  cout << n - cnt << '\n';
  for (int i = 0; i < n; i++) {
   if (!b[i]) {
    cout << a[i] << ' ';
   }
  }
  cout << '\n';
 }
}