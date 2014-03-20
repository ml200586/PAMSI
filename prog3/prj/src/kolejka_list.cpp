#include "kolejka.hh"

/*!
 * \file
 * \brief Modul zawierajacy definicje metod klasy KolejkaList.
 *										
 */
 
KolejkaList::KolejkaList()
{
	first=NULL;
}

void KolejkaList::Enqueue(Wektor wekt)
{
	for(int i=wekt._wektor[0]; i >= 1; i--)
	{
		Element *e = new Element; 
		e->wartosc = wekt._wektor[i];
		e->next = first;
		first = e;                      
	}
}

bool KolejkaList::Is_Empty()
{
	if(first == NULL)return true;              
	else return false;
}

void KolejkaList::Dequeue()
{
	if(Is_Empty()!=0) 
	{cout << "\nKolejka pusta!!!!\n" << endl << endl; 
	}                
	else
	{
		Element *tmp = first->next;
		first=NULL;
		delete first;
		first = tmp;
	}
}

void KolejkaList::Wypisz()
{
	if(Is_Empty()!=0) 
	{cout << "\nKolejka pusta!!!!\n" << endl;}
	else
	{
		Element *tmp;
		tmp = first;
		cout << "\n---------- Kolejka: ----------\n";
		while(first != NULL)
		{
			cout << first->wartosc << endl;
			first = first -> next;
			}
			first = tmp;
			}
}

KolejkaList::~KolejkaList()
{
	while(Is_Empty()==0)
	{
		this->Dequeue();
		}
		if(first==NULL) cout<<"\nUsunieto kolejke\n";
}
