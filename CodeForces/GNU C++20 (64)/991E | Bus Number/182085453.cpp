#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define umin(a, b) a = min(a, b)
#define umax(a, b) a = max(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second
 
// # of distinct strings we can make with these digits
ll ways(vector<int> cnt) {
    // the method we use to generate sets returns amounts with 0 = 1, 1 = 2, etc, so this is to adjust
    for (int i = 0; i < sz(cnt); i++) {
        cnt[i]++;
    }
    // total length factorial divided by the amount of each digit factorial
    int tot = 0;
    for (int i = 0; i < sz(cnt); i++) {
        tot += cnt[i];
    }
    ll ans = 1;
    for (int i = 2; i <= tot; i++) {
        ans *= i;
    }
    for (int i = 0; i < sz(cnt); i++) {
        for (int j = 2; j <= cnt[i]; j++) {
            ans /= j;
        }
    }
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    // count up the amount of each digit
    // if there are 0 of some digits, just erase them, as the values of digits don't matter and this makes it easier to enumerate sets
    vector<int> tcnt(10);
    while (n > 0) {
        tcnt[n % 10]++;
        n /= 10;
    }
    bool has0 = tcnt[0] > 0;
    tcnt.erase(remove(tcnt.begin(), tcnt.end(), 0), tcnt.end());
 
    vector<int> cset(sz(tcnt));
    int sets = 1;
    for (int i = 0; i < sz(tcnt); i++) {
        sets *= tcnt[i];
    }
    ll ans = 0;
    for (int i = 0; i < sets; i++) {
        ans += ways(cset);
        if (has0) {
            cset[0]--;
            ans -= ways(cset);
            cset[0]++;
        }
 
        bool carry = true;
        for (int j = sz(tcnt) - 1; j >= 0; j--) {
            if (carry) {
                cset[j]++;
                carry = false;
            }
            if (cset[j] == tcnt[j]) {
                cset[j] = 0;
                carry = true;
            }
        }
    }
    cout << ans << '\n';
}