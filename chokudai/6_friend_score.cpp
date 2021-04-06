/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FriendScore {
public:
	int highestScore(vector<string> friends)
	{
		vector<int> score_table(friends.size(), 0);
		for (int j = 0; j < friends.size(); ++j)
		{
			int row = count(friends[j].begin(), friends[j].end(), 'Y');
			score_table[j] += row;
			for (int i = 0; i < friends.size(); ++i)
			{
				if (friends[j][i] == 'Y')
				{
				// for each [j][k]==Y, [i][k] must ==N then it canbe counted 
					if (row - 1 > 0)
					{
						score_table[i] += (row - 1);
					}

				}
			}
		}
		auto iter = max_element(score_table.begin(), score_table.end());
		return distance(score_table.begin(), iter);
	}
};*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class FriendScore
{
public:
	int highestScore(vector<string> friends)
	{
		int ans = 0;
		int n = friends[0].length();

		for (int i1 = 0; i1 < n; ++i1)
		{
			int cnt = 0; //real friends for i1

			for (int i2 = 0; i2 < n; ++i2)
			{
				if (i1 == i2)
					continue;
				if (friends[i1][i2] == 'Y')
				{
					cnt++; //direct friends
				}
				else
				{//maybe indirect friends
					for (int i3 = 0; i3 < n; ++i3)
					{
						if (friends[i2][i3] == 'Y'&&
							friends[i3][i1] == 'Y')
						{
							++cnt;
							break;
						}
					}
				}
			}
			ans = max(ans, cnt);
		}
		return ans;
	}
};
