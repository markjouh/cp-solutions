#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int n, k;
 cin >> n >> k;
 vector<int> arr(n);
 for (int i = 0; i < n; i++) {
  cin >> arr[i];
 }
 sort(arr.begin(), arr.end());
 int ans = n;
 for (int i = 0; i < n; i++) {
  auto it = upper_bound(arr.begin(), arr.end(), arr[i]);
  if (it != arr.end() && *it <= arr[i] + k) {
   ans--;
  }
 }
 cout << ans << '\n';
}