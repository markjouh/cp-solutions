#include <bits/stdc++.h>
using namespace std;
 
int arr[400005];
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  arr[0] = 0;
  arr[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
   cin >> arr[i];
  }
  long long ans = 0;
  for (int i = 1; i < n + 2; i++) {
   ans += abs(arr[i] - arr[i - 1]);
   ans -= max(0, arr[i] - max(arr[i - 1], arr[i + 1]));
  }
  cout << ans << '\n';
 }
}