#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pt> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].fi >> p[i].se;
    }
    ll ans = 0;
    map<pt, ll> mp; // [directionless vector] = pairs of points
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pt a = p[i];
            pt b = p[j];
            if (a > b) {
                swap(a, b);
            }
            ans += mp[{a.first - b.first, a.second - b.second}]++;
        }
    }
    cout << ans / 2 << '\n';
}