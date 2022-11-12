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
        cout << n << '\n';
        vector<int> p(n);
        iota(all(p), 1);
        for (int i = 0; i < n; i++) {
            cout << p[i] << ' ';
        }
        cout << '\n';
        for (int i = 0; i < n - 1; i++) {
            swap(p[i], p[i + 1]);
            for (int j = 0; j < n; j++) {
                cout << p[j] << ' ';
            }
            cout << '\n';
        }
    }
}