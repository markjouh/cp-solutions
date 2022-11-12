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
 
bool chk(int a, int b, int c) {
  int need = 0, x = max(0,(b-a+1)/2);
  need += x;
  a += x*2;
  need += max(0,a-b);
  return c >= need && (c-need)%3 == 0;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(i,0,n) {
      char last = '*';
      int a = 0, b = 0, c = 0;
      rep(j,i,n) {
        a += s[j] == '-';
        b += s[j] == '+';
        if (s[j] == '-' && last == '-') {
          a -= 2;
          c++;
          last = '*';
        } else {
          last = s[j];
        }
        ans += chk(a,b,c);
      }
    }
    cout << ans << '\n';
  }
}