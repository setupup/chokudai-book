#include <cmath>
#include <string>
#include <vector>
using namespace std;
class StockHistroy
{
public:
	int maximumEarnings(int initialInvestment,
		int monthlyContribution,
		vector<string> stockPrices) //notice the special format in element
	{ 
		int money = initialInvestment;
		int month = stockPrices.size();
		int corp = 1; //from 1
		char* s = (char*)stockPrices[0].c_str();//string --> c_str;
		while (*s++) //fix usage
		{
			if (*s == ' ') //stringstream?
				corp++; //
		}

		int prices[50][999]; //cause this kind of data type issimple!
							 //some area may be empty, but its okay!!
		double max = 0;
		double profit = 0;
		double proportion[50] = { 0 }; //array intial?
		bool buy[50] = { false };

		for (int i = 0; i < month; ++i)
		{

			//string:: find(), substr(), c_str()
			//c_str:: atoi()
			string s = stockPrices[i]; 
			for (int j = 0; j < corp; ++j)
			{
				int pos = s.find(" ");
				if (pos == string::npos)
				{
					prices[i][j] = atoi(s.c_str());
				}
				else
				{
					prices[i][j] = atoi(s.substr(0, pos).c_str());
					s = s.substr(pos + 1, s.size());//?
				}
			}
		}

		for (int i = month - 2; i >= 0; --i) //this is quite important!!(reverse order)
		{
			for (int j = 0; j < corp; ++j)
			{
				double p = 1.0*prices[month - 1][j] / prices[i][j] - 1;

				if (0 < p&&max < p)
				{
					buy[i] = true;
					max = p;
					proportion[i] = p;
				}
			}
		}

		for (int i = 0; i < month; ++i)
		{
			if (buy[i])
			{
				profit += money*proportion[i];
				money = 0;
			}
			money += monthlyContribution;
		}

	}
};