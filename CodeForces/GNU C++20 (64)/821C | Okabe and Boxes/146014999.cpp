#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define rb pop_back
#define bg begin()
#define ed end()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int cur_del = 0, ans = 0;
  vector<int> stack;
  for (int i = 0; i < n * 2; i++) {
    string s;
    cin >> s;
    if (s == "add") {
      int x;
      cin >> x;
      stack.pb(x);
    } else {
      cur_del++;
      if (stack.empty()) {
        continue;
      }
      if (stack.back() == cur_del) {
        stack.rb();
      } else {
        stack.clear();
        ans++;
      }
    }
  }
  cout << ans << '\n';
}