#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
bool sorted(vector<int> a) {
 for (int i = 1; i < sz(a); i++) {
  if (a[i] < a[i - 1]) {
   return false;
  }
 }
 return true;
}
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int T; cin >> T;
 while (T--) {
  int n; cin >> n;
  vector<int> a(n);
  for (int &x : a) {
   cin >> x;
  }
  if (sorted(a)) {
   cout << 0 << '\n';
   continue;
  }
  if (a[n - 2] > a[n - 1] || a[n - 2] - a[n - 1] > a[n - 2]) {
   cout << -1 << '\n';
   continue;
  }
  vector<int> ans;
  for (int i = n - 3; i >= 0; i--) {
   ans.push_back(i + 1);
  }
  cout << sz(ans) << '\n';
  for (int x : ans) {
   cout << x << ' ' << n - 1 << ' ' << n << '\n';
  }
 }
}
 