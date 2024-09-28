#include <bits/stdc++.h>
using namespace std;

struct Project {
  int start;
  int end;
  int profit;

  bool operator<(Project other) { return this->end < other.end; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<Project> projects(n);

  for (int i = 0; i < n; i++)
    cin >> projects[i].start >> projects[i].end >> projects[i].profit;

  sort(projects.begin(), projects.end());
  vector<long long> dp(n, 0);
  dp[0] = projects[0].profit;

  auto lower_bound = [&](int i) -> int {
    int low = 0, high = i - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (projects[mid].end < projects[i].start) {
        if (projects[mid + 1].end < projects[i].start)
          low = mid + 1;
        else
          return mid;
      } else
        high = mid - 1;
    }

    return -1;
  };

  for (int i = 1; i < n; i++) {
    long long inclusion = projects[i].profit;
    long long exclution = dp[i - 1];
    int lb = lower_bound(i);

    if (lb != -1)
      inclusion += dp[lb];

    dp[i] = max(inclusion, exclution);
  }

  cout << dp[n - 1] << '\n';
}
