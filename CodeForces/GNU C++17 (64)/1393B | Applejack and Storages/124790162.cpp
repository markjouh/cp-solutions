#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.tie(0);
 cin.sync_with_stdio(0);
 int n;
 cin >> n;
 map<int, int> mp;
 int cnt2 = 0, cnt4 = 0;
 for (int i = 0; i < n; i++) {
  int x;
  cin >> x;
  cnt2 -= mp[x] / 2;
  cnt4 -= mp[x] / 4;
  mp[x]++;
  cnt2 += mp[x] / 2;
  cnt4 += mp[x] / 4;
 }
 int q;
 cin >> q;
 while (q--) {
  char c;
  int x;
  cin >> c >> x;
  cnt2 -= mp[x] / 2;
  cnt4 -= mp[x] / 4;
  mp[x] += (c == '+' ? 1 : -1);
  cnt2 += mp[x] / 2;
  cnt4 += mp[x] / 4;
  cout << (cnt2 >= 4 && cnt4 ? "YES" : "NO") << '\n';
 }
}