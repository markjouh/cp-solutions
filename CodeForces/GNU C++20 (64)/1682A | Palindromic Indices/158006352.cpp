#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    string s;
    cin >> n >> s;
    s += '*';
    vector<int> seg;
    int cur = 1;
    for (int i = 1; i < n + 1; i++) {
      if (s[i] != s[i - 1]) {
        seg.push_back(cur);
        cur = 0;
      }
      cur++;
    }
    cout << (seg.size() % 2 ? seg[seg.size() / 2] : 0) << '\n';
  }
}