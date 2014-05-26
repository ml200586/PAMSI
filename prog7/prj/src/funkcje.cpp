#include "funkcje.hh"
#include <sstream>
#include "tabasoc.hh"
#include "bst.hh"
#include "tabhash.hh"

/*!
 * \file
 * \brief Zawiera definicje funkcji uzytych w programie.
 */

double Start(int ilosc_elementow, int ilosc_powtorzen)
{
	TabHash hash(ilosc_elementow+10);
	BST drzewo;
	TabAsoc<string> tab_a;
	string szukane;
	int lewy=0;
	int prawy=tab_a.Rozmiar()-1;
	int pivot=5;	
	ostringstream ile;
	ile<<ilosc_elementow;
	szukane = ile.str();
	clock_t s,f;
	double czas=0;
	
	for(int i=0; i<ilosc_elementow; i++)
	{
		ostringstream konw;
		konw<<i;
		string znak = konw.str();
		tab_a.DodajElement(znak, znak);
	}
	s=clock();

	for(int i=0; i<ilosc_powtorzen; i++)
	{
		tab_a.Wyszukaj(szukane, lewy, pivot, prawy);
	}
	f=clock();
	czas=(double)(f-s)/(double)(CLOCKS_PER_SEC);
	double czas_sredni=czas/ilosc_powtorzen;
	cout<<endl<<endl<<"Czas wykonania: "<<czas<<endl<<endl;
	Zapis(czas_sredni, ilosc_elementow);
	return czas;
}

void Zapis (double czas_sredni, int ilosc_elementow)
{
	ofstream plik;
	
	plik.open("Pomiary.csv", ios::app);
	plik<<ilosc_elementow<<";"<<czas_sredni<<endl;
	
	plik.close();
}

