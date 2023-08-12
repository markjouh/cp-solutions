#include "bits/stdc++.h"

using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  multiset<int> st, diff;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      auto it = st.upper_bound(x);
      if (it != st.begin() && it != st.end()) {
        diff.erase(diff.find(*prev(it) ^ *it));
      }
      st.insert(x);
      it = prev(st.upper_bound(x));
      if (it != st.begin()) {
        diff.insert(*prev(it) ^ *it);
      }
      if (it != prev(st.end())) {
        diff.insert(*it ^ *next(it));
      }
    } else if (t == 2) {
      int x;
      cin >> x;
      auto it = prev(st.upper_bound(x));
      if (it != st.begin()) {
        diff.erase(diff.find(*prev(it) ^ *it));
      }
      if (it != prev(st.end())) {
        diff.erase(diff.find(*it ^ *next(it)));
      }
      if (it != st.begin() && it != prev(st.end())) {
        diff.insert(*prev(it) ^ *next(it));
      }
      st.erase(it);
    } else {
      cout << *diff.begin() << '\n';
    }
  }
}
