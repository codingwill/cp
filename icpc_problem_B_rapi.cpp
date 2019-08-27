#include <bits/stdc++.h>
/* code by wkwkwill */
using namespace std;

int main()
{
	string W, subW[100000];
	int x = 0, i = 0, j = 0;
	getline(cin, W);
	int len = W.length();
	//MEMBUAT SUBSTRING DARI KALIMAT (STRING INPUT) BERDASARKAN KATA, TANDA TITIK, DAN TANDA KOMA.
	while (i < len)
	{
		if (W[i] == ' ')
		{
			x++;
			j = 0;
		}
		else if (W[i] == ',' || W[i] == '.')
		{
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
	}
	
	//MENYISIPKAN KOMA KE DALAM KALIMAT SESUAI ATURAN DR. SPRINKLER
	bool noKoma = false;
	i = 0;
	int ulang = 0;
	int nKomaOld = 0, nKomaNew = 0;
	while(!noKoma)
	{
		string bef, af;
		int nKoma[100000];
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
					}
				}	
			}
		}
		if (ulang > 0)
		{
			if (nKoma[ulang-1] == nKoma[ulang])
			{
				noKoma = true;	
			}
		}
		ulang++;
		noKoma = true;
	}
	
	//MENCETAK KALIMAT YANG SUDAH DIEDIT BERDASARKAN ATURAN DR. SPRINKLER DAN KAIDAH PENULISAN KALIMAT
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
