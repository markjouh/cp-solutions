#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(x...)
#endif
 
typedef long long ll;
 
#define sz(x) static_cast<int>(size(x))
#define all(x) begin(x), end(x)
 
vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
 
void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};
 
    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
 
            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}
 
// Determines whether n is prime in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(1) time.
bool is_prime(int64_t n) {
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
 
    if (n <= sieve_max)
        return prime[n];
 
    for (int64_t p : primes) {
        if (p * p > n)
            break;
 
        if (n % p == 0)
            return false;
    }
 
    return true;
}
 
// Prime factorizes n in worst case O(sqrt n / log n). Requires having run `sieve` up to at least sqrt(n).
// If we've run `sieve` up to at least n, takes O(log n) time.
template<typename T>
vector<pair<T, int>> prime_factorize(T n) {
    int64_t sieve_max = int64_t(smallest_factor.size()) - 1;
    assert(1 <= n && n <= sieve_max * sieve_max);
    vector<pair<T, int>> result;
 
    if (n <= sieve_max) {
        while (n != 1) {
            int p = smallest_factor[n];
            int exponent = 0;
 
            do {
                n /= p;
                exponent++;
            } while (n % p == 0);
 
            result.emplace_back(p, exponent);
        }
 
        return result;
    }
 
    for (int p : primes) {
        if (int64_t(p) * p > n)
            break;
 
        if (n % p == 0) {
            result.emplace_back(p, 0);
 
            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    }
 
    if (n > 1)
        result.emplace_back(n, 1);
 
    return result;
}
 
template<typename T>
vector<T> generate_factors(const vector<pair<T, int>> &prime_factors, bool sorted = false) {
    // See http://oeis.org/A066150 and http://oeis.org/A036451 for upper bounds on number of factors.
    static vector<T> buffer;
    int product = 1;
 
    for (auto &pf : prime_factors)
        product *= pf.second + 1;
 
    vector<T> factors = {1};
    factors.reserve(product);
 
    if (sorted)
        buffer.resize(product);
 
    for (auto &pf : prime_factors) {
        T p = pf.first;
        int exponent = pf.second;
        int before_size = int(factors.size());
 
        for (int i = 0; i < exponent * before_size; i++)
            factors.push_back(factors[factors.size() - before_size] * p);
 
        if (sorted && factors[before_size - 1] > p)
            for (int section = before_size; section < int(factors.size()); section *= 2)
                for (int i = 0; i + section < int(factors.size()); i += 2 * section) {
                    int length = min(2 * section, int(factors.size()) - i);
                    merge(factors.begin() + i, factors.begin() + i + section,
                          factors.begin() + i + section, factors.begin() + i + length,
                          buffer.begin());
                    copy(buffer.begin(), buffer.begin() + length, factors.begin() + i);
                }
    }
 
    assert(int(factors.size()) == product);
    return factors;
}
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    gp_hash_table<ll, ll, custom_hash> freq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
 
    ll ans = 0;
    for (ll i : a) {
        if (freq[i] > 2) {
            ans += freq[i] * (freq[i] - 1) * (freq[i] - 2);
        }
 
        // vector<int> factors;
        // for (ll j = 1; j * j <= i; j++) {
        //     if (i % j == 0) {
        //         factors.push_back(j);
        //         if (j * j != i) {
        //             factors.push_back(i / j);
        //         }
        //     }
        // }
        // factors.erase(find(all(factors), i));
 
        vector<pair<int, int>> prime_factors = prime_factorize<int>(i);
        vector<int> factors = generate_factors<int>(prime_factors);
 
        assert(sz(factors) <= 1344);
        factors.erase(find(all(factors), i));
 
        for (ll f : factors) {
            if (freq.find(f) != freq.end() && freq.find(i * (i / f)) != freq.end()) {
                ans += freq[f] * freq[i] * freq[i * (i / f)];
            }
        }
    }
    cout << ans << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    sieve(4e4);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
 
/*
 
We might be able to cheese this!
First, sieve up to sqrt(MAXN), so that we can factorize in O(N / log(N)).
Make A unique.
For each value in A, factorize it, then use the prime factorization to find the set of all factors. This is O(log(N) + factors), which is bounded by ~1400 ops
Then, count all triples using something fast like a PBDS map.
 
This will take something like 1400N operations, which might pass if our constant is good enough.
 
*/