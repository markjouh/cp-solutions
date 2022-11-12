#include <bits/stdc++.h>
using namespace std;
 
int arr[100];
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }
  if (n * *max_element(arr, arr + n) < k) {
   cout << -1 << '\n';
   continue;
  }
  int ans = -1;
  for (int i = 0; i < k; i++) {
   int cur = -1;
   for (int j = 0; j < n - 1; j++) {
    if (arr[j] < arr[j + 1]) {
     cur = j;
     arr[j]++;
     break;
    }
   }
   ans = cur + (cur != -1);
   if (cur == -1) break;
  }
  cout << ans << '\n';
 }
}