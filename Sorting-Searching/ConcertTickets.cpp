#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif

#define len(x) int((x).size())
#define ll int64_t

using namespace std;

void print(){cout << " ";}template<typename T, typename...types> void print(const T& first, const types&...args) {cout << first << " "; print(args...);}
void println(){cout << "\n";}template<typename T, typename...types> void println(const T& first, const types&...args) {cout << first << " "; println(args...);}

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  set<array<int, 2>> tickets;
  vector<int> customers(M);

  for (int i = 0; i < N; i++) {
    int value;
    cin >> value;
    tickets.insert({value, i});
  }
  for (int i = 0; i < M; i++)
    cin >> customers[i];

  for (int i = 0; i < M; i++) {
    auto it = tickets.lower_bound({customers[i] + 1, 0}); 

    if (it == tickets.begin()) {
      println(-1);
    } else {
      println((*--it)[0]);
      tickets.erase(it);
    }
  }

  return 0;
}
