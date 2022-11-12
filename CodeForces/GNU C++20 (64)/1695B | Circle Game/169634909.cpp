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
        cin >> n;
        int mn = 1e9, idx = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x < mn) {
                mn = x;
                idx = i;
            }
        }
        if (n % 2) {
            cout << "Mike\n";
        } else {
            cout << (idx % 2 ? "Mike\n" : "Joe\n");
        }
    }
}