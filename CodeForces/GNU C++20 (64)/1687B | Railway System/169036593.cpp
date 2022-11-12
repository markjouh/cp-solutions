#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
string s;
 
int ask() {
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return x;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    s = string(m, '0');
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; i++) {
        s[i] = '1';
        e[i] = {ask(), i};
        s[i] = '0';
    }
    sort(all(e));
 
    int cost = 0;
    int ans = 0;
    for (auto [w, i] : e) {
        s[i] = '1';
        int with = ask();
        if (with == cost + w) {
            ans += w;
            cost = with;
        } else {
            s[i] = '0';
        }
    }
    cout << "! " << ans << endl;
}