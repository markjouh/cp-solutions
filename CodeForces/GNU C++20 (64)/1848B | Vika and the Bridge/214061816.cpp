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
        int N, K;
        cin >> N >> K;
        vector<int> C(N);
        for (int i = 0; i < N; i++) {
            cin >> C[i];
            C[i]--;
        }
        vector<int> prev(K, -1), mx_f(K), mx_s(K);
        for (int i = 0; i < N; i++) {
            int g = i - prev[C[i]] - 1;
            prev[C[i]] = i;
            mx_s[C[i]] = max(mx_s[C[i]], g);
            if (mx_s[C[i]] > mx_f[C[i]]) {
                swap(mx_s[C[i]], mx_f[C[i]]);
            }
        }
        for (int i = 0; i < K; i++) {
            int g = N - prev[i] - 1;
            mx_s[i] = max(mx_s[i], g);
            if (mx_s[i] > mx_f[i]) {
                swap(mx_s[i], mx_f[i]);
            }
        }
        int ans = 1e9;
        for (int i = 0; i < N; i++) {
            ans = min(ans, max(mx_s[C[i]], mx_f[C[i]] / 2));
        }
        cout << ans << '\n';
    }
}