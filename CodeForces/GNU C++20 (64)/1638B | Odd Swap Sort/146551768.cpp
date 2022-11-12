#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define rb pop_back
#define bg begin()
#define ed end()
#define f first
#define s second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) {
            cin >> x;
        }
        bool ans = true;
        int mnodd = 1e9, mneven = 1e9;
        for (int i = n - 1; i >= 0; i--) {
            ans &= a[i] <= (a[i] % 2 ? mnodd : mneven);
            if (a[i] % 2) {
                mnodd = min(mnodd, a[i]);
            } else {
                mneven = min(mneven, a[i]);
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}