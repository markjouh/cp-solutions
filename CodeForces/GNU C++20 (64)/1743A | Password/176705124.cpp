#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
int fac(int x) {
    int res = 1;
    for (int i = 2; i <= x; i++) {
        res *= i;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // ((10 - n) choose 2) * 6
        cout << fac(10 - n) / fac(2) / fac(10 - n - 2) * 6 << '\n';
    }
}