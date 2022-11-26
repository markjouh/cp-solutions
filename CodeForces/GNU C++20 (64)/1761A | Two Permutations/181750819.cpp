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
        int n, a, b;
        cin >> n >> a >> b;
        cout << (a + b + 1 < n || a + b == n * 2 ? "Yes\n" : "No\n");
    }
}