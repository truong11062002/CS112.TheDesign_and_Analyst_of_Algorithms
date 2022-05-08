#include<iostream>
#include<vector>

using namespace std;
/*
	Input: 2
	Output:
		(())
		()()
	Input: 3
	Output:
		((()))
		(()())
		(())()
		()(())
		()()()
*/

void Solving(vector<int>,int, int);
void Xuat(vector<int>);
int isValid(vector<int>);
int main()
{
	int n;
	cin >> n;

	vector<int> S(n * 2);
	S[0] = -1;
	Solving(S, n, 1);
	return 0;
}
int isValid(vector<int> S)
{
	int flag = 0;
	int num = 0;
	for (int i = 0; i < S.size(); i++)
	{
		num += S[i];
		if (num > 0)
			return flag;
	}
	if (num == 0)
		flag = 1;
	return flag;
}

void Xuat(vector<int> S)
{
	for (int i = 0; i < S.size(); i++)
	{
		switch (S[i])
		{
		case -1:
			cout << "(";
			break;
		case 1:
			cout << ")";
			break;
		}
	}
}

void Solving(vector<int> S, int n, int i)
{
	for (int j = 0; j <= 1; j++)
	{
		switch (j)
		{
		case 0:
			S[i] = -1;
			break;
		case 1:
			S[i] = 1;
			break;
		}

		if (i < 2 * n - 1)
			Solving(S, n, i + 1);
		else
		{
			if (isValid(S) == 1)
			{
				Xuat(S);
				cout << endl;
			}
		}

	}
}
