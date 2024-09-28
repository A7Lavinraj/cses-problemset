#include <bits/stdc++.h>
#ifdef DEBUG
#include "/home/lavinraj/career/code-library/debug.cpp"
#else
#define dbg(x...) 32
#endif
#define len(x) int((x).size())

using namespace std;

void print(){cout << "\n";}template<typename T, typename...types> void print(const T& first, const types&...args) {cout << first << " "; print(args...);}

int answer = 0;

void dfs(int row, vector<bool> &column, vector<bool> &leftDiagonal, vector<bool> &rightDiagonal, vector<string> chessboard) {
  if (row == 8) {
    answer++;
    return;
  }
  for (int i = 0; i < 8; i++) {
    if (column[i] == 0 && leftDiagonal[row - i + 7] == 0 && rightDiagonal[row + i] == 0 && chessboard[row][i] == '.') {
      column[i] = leftDiagonal[row - i + 7] = rightDiagonal[row + i] = true;
      dfs(row + 1, column, leftDiagonal, rightDiagonal, chessboard);
      column[i] = leftDiagonal[row - i + 7] = rightDiagonal[row + i] = false;
    }
  }
}

int main() { 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<string> chessboard(8);
  vector<bool> rightDiagonal(14, false), leftDiagonal(14, false), column(8);

  for (int i = 0; i < 8; i++)
    cin >> chessboard[i];

  dfs(0, column, leftDiagonal, rightDiagonal, chessboard);

  print(answer);

  return 0;
}
