#include <bits/stdc++.h>
using namespace std;
 
int arr[10];
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  long long n, m, ans = 0;
  cin >> n >> m;
  n /= m;
  for (int i = 0; i < 10; i++) {
   arr[i] = (i + 1) * m % 10;
  }
  for (int i = 0; i < n % 10; i++) {
   ans += arr[i];
  }
  ans += n / 10 * accumulate(arr, arr + 10, 0LL);
  cout << ans << '\n';
 }
}
 