#include <iostream>
#include <vector>

using namespace std;

int n, m;
int result = 11;
char map[21][21];

struct POS
{
  int y, x;
};

POS moveArr[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isOut(POS position)
{
  if (position.y >= n ||
      position.x >= m ||
      position.y < 0 ||
      position.x < 0)
  {
    return true;
  }
  return false;
}

bool isWall(POS position)
{
  if (map[position.y][position.x] == '#')
  {
    return true;
  }
  return false;
}

void func(POS coinPos1, POS coinPos2, int moveCount)
{
  if (moveCount > 10)
  {
    return;
  }
  if (isOut(coinPos1) && isOut(coinPos2))
  {
    return;
  }
  if (isOut(coinPos1) || isOut(coinPos2))
  {
    result = min(result, moveCount);
    return;
  }

  for (auto move : moveArr)
  {
    POS nextCoinPos1 = {coinPos1.y + move.y, coinPos1.x + move.x};
    POS nextCoinPos2 = {coinPos2.y + move.y, coinPos2.x + move.x};

    if (isWall(nextCoinPos1))
    {
      nextCoinPos1 = coinPos1;
    }

    if (isWall(nextCoinPos2))
    {
      nextCoinPos2 = coinPos2;
    }

    func(nextCoinPos1, nextCoinPos2, moveCount + 1);
  }
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  string input;
  vector<POS> coinPosList;

  for (int i = 0; i < n; i++)
  {
    cin >> input;
    int col = 0;
    for (char c : input)
    {
      if (c == 'o')
      {
        coinPosList.push_back({i, col});
      }
      map[i][col++] = c;
    }
  }

  func(coinPosList[0], coinPosList[1], 0);

  if (result > 10)
  {
    cout << -1;
    return 0;
  }

  cout << result;

  return 0;
}