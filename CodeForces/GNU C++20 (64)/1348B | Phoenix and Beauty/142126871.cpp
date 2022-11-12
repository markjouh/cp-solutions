#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define FOR(i, n) for (int i = 0; i < n; i++)
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    set<int> st;
    for (int &x : a) {
      cin >> x;
      st.insert(x);
    }
    if (st.size() > k) {
      cout << -1 << '\n';
      continue;
    }
    FOR(i, n) {
      if (st.size() == k) {
        break;
      }
      if (!st.count(i+1)) {
        st.insert(i+1);
      }
    }
    cout << st.size()*n << '\n';
    FOR(i, n) {
      for (int x : st) {
        cout << x << ' ';
      }
    }
    cout << '\n';
  }
}
 
/*
  Read the problem statement carefully
  Think about the problem in different ways
*/