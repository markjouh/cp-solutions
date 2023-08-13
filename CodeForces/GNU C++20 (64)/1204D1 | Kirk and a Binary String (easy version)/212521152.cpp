#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
 
// for a pair of chars at i, j such that i < j, s[i] == '1', and s[j] == '0', their contribution
// to the LIS of the whole array is always 1
 
// once we eliminate all such pairs, we are left with an ascending binary string
// we can change all remaining elements into '0', and the LIS will not change
 
// how can we guarantee the LIS for subarrays is the same?
// let's pick an arbitrary subarray [l, r) and compare solve(l, r) to solve(0, n)(l, r)
// add the 1s to a stack, ensuring we pair 0s with the rightmost available 1
// if a pair is contained within [l, r), this process is sure to find it
// what if we enter a situation where we pair a 1 from before l to a 0 in the range?
// it turns out that the answer is not affected at all
 
void solve() {
    string s;
    cin >> s;
    vector<int> stk;
    string res = s;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '1') {
            stk.push_back(i);
        }
        if (s[i] == '0') {
            if (stk.empty()) {
                res[i] = '0';
            } else {
                stk.pop_back();
            }
        }
    }
    for (int i = 0; i < sz(stk); i++) {
        res[stk[i]] = '0';
    }
    cout << res << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}