#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int t;
  cin >> t;
  if (t > 45) {
   cout << -1 << '\n';
   continue;
  }
  string s;
  vector<int> a(9);
  int sum = 0;
  iota(a.begin(), a.end(), 1);
  reverse(a.begin(), a.end());
  while (sum < t) {
   for (int &x : a) {
    if (x <= t - sum && x != -1) {
     s += to_string(x);
     sum += x;
     x = -1;
    }
   }
  }
  sort(s.begin(), s.end());
  cout << s << '\n';
 }
}