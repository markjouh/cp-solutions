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
  cin >> n;
  string s;
  cin >> s;
  char c;
  auto flip = [&]() {
   c = (c == 'B' ? 'R' : 'B');
  };
  string a = s, b = s;
  for (int rep = 0; rep <= 1; rep++) {
   c = (rep ? 'B' : 'R');
   for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
     a[i] = c;
     flip();
    } else if (c == s[i]) {
     flip();
    }
   }
   swap(a, b);
  }
  int acnt = 0, bcnt = 0;
  for (int rep = 0; rep <= 1; rep++) {
   string cur = (rep ? a : b);
   for (int i = 0; i < n; i++) {
    if (cur.substr(i, 2) == "BB" || cur.substr(i, 2) == "RR") {
     (rep ? acnt : bcnt)++;
    }
   }
  }
  cout << (acnt < bcnt ? a : b) << '\n';
 }
}