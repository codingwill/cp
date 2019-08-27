#include <bits/stdc++.h>
/* code by wkwkwill */
using namespace std;

int main()
{
	string W, subW[100];
	int x = 0, i = 0, j = 0;
	getline(cin, W);
	int len = W.length();
	//cout << i << len << endl;
	while (i < len)
	{
		if (W[i] == ' ')
		{
			//cout << "asd" << endl;
			x++;
			j = 0;
		}
		else if (W[i] == ',' || W[i] == '.')
		{
			//cout << "asd" << endl;
			x++;
			j = 0;
			subW[x].insert(j, string(1, W[i]));
			j = 0;
		}
		else
		{
			subW[x].insert(j, string(1, W[i]));
			j++;	
		}
		
		i++;
		
		//cout << "tes" << endl;
	}
	//cout << subW[1] << endl;
	bool noKoma = false;
	//while (!noKoma)
	//cout << i << x << endl;
	i = 0;
	//cout << subW[0];
	/*
	cout << x << endl;
	while (i <= x)
	{
		cout << subW[i] << endl;
		i++;
		
	}
	*/
	int ulang = 0;
	int nKomaOld = 0, nKomaNew = 0;
	while(!noKoma)
	{
		string bef, af;
		int nKoma[10000];
		memset(nKoma, 0, sizeof(nKoma));
		for (i = 0; i <= x; i++)
		{
			if (subW[i] == ",")
			{
				bef = subW[i-1];  
				af = subW[i+1];
				nKoma[ulang]++;
				for (int k = 0; k <= x; k++)
				{
					if (subW[k] == bef && subW[k+1] != "." && subW[k+1] != ",")
					{
						x++;
						for (int n = x; n > k+1; n--)
						{
							subW[n] = subW[n-1];
						}
						subW[k+1] = ",";
					}
					else if (subW[k] == af && subW[k-1] != "." && subW[k-1] != ",")
					{
						x++;
						for (int n = x; n > k; n--)
						{
							subW[n] = subW[n-1];
						}
						subW[k] = ",";
					}
					else
					{
						//subW[k].insert(0, " ");
					}
				}	
			}
			//cout << nKomaOld << nKomaNew;	
		}
		//cout << nKomaOld << nKomaNew;
		if (ulang > 0)
		{
			if (nKoma[ulang-1] == nKoma[ulang])
			{
				//cout << nKomaOld << nKomaNew;
				noKoma = true;	
			}
			//nKoma[ulang-1] = nKoma[ulang];
		}
		//cout << "asd" << endl;
		ulang++;
		noKoma = true;
	}
	
	i = 0;
	while (i <= x)
	{
		cout << subW[i];
		if (subW[i] == "," || subW[i] == ".")
		{
			cout << " ";
		}
		else if (subW[i+1] != "." && subW[i+1] != ",")
		{
			cout << " ";
		}
		i++;
		
	}
	cout << "\n";
}
