#include <bits/stdc++.h>
using namespace std;
 
string cc(char a, char b) {
  string s;
  s += a;
  s += b;
  return s;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  unordered_map<string, int> mp;
  string res = "a";
  for (int i = 0; i < n-1; i++) {
    int mn = 1e9;
    char mnc = 'a';
    for (char c = 'a'; c <= 'a'+k-1; c++) {
      int cur = mp[cc(res.back(), c)];
      if (cur <= mn) {
        mn = cur;
        mnc = c;
      }
    }
    mp[cc(res.back(), mnc)]++;
    res += mnc;
  }
  cout << res << '\n';
}