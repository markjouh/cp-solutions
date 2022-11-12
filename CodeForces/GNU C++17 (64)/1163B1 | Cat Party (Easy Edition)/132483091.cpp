#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 vector<int> cnt(10);
 int ans = 0;
 for (int i = 0; i < n; i++) {
  int color;
  cin >> color;
  cnt[color - 1]++;
  map<int, int> mp;
  for (int x : cnt) {
   if (x > 0) {
    mp[x]++;
   }
  }
  bool ok = false;
  ok |= mp.size() == 2 && mp.begin() -> first == 1 && mp.begin() -> second == 1;
  ok |= mp.size() == 2 && mp.begin() -> first + 1 == mp.rbegin() -> first && mp.rbegin() -> second == 1;
  bool flag = true;
  for (int x : cnt) {
   flag &= x < 2;
  }
  ok |= flag;
  int over0 = 0;
  for (int x : cnt) {
   over0 += x > 0;
  }
  ok |= over0 == 1;
  if (ok) {
   ans = i + 1;
  }
 }
 cout << ans << '\n';
}