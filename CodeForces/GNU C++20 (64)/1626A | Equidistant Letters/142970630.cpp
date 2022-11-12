#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
#define FOR(i, n) for (int i = 0; i < (int)n; i++)
 
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
      ct[c-'a']++;
    }
    FOR(i, 2) {
      FOR(j, 26) {
        if (ct[j] == 2) {
          cout << char('a'+j);
        }
      }
    }
    FOR(i, 26) {
      if (ct[i] == 1) {
        cout << char('a'+i);
      }
    }
    cout << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/