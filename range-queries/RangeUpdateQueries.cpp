#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif
#define len(x) int((x).size())

struct Segement_tree {
  vector<int64_t> tree, lazy;

  Segement_tree(int N = 200200) {
    tree.resize(4 * N);
    lazy.resize(4 * N);
  }

  void build(vector<int64_t> &container, int node, int begin, int end) {
    if (begin == end)
      tree[node] = container[begin];
    else {
      int mid = begin + (end - begin) / 2;

      build(container, 2 * node, begin, mid);
      build(container, 2 * node + 1, mid + 1, end);

      tree[node] = tree[2 * node] + tree[2 * node + 1] + int64_t(0);
    }
  }

  int64_t query(int node, int begin, int end, int low, int high) {
    if (lazy[node] != 0) {
      tree[node] += (end - begin + 1) * lazy[node];

      if (begin != end) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }

      lazy[node] = 0;
    }

    if (end < low || begin > high)
      return 0;

    if ((low <= begin) && (end <= high))
      return tree[node];

    int mid = begin + (end - begin) / 2;

    return query(2 * node, begin, mid, low, high) + query(2 * node + 1, mid + 1, end, low, high) + int64_t(0);
  }

  void update(int node, int begin, int end, int low, int high, int value) {
    if (lazy[node] != 0) {
      tree[node] += (end - begin + 1) * lazy[node] + int64_t(0);

      if (begin != end) {
        lazy[2 * node] += lazy[node] + int64_t(0);
        lazy[2 * node + 1] += lazy[node] + int64_t(0);
      }

      lazy[node] = 0;
    }

    if ((end < low) || (begin > high))
      return;

    if (begin >= low && end <= high) {
      tree[node] += (end - begin + 1) * value + int64_t(0);

      if (begin != end) {
        lazy[2 * node] += value + int64_t(0);
        lazy[2 * node + 1] += value + int64_t(0);
      }

      return;
    }

    int mid = begin + (end - begin) / 2;

    update (2 * node, begin, mid, low, high, value);
    update (2 * node + 1, mid + 1, end, low, high, value);

    tree[node] = tree[2 * node] + tree[2 * node + 1] + int64_t(0);
  }
};

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  vector<int64_t> v(N);

  for (int i = 0; i < N; i++)
    cin >> v[i];

  Segement_tree tree(N);
  tree.build(v, 1, 0, N - 1);

  while(Q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int a, b, value;
      cin >> a >> b >> value;

      tree.update(1, 0, N - 1, a - 1, b - 1, value);
    } 
    else {
      int k;
      cin >> k;

      cout << tree.query(1, 0, N - 1, k - 1, k - 1) << '\n';
    }
  }

  return 0;
}
