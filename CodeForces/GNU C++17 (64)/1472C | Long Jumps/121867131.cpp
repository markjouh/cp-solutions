#include <bits/stdc++.h>
using namespace std;
 
int arr[200000];
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
   cin >> arr[i];
  }
  int dp[n];
  for (int i = n - 1; i >= 0; i--) {
   dp[i] = arr[i];
   int j = i + arr[i];
   if (j < n) {
    dp[i] += dp[j];
   }
  }
  cout << *max_element(dp, dp + n) << '\n';
 }
}