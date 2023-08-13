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
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> P(N), pos(N + 1);
        for (int i = 0; i < N; i++) {
            cin >> P[i];
            pos[P[i]] = i;
        }
        if (N == 1) {
            cout << 1 << '\n';
            continue;
        }
        auto get_res = [&](int l, int r) {
            vector<int> res;
            for (int i = r + 1; i < N; i++) {
                res.push_back(P[i]);
            }  
            for (int i = r; i >= l; i--) {
                res.push_back(P[i]);
            }
            for (int i = 0; i < l; i++) {
                res.push_back(P[i]);
            }
            return res;
        };
        vector<pair<int, int>> to_try;
        for (int i = 0; i <= pos[N]; i++) {
            to_try.push_back({i, pos[N]});
        }
        for (int i = 0; i <= pos[N] - 1; i++) {
            to_try.push_back({i, pos[N] - 1});
        }
        for (int i = 0; i <= pos[N - 1]; i++) {
            to_try.push_back({i, pos[N - 1]});
        }
        for (int i = 0; i <= pos[N - 1] - 1; i++) {
            to_try.push_back({i, pos[N - 1] - 1});
        }
        vector<int> ans(N, -1e9);
        for (auto [l, r] : to_try) {
            ans = max(ans, get_res(l, r));
        }
        for (int i = 0; i < N; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}