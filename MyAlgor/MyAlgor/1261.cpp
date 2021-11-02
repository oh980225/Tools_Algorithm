#include <iostream>
#include <queue>

using namespace std;

int n, m;
int maps[105][105];
int dis[105][105];
int INF = 1e9;

struct MOVE
{
  int y, x;
};

MOVE moves[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void func(int x, int y)
{
  queue<MOVE> q;
  q.push({0, 0});

  while (q.size())
  {
    int curX = q.front().x;
    int curY = q.front().y;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int newX = curX + moves[i].x;
      int newY = curY + moves[i].y;

      if (0 <= newX && newX < m && 0 <= newY && newY < n)
      {
        if (maps[newY][newX])
        {
          if (dis[newY][newX] > dis[curY][curX] + 1)
          {
            dis[newY][newX] = dis[curY][curX] + 1;
            q.push({newY, newX});
          }
        }
        else
        {
          if (dis[newY][newX] > dis[curY][curX])
          {
            dis[newY][newX] = dis[curY][curX];
            q.push({newY, newX});
          }
        }
      }
    }
  }
}

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n;
  string str;
  for (int i = 0; i < n; i++)
  {
    cin >> str;
    int j = 0;
    for (auto s : str)
    {
      maps[i][j] = s - '0';
      dis[i][j] = INF;
      j++;
    }
  }

  dis[0][0] = 0;
  func(0, 0);

  cout << dis[n - 1][m - 1];

  return 0;
}