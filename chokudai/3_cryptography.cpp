/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Cryptography {
public:
	long long encrypt(vector<int> numbers)
	{
		auto min_elem = min_element(numbers.begin(), numbers.end());
		long long multiply = 1;
		bool flag = false;
		for (auto& elem : numbers)
		{
			if (elem == *min_elem && !flag)
			{
				flag = true;
				multiply *= (elem + 1); //increase that elem by 1
			}
			else
			{
				multiply *= elem;
			}
		}
		return multiply;
	}
};*/
//my code is okay