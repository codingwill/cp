#include <bits/stdc++.h>

using namespace std;

struct JADWALBUS
{
	int awal, tuj;
	long long pergi, datang;
	double P, P_Sukses, P_Gagal;
};

void transferData(struct JADWALBUS *bis, struct JADWALBUS *temp)
{
	temp->awal = bis->awal;
	temp->tuj = bis->tuj;
	temp->pergi = bis->pergi;
	temp->datang = bis->datang;
	temp->P = bis->P;
	temp->P_Sukses = bis->P_Sukses;
	temp->P_Gagal = bis->P_Gagal;
}

int main()
{
	int M, N; 
	long long K;
	cin >> M >> N >> K;
	
	JADWALBUS bis[M];
	JADWALBUS rute[M];
	JADWALBUS prev;
	JADWALBUS next;
	
	int peluang;
	bool sampai = false, berhasil;
	for (int i = 0; i < M; i++)
	{
		cin >> bis[i].awal >> bis[i].tuj >> bis[i].pergi >> bis[i].datang >> bis[i].P_Sukses;
	}
	
	int nomor = 0;
	for (int j = 0; j < M; j++)
	{
		//cout << "WKWKWKWKWKWKWKW" << " nomor = " << nomor << endl;
		sampai = false;
		if (bis[j].awal == 0)
		{
			transferData(&bis[j],&rute[nomor]);
			rute[nomor].P = rute[nomor].P_Sukses;
			transferData(&bis[j], &prev);
			while (!sampai)
			{
				
				for (int i = 0; i < M; i++)
				{
					if (i != j)
					{
						if (j != nomor)
						{
							transferData(&next, &prev);							
						}
						transferData(&bis[i], &next);
						//cout << "TEST" << endl;
						//cout << prev.datang << " <= " << K << " && " << next.pergi << " > " << prev.pergi << " && " << next.awal<< " == " << prev.tuj << endl;
						//kalau rute langsung ke bandara dan waktu tempuh kurang dari sama dengan K
						if (prev.tuj == 1 && prev.datang <= K)
						{
							//cout << "TEST" << endl;
							//kalau peluang ke bandara = 100%
							if (prev.P_Sukses == 1.0)
							{
								rute[nomor].P = 1.0;
								break;	//hentikan pengecekan rute lain dan simpan peluang rute tsb
							}
							sampai = true; //hentikan pengulangan ketika sampai
						}
						//
						
						if (prev.datang <= K && next.pergi > prev.pergi)
						{
							//cout << "TEST" << endl;
							if (next.awal == prev.tuj)
							{
								//cout << "TEST" << endl;
								rute[nomor].P = rute[nomor].P * (1.0 - next.P_Sukses) + next.P_Sukses;
								sampai = true;
								break;
							}
							else if (prev.awal == next.awal)
							{
								//cout << "TEST" << endl;
								rute[nomor].P = prev.P_Sukses + (1.0 - prev.P_Sukses) * next.P_Sukses;
								sampai = true;
								break;
							}
							/*
							else if ()
							{
							//	cout << "TEST" << endl;
								rute[nomor].P = rute[nomor].P * (1.0 - next.P_Sukses) + next.P_Sukses;
								sampai = true;
								break;	
							}
							*/
							
						}
						else if (next.pergi < prev.pergi)
						{
							
						}
						
					}
					//cout << "TEST" << endl;
					//break;
				}
				//sampai = true;
			}
			nomor++;
		}	
	}
	double maks;
	//cout << bis[nomor].tuj << "\n" << bis[2].awal << "\n" << bis[nomor].datang << "\n" << bis[2].pergi << "\n" << bis[2].datang << endl;
	cout << "\n";
	for (int i = 0; i < nomor; i++)
	{
		if (i == 0)
		{
			maks = rute[i].P;
		}
		else
		{
			maks = max(maks, rute[i].P);	
		}
		//cout << rute[i].P << endl;
	}
	cout << maks << "\n";
	
}
