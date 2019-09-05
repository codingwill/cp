#include <bits/stdc++.h>

using namespace std;

int main ()
{
	long n, sumA = 0, sumB = 0;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sumA += a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		sumB += b[i];
	}
	cout << n*(sumA + sumB) << "\n";
}
