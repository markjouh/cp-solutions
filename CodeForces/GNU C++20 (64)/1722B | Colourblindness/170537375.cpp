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
        int n;
        string a, b;
        cin >> n >> a >> b;
 
        for (int i = 0; i < n; i++) {
            if (a[i] == 'G') {
                a[i] = 'B';
            }
            if (b[i] == 'G') {
                b[i] = 'B';
            }
        }
 
        cout << (a == b ? "YES\n" : "NO\n");
    }
}