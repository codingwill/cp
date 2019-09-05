#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	string h[t];
	int a, b, k, z;
	for (int i = 0; i < t; i++)
	{
		z = 0;
		cin >> a >> b >> k;	
		if (a == 0)
		{
			if (b > k)
			{
				h[i] = "mustahil";
			}
			else
			{
				for (int j = 0; j < b; j++)
				{
					h[i].insert(h[i].length(), "P");
					z++;
				}		
			}	
		}
		else
		{
			if (b > 2*k)
			{	
				h[i] = "mustahil";
			}
			else
			{
				for (int j = 0; j < min(b,k); j++)
				{
					h[i].insert(h[i].length(), "P");
					z++;
				}
				h[i].insert(h[i].length(), "L");
				z++;
				for (int j = 0; j < b-min(b,k); j++)
				{
					h[i].insert(h[i].length(), "P");
					z++;
				}
			}
			
		}
	}	
	for (int i = 0; i < t; i++)
	{
		cout << h[i].c_str() << endl;
	}
}
