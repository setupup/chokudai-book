#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool visited[50] = { false }; //??

class HamiltonPath
{
public:
	vector<string> roads;

	int countPaths(vector<string> roads)
	{
		int group = 0, free = 0;
		int connect[50] = { 0 }; //no need to use fill_n anymore, need to check STD or Primer

		long long sum = 1;

		this->roads = roads;

		for (int i = 0; i < roads.size(); ++i)
		{
			int y = 0;
			for (int j = 0; j < roads[i].size(); ++j)
			{
				if (roads[i].substr(j, 1) == "Y")
				{
					if (2 < ++y)
						return 0;
				}
			}

			connect[i] = y; //0,1,2
		}

		for (int i = 0; i < roads.size(); ++i)
		{
			if (connect[i] == 0)
			{
				visited[i] = true;
				++free;
			}
			else if (connect[i] == 1 && !visited[i])
			{
				++group;
				dfs(i);//will traverse and change visited[]
			}

		}

		for (int i = 0; i < roads.size(); ++i)
		{
			if (!visited[i])
				return 0;
		}
		for (int i = 0; i < group + free; ++i)
		{
			sum = sum*(i + 1) % 1000000007;
		}
// 		for (int i = 0; i < group; ++i)
// 		{
// 			sum = sum * 2 % 1000000007;
// 		}
		sum = sum * 2 * group % 1000000007;
		return (int)sum;
	}

	void dfs(int city)
	{
		visited[city] = true;
		for (int i = 0; i < roads[city].size(); ++i)
		{
			if (roads[city].substr(i, 1) == "Y" && !visited[i])
			{
				dfs(i);
			}
		}
	}
};