#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ckmin(a, b) a = min(a, b)
#define ckmax(a, b) a = max(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second
 
// I think not needing to take them in order is very important
// if we go through the astronauts from weakest to strongest, if we fail to beat one at any point,
// we will have to use a serum to continue forward
 
// it's always optimal to only use serums when we have to, since using them later can potentially add more to our power
 
// it's really just a question of when to use each serum
 
// I think the key observation is that there aren't many possibilities to branch out into
 
vector<ll> a;
 
int solve(int id, ll pow, int s1, int s2) {
    while (id < sz(a) && pow > a[id]) {
        pow += a[id] / 2;
        id++;
    }
    if (id < sz(a)) {
        int cid = id;
        if (s1 > 0) {
            ckmax(id, solve(cid, pow * 2, s1 - 1, s2));
        }
        if (s2 > 0) {
            ckmax(id, solve(cid, pow * 3, s1, s2 - 1));
        }
    }
    return id;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, h;
        cin >> n >> h;
        a.clear();
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(all(a));
        cout << solve(0, h, 2, 1) << '\n';
    }
}