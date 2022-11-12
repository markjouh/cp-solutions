#include <bits/stdc++.h>
using namespace std;
 
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
    int n;
    cin >> n;
    vt<int> a(n), zeroes{-1};
    for (int &x : a) {
      cin >> x;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        zeroes.pb(i);
      }
    }
    zeroes.pb(n);
    int best = 0, l = n, r = 0;
    for (int i = 0; i < sz(zeroes)-1; i++) {
      // Count twos and negatives in the full subsequence.
      int f_two = 0, f_neg = 0;
      for (int j = zeroes[i]+1; j < zeroes[i+1]; j++) {
        f_two += abs(a[j]) == 2;
        f_neg += a[j] < 0;
      }
      if (f_neg%2 == 0 && f_two > best) {
        best = f_two;
        l = zeroes[i]+1;
        r = n-zeroes[i+1];
        continue;
      }
      // Prefix or suffix with the minumum # of twos for when f_neg is odd
      int pre_two = 0, pre_id = zeroes[i]+1;
      for (; pre_id < zeroes[i+1]; pre_id++) {
        pre_two += abs(a[pre_id]) == 2;
        if (a[pre_id] < 0) {
          break;
        }
      }
      int suf_two = 0, suf_id = zeroes[i+1]-1;
      for (; suf_id >= zeroes[i]+1; suf_id--) {
        suf_two += abs(a[suf_id]) == 2;
        if (a[suf_id] < 0) {
          break;
        }
      }
      if (f_two-pre_two > best) {
        best = f_two-pre_two;
        l = pre_id+1;
        r = n-zeroes[i+1];
      }
      if (f_two-suf_two > best) {
        best = f_two-suf_two;
        l = zeroes[i]+1;
        r = n-suf_id;
      }
    }
    cout << l << ' ' << r << '\n';
  }
}