#include <bits/stdc++.h>
using namespace std;
 
double miners[1000000], diamonds[1000000];
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  int idx_m = 0, idx_d = 0;
  for (int i = 0; i < n * 2; i++) {
   int a, b;
   cin >> a >> b;
   a = abs(a);
   b = abs(b);
   if (a == 0) {
    miners[idx_m] = b;
    idx_m++;
   } else {
    diamonds[idx_d] = a;
    idx_d++;
   }
  }
  sort(miners, miners + n);
  sort(diamonds, diamonds + n);
  long double ans = 0;
  for (int i = 0; i < n; i++) {
   ans += sqrt(pow(miners[i], 2) + pow(diamonds[i], 2));
  }
  cout << fixed << setprecision(15) << ans << '\n';
 }
}