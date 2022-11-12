#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define all(x) (x).begin(), (x).end()
 
// idea: find the prime factorization of A*B. brute force the amount of each factor we take
// then, calculate the minimum need y and check using math from e1
 
// factorize a and b seperately
// combine their factorizations
// keep the amount of each prime factor p in a vector called amt
// brute force through all ways to pick factors, incrementing a number and using amt as a kind of "base"
// then, multiply the factors we picked as needed to get x, and use math from e1 to get y and check if its valid
 
vector<bool> isprime;
vector<ll> primes, mnfactor;
 
void sieve(ll n) {
    isprime.resize(n + 1);;
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
 
vector<pair<ll, ll>> factorize(ll n) {
    vector<pair<ll, ll>> res;
    // O(log(n)) if we've run sieve up to n.
    if (n <= int(isprime.size()) - 1) {
        while (n != 1) {
            ll f = mnfactor[n];
            ll exp = 0;
            while (n % f == 0) {
                n /= f;
                exp++;
            }
            res.push_back({f, exp});
        }
    }
    // O(sqrt(n) / log(n)) otherwise. Sieve must be run until at least sqrt(n).
    for (ll p : primes) {
        if (p * p > n) {
            break;
        }
        if (n % p == 0) {
            ll exp = 0;
            while (n % p == 0) {
                n /= p;
                exp++;
            }
            res.push_back({p, exp});
        }
    }
    if (n > 1) {
        res.push_back({n, 1});
    }
    return res;
}
 
vector<pair<ll, ll>> combine(vector<pair<ll, ll>> a, vector<pair<ll, ll>> b) {
    vector<pair<ll, ll>> res;
    reverse(all(a));
    reverse(all(b));
    while (!a.empty() && !b.empty()) {
        if (a.back().first < b.back().first) {
            res.push_back(a.back());
            a.pop_back();
        } else {
            res.push_back(b.back());
            b.pop_back();
        }
    }
    if (a.empty() && !b.empty()) {
        swap(a, b);
    }
    while (!a.empty()) {
        res.push_back(a.back());
        a.pop_back();
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(1e5);
    int T;
    cin >> T;
    while (T--) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
 
        if (A*B == 1) {
            cout << C << ' ' << D << '\n';
            continue;
        }
 
        vector<pair<ll, ll>> abfac = combine(factorize(A), factorize(B));
        int m = abfac.size();
 
        int sets = 1;
        for (int i = 0; i < m; i++) {
            sets *= abfac[i].second+1;
        }
 
        vector<int> cnt(m);
        ll ans1 = -1, ans2 = -1;
 
        for (int i = 0; i < sets; i++) {
            // try
            ll x = 1;
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < cnt[j]; k++) {
                    x *= abfac[j].first;
                }
            }
            x = A/x*x+x;
            ll g = gcd(A*B, x);
            ll req = A*B/g;
            ll y = B/req*req+req;
            if (x <= C && y <= D) {
                ans1 = x;
                ans2 = y;
            }
 
            // add
            cnt[m-1]++;
            for (int j = m-1; j >= 1; j--) {
                if (cnt[j] > abfac[j].second) {
                    cnt[j-1]++;
                    cnt[j] = 0;
                }
            }           
        }
 
        cout << ans1 << ' ' << ans2 << '\n';
    }
}