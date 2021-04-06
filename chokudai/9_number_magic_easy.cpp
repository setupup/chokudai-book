/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
class NumberMagicEasy {
public:
	int theNumber(string answer)
	{
		vector<int> card1 = { 1,2,3,4,5,6,7,8 };
		vector<int> card11 = { 9,10,11,12,13,14,15,16 };

		vector<int> card2 = { 1,2,3,4,9,10,11,12 };
		vector<int> card22 = { 5,6,7,8,13,14,15,16 };
		vector<int> card3 = { 1,2,5,6,9,10,13,14 };
		vector<int> card33 = { 3,4,7,8,11,12,15,16 };
		vector<int> card4 = { 1,3,5,7,9,11,13,15 };
		vector<int> card44 = { 2,4,6,8,10,12,14,16 };
		vector<int> res;
		vector<vector<int>> all_cards;
		all_cards.push_back(card1);
		all_cards.push_back(card2);
		all_cards.push_back(card3);
		all_cards.push_back(card4);
		vector<vector<int>> all_cards_neg;
		all_cards_neg.push_back(card11);
		all_cards_neg.push_back(card22);
		all_cards_neg.push_back(card33);
		all_cards_neg.push_back(card44);
		cout << "what?" << endl;
		for (int i = 0; i < 4; ++i)
		{

			if (answer[i] == 'Y')
			{
				if (res.empty())
				{
					res.resize(all_cards[i].size());
					copy(all_cards[i].begin(), all_cards[i].end(), res.begin());

				}
				else
				{
					vector<int> res_temp;
					for (auto& elem1 : res)
						for (auto& elem2 : all_cards[i])
						{
							if (elem1 == elem2)
							{
								res_temp.push_back(elem1);
							}
						}
					swap(res, res_temp);
				}
			}
			else
			{
				if (res.empty())
				{
					res.resize(all_cards_neg[i].size());
					copy(all_cards_neg[i].begin(), all_cards_neg[i].end(), res.begin());
				}
				else
				{
					vector<int> res_temp;
					for (auto& elem1 : res)
						for (auto& elem2 : all_cards_neg[i])
						{
							if (elem1 == elem2)
							{
								res_temp.push_back(elem1);
							}
						}
					swap(res, res_temp);
				}
			}
			for (auto& elem : res)
			{
				cout << elem << endl;
			}
			cout << "one turn" << endl;
		}
		return res[0];
	}
};
*/

#include <string>
using namespace std;

class NumberMagicEasy {
public:
	char check(int X[], int number)
	{
		for (int x; x < 8; ++x)
		{
			if (X[x] == number)
			{
				return 'Y';
			}
		}
		return 'N';
	}

	int theNumber(string answer)
	{
		int A[] = { 1,2,3,4,5,6,7,8 };
		int B[] = { 1,2,3,4,9,10,11,12 };
		
		int C[] = { 1,2,5,6,9,10,13,14 };
		int D[] = { 1,3,5,7,9,11,13,15 };

		for (int i = 1; i <= 16; ++i) {
			if (check(A, i) != answer[0]) continue;
			if (check(B, i) != answer[0]) continue;
			if (check(C, i) != answer[0]) continue;
			if (check(D, i) != answer[0]) continue;
			return i;
		}
		return 0;
	}

	int theNumber3(string answer) //process all the patterns
	{
		string c[] =
		{
			"YYYY",
			"YYYN",
			"YYNY",
			"YYNN",
			"YNYY",
			"YNYN",
			"YNNY",
			"YNNN",
			"NYYY",
			"NYYN",
			"NYNY",
			"NYNN",
			"NNYY",
			"NNYN",
			"NNNY",
			"NNNN"
		};

		for (int i = 0; i <= 15; ++i)
		{
			if (answer == c[i])
			{
				return i + 1;
			}
		}
		return 0;
	}
};