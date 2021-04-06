#include <algorithm>
#include <cmath>
using namespace std;

class AutoLoan
{
public:
	double interestRate(double price, double monthlyPayment,
		int loanTerm)
	{
		double balance;
		double high = 100, low = 0, mid = 0;
		//use while to write binary search
		while ((1e-9 < high - low) && //absolute deviation
			(1e-9 < (high - low) / high)) //relative deviation
		{
			balance = price;
			mid = (high + low) / 2; //notice this low, high, and mid

			for (int j = 0; j < loanTerm; ++j)
			{
				balance *= mid / 1200 + 1;
				balance -= monthlyPayment;
			}
			//always use mid to replace high/low
			if (0 < balance)
			{
				high = mid;
			}
			else
			{
				low = mid;
			}
		}
		return mid;
	}
};