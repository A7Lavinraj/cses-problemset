#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...)
#endif
#define len(x) int((x).size())

using namespace std;

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<array<int, 3>> customers(N);

  for (int i = 0; i < N; i++)
    cin >> customers[i][0] >> customers[i][1], customers[i][2] = i;

  sort(customers.begin(), customers.end(), [](auto a, auto b) -> bool {
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
  });

  priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> rooms;
  vector<int> answer(N);
  int roomId = 1;

  for (int i = 0; i < N; ++i) {
    if (rooms.size() == 0) {
      answer[customers[i][2]] = roomId;
      rooms.push({customers[i][1], roomId});
      roomId++;
    }
    else {
      if (rooms.top()[0] < customers[i][0]) {
        array<int, 2> tmp = rooms.top();
        rooms.pop();
        answer[customers[i][2]] = tmp[1];
        rooms.push({customers[i][1], tmp[1]});
      }
      else {
        answer[customers[i][2]] = roomId;
        rooms.push({customers[i][1], roomId});
        roomId++;
      }
    }
  }

  cout << roomId - 1 << '\n';

  for (int i = 0; i < N; i++)
    cout <<  answer[i] << ' ';

  return 0;
}
