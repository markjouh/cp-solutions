#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  string s;
  cin >> n >> s;
  int ans = 1e9;
  for (char c = 'a'; c <= 'z'; ++c) {
   int l = 0, r = n - 1;
   int cur = 0;
   while (l < r) {
    if (s[l] == s[r]) {
     ++l;
     --r;
    } else if (s[l] == c) {
     ++l;
     ++cur;
    } else if (s[r] == c) {
     --r;
     ++cur;
    } else {
     break;
    }
   }
   if (l >= r) {
    ans = min(ans, cur);
   }
  }
  cout << (ans == 1e9 ? -1 : ans) << '\n';
 }
}