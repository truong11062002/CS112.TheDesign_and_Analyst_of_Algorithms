#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

/*
	Input:
	n: Cột điểm của môn học
	Mảng chứa n cột điểm
	Đtb môn của SV
	Output:
	Ứng với mỗi cách ghi điểm cuả giảng viên xuất ra trên một hàng các điểm số của mỗi cột điểm, cách nhau bởi khoảng trắng.
*/

void Diem(vector<int>, int, vector<double>, double, int);
void Xuat(vector<double>, int);
double LamTron(double);
double kq = 0;
int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	vector<double> S(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	double x;
	cin >> x; // dtb của SV
	
	Diem(a, n, S, x, 0);

	return 0;
}

double LamTron(double number)
{
	number = number * 10;
	number = (double)roundf(number) / 10;
	return number;
}

void Xuat(vector<double> S, int n)
{
	for (int k = 0; k < n; k++)
		cout << S[k] << " ";
	cout << endl;
}


void Diem(vector<int> a, int n, vector<double> S, double x, int i)
{
	for (double j = 0.25; j <= 10; j += 0.25)
	{
		double temp1 = LamTron(kq);
		if (temp1 > x)
			break;
		S[i] = j;
		kq = kq + (a[i] * S[i]) / 100;
		if (i == n - 1)
		{
			double temp2 = LamTron(kq);
			if (temp2 == x)
				Xuat(S, n);
		}
		else
			Diem(a, n, S, x, i + 1);
		kq = kq - (a[i] * S[i]) / 100;
	}
}