#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...)
#endif
#define len(x) int((x).size())

using namespace std;

struct Segement_tree {
  const int N = 200200;
  vector<int64_t> tree;

  Segement_tree() { tree.assign(4 * N, 0); }

  void build(vector<int64_t> &container, int node, int low, int high) {
    if (low == high)
      tree[node] = container[low];
    else {
      int mid = low + (high - low) / 2;

      build(container, 2 * node, low, mid);
      build(container, 2 * node + 1, mid + 1, high);

      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }

  int64_t query(int node, int begin, int end, int low, int high) {
    if (low > high)
      return 0;

    if (low == begin && high == end)
      return tree[node];

    int mid = begin + (end - begin) / 2;

    return query(2 * node, begin, mid, low, min(high, mid)) +
           query(2 * node + 1, mid + 1, end, max(low, mid + 1), high) +
           int64_t(0);
  }

  void update(int node, int begin, int end, int index, int value) {
    if (begin == end)
      tree[node] = value;
    else {
      int mid = begin + (end - begin) / 2;

      if (index <= mid)
        update(2 * node, begin, mid, index, value);
      else
        update(2 * node + 1, mid + 1, end, index, value);

      tree[node] = tree[2 * node] + tree[2 * node + 1] + int64_t(0);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  vector<int64_t> arr(N);

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  Segement_tree tree;
  tree.build(arr, 1, 0, N - 1);

  while (Q--) {
    int k;
    cin >> k;

    if (k == 1) {
      int64_t a, b;
      cin >> a >> b;
      tree.update(1, 0, N - 1, a - 1, b);
    } else {
      int64_t a, b;
      cin >> a >> b;
      cout << tree.query(1, 0, N - 1, a - 1, b - 1) << '\n';
    }
  }

  return 0;
}
