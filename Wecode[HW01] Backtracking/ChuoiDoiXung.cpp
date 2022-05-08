#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;

/*
	Input: aab
	Output:
		aa b
		a a b
*/
int isSymmetry(string);
void Solving(ll, ll);
void Xuat(vector<string>);
string str;
ll l;
vector<string> S;
int main()
{
	cin >> str;

	l = str.length(); // Kich thuoc dau vao cua chuoi

	Solving(0, 0);
	return 0;
}
int isSymmetry(string s)
{
	for (int i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() - i - 1])
			return 0;
	}
	return 1;
}

void Xuat(vector<string> S)
{
	ll n = size(S);
	for (int i = 0; i < n; i++)
	{
		cout << S[i] << " ";
	}
	cout << endl;
}

void Solving(ll i, ll begin)
{
	for (ll j = 1; j <= l - begin; j++)
	{
		string sub_str = str.substr(begin, j);
		if (!isSymmetry(sub_str))
		{
			continue;
		}
		else
		{
			S.push_back(sub_str);
			if (begin + j < l)
			{
				Solving(i + 1, begin + j);
			}
			else
				Xuat(S);
			S.erase(S.begin() + i);
		}
	}
}
