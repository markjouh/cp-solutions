#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
 
        if (n == 1) {
            cout << 2 << '\n';
            continue;
        }
 
        int mxmul = n / 3 * 3;
        if (mxmul > 0 && mxmul % 2 != n % 2) {
            mxmul -= 3;
        }
        cout << mxmul / 3 + (n - mxmul) / 2 << '\n';
    }
}