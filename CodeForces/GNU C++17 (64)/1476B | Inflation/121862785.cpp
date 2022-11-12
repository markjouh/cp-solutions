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
  long long x = 0, sum = arr[0];
  for (int i = 1; i < n; i++) {
   x = max(x, (100ll * arr[i] - k * sum + k - 1) / k);
   sum += arr[i];
  }
  cout << x << '\n';
 }
}