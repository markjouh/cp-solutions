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
 
/*
  We can put any one number in position 0, then put the rest in descending order.
  This works because position 0 and 1 aren't checked, and positions 2..n-1 will
  each have a number greater than itself before itself.
*/
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    rep(i,1,n+1) {
      cout << i << ' ';
      per(j,1,n+1) {
        if (i != j) {
          cout << j << ' ';
        }
      }
      cout << '\n';
    }
  }
}