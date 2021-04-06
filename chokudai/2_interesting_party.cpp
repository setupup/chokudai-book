/*#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;
class InterestingParty
{
public:
	int bestInvitation(vector<string> first, vector<string> second)
	{
		unordered_map<string, int> my_map;
		for (auto& elem : first)
		{
			my_map[elem]++;
		}
		for (auto& elem : second)
		{
			my_map[elem]++;
		}
		int res = -1;
		for (auto& elem : my_map)
		{
			if (elem.second > res)
			{
				res = elem.second;
			}
		}
		return res;
	}
};*/

#include <string>
#include <map>
#include <vector>
using namespace std;

class InterestingParty
{
public:
	int bestInvitation(vector<string> first, vector<string> second)
	{
		map<string, int> dic; //dic is a good name

		for (int i = 0; i < first.size(); ++i)
		{
			dic[first[i]] = 0;
			dic[second[i]] = 0;
		}//actually not needed.

		for (int i = 0; i < first.size(); ++i)
		{
			dic[first[i]]++;
			dic[second[i]]++;
		}

		int ans = 0;
		map<string, int>::iterator it; //when to use const_iterator
		for (it = dic.begin(); it != dic.end(); ++it)
		{
			if (ans < it->second)
			{
				ans = it->second;
			}
		}

		return ans;
	}
};