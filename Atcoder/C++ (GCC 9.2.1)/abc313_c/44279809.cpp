// #ifndef DEBUG
//   #pragma GCC optimize("Ofast,no-stack-protector")
//   #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
//   #pragma GCC optimize("unroll-loops")
// #endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define F0R(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for (int i = (int)b - 1; i >= a; i--)
#define RF0R(i, n) RFOR(i, 0, n)
#define REP(n) F0R(_, n)

#define sz(x) static_cast<int>((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

template<class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) { int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}"; }
template<typename T, typename V>
void __print(const pair<T, V> &x) { cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}'; }
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }

#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

constexpr int MOD = 1e9 + 7; // 998244353;
constexpr int INF = INT_MAX / 2;
constexpr ll BIG = LLONG_MAX / 2;

// ---------- END OF TEMPLATE ----------

// (1 / (x * (x + 1))) = (1 / x) - (1 / (x + 1))
// (1 / 1) - (1 / 2) + (1 / 2) - (1 / 3) + ... + (1 / n - 1) - (1 / n) = 1 - (1 / n)
// let A(N) = (1 / (1 * 2)) + (1 / (2 * 3)) + ... + (1 / ((n - 1) * n)) = 1 - (1 / n), + (1 / n) = 1
// however, this fails when there exists k where k * (k + 1) = n
// in this case, try (1 / 2) + (A(N - 1) / 2)
// if N fails, N - 1 can't fail since terms are never adjacent
// all A(X) = 1, so sum(A(N - 1) / 2) = (1 / 2), + (1 / 2) = 1
// all terms in A(N - 1) are distinct and >= 4, so they won't overlap with our (1 / 2)

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "Yes\n1\n";
        return;
    }
    if (n == 2) {
        cout << "No\n";
        return;
    }
    bool flag = false;
    FOR(i, 1, n) {
        flag |= i * (i + 1) == n;
    }
    cout << "Yes\n";
    if (flag) {
        cout << 2 << ' ';
        FOR(i, 1, n - 1) {
            cout << i * (i + 1) * 2 << ' ';
        }
        cout << (n - 1) * 2 << '\n';
    } else {
        FOR(i, 1, n) {
            cout << i * (i + 1) << ' ';
        }
        cout << n << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}