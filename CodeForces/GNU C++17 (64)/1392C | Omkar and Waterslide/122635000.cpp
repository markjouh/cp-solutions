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
  int arr[n];
  for (int &x : arr) {
   cin >> x;
  }
  long long ans = 0;
  for (int i = 1; i < n; i++) {
   int diff = arr[i - 1] - arr[i];
   if (diff > 0) {
    ans += diff;
   }
  }
  cout << ans << '\n';
 }
}