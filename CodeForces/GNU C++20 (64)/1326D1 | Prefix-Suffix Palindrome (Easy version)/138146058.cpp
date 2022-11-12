#include <bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int)(a).size()
 
bool pal(string s) {
 for (int i = 0; i < sz(s) / 2; ++i) {
  if (s[i] != s[sz(s) - i - 1]) {
   return false;
  }
 }
 return true;
}
 
int main() {
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  string s;
  cin >> s;
  int l = 0, r = sz(s) - 1;
  string left, mid, right;
  while (l <= r && s[l] == s[r]) {
   left = left + s[l];
   if (l != r) {
    right = s[r] + right;
   }
   ++l;
   --r;
  }
  if (l < r) {
   string cur;
   for (int i = l; i <= r; ++i) {
    cur += s[i];
    if (sz(cur) > sz(mid) && pal(cur)) {
     mid = cur;
    }
   }
   cur.clear();
   for (int i = r; i >= l; --i) {
    cur += s[i];
    if (sz(cur) > sz(mid) && pal(cur)) {
     mid = cur;
    }
   }
  }
  cout << left + mid + right << '\n';
 }
}
 
/*
 Read the problem statement carefully
 Try to think of ideas from past problems
 Check for edge cases, overflow, etc.
*/
 
 