#include <bits/stdc++.h>
using namespace std;
 
int psum(int x) {
 int res = 0;
 for (int i = 1; i < x; i++) res += i;
 return res;
}
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &x : v) cin >> x;
  map<int, int> res;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
   ans += res[v[i] - i - 1];
   res[v[i] - i - 1]++;
  }
  cout << ans << '\n';
 }
}