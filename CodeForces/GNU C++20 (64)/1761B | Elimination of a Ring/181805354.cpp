#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
#define x first
#define y second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<bool> seen(n + 1);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int e;
            cin >> e;
            cnt += !seen[e];
            seen[e] = true;
        }
        cout << (cnt <= 2 ? n / 2 + 1 : n) << '\n';
    }
}