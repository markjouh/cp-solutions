#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return b > a ? a = b, 1 : 0; }

void solve() {
  int n;
  string s;
  cin >> n >> s;
  set<char> st;
  int idx = 0;
  while (sz(st) < 3) {
    st.insert(s[idx++]);
  }
  cout << idx << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  /* cin >> t; */
  while (t--) {
    #ifndef ONLINE_JUDGE
      cout << string(32, '_') << endl;
    #endif
    solve();
  }
  return 0;
}


