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
 
// if the sum is odd, there is no solution as flips can only change the sum by 2
// if the current sum of a is negative, only flip -1 and vice versa for positive
// if we want to flip -1s, but there are 2 adjacent ones, take the earlier one
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int sum = 0;
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            if (x == -1) {
                a.push_back(i);
            } else if (x == 1) {
                b.push_back(i);
            }
        }
        if (sum % 2) {
            cout << -1 << '\n';
            continue;
        }
        if (sum > 0) {
            swap(a, b);
        }
        int req = abs(sum) / 2;
        int seg = n;
        vector<bool> in_pair(n);
        for (int i = 0; i < siz(a) && req > 0; i++) {
            if (a[i] > 0 && !in_pair[a[i] - 1]) {
                in_pair[a[i]] = true;
                req--;
                seg--;
            }
        }
        cout << seg << '\n';
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && in_pair[i + 1]) {
                cout << i + 1 << ' ' << i + 2 << '\n';
                i++;
            } else {
                cout << i + 1 << ' ' << i + 1 << '\n';
            }
        }
    }
}