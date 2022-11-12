#include <bits/stdc++.h>
using namespace std;
 
int arr[2000000];
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }
  sort(arr, arr + n);
  int size = 0, mx = 0, ans = 0;
  for (int i = 0; i < n; i++) {
   mx = max(mx, arr[i]);
   size++;
   if (size >= mx) {
    size = 0;
    mx = 0;
    ans++;
   }
  }
  cout << ans << '\n';
 }
}