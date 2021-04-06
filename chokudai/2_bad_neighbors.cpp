#include <vector>
#include <algorithm>
using namespace std;

class BadNeighbors {
public:
	//there some problems in this code!!
	int maxDonations(vector<int> donations)
	{
		int i;
		int ans = 0;

		int N = donations.size();
		int* dp = new int[N];

		for (i = 0; i < N - 1; ++i) //1~n-1
		{
			dp[i] = donations[i];
			if (i > 0) //from 1
				dp[i] = max(dp[i], dp[i - 1]);
			if (i > 1) //from 2
				dp[i] = max(dp[i], dp[i - 2] + donations[i]);
			ans = max(ans, dp[i]);
		}

		for (i = 0; i < N - 1; ++i) //2~n
		{
			dp[i] = donations[i + 1];
			if (i > 0)
				dp[i] = max(dp[i], dp[i - 1]);
			if (i > 1)
				dp[i] = max(dp[i], dp[i - 2] + donations[i + 1]);
			ans = max(ans, dp[i]);
		}

		delete [] dp;
		return ans;
	}
};