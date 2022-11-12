#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
#define sz(x) int(size(x))
#define all(x) begin(x), end(x)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    s += '*';
    char last = s[0];
    int cur = 1;
    vector<int> len;
    for (int i = 1; i <= n; i++) {
      if (s[i] != last) {
        len.push_back(cur);
        last = s[i];
        cur = 0;
      }
      cur++;
    }
    int ans = 0;
    for (int i = 0; i < sz(len)-1; i++) {
      if (len[i] % 2) {
        len[i]++;
        len[i+1]--;
        ans++;
      }
    }
    cout << ans << '\n';
  }
}