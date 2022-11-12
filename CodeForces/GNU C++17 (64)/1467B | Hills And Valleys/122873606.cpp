#include <bits/stdc++.h>
using namespace std;
 
int n;
int a[300000], b[300000];
 
inline int score(int i) {
 if (i <= 0 || i >= n - 1) {
  return 0;
 }
 return (a[i] < a[i - 1] && a[i] < a[i + 1]) || (a[i] > a[i - 1] && a[i] > a[i + 1]);
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  cin >> n;
  for (int i = 0; i < n; i++) {
   cin >> a[i];
   b[i] = 0;
  }
  int sum = 0, ans;
  for (int i = 1; i < n - 1; i++) {
   if (score(i)) {
    sum++;
    b[i] = 1;
   }
  }
  ans = sum;
  for (int i = 1; i < n - 1; i++) {
   int keep = a[i], rem = b[i - 1] + b[i] + b[i + 1];
   a[i] = a[i - 1];
   ans = min(ans, sum - rem + score(i - 1) + score(i) + score(i + 1));
   a[i] = a[i + 1];
   ans = min(ans, sum - rem + score(i - 1) + score(i) + score(i + 1));
   a[i] = keep;
  }
  cout << ans << '\n';
 }
}