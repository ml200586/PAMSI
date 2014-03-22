#include "sortowanie.hh"

/*!
 * \file
 * \brief Modul zawierajacy definicje metod klasy StosList.
 *										
 */
 
StosList::StosList()
{
	end=NULL;                   
}
 
void StosList::Push(Wektor wekt)   
{
	for(int i=1; i <= wekt._wektor[0]; i++)
	{
		Element *e = new Element; 
		e->value = wekt._wektor[i];
		e->prev = end;
		end = e;                      
		}
}

bool StosList::Is_Empty()
{
	if(end == NULL)return true;              
	else return false;
}

void StosList::Pop()
{
	if(Is_Empty() != 0) 
	{cout << "\nStos pusty!!!!\n" << endl << endl; 
	}                
	else
	{
		Element *tmp = end->prev;
		end=NULL;
		delete end;
		end = tmp;
	}
}
 
void StosList::Wypisz()
{
	if(Is_Empty() != 0) 
	{cout << "\nStos pusty!!!!\n" << endl;}
	else
	{
		Element *tmp;
		tmp = end;
		cout << "\n---------- Stos: ----------\n";
		while(end != NULL)
		{
			cout << end->value << endl;
			end = end -> prev;
			}
			end = tmp;
			}
}
 
StosList::~StosList()
{
	while(Is_Empty() == 0) 
	{
		this->Pop();
		}
		if(end==NULL) cout<<"\nUsunieto Stos\n";
}
