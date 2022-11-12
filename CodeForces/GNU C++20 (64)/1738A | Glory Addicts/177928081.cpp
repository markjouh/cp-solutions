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
#define rall(x) (x).rbegin(), (x).rend()
#define siz(x) (int)(x).size()
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
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
        ll sum = 0;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            (t[i] ? b : a).push_back(x);
        }
        sort(rall(a));
        sort(rall(b));
        if (siz(a) == siz(b)) {
            ll ans = 0;
            for (int i = 0; i < siz(a) - 1; i++) {
                ans += a[i];
                ans += b[i];
            }
            ans += max(a.back(), b.back());
            cout << sum + ans << '\n';
            continue;
        }
        if (siz(a) < siz(b)) {
            swap(a, b);
        }
        ll ans = 0;
        for (int i = 0; i < siz(b); i++) {
            ans += a[i];
        }
        ans += accumulate(all(b), 0ll);
        cout << sum + ans << '\n';
    }
}