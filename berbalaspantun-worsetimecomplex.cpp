#include <bits/stdc++.h>

using namespace std;

int main ()
{
	long long n, totalWaktu = 0;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			totalWaktu += a[i] + b[i];
		}
	}
	cout << totalWaktu << "\n";
}
