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
        int n;
        string s;
        cin >> n >> s;
 
        vector<bool> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = s[i] - '0';
        }
 
        vector<int> suf_0(n), suf_1(n);
        if (b[n - 1]) {
            suf_0[n - 1] = 1;
        } else {
            suf_1[n - 1] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            suf_0[i] = suf_0[i + 1];
            suf_1[i] = suf_1[i + 1];
            if (b[i] != b[i + 1]) {
                if (b[i]) {
                    suf_0[i] += 2;
                } else {
                    suf_1[i] += 2;
                }
            }
        }
 
        int ans = min(suf_0[0], suf_1[0]), cur = 0;
        bool flip = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] ^ flip) {
                flip ^= 1;
                cur++;
            }
            if (i == n - 1) {
                ans = min(ans, cur);
            } else if (!flip) {
                ans = min(ans, cur + suf_1[i + 1]);
            } else {
                ans = min(ans, cur + suf_0[i + 1]);
            }
            DEBUG(cur);
        }
        DEBUG(suf_0);
        DEBUG(suf_1);
        cout << ans << '\n';
    }
}