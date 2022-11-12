#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 cin >> n;
 map<int, int> pos, mp;
 for (int i = 0; i < n; i++) {
  int x;
  cin >> x;
  pos[x] = i;
 }
 for (int i = 0; i < n; i++) {
  int x;
  cin >> x;
  mp[pos[x] - i]++;
  mp[n - i + pos[x]]++;
  mp[-(i + n - pos[x])]++;
 }
 int hi = 0;
 for (auto [x, y] : mp) {
  if (y > hi) {
   hi = y;
  }
 }
 cout << hi << '\n';
}