//path number of A --> B
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class PathCalculate {
	int h = 5;//4
	int w = 4;//5
public:         // y         x
	int dfs(int nowh, int noww)
	{
		if (nowh > h || noww > w)
			return 0;
		if (nowh == h&&noww == w)
		{
			return 1;
		}

		return dfs(nowh + 1, noww) + dfs(nowh, noww + 1);
	}
	
};

class PathCalMemo {
public:
	//memo method
	static const int h = 5, w = 4;
	int dp[h + 1][w + 1]; //all 0;

	int dfs(int nowh, int noww)
	{
		if (nowh > h || noww > w)
			return 0;
		if (nowh == h&&noww == w)
			return 1;
		if (dp[nowh][noww] != 0)
			return dp[nowh][noww];
		//at the same time fill the dp table
		return dp[nowh][noww] = dfs(nowh + 1, noww) + dfs(nowh, noww + 1);
	}
	//dfs(0,0)
};

class PathCalDp {
public:
	static const int h = 5, w = 4;
	int dp[h + 1][w + 1];

	void calc()
	{
		int i, j;
		dp[0][0] = 1;
		for (i = 0; i < h; ++i)
		{
			for (j = 0; j <= w; ++j)
			{
				if (i != 0)
					dp[i][j] += dp[i - 1][j];
				if (j != 0)
					dp[i][j] += dp[i][j - 1];
			}
		}

	}
	//cout d[h+1][w+1]
};

//second example Knapsack 
class KnapsackMemoTest1 {
public:
	int ws[5] = { 3,4,1,2,3 };
	int ps[5] = { 2,3,2,3,6 };
	int maxw = 10;

	int ret = 0;

	void knapsack(int n, int w, int p)
	{
		if (w > maxw)
			return;
		ret = max(ret, p);
		if (n >= 5)
			return;
		knapsack(n + 1, w, p);
		knapsack(n + 1, w + ws[n], p + ps[n]);
	}
	//ret value is the largest value
		
};
class KnapsackMemoTest2 {
public:
	int ws[5] = { 3,4,1,2,3 };
	int ps[5] = { 2,3,2,3,6 };
	int maxw = 10;

	int ret = 0;

	int knapsack(int n, int w)
	{
		if (w > maxw)
			return -INT_MAX;
		
		if (n >= 5)
			return 0;
		int nchoose = knapsack(n + 1, w);
		int choose = knapsack(n + 1, w + ws[n]) + ps[n];
		return max(nchoose, choose);
	}
	//ret value is the largest value

}; class KnapsackMemo {
public:
	int ws[5] = { 3,4,1,2,3 };
	int ps[5] = { 2,3,2,3,6 };
	int maxw = 10;
	int dp[6][11]; //all -1//n+1, w+1
	

	int knapsack(int n, int w)
	{
		if (w > maxw)
			return -INT_MAX;
		
		if (n >= 5)
			return 0;
		if (dp[n][w] >= 0)
			return dp[n][w];
		return dp[n][w] = max(
		knapsack(n + 1, w),
		knapsack(n + 1, w + ws[n]) + ps[n]
			);
	}
	
};

class KnapsackDp {
public:

	int knapsack()
	{
		int ws[5] = { 3,4,1,2,3 };
		int ps[5] = { 2,3,2,3,6 };

		int maxw = 10;
		int dp[6][11];
		int ret = 0;

		for (int i = 0; i <= 5; ++i)
		{
			for (int j = 0; j <= maxw; ++j)
			{
				if (j + ws[j] <= maxw)
				{
					dp[i + 1][j + ws[i]] =
						max(dp[i][j + ws[i]],
							dp[i][j] + ps[i]);

					ret = max(dp[i + 1][j + ws[i]], ret);
				}
			}
		}
		return ret;
	}

	

};