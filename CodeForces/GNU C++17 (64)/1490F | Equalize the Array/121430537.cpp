#include <bits/stdc++.h>
using namespace std;
 
void run_case() {
 int n;
 cin >> n;
 map<int, int> m;
 for (int i = 0; i < n; i++) {
  int a; 
  cin >> a;
  m[a]++;
 }
 vector<int> cnt;
 for (auto x : m) {
  cnt.emplace_back(x.second);
 }
 sort(cnt.begin(), cnt.end());
 int best = n;
 for (int i = 0; i < cnt.size(); i++) {
  int cur = n - (cnt.size() - i) * cnt[i];
  best = min(best, cur);
 }
 cout << best << '\n';
}
 
int main() {
 cin.sync_with_stdio(0);
 cin.tie(0);
 int t;
 cin >> t;
 while (t--) {
  run_case();
 }
}