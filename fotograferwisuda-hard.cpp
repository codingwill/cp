#include <bits/stdc++.h>

using namespace std;

void cetakKombin(float L, float P, float K, string* kombin)
{
	//cout << L;
	int x = 0;
	int pemisah1 = floor(P/K);
	int pemisah2 = L;
	int pemisah = max(pemisah1, pemisah2);
	int banyakP;
	if (L > 0)
		banyakP = 2*(P/L);
	else
		banyakP = 1;
	while (L > 0 || P > 0)
	{
		//cout << L;
		if (P > L)
		{
			//cout << P << L;
			while (pemisah > 0)
			{
				for (int i = 0; i < 1 && L > 0; i++)
				{
					kombin->insert(x, "L");
					L--;
					x++;	
				//	cout << "L";
				}
				for (int i = 0; i <= banyakP && P > 0; i++)
				{
					kombin->insert(x, "P");
					x++; P--;	
					//cout << "P";
				}	
				pemisah--;			
			}
		}
		else
		{
		//	cout << L;
			if (L > 0)
			{
				for (int i = 0; i < 2 && P > 0; i++)
				{
					kombin->insert(x, "L");
					L--; 
					x++;	
				}
			}
			for (int i = 0; i < banyakP && P > 0; i++)
			{
				kombin->insert(x, "P");
				P--; 
				x++;	
			//	cout << "test";
			}
		}
		
	}
}

int main()
{
	int T;
	cin >> T;
	float L, P, K;
	string kombin[T];
	for (int i = 0; i < T; i++)
	{
		cin >> L >> P >> K;
		if (P/K <= L + 1.0 && L <= 2*P + 2)
		{
			cetakKombin(L, P, K, &kombin[i]);
		}
		else
			kombin[i] = "mustahil";
	}
	
	for (int i = 0; i < T; i++)
		cout << kombin[i] << endl;
}
