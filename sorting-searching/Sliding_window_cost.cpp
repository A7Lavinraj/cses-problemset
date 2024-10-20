#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define len(x) int((x).size())
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  set<pair<int, int>> left, right;

  for (int i = 0; i < N; i++)
    cin >> a[i];

  if (K == 1) {
    for (int i = 0; i < N; i++)
      cout << 0 << " ";

  } else if (K == 2) {
    for (int i = 1; i < N; i++)
      cout << abs(a[i - 1] - a[i]) << " ";
  } else {
    vector<pair<int, int>> st;

    for (int i = 0; i < K; i++)
      st.push_back({a[i], i});

    sort(st.begin(), st.end());
    long long left_sum = 0, right_sum = 0;

    for (int i = 0; i < K / 2 + (K % 2); i++) {
      left.insert(st[i]);
      left_sum += st[i].first;
    }

    for (int i = K / 2 + (K % 2); i < K; i++) {
      right.insert(st[i]);
      right_sum += st[i].first;
    }

    long long median = left.rbegin()->first;
    cout << median * len(left) - left_sum + right_sum - median * len(right)
         << " ";

    for (int j = 1; j < N - K + 1; j++) {
      if (left.count({a[j - 1], j - 1})) {
        left_sum -= a[j - 1];
        left.erase({a[j - 1], j - 1});
      } else {
        right_sum -= a[j - 1];
        right.erase({a[j - 1], j - 1});
      }

      if (*(left.rbegin()) < make_pair(a[K + j - 1], K + j - 1)) {
        right_sum += a[K + j - 1];
        right.insert({a[K + j - 1], K + j - 1});
      } else {
        left_sum += a[K + j - 1];
        left.insert({a[K + j - 1], K + j - 1});
      }

      while (len(left) < K / 2 + K % 2) {
        pair<int, int> tmp = *right.begin();
        left.insert(tmp);
        left_sum += tmp.first;
        right.erase(tmp);
        right_sum -= tmp.first;
      }

      while (len(left) > K / 2 + K % 2) {
        pair<int, int> tmp = *left.rbegin();
        left.erase(tmp);
        left_sum -= tmp.first;
        right.insert(tmp);
        right_sum += tmp.first;
      }

      median = left.rbegin()->first;
      cout << median * len(left) - left_sum + right_sum - median * len(right)
           << " ";
    }
  }

  cout << endl;

  return 0;
}
