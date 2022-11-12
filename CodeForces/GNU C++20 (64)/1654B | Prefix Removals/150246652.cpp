#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    vector<int> ct(26);
    for (char c : s) {
      ct[c - 'a']++;
    }
    int idx = 0;
    while (idx < sz(s)) {
      if (--ct[s[idx] - 'a'] == 0) {
        break;
      }
      idx++;
    }
    for (int i = idx; i < sz(s); i++) {
      cout << s[i];
    }
    cout << '\n';
  }
}