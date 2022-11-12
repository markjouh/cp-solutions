#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n, k; cin >> n >> k;
 vector<int> a(n);
 for (int &x : a) {
  cin >> x;
 }
 sort(all(a), greater<int>());
 a.push_back(-1);
 vector<pair<int, int>> b;
 int val = a[0], ct = 1;
 for (int i = 1; i < sz(a); i++) {
  if (a[i] != val) {
   b.push_back({val, ct});
   val = a[i];
   ct = 0;
  }
  ct++;
 }
 for (int i = 1; i < sz(b); i++) {
  b[i].second += b[i - 1].second;
 }
 vector<int> layers;
 for (int i = 0; i < sz(b) - 1; i++) {
  for (int j = 0; j < b[i].first - b[i + 1].first; j++) {
   layers.push_back(b[i].second);
  }
 }
 int bal = 0, ans = 0;
 for (int x : layers) {
  if (x > bal) {
   bal = k;
   ans++;
  }
  bal -= x;
 }
 cout << ans << '\n';
}