#include <bits/stdc++.h>
using namespace std;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n;
  cin >> n;
  set<pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
   int x;
   cin >> x;
   if (x > 0) {
    st.emplace(x, i + 1);
   }
  }
  vector<pair<int, int>> res;
  while (st.size() > 1) {
   auto a = *st.rbegin();
   st.erase(a);
   auto b = *st.rbegin();
   st.erase(b);
   res.emplace_back(a.second, b.second);
   if (--a.first > 0) {
    st.emplace(a.first, a.second);
   }
   if (--b.first > 0) {
    st.emplace(b.first, b.second);
   }
  }
  cout << res.size() << '\n';
  for (auto [f, s] : res) {
   cout << f << ' ' << s << '\n';
  }
 }
 
}