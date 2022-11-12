#include <bits/stdc++.h>
using namespace std;
 
long long arr[100000];
 
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
  sort(arr, arr + n);
  long long sum = 0, last = 0, ans = 0;
  for (long long i = 0; i < n; i++) {
   ans -= arr[i] * (i - 1) - sum;
   sum += last;
   last = arr[i];
  }
  cout << ans << '\n';
 }
}