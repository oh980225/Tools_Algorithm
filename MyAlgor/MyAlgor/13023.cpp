#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[2005];
bool chk[2005];

void dfs(int s, int dis)
{
    if (dis >= 4)
    {
        printf("1");
        exit(0);
    }
    for (int i = 0; i < tree[s].size(); i++)
    {
        if (!chk[tree[s][i]])
        {
            chk[tree[s][i]] = 1;
            dfs(tree[s][i], dis + 1);
            chk[tree[s][i]] = 0;
        }
    }
    return;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    for (int i = 0; i < n; i++)
    {
        chk[i] = 1;
        dfs(i, 0);
        chk[i] = 0;
    }

    printf("0");
    return 0;
}