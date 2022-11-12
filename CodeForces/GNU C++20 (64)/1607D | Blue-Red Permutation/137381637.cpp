#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> pos(n);
    for (int &x : pos) {
      cin >> x;
    }
    string s;
    cin >> s;
    vector<int> b, r;
    for (int i = 0; i < n; ++i) {
      (s[i] == 'B' ? b : r).push_back(--pos[i]);
    }
    bool ok = true;
    sort(b.begin(), b.end());
    for (int i = 0; i < b.size(); ++i) {
      ok &= b[i] >= i;
    }
    sort(r.begin(), r.end(), greater<int>());
    for (int i = 0; i < r.size(); ++i) {
      ok &= r[i] <= n - i - 1;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Try to think of ideas from past problems
  Check for edge cases, overflow, etc.
*/