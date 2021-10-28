#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

class UnionFind
{
public:
	vector<int> p;
	vector<int> dep;

	void init(int n)
	{
		p.resize(n + 1);
		dep.resize(n + 1);
		for (int i = 0; i < p.size(); i++)
		{
			p[i] = i;
			dep[i] = 0;
		}
	}

	int Find(int x)
	{
		if (x == p[x])
			return p[x];
		return p[x] = Find(p[x]);
	}

	bool Union(int x, int y)
	{
		x = Find(x);
		y = Find(y);
		if (x != y)
		{
			if (dep[x] < dep[y])
			{
				p[x] = y;
			}
			else if (dep[y] < dep[x])
			{
				p[y] = x;
			}
			else
			{
				++dep[x];
				p[y] = x;
			}
			return true;
		}
		return false;
	}
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	UnionFind u;
	u.init(n);

	int from, to;

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &from, &to);

		u.Union(from, to);
	}

	set<int> s;
	for (int i = 1; i <= n; i++)
	{
		s.insert(u.Find(i));
	}

	int result = s.size();
	printf("%d", result);

	return 0;
}