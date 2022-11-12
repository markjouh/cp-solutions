#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
constexpr ll MOD = 998244353;
 
ll madd(ll a, ll b) {
    return (a + b) % MOD;
}
 
ll msub(ll a, ll b) {
    return (((a - b) % MOD) + MOD) % MOD;
}
 
ll mmul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
 
vector<bool> isprime;
vector<ll> primes, mnfactor;
 
void sieve(ll n) {
    isprime.resize(n + 1);
    fill(all(isprime), 1);
    isprime[0] = isprime[1] = false;
    mnfactor.resize(n + 1);
    // Runs in O(n * log(log(n))).
    for (ll i = 2; i <= n; i++) {
        if (isprime[i]) {
            primes.push_back(i);
            mnfactor[i] = i;
            for (ll j = i * i; j <= n; j += i) {
                isprime[j] = false;
                mnfactor[j] = i;
            }
        }
    }
}
 
// in an ambiguous array, there is some point where 2 different operations can be valid.
// since applying the operation to 1 is always valid, we want to make sure that the gcd
// of 2...i with a[i] for all indices is >1
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
 
    sieve(n);
 
    // ans = total ambiguous arrays so far
    // tot = total arrays so far
    // cur = non-ambiguous arrays of length n
    ll ans = 0, tot = 1, cur = 1;
    ll l = 1;
    for (ll i = 1; i <= n; i++) {
        if (l <= m && isprime[i]) {
            l *= i;
        }
        cur = mmul(cur, m / l);
        tot = mmul(tot, m);
        ans = madd(ans, msub(tot, cur));
    }
    cout << ans << '\n';
}