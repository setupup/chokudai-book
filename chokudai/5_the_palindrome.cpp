/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class ThePalindrome
{
public:
	int find(string s)
	{
		//string t = s;
		//reverse(s.begin(),s.end());
		for (int i = s.length() - 2; i > s.length() / 2; --i)
		{
			int len = s.length() - 1 - i;
			int start = i - (s.length() - 1 - i);
			string t = s.substr(i);
			reverse(t.begin(), t.end());

			if (t != s.substr(start, len))
			{
				return s.length() + i + 1;
			}
		}
		return s.length();
	}
};

*/

#include <string>
using namespace std;

class ThePalindrome
{
public://O(n2)
	int find(string s)
	{
		for (int i = s.size();; ++i)
		{
			bool flag = true;
			for (int j = 0; j < s.size(); ++j)
			{
				if ((i - j - 1) < s.size() && s[j] != s[i - j - 1])
				{
					flag = false;
					break;
				}
			}
			if (flag)
				return i;
		}
	}

};