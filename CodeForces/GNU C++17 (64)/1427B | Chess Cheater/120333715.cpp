#include <bits/stdc++.h>
using namespace std;
 
void solve() {
 int n, k;
 string s;
 cin >> n >> k >> s;
 int ans = 0;
 vector<pair<int, pair<int, int>>> gaps;
 
 for (int i = 0; i < n; i++) {
  if (s[i] == 'W' && s[i + 1] != 'W') {
   for (int j = i + 2; j < n; j++) {
    if (s[j] == 'W') {
     gaps.push_back({j - i, {i, j}});
     i = j - 1;
     break;
    }
   }
  }
 }
 sort(gaps.begin(), gaps.end());
 for (int i = 0; i < gaps.size(); i++) {
  for (int j = gaps[i].second.first + 1; j < gaps[i].second.second; j++) {
   if (k == 0) break;
   s[j] = 'W';
   k--;
  }
 }
 
 for (int i = 0; i < n; i++) {
  if (k == 0) break;
  if (s[i] == 'L' &&  s[i - 1] == 'W') {
   s[i] = 'W';
   k--;
  }
 }
 for (int i = n; i >= 0; i--) {
  if (k == 0) break;
  if (s[i] == 'L' && s[i + 1] == 'W') {
   s[i] = 'W';
   k--;
  }
 }
 for (int i = 0; i < n; i++) {
  if (k == 0) break;
  if (s[i] == 'L') {
   s[i] = 'W';
   k--;
  }
 }
 for (int i = 0; i < n; i++) {
  if (s[i] == 'W') ans++;
  if (s[i] == 'W' && s[i - 1] == 'W') ans++;
 }
 cout << ans << '\n';
}
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  solve();
 }
}