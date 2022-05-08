#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include<iostream>
using namespace std;
typedef long long ll;
typedef long double ld;

string keyword;
vector<string> v_t;
ll dong; // so dong
ll cot; // so cot

bool answer = false;
vector<vector<ll>> flag;
/*
	Input:
		ABCCED
		ABCE
		SFCS
		ADEE
		.
	Output:
		true
*/
int ktHople(ll, ll);
void joinWord(ll, ll, ll);
void Solving();

int main()
{
	cin >> keyword;
	string str;
	cin >> str;

	while (str != ".")
	{
		v_t.push_back(str);
		cin >> str;
	}
	dong = size(v_t);
	cot = v_t[0].length();
	flag.resize(dong, vector<ll>(cot, 0));
	Solving();

	return 0;
}
int ktHople(ll a, ll b)
{
	if (0 <= a && a < dong && 0 <= b && b < cot)
		return 1;
	return 0;
}
void joinWord(ll i, ll a, ll b)
{
	if (answer)
		return;
	for (ll j = -1; j <= 1; j++)
	{
		for (ll k = -1; k <= 1; k++)
		{
			ll cur_a = a + j;
			ll cur_b = b + k;
			if (!ktHople(cur_a, cur_b) || flag[cur_a][cur_b] == 1 || v_t[cur_a][cur_b] != keyword[i])
				continue;
			flag[cur_a][cur_b] = 1;
			if (i < keyword.length() - 1)
				joinWord(i + 1, cur_a, cur_b);
			else
				answer = true;
			flag[cur_a][cur_b] = 0;
		}
	}
}
void Solving()
{
	for (ll i = dong - 1; i >= 0; i--)
	{
		for (ll j = cot - 1; j >= 0; j--)
		{
			if (v_t[i][j] != keyword[0])
				continue;
			else
			{
				if (keyword.length() == 1)
				{
					cout << "true";
					cout << endl;
				}
			}

			flag[i][j] = 1;
			joinWord(1, i, j);
			flag[i][j] = 0;
		}
	}

	if (answer == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}
