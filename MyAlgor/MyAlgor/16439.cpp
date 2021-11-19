#include <iostream>
#include <vector>

using namespace std;

vector<int> members[31];
vector<int> checker;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  checker.resize(m);

  for (int i = m; i > 0; i--)
  {
    if (i - 3 <= 0)
    {
      checker.push_back(1);
      continue;
    }
    checker.push_back(0);
  }
  int profer;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> profer;
      members[i].push_back(profer);
    }
  }

  int result = 0;

  do
  {
    int total = 0;
    for (int i = 0; i < n; i++)
    {
      int maxProfer = 0;
      for (int j = 0; j < m; j++)
      {
        if (checker[j])
        {
          maxProfer = max(maxProfer, members[i][j]);
        }
      }
      total += maxProfer;
    }
    result = max(result, total);
  } while (next_permutation(checker.begin(), checker.end()));

  cout << result;

  return 0;
}