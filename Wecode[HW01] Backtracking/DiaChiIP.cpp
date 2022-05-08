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
/*
	Input: 25525511135
	Output: 
	255.255.11.135
	255.255.111.35
*/

typedef long long ll;
typedef long double ld;
string s;
vector<ll> S(4);

void DiaChiIP(ll, ll);
void Xuat(vector<ll>);
int main()
{
	cin >> s;

	DiaChiIP(0, 0);
	return 0;
}
void Xuat(vector<ll> S)
{
	cout << S[0] << "." << S[1] << "." << S[2] << "." << S[3] << endl;
}

void DiaChiIP(ll i, ll begin)
{
	for (ll j = 1; j <= 3; j++)
	{
		if (begin + j > s.length() || (s[begin] == '0' && j > 1))
			break;
		S[i] = stoi(s.substr(begin, j)); // convert string to integer
		if (S[i] > 255)
			break;
		else
		{
			if (i < 3)
				DiaChiIP(i + 1, begin + j);
			else if (begin + j == s.length())
				Xuat(S);
		}
	}
}