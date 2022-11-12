#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        ll n, m;
        cin >> n >> m;
        if (n < m) {
            swap(n, m);
        }
        cout << n + m - 2 + m - 1 + (n > 1) << '\n';
    }
}