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
  vector<pair<int, int>> a(N);

  for (int i = 0; i < N; i++)
    cin >> a[i].first >> a[i].second;

  sort(a.begin(), a.end(),
       [](const pair<int, int> &x, const pair<int, int> &y) -> bool {
         return x.second < y.second;
       });
  set<pair<int, int>> available;
  int cnt = 0;

  for (int i = 0; i < N; i++) {
    if (len(available) == 0)
      available.insert({a[i].second * (-1), i});
    else {
      auto itr = available.upper_bound({a[i].first * (-1), -1});

      if (itr != available.end()) {
        available.erase(itr);
        available.insert({a[i].second * (-1), i});
      } else if (itr == available.end() && len(available) < K) {
        available.insert({a[i].second * (-1), i});
      } else
        cnt++;
    }
  }

  cout << N - cnt << endl;

  return 0;
}
