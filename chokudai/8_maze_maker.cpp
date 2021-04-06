#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;
class MazeMaker {
public:
	int longestPath(vector<string> maze, int startRow,
		int startCol, vector<int> moveRow, vector<int> moveCol)
	{
		int max = 0;
		int width = maze[0].size();
		int height = maze.size();
		int board[50][50]; //note here, is not a bool board/grid
		
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				board[i][j] = -1;
			}
		}

		board[startRow][startCol] = 0;
		
		queue<int> queueX;
		queue<int> queueY;

		queueX.push(startCol);
		queueY.push(startRow);

		while(queueX.size()>0)
		{
			int x = queueX.front();
			int y = queueY.front();
			queueX.pop();
			queueY.pop();
			for (int i = 0; i < moveRow.size(); ++i)
			{
				int nextX = x + moveCol[i];
				int nextY = y + moveRow[i];

				if (0 <= nextY&&nextX < width &&
					0 <= nextY&&nextY <= height&&
					board[nextY][nextX] == -1 &&
					maze[nextY].substr(nextX, 1) == ".")
				{//valid
					board[nextY][nextX] = board[x][y] + 1;
					queueX.push(nextX);
					queueY.push(nextY);
				}

			}
		}
		//at last, board[][] contains the values
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (maze[i].substr(j, 1) == "."&&
					board[i][j] == -1)
				{
					return -1; //the best is impossible
				}
				max = std::max(max, board[i][j]);
			}
		}
	}
};