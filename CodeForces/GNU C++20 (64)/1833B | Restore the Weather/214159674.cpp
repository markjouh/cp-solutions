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
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i].first;
            A[i].second = i;
        }
        sort(A.begin(), A.end());
        vector<pair<int, int>> B(N);
        for (int i = 0; i < N; i++) {
            cin >> B[i].first;
            B[i].second = i;
        }
        sort(B.begin(), B.end());
        
        vector<int> ans(N);
        for (int i = 0; i < N; i++) {
            ans[A[i].second] = B[i].first;
        }
        
        for (int i = 0; i < N; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}