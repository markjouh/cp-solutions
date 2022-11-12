#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pos[x] = i + 1;
        }
        for (int i = 1; i <= n; i++) {
            cout << pos[n - i + 1] << ' ';
        }
        cout << '\n';
    }
}