#include "plecak.hh"

/*!
 * \file
 * \brief Modul zawierajacy definicje metod klas Przedmiot i Plecak oraz funkcji Tworz.
 *										
 */

void Tworz(int ilosc_elementow, int pojemnosc_plecaka)
{
	Przedmiot zerowy, pierwszy, drugi, trzeci, czwarty, piaty;
	Plecak g;
	
	zerowy.DodajPrzedmiot(0, 0, 0);
	pierwszy.DodajPrzedmiot(1, 1, 1);// ind wart waga
	drugi.DodajPrzedmiot(2, 2, 3);
	trzeci.DodajPrzedmiot(3, 2, 2);
	czwarty.DodajPrzedmiot(4, 1, 2);
	piaty.DodajPrzedmiot(5, 4, 3);
	
	g._przedmioty.push_back(zerowy);
	g._przedmioty.push_back(pierwszy);
	g._przedmioty.push_back(drugi);
	g._przedmioty.push_back(trzeci);
	g._przedmioty.push_back(czwarty);
	g._przedmioty.push_back(piaty);
	
	cout<<"\n\nRozwiazywanie problemu plecakowego...\n"<<endl;
	
	g.ProblemPlecakowy(ilosc_elementow, pojemnosc_plecaka);

}


void Plecak::ProblemPlecakowy(int ilosc_elementow, int pojemnosc_plecaka)
{
	Elementy x, y;
	Elementy obecny;
	
	_ileelem=ilosc_elementow;
	_pojemnosc=pojemnosc_plecaka;
	
	for(int i=0; i<=_ileelem; i++)
	{
		for(int j=0; j<=_pojemnosc; j++)
		{
			if(_przedmioty[i]._waga>j)
			{
				if(i>0)
					_tablica[i][j]=_tablica[i-1][j];
				else
				{
					_tablica[i][j]._suma=0;
					_tablica[i][j]._wybrane_elementy.push_back(0);
				
				}
			}
			else
			{
				if(i>0)
				{
					x=_tablica[i-1][j];
					x._suma=ObliczWartosc(x);
					y=_tablica[i-1][j-_przedmioty[i]._waga];
					y._suma=ObliczWartosc(y);
					y._suma+=_przedmioty[i]._wartosc;
					if(y._suma>x._suma)
					{
						_tablica[i][j]=y;
						_tablica[i][j]._wybrane_elementy.push_back(i);
					}
					else
					{
						_tablica[i][j]=x;
					}
				}
			}
		}
	}
	
	cout<<"Dobrane przedmioty: "<<endl;
	
	for(unsigned int i=0; i<_tablica[_ileelem][_pojemnosc]._wybrane_elementy.size(); i++)
		cout<<_tablica[_ileelem][_pojemnosc]._wybrane_elementy[i]<<" ";
	
	cout<<endl<<endl;
}


int Plecak::ObliczWartosc(Elementy pole)
{
	int wartosc=0;
	
	for(unsigned int i=0; i<pole._wybrane_elementy.size(); i++)
	{
		wartosc+=_przedmioty[pole._wybrane_elementy.size()]._wartosc;
	}
	return wartosc;
}

void Przedmiot::DodajPrzedmiot (int ind, int wart, int wag)
{
	_indeks=ind;
	_wartosc=wart;
	_waga=wag;
}
