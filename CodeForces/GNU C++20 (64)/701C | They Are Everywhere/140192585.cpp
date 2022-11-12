#include <bits/stdc++.h>
using namespace std;
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int n;
 string s;
 cin >> n >> s;
 
 set<char> sc;
 for (char c : s) {
  sc.insert(c);
 }
 int all = sc.size();
 
 map<char, int> mp;
 int l = 0, r = 0, ct = 0, best = 1e9;
 while (l < n) {
  while (ct < all && r < n) {
   mp[s[r]]++;
   if (mp[s[r]] == 1) {
    ct++;
   }
   r++;
  }
  if (ct == all) {
   best = min(best, r - l);
  }
  mp[s[l]]--;
  if (mp[s[l]] == 0) {
   ct--;
  }
  l++;
 }
 cout << best << '\n';
}
 
/*
 Think before implementing!
*/