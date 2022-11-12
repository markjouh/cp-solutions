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
 
int a[2000];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int XOR = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            XOR ^= a[i];
        }
        int cXOR = 0, ct = 0;
        for (int i = 0; i < n; i++) {
            cXOR ^= a[i];
            if (cXOR == XOR) {
                cXOR = 0;
                ct++;
            }
        }
        cout << (XOR == 0 || (cXOR == 0 && ct >= 3) ? "YES\n" : "NO\n");
    }
}