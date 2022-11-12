#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
 cin.sync_with_stdio(false);
 cin.tie(nullptr);
 int tc;
 cin >> tc;
 while (tc--) {
  int n, m;
  cin >> n >> m;
  set<int> st;
  for (int i = 1; i <= n; i++) {
   st.insert(i);
  }
  for (int i = 0; i < m; i++) {
   int a, b, c;
   cin >> a >> b >> c;
   st.erase(b);
  }
  int root = *st.begin();
  for (int i = 1; i <= n; i++) {
   if (i != root) {
    cout << root << ' ' << i << '\n';
   }
  }
 }
}