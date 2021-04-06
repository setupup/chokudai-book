#include <iostream>
#include <vector>
using namespace std;

class CirclesCountry
{
public:
	int leastBorders(vector<int> X, vector<int> Y, vector<int> R,
		int x1, int y1, int x2, int y2)
	{
		int num = 0;

		for (int i = 0; i < X.size(); ++i)
		{
			if (inside(X[i], Y[i], x1, y1, R[i])!=
				inside(X[i], Y[i], x2, y2, R[i]))
			{
				++num;
			}
		}
		return num;
	}

	bool inside(int x1, int y1, int x2, int y2, int r)
	{
		return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) <= r*r;
	}
};