#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int main() {
 cin.tie(0)->sync_with_stdio(0);
 cin.exceptions(cin.failbit);
 int tc;
 cin >> tc;
 while (tc--) {
  string s;
  cin >> s;
  bool same = true;
  rep(i, 1, sz(s)) {
   same &= s[i] == s[0];
  }
  cout << (same ? -1 : sz(s) - 1) << '\n';
 }
}