#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/cp/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif

#define len(x) int((x).size())
#define ll int64_t

using namespace std;

void print(){cout << "\n";}template<typename T, typename...types> void print(const T& first, const types&...args) {cout << first << " "; print(args...);}

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, K;
  cin >> N >> M >> K;
  vector<int> applicants(N), apartments(M);

  for (int i = 0; i < N; i++) 
    cin >> applicants[i];

  for (int i = 0; i < M; i++)
    cin >> apartments[i];

  sort(applicants.begin(), applicants.end());
  sort(apartments.begin(), apartments.end());
  int answer = 0;

  int up_ptr = 0, down_ptr = 0;

  while (up_ptr < N && down_ptr < M) {
    if (abs(applicants[up_ptr] - apartments[down_ptr]) > K) {
      if (applicants[up_ptr] > apartments[down_ptr])
        down_ptr++;
      else 
        up_ptr++;
    }
    else 
      up_ptr++, down_ptr++, answer++;
  }

  print(answer);

  return 0;
}
