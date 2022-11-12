#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rep1(i, n) for (int i = 1; i <= int(n); i++)
 
template<typename T>
struct fenwick_tree {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }
 
    int tree_n = 0;
    T tree_sum = T();
    vector<T> tree;
 
    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }
 
    void init(int n) {
        tree_n = n;
        tree_sum = T();
        tree.assign(tree_n + 1, T());
    }
 
    // O(n) initialization of the Fenwick tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert(int(initial.size()) == tree_n);
        tree_sum = T();
 
        for (int i = 1; i <= tree_n; i++) {
            tree[i] = initial[i - 1];
            tree_sum += initial[i - 1];
 
            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                tree[i] += tree[i - k];
        }
    }
 
    // index is in [0, tree_n).
    void update(int index, const T &change) {
        assert(0 <= index && index < tree_n);
        tree_sum += change;
 
        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }
 
    // Returns the sum of the range [0, count).
    T query(int count) const {
        count = min(count, tree_n);
        T sum = T();
 
        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];
 
        return sum;
    }
 
    // Returns the sum of the range [start, tree_n).
    T query_suffix(int start) const {
        return tree_sum - query(start);
    }
 
    // Returns the sum of the range [a, b).
    T query(int a, int b) const {
        return query(b) - query(a);
    }
 
    // Returns the element at index a in O(1) amortized across every index. Equivalent to query(a, a + 1).
    T get(int a) const {
        assert(0 <= a && a < tree_n);
        int above = a + 1;
        T sum = tree[above];
        above -= above & -above;
 
        while (a != above) {
            sum -= tree[a];
            a -= a & -a;
        }
 
        return sum;
    }
 
    bool set(int index, T value) {
        assert(0 <= index && index < tree_n);
        T current = get(index);
 
        if (current == value)
            return false;
 
        update(index, value - current);
        return true;
    }
 
    // Returns the largest p in `[0, tree_n]` such that `query(p) <= sum`. Returns -1 if no such p exists (`sum < 0`).
    // Can be used as an ordered set/multiset on indices in `[0, tree_n)` by using the tree as a 0/1 or frequency array:
    // `set(index, 1)` is equivalent to insert(index). `update(index, +1)` is equivalent to multiset.insert(index).
    // `set(index, 0)` or `update(index, -1)` are equivalent to erase(index).
    // `get(index)` provides whether index is present or not, or the count of index (if multiset).
    // `query(index)` provides the count of elements < index.
    // `find_last_prefix(k)` finds the k-th smallest element (0-indexed). Returns `tree_n` for `sum >= set.size()`.
    int find_last_prefix(T sum) const {
        if (sum < T())
            return -1;
 
        int prefix = 0;
 
        for (int k = highest_bit(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }
 
        return prefix;
    }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); 
  int n, q;
  cin >> n >> q;
  fenwick_tree<int> rows(n), cols(n);
  vector<int> rowct(n), colct(n);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      rowct[x - 1]++;
      colct[y - 1]++;
      rows.set(x - 1, 1);
      cols.set(y - 1, 1);
    } else if (t == 2) {
      int x, y;
      cin >> x >> y;
      if (--rowct[x - 1] == 0) {
        rows.set(x - 1, 0);
      }
      if (--colct[y - 1] == 0) {
        cols.set(y - 1, 0);
      }
    } else {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      int rowsum = rows.query(x1 - 1, x2);
      int colsum = cols.query(y1 - 1, y2);
      cout << (rowsum == x2 - x1 + 1 || colsum == y2 - y1 + 1 ? "Yes\n" : "No\n");
    }
  }
}