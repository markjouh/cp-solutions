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
        int N, M, K;
        cin >> N >> M >> K;
        
        int X, Y;
        cin >> X >> Y;
        
        bool ok = true;
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            ok &= (abs(X - x) + (Y - y)) % 2;
        }
        
        cout << (ok ? "YES\n" : "NO\n");
    }
}