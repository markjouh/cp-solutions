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
  sort(a.rbegin(), a.rend());
  ll sum = 0;
  for (int i = 0; i < n; i++) {
   if (i % 2 == 0 && a[i] % 2 == 0) {
    sum += a[i];
   } else if (i % 2 && a[i] % 2) {
    sum -= a[i];
   }
  }
  cout << (sum == 0 ? "Tie" : (sum > 0 ? "Alice" : "Bob")) << '\n';
 }
}