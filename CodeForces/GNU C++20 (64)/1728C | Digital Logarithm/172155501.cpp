#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
int f(int x) {
    int ans = 0;
    while (x > 0) {
        x /= 10;
        ans++;
    }
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        priority_queue<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push(x);
        }
        priority_queue<int> b;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b.push(x);
        }
        int ans = 0;
        while (siz(a)) {
            if (a.top() == b.top()) {
                a.pop();
                b.pop();
            } else if (a.top() > b.top()) {
                a.push(f(a.top()));
                a.pop();
                ans++;
            } else {
                b.push(f(b.top()));
                b.pop();
                ans++;
            }
        }
        cout << ans << '\n';
    }
}