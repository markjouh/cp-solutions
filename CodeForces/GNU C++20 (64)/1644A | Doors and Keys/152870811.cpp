#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,a,b) for (int i = a; i < b; i++)
#define per(i,a,b) for (int i = b-1; i >= a; i--)
template<class T>
using vt = vector<T>;
using ll = long long;
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
    rep(i,0,sz(s)) {
      mp[s[i]] = i;
    }
    cout << (mp['r'] < mp['R'] && mp['g'] < mp['G'] && mp['b'] < mp['B'] ? "YES\n" : "NO\n");
  }
}