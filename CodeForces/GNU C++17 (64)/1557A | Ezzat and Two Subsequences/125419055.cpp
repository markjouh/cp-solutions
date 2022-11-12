#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  int mx = *max_element(a.begin(), a.end());
  double res = (accumulate(a.begin(), a.end(), 0ll) - mx) / (double)(n - 1);
  cout << setprecision(9) << fixed << mx + res << '\n';
 }
}