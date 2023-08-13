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
 
// to make them all even, odd ones must be subtracted by a smaller odd number
// this is impossible for the smallest odd
// so all even is only possible when they are all initially even
 
// to make all odd, even ones must be subtracted by a smaller odd number
// in this case, we only need to make sure that the smallest even is greater than the smallest odd
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        bool all_even = true;
        int mn_even = 1e9 + 1, mn_odd = 1e9;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            if (x % 2) {
                all_even = false;
                mn_odd = min(mn_odd, x);
            } else {    
                mn_even = min(mn_even, x);
            }
        }
        cout << (all_even || mn_even > mn_odd ? "YES\n" : "NO\n");
    }
}