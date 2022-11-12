#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> heights(n);
 for (int& x : heights) {
  cin >> x;
 }
 ll best = 0;
 vector<int> ans(n);
 for (int i = 0; i < n; ++i) {
  ll cur = heights[i];
  vector<int> res(n);
  res[i] = heights[i];
  for (int j = i - 1; j >= 0; --j) { 
   res[j] = min(res[j + 1], heights[j]); 
   cur += res[j];
  }
  for (int j = i + 1; j < n; ++j) { 
   res[j] = min(res[j - 1], heights[j]);
   cur += res[j];
  }
  if (cur > best) {
   best = cur;
   ans = res;
  }
 }
 for (int x : ans) {
  cout << x << ' ';
 }
} 