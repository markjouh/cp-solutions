#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,a,b) for (int i = a; i < b; i++)
#define per(i,a,b) for (int i = b-1; i >= a; i--)
#define ea(x,a) for (auto &x : a)
using ll = long long;
template<class T> using vt = vector<T>;
#define fi first
#define se second
#define pb push_back
#define pp pop_back
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    map<char,int> mp;
    int ans = 0;
    for (char c : s) {
      if (c == ')' && mp['(']) {
        ans++;
        mp['(']--;
      }
      if (c == ']' && mp['[']) {
        ans++;
        mp['[']--;
      }
      mp[c]++;
    }
    cout << ans << '\n';
  }
}