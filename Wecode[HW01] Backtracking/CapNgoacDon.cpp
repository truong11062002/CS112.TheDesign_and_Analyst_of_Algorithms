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

void Solving(vector<string>&, int, int,int,string);
int main()
{
	int n;
	cin >> n;

	vector<string> S;
	Solving(S, 0, 0, n, "");
	for (auto s : S)
	{
		cout << s << endl;
	}
	return 0;
}
void Solving(vector<string> &S, int open, int close, int n, string s)
{
	if (open == n && close == n)
	{
		S.push_back(s);
		return;
	}
	if (open < n)
		Solving(S, open + 1, close, n, s + "(");
	if (close < open)
		Solving(S, open, close + 1, n, s + ")");
}
