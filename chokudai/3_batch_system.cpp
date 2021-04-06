#include <map>
#include <string>
#include <vector>
using namespace std;

class BatchSystem
{
public:
	vector<int> schedule(vector<int> duration, vector<string> user)
	{
		int N = duration.size();
		map<string, long long> jobTime; //value position intitial value is 0
		for (int n = 0; n < N; ++n)
		{
			jobTime[user[n]] += duration[n];
		}
		
		vector<bool> done(N);
		vector<int> ans;
		while (ans.size() < N)
		{
			string next;
			for (int n = 0; n < N; ++n)
			{
				if (!done[n] &&
					(next.empty() ||jobTime[user[n]] < jobTime[next]))
				{
					next = user[n]; //find the min user time as the next
				}
			}

			for (int n = 0; n < N; ++n)
			{
				if (user[n] == next)
				{
					done[n] = true;
					ans.push_back(n); //as n from 0 to N-1, its in lexico order
				}
			}
		}

	}
};