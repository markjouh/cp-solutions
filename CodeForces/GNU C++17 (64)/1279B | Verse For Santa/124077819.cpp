#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  if (s >= accumulate(a.begin(), a.end(), 0LL)) {
   cout << 0 << '\n';
   continue;
  }
  int pos = 0;
  for (int i = 0; i < n; i++) {
   s -= a[i];
   pos = i;
   if (s < 0) {
    break;
   }
  }
  cout << max_element(a.begin(), a.begin() + pos + 1) - a.begin() + 1 << '\n';
 }
}