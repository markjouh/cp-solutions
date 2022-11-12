#include <bits/stdc++.h>
using namespace std;
 
#ifdef MARK
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...)
#endif
 
template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr> ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}
 
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
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            ll bsum = 0, bxor = 0;
            for (int i = l; i < r; i++) {
                bsum += a[i];
                bxor ^= a[i];
            }
            ll best = bsum - bxor;
 
            int lo = 0, hi = r - l;
            ll ansl = l + 1, ansr = r;
            while (lo + 1 < hi) {
                int mid = lo + (hi - lo) / 2;
                ll csum = 0, cxor = 0;
                for (int i = l; i < l + mid; i++) {
                    csum += a[i];
                    cxor ^= a[i];
                }
                bool ok = false;
                for (int i = l; i + mid <= r; i++) {
                    if (csum - cxor == best) {
                        ok = true;
                        ansl = i + 1;
                        ansr = i + mid;
                        break;
                    }
                    csum -= a[i];
                    cxor ^= a[i];
                    if (i + mid < r) {
                        csum += a[i + mid];
                        cxor ^= a[i + mid];
                    }
                }
                (ok ? hi : lo) = mid;
            }
 
            cout << ansl << ' ' << ansr << '\n';
        }
    }
}