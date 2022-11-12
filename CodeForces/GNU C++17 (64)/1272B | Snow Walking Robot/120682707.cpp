#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int t;
 cin >> t;
 while (t--) {
  string s;
  cin >> s;
  map<char, int> m;
  for (char c : s) m[c]++;
  int vert = min(m['U'], m['D']), hor = min(m['L'], m['R']);
  if (vert == 0) hor = min(1, hor);
  if (hor == 0) vert = min(1, vert);
  cout << vert * 2 + hor * 2 << '\n';
  for (int i = 0; i < vert; i++) cout << 'U';
  for (int i = 0; i < hor; i++) cout << 'R';
  for (int i = 0; i < vert; i++) cout << 'D';
  for (int i = 0; i < hor; i++) cout << 'L';
  cout << '\n';
 }
}