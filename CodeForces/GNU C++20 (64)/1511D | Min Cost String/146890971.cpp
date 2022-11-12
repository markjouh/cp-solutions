#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> ct(26, vector<int>(26));
  string res = "a";
  for (int i = 0; i < n-1; i++) {
    int mn = 1e9;
    char mnchar = 'a';
    for (char c = 'a'; c <= 'a'+k-1; c++) {
      int cur = ct[res.back()-'a'][c-'a'];
      if (cur <= mn) {
        mn = cur;
        mnchar = c;
      }
    }
    ct[res.back()-'a'][mnchar-'a']++;
    res += mnchar;
  }
  cout << res << '\n';
}