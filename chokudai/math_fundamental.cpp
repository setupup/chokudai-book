#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Prime {
public:
	bool isPrime(int n) //O(n)
	{
		if (n < 2) 
			return false;

		for (int i = 2; i < n; ++i)
		{
			if (n%i == 0)
				return false;
		}
		return true;
	}

	bool isPrime2(int n)
	{
		if (n < 2)
			return false;
		for (int i = 0; i*i <= n; ++i)
		{
			if (n%i == 0)
				return false;
		}
		return true;

	}
	//naive one
	vector<bool> prime_list(int n)
	{
		vector<bool> prime;
		for (int i = 0; i <= n; ++i)
		{
			prime.push_back(isPrime(i));
		}
		return prime;
	}

	//Eratosthenes's furui
	
	vector<int> Eratosthenes(int n)
	{
		vector<bool> dp(n);

		for (int i = 0; i < n; ++i)
		{
			dp[i] = false; //false is prime
		}

		dp[0] = dp[1] = true;
		vector<int> prime;

		for (int i = 2; i < n; ++i)
		{
			if (dp[i])
				continue;
			prime.push_back(i);
			for (int j = i * 2; j < n; j += i)
			{
				dp[j] = true;
			}
		}
		return prime;
	}
};

class Gcd {
public:
	int gcd0(int a, int b)
	{
		for (int i = min(a, b); i >= 2; i--)
		{
			if (a%i == 0 && b%i == 0)
				return i;
		}
	}

	int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		return gcd(b, a%b);
	}

	int extgcd(int a, int b, int& x, int& y)
	{
		int g = a; 
		x = 1; y = 0;
		if (b != 0)
		{
			g = extgcd(b, a%b, y, x);
			y -= (a / b)*x;
		}
		return g;
	}
};

int main()
{
	int a[10] = {1};
	cout << a[10] << endl;
}