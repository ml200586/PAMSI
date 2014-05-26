#include <iostream>
#include <string>
#include <sstream>

/*!
 * \file
 * \brief Zawiera definicje klase TabHash oraz Element, ich metod oraz
 * instrukcje załączenia poszczególnych bibliotek.
 */


using namespace std;


class Element
{
private:
	string dane;

public:
	string adres;
	bool zajety;
	Element *nastepny;
	
	Element()
	:zajety(NULL), nastepny(NULL)
	{
	}
	
	friend class TabHash;


	friend ostream& operator <<(ostream& ostr, Element& elem);
};


class TabHash
{
private:
	Element * _element;
	int _rozmiar;
	
public:
	
	TabHash(int ile);
	
	Element* operator [](string adres);
	
	void dodaj(string adres, string dane);

	void usun(string adres);
	
	Element* znajdz(string adres);
	
	int haszuj(string adres);
	
	friend class Element;
};
