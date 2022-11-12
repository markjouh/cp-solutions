#include <bits/stdc++.h>
using namespace std;
 
// Read the problem statement carefully
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int n, q;
 string s;
 cin >> n >> q >> s;
 int res = 0;
 for (int i = 0; i < n - 2; ++i) {
  if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
   ++res;
  }
 }
 auto ck = [&](int id) {
  if (s[id] == 'a') {
   return id < n - 2 && s[id + 1] == 'b' && s[id + 2] == 'c';
  } else if (s[id] == 'b') {
   return id > 0 && id < n - 1 && s[id - 1] == 'a' && s[id + 1] == 'c';
  } else {
   return id > 1 && s[id - 2] == 'a' && s[id - 1] == 'b';
  }
 };
 while (q--) {
  int id;
  char c;
  cin >> id >> c;
  --id;
  res -= ck(id);
  s[id] = c;
  res += ck(id);
  cout << res << '\n';
 }
}