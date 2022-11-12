#include <bits/stdc++.h>
using namespace std;
 
// check whether a beats b, a goes first
bool solve(vector<int> a, vector<int> b) {
  while (!a.empty()) {
    int t = a.back();
    a.pop_back();
    while (!b.empty() && b.back() <= t) {
      b.pop_back();
    }
    // b has no cards to beat t
    if (b.empty()) {
      return 1;
    }
  }
  // a runs out of cards before beating b
  return 0;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    vector<int> b(m);
    for (int &x : b) {
      cin >> x;
    }
    sort(b.begin(), b.end());
    cout << (solve(a, b) ? "Alice\n" : "Bob\n");
    cout << (solve(b, a) ? "Bob\n" : "Alice\n");
  }
}