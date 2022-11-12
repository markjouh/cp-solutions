#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
 
int main() {
#ifdef LOCAL
  freopen("1.in", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    vector<int> cnt(10);
    int sum = 0, even = 0;
    for (char c : s) {
      cnt[c - '0']++;
      sum += c - '0';
      even += (c - '0') % 2 == 0;
    }
    cout << (cnt[0] && even > 1 && sum % 3 == 0 ? "red\n" : "cyan\n");
  }
}