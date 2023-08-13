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
        string S;
        cin >> N >> S;
        vector<vector<bool>> pairs(7, vector<bool>(7));
        for (int i = 0; i < N - 1; i++) {
            pairs[S[i] - 'a'][S[i + 1] - 'a'] = true;
        }
        int ans = 0;
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                ans += pairs[i][j];
            }
        }
        cout << ans << '\n';
    }
}