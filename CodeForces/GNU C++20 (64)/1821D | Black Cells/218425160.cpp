#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(x...)
#endif
 
using ll = long long;
 
#define sz(x) static_cast<int>(size(x))
#define all(x) begin(x), end(x)
 
constexpr int INF = INT_MAX / 2;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    l.push_back(INF);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
 
    int cur_rng = -1, pos = 0;
    int sum_take = 0;
    multiset<int> take;
    while (cur_rng + 1 < n && sum_take < k) {
        cur_rng++;
 
        pos = min(r[cur_rng], l[cur_rng] + k - sum_take - 1);
        sum_take += pos - l[cur_rng] + 1;
        take.insert(pos - l[cur_rng] + 1);
    }
 
    if (sum_take < k) {
        cout << -1 << '\n';
        return;
    }
 
    int ans = pos + 2 * sz(take);
    for (int i = 0; i < 2 * n; i++) {
        pos++;
        if (pos >= l[cur_rng + 1]) {
            cur_rng++;
        }
        
        if (pos <= r[cur_rng]) {
            int seg = pos - l[cur_rng] + 1;
            if (take.find(seg - 1) != take.end()) {
                sum_take++;
                take.erase(take.find(seg - 1));
                take.insert(seg);
            }
            if (sum_take - *take.begin() >= k) {
                sum_take -= *take.begin();
                take.erase(take.begin());
            }
        }
 
        ans = min(ans, pos + 2 * sz(take));
    }
    cout << ans << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
 
/*
if we fix the number of move operations (r) we perform, finding the optimal answer is trivial
let s be the set of the sizes of all ranges' intersections with [1..r]
greedily take the largest element while the sum is < x
the answer is r + 2 * taken
 
maintain a datastructure that simulates the above process
initialize it with a set of ranges with sum >= k, erase the smallest element whenever sum - smallest >= k
*/