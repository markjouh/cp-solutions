#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
const int MOD = 998244353;
 
namespace modop {
    ll madd(ll a, ll b) {
      return (a + b) % MOD;
    }
    ll msub(ll a, ll b) {
      return (((a - b) % MOD) + MOD) % MOD;
    }
    ll mmul(ll a, ll b) {
      return ((a % MOD) * (b % MOD)) % MOD;
    }
    ll mpow(ll base, ll exp) {
      ll res = 1;
      while (exp) {
        if (exp % 2 == 1){
            res = (res * base) % MOD;
        }
        exp >>= 1;
        base = (base * base) % MOD;
      }
      return res;
    }
    ll minv(ll base) {
      return mpow(base, MOD - 2);
    }
    ll mdiv(ll a, ll b) {
      return mmul(a, minv(b));
    }
    
    const ll FACTORIAL_SIZE = 1.1e6;
    ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
    bool __factorials_generated__ = 0;
    void gen_factorial(ll n) {
        __factorials_generated__ = 1;
        fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
        
        for (ll i = 2; i <= n; i++) {
            fact[i] = (i * fact[i - 1]) % MOD;
        }
        ifact[n] = minv(fact[n]);
        for (ll i = n - 1; i >= 2; i--) {
            ifact[i] = ((i + 1) * ifact[i + 1]) % MOD;
        }
    }
    ll nck(ll n, ll k) {
        if (!__factorials_generated__) {
            cerr << "Call gen_factorial you dope" << endl;
            exit(1);
        }
        if (k < 0 || n < k) return 0;
        ll den = (ifact[k] * ifact[n - k]) % MOD;
        return (den * fact[n]) % MOD;
    }
}
 
using namespace modop;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    gen_factorial(100);
 
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
 
        vector<int> p(n);
        for (int i = n - 4; i >= 0; i -= 4) {
            p[i] = p[i + 3] = 1;
        }
        if (n % 4) {
            p[1] = 1;
        }
 
        // we can have a even length suffix of the tying case,
        // then a pair of cards that decides the outcome (not equal to the tying case)
        // then any distribution of the remaining cards
 
        int ans_a = 0, ans_b = 0;
 
        for (int i = 1; i < n; i += 2) {
            int r = n / 2 - (n - i - 1) / 2;
 
            ans_a = madd(ans_a, nck(i - 1, r - 2));
            ans_b = madd(ans_b, nck(i - 1, r - 2));
 
            if (p[i]) {
                ans_a = madd(ans_a, nck(i - 1, r - 1));
            } else {
                ans_b = madd(ans_b, nck(i - 1, r - 1));
            }
        }
 
        cout << ans_a << ' ' << ans_b << ' ' << 1 << '\n';
    }
}