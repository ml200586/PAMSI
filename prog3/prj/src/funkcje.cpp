#include "kolejka.hh"


/*!
 * \file
 * \brief Modul zawierajacy definicje funkcji mnozenia oraz przeciazen 
 * operatorow dla vectora.
 *										
 */
 
ostream& operator << (ostream &out, const Wektor L)
{
	for(vector<int>::const_iterator Iter = L._wektor.begin(); Iter < L._wektor.end(); ++Iter)
	
	out << *Iter << endl;
	return out;
}

istream& operator >> (istream &in, Wektor& wektor){
	int liczba,pierwsza_liczba;
	in >> pierwsza_liczba;
	wektor._wektor.push_back(pierwsza_liczba);
	for(int i=0; i < pierwsza_liczba; i++)
	{
		in >> liczba;
		wektor._wektor.push_back(liczba);
	}
	return in;
}

Wektor Wektor::Mnozenie (Wektor wektor, int czynnik)
{
	for(int i=1; i <= wektor._wektor[0]; i++)
		{
			wektor._wektor[i]=wektor._wektor[i]*czynnik;
		}
	return wektor;
}

void Wektor::Zamien_elementy (Wektor &wektor, int numer1, int numer2)
{
	int pomocnicza;
	pomocnicza=wektor._wektor[numer1];
	wektor._wektor[numer1]=wektor._wektor[numer2];
	wektor._wektor[numer2]=pomocnicza;
}

void Wektor::Odwroc_kolejnosc (Wektor &wektor)
{
	Wektor pomocniczy;
	pomocniczy=wektor;
	wektor._wektor.clear();
	wektor._wektor.push_back(pomocniczy._wektor[0]);
	for(int i=wektor._wektor[0]; i >= 1; i--)
	{
		wektor._wektor.push_back(pomocniczy._wektor[i]);
	} 
}

void Wektor::Dodaj_element (Wektor &wektor, int element)
{
	wektor._wektor.push_back(element);
}

void Wektor::Dodaj_elementy (Wektor &wektor1, Wektor wektor2)
{
	wektor1=wektor1+wektor2;
}

bool Wektor::operator == (Wektor w1)
{
	for(int i=1; i <= w1._wektor[0]; i++)
	{
		if (w1._wektor[i]==_wektor[i]) continue;
		else return false;
	} 
	return true;
}

Wektor Wektor::Wczytywanie(const char *nazwa_pliku)
{
	ifstream plik(nazwa_pliku);
	if (!plik.is_open())
		cerr << "\nNie otworzylem pliku\n" << nazwa_pliku << endl;
		else
		cout << "\nOtworzylem plik\n" << endl;
	Wektor jakis_wektor;
	plik >> jakis_wektor;
	return jakis_wektor;
}

Wektor Wektor::operator = (Wektor w1)
{
	_wektor.clear();
	for (int i=0; i <= w1._wektor[0]; i++)
	{	
		_wektor.push_back(w1._wektor[i]);
	}
	return w1;
}

Wektor Wektor::operator + (Wektor w1)
{
	Wektor wynik;
	for (int i=1; i <= w1._wektor[0]; i++)
	{	
		_wektor.push_back(w1._wektor[i]);
	}
	wynik._wektor.push_back(_wektor[0]+w1._wektor[0]);
	for (int i=1; i <= _wektor[0]+w1._wektor[0]; i++)
	{	
		wynik._wektor.push_back(_wektor[i]);
	}
	return wynik;
}

double Start (int ile_powtorzen, int ile_liczb, Wektor dane)
{
	clock_t start, stop;
	Wektor pomocniczy=dane;
/* ******* Dopasowanie wektora z pliku do zadanych danych ******* */	
	if (ile_liczb<10) 
	{
		for (int i=1; i<=10-ile_liczb; i++)
		{
			dane._wektor.pop_back();
		}	
		dane._wektor[0]=ile_liczb;
	}
	if (ile_liczb>10 && (ile_liczb/10)>1)
	{
		for (int i=1; i<=(ile_liczb-10)/10; i++)
		{
			dane=dane+pomocniczy;
		}
	}
/* ************************************************************** */
	//cout << "Wektor do pomnozenia: \n" << dane << endl;
	cout << "Liczb jest: " << dane._wektor[0] << endl;
	cout << "Powtorzen jest: " << ile_powtorzen << endl;
	
/* ***************** Mierzenie czasu i algorytm ***************** */
	//KolejkaTab kt;
	//StosList sl;
	//KolejkaList kl;
	StosTab st;
	double czas=0;
	start=clock();
	for (int i=1; i<=ile_powtorzen; i++)
	{
		//kl.Enqueue(dane);	
		st.Push(dane);	
	}	
	stop=clock();
/* ************************************************************** */	

	//dane=dane.Mnozenie(dane,2);
	//cout << "Po mnożeniu: " << endl << dane << endl;
	czas=(double)(stop-start)/(double)(CLOCKS_PER_SEC);
	cout << "Czas wykonania algorytmu: " << czas << endl;


/* ******** Sprawdzenie poprawnosci wykonania algorytmu  ******** */	
/*	Wektor sprawdzenie=sprawdzenie.Wczytywanie("spr.txt");
	pomocniczy=sprawdzenie;
	if (ile_liczb<10) 
	{
		for (int i=1; i<=10-ile_liczb; i++)
		{
			sprawdzenie._wektor.pop_back();
		}	
		sprawdzenie._wektor[0]=ile_liczb;
	}
	if (ile_liczb>10)
	{
		for (int i=1; i<=(ile_liczb-10)/10; i++)
		{
			sprawdzenie=sprawdzenie+pomocniczy;
		}
	}
*/

/* ************************************************************** */
/*	//cout << "Sprawdzenie: \n" << sprawdzenie << endl;
	cout << "Czy mnożenie jest poprawne?" << endl;
	if (dane==sprawdzenie) cout << "Tak\n" << endl;
	else cout << "Nie\n" << endl;
*/

/* ************************************************************** */
	return czas;
}

void Zapis_do_csv(double czas_sredni, int ile_powtorzen, int ile_liczb)
{
	ofstream plik;
	plik.open("Pomiary.csv", ios::app);
	plik << ile_powtorzen << ",";
	plik << ile_liczb << ",";
	plik << czas_sredni << "\n";
	plik.close();
}
