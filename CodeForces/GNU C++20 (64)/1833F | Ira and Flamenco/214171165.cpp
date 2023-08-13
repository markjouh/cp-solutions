#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
 
using namespace std;
 
#define int int64_t
 
// okay, so basically you need 1, 2, ... M
// or some version of that with a constant value added to all dancers
 
// suppose we have a frequency array of size 1e9 with all levels
// the answer is the sum of the product of all ranges of size M
 
// we only care about continguous segments of > 0
 
const int MOD = 1e9 + 7;
 
int mod_exp(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp & 1) {
            res = res * base % MOD;
        }
        exp >>= 1;
        base = base * base % MOD;
    }
    return res;
}
 
int mod_inv(int base) {
    return mod_exp(base, MOD - 2);
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        map<int, int> mp;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        
        vector<pair<int, int>> P;
        for (auto [k, v] : mp) {
            P.push_back({k, v});
        }
 
        vector<vector<int>> S;
        int prev = -1;
        for (int i = 0; i < (int)P.size(); i++) {
            if (P[i].first != prev + 1) {
                S.emplace_back();
            }
            S.back().push_back(P[i].second);
            prev = P[i].first;
        }
        
        int ans = 0;
        for (auto v : S) {
            int sz_v = v.size();
            if (sz_v < M) {
                continue;
            }
            int cur = 1;
            for (int i = 0; i < M; i++) {
                cur = cur * v[i] % MOD;
            }
            ans = (ans + cur) % MOD;
            for (int i = M; i < sz_v; i++) {
                cur = cur * v[i] % MOD;
                cur = cur * mod_inv(v[i - M]) % MOD;
                ans = (ans + cur) % MOD;
            }
        }
        cout << ans << '\n';
    }
}