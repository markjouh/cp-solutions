#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string g, p;
  cin >> g >> p;
  vector<bool> good(26);
  for (char c : g) {
    good[c-'a'] = true;
  }
  bool hasAst = count(all(p),'*');
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int asz = sz(s)-sz(p)+hasAst;
    if (asz < 0) {
      cout << "NO\n";
      continue;
    }
    int id = 0;
    bool ok = true;
    for (int i = 0; i < sz(p); i++) {
      if (s[id] == p[i] || (good[s[id]-'a'] && p[i] == '?')) {
        id++;
      } else if (p[i] == '*') {
        for (int j = 0; j < asz; j++) {
          ok &= !good[s[id+j]-'a'];
        }
        id += asz;
      } else {
        ok = false;
        break;
      }
    }
    cout << (id == sz(s) && ok ? "YES\n" : "NO\n");
  }
}