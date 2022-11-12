#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
 
vector<bool> isprime;
vector<int> mnfactor;
 
void sieve(int n) {
    isprime.resize(n + 1, true);
    isprime[0] = isprime[1] = false;
    mnfactor.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) {
            mnfactor[i] = i;
            for (int j = i * i; j <= n; j += i) {
                if (isprime[j]) {
                    isprime[j] = false;
                    mnfactor[j] = i;
                }
            }
        }
    }
}
 
vector<pair<int, int>> get_fac(int n, int mod) {
    vector<pair<int, int>> res;
    while (n != 1) {
        int f = mnfactor[n];
        int exp = 0;
        while (n % f == 0) {
            n /= f;
            exp++;
        }
        if (exp % mod != 0) {
            res.push_back({f, exp % mod});
        }
    }
    return res;
}
 
vector<pair<int, int>> get_inv_fac(vector<pair<int, int>> fac, int mod) {
    for (int i = 0; i < int(fac.size()); i++) {
        fac[i].second = mod - fac[i].second;
    }
    return fac;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(1e5);
    int n, k;
    cin >> n >> k;
    map<vector<pair<int, int>>, int> fac_cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        fac_cnt[get_fac(x, k)]++;
    }
    int ans = 0;
    for (auto [fac, exp] : fac_cnt) {
        vector<pair<int, int>> inv_fac = get_inv_fac(fac, k);
        if (fac == inv_fac) {
            ans += exp * (exp - 1);
        } else {
            ans += exp * fac_cnt[inv_fac];
        }
    }
    cout << ans / 2 << '\n';
}