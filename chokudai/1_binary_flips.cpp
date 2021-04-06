#include <queue>
#include <algorithm>

using namespace std;
class BinaryFlips
{
	/* use state transition in bfs */
public:
	int minimalMoves(int A, int B, int K)
	{//exceptions
		if (A == 0)
			return 0;
		if (A + B < K)
			return -1;

		int* array=new int[A + B + 1]; //important!!
		for (int i = 0; i <= A + B; ++i)
		{
			array[i] = -1;
		}

		queue<int> q;
		q.push(A);

		array[A] = 0;
		while (!q.empty())
		{
			int i = q.front();// i is num of 0s
			q.pop();

			for (int j = max(0, K - (A + B - i)); j <= min(i, K); ++j)
			{
				int nextzero = i + (K - 2 * j); //next transition

				if (array[nextzero] == -1) //first visit
				{
					if (nextzero == 0)
						return array[i] + 1;

					array[nextzero] = array[i] + 1;// count turns
					q.push(nextzero);
				}
			}
		}
		return -1;
	}
};