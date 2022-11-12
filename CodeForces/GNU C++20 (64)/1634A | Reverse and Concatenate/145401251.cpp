#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
bool palindrome(string s) {
  for (int i = 0; i < (int)s.size() / 2; i++) {
    if (s[i] != s[s.size() - i - 1]) {
      return false;
    }
  }
  return true;
}
 
int main() {
#ifdef LOCAL
  freopen("input.in", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    cout << (k == 0 ? 1 : !palindrome(s) + 1) << '\n';
  }
}