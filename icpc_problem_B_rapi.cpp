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
	i = 0;	
	int ulang = 0;
	string bef, af;
	for (i = 0; i <= x; i++)
	{
		//cout << "tes" << endl;		
		if (subW[i] == ",")
		{
			//cout << "-----------------------" << "\n";
			bef = subW[i-1];  
			af = subW[i+1];
		//	nKoma[ulang]++;
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
				if (k > 0) //penyisipan koma di belakang kata hanya berlaku jika kata tersebut bukan kata pertama pada kalimat #bugfix_01
				{
					if (subW[k] == af && subW[k-1] != "." && subW[k-1] != ",")
					{
						x++;
						for (int n = x; n > k; n--)
						{
							subW[n] = subW[n-1];
						}
						subW[k] = ",";
					}
				}

			}	
		}
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
