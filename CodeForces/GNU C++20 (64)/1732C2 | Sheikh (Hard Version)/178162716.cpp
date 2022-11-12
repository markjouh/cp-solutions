#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(x) (x).begin(), (x).end()
 
// taking the whole range always results in the best answer, because adding a bit will always increase
// the answer by (1<<pos), while the xor subtracted can be (1<<pos) at most.
 
// now, we can answer queries for the best answer in O(1) using prefix sums/xor.
// however, we may be able to take some elements off the front and back and still have the optimal answer.
 
// we've established that removing elements never increases our answer, but it can have no effect.
// when all the set bits in a number are also set in our total xor, switching it off won't change the answer.
// since we can't switch the same bit off twice, the maxmimum number of nonzero elements we can remove is
// log2 of 1e9, which is 30.
 
// however, we can remove as many zeroes as we want, so we need to come up with some way to skip 0s to
// prevent our solution from becoming O(N). I think one way to do this would be to store the positions
// of nonzero elements, use lb and ub to find the left and right bounds, then fix the number of elements
// to remove on the left and right, which is log(N)^2
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
     int N, Q;
     cin >> N >> Q;
     vector<int> a(N);
     vector<int> notz;
     for (int i = 0; i < N; i++) {
      cin >> a[i];
      if (a[i] != 0) {
       notz.push_back(i+1);
      }
     }
     vector<ll> prefs(N+1), prefx(N+1);
     for (int i = 0; i < N; i++) {
      prefs[i+1] = prefs[i]+a[i];
      prefx[i+1] = prefx[i]^a[i];
     }
     while (Q--) {
      int L, R;
      cin >> L >> R;
      int lb = lower_bound(all(notz), L)-notz.begin();
      int ub = upper_bound(all(notz), R)-notz.begin()-1;
 
      // no elements in the range => 0 is best => length of 1 is optimal
      if (lb == int(notz.size()) || notz[lb] > R) {
       cout << L << ' ' << L << '\n';
                continue;
      }
 
      ll best = prefs[R]-prefs[L-1]-(prefx[R]^prefx[L-1]);
            int finl = L, finr = R;
            for (int i = lb; i <= min(lb+30, ub); i++) {
                for (int j = ub; j >= max(ub-30, i); j--) {
                    int l = notz[i], r = notz[j];
                    ll cur = prefs[r]-prefs[l-1]-(prefx[r]^prefx[l-1]);
                    if (cur == best && r-l < finr-finl) {
                        finl = l;
                        finr = r;
                    }
                }
            }
            cout << finl << ' ' << finr << '\n';
     }
    }
}