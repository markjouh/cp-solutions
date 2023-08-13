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
 
const int N = 1e6;
vector<bool> ok(N + 1);
 
void solve() {
    int n;
    cin >> n;
    cout << (ok[n] ? "YES\n" : "NO\n");
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    for (int i = 2; i * i <= N; i++) {
        ll sum = 1 + i + i * i;
        ll cur = i * i;
        while (sum < N) {
            ok[sum] = true;
            cur *= i;
            sum += cur;
        }
    }
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}