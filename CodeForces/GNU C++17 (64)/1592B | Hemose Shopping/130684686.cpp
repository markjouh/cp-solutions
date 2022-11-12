#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, x;
  cin >> n >> x;
  vector<int> arr(n), sorted;
  for (int &x : arr) {
   cin >> x;
  }
  sorted = arr;
  sort(sorted.begin(), sorted.end());
  bool ok = true;
  for (int i = 0; i < n; i++) {
   if (arr[i] != sorted[i] && i - x < 0 && i + x >= n) {
    ok = false;
   }
  }
  cout << (ok ? "YES" : "NO") << '\n';
 }
}