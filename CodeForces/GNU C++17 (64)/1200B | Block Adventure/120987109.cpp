#include <bits/stdc++.h>
using namespace std;
 
int arr[100];
 
void solve() {
 int n, m, k;
 cin >> n >> m >> k;
 for (int i = 0; i < n; i++) {
  cin >> arr[i];
 }
 for (int i = 0; i < n - 1; i++) {
  int target = max(0, arr[i + 1] - k);
  if (target < arr[i]) {
   m += arr[i] - target;
  } else if (target - arr[i] > m) {
   cout << "NO" << '\n';
   return;
  } else {
   m -= target - arr[i];
  }
 }
 cout << "YES" << '\n';
}
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  solve();
 }
}
 
/*
1
10 50 160
319 47 107 192 866 475 139 594 636 345
*/