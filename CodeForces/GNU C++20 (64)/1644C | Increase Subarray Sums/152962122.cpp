#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,a,b) for (int i = a; i < b; i++)
#define per(i,a,b) for (int i = b-1; i >= a; i--)
#define ea(x,a) for (int &x : a)
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
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vt<int> pre(n+1), mx(n+1,-1e9);
    rep(i,1,n+1) {
      cin >> pre[i];
      pre[i] += pre[i-1];
    }
    // mx[i] is the maximum sum for a continguous subarray of length i
    rep(i,1,n+1)
      rep(j,0,i)
        mx[i-j] = max(mx[i-j],pre[i]-pre[j]);
    // i is the max value of k, j is the length of the subarray
    rep(i,0,n+1) {
      int best = 0;
      rep(j,1,n+1)
        best = max(best, mx[j]+min(i,j)*x);
      cout << best << ' ';
    }
    cout << '\n';
  }
}