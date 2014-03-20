#include "kolejka.hh"

/*!
 * \file
 * \brief Modul zawierajacy definicje metod klasy KolejkaTab.
 *										
 */
 
KolejkaTab::KolejkaTab () 
	: _top (0), _rozmiar (initKolejka)
{
      _tab = new int [initKolejka]; // utwórz tablicę (przydziel pamięć) w kolejce
}

KolejkaTab::~KolejkaTab ()
{
	delete []_tab; // usuń tablicę z pamięci komputera (zwolnij pamięć)
}

void KolejkaTab::Enqueue (Wektor wek)
{
	for(int i=1; i <= wek._wektor[0]; i++)
      {
		  assert (_top <= _rozmiar);
			if (_top == _rozmiar)
				Powieksz_Kolejke_dod1 ();
		  _tab [_top] = wek._wektor[i];
		  ++_top;
	  }
}

int  KolejkaTab::Dequeue ()
{
	// Nie wolno pobierać liczb z pustego stosu
      assert (_top > 0);
      for(int i=0; i<=_top; i++)
      {
		  _tab[i]=_tab[i+1];
	  }
	  --_top;
	  return _tab [_top];
}

bool KolejkaTab::Is_Empty () const
{
	assert (_top >= 0); 
	return _top == 0;
}


void KolejkaTab::Powieksz_Kolejke ()
{
	cout << "Podwajanie stosu o rozmiarze: " << _rozmiar << ".\n";
      // utwórz na stercie nową tablicę
      int * tabNew = new int [2 * _rozmiar];
      // skopiuj wszystkie elementy
      for (int i = 0; i < _rozmiar; ++i)
            tabNew [i] = _tab [i];
      _rozmiar = 2 * _rozmiar;
      // zwolnij pamięć, zajmowaną przez starą tablicę
      delete []_tab;
      // zapisz adres nowej tablicy w składowej _tab
      _tab = tabNew;
}

void KolejkaTab::Powieksz_Kolejke_dod1 ()
{
	// utwórz na stercie nową tablicę
      int * tabNew = new int [1 + _rozmiar];
      // skopiuj wszystkie elementy
      for (int i = 0; i < _rozmiar; ++i)
            tabNew [i] = _tab [i];
      _rozmiar = 1 + _rozmiar;
      // zwolnij pamięć, zajmowaną przez starą tablicę
      delete []_tab;
      // zapisz adres nowej tablicy w składowej _tab
      _tab = tabNew;
}

int KolejkaTab::Size ()
{
	return _top;
}


void KolejkaTab::Wypisz ()
{
	for(int i=0; i<_top; i++)
	{
		cout << _tab[i] << endl;
	}
}
