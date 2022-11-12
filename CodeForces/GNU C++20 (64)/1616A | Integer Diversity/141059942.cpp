#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
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
  int ans = 0;
  set<int> st;
  for (int &x : a) {
   if (st.count(x)) {
    x = -x;
   }
   if (!st.count(x)) {
    ans++;
    st.insert(x);
   }
  }
  cout << ans << '\n';
 }
}