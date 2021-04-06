#include <iostream>
using namespace std;

bool grid[100][100] = { false };
int vx[] = { 1,-1,0,0 };
int vy[] = { 0,0,1,-1 };
double prob[4];

class CrazyBot {
public:
	double getProbability(int n, int east, int west, int south, int north)
	{//prob[i] can be known after the input.
		prob[0] = east / 100.0;
		prob[1] = west / 100.0;
		prob[2] = south / 100.0;
		prob[3] = north / 100.0;

		//!!!

		return dfs(50, 50, n); //50,50 should be the start center point
	}

	double dfs(int x, int y, int n)
	{
		if (grid[x][y]) //visited
			return 0;
		if (n == 0) //corner case for '0'
			return 1;
		
		grid[x][y] = true;
		double ret = 0;
		for (int i = 0; i < 4; ++i)
		{
			//east -- west -- south -- north
			ret += dfs(x + vx[i], y + vy[i], n - 1)*prob[i]; //multiply the prob of direction and then plus them.
		}
		grid[x][y] = false; //cannot confirm that each branch 
							//do not overlap on the map.
							//this is the place that its diff from danjo traversal.

		return ret;
	}
};