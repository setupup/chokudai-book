#include <vector>
using namespace std;
class InterestingDigits
{
public:
	//base from 3 - 30
	/* O(n4) solution */
	vector<int> digits(int base)
	{
		vector<int> ans;

		for (int n = 2; n < base; ++n)
		{
			bool ok = true; //use this to indicate if find counter-example
			for (int k1 = 0; k1 < base; ++k1)
			{
				for (int k2 = 0; k2 < base; ++k2)
				{
					for (int k3 = 0; k3 < base; ++k3)
					{ 
						//transfrom into decimal form and do the calculation
						if ((k1 + k2*base + k3*base*base) % n == 0 &&
							(k1 + k2 + k3) % n != 0)
						{
							ok = false;
							break;
						}
					}
					if (!ok) break;
				}
				if (!ok) break;
			}
			if (ok) ans.push_back(n);
		}
		return ans;
	}

	/* solution using mod O(n) */
	vector<int> digits(int base)
	{
		vector<int> ans;

		for (int i = 2; i < base; ++i)
		{
			//just compute base-1 and less divisor
			//reason from the expansion of binary to decimal formular expansion.
			if (((base - 1) % i) == 0) //at least one 16-->15
				ans.push_back(i);
		}
	}

};