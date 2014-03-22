#include "sortowanie.hh"

/*!
 * \file
 * \brief Modul zawierajacy definicje metod klasy StosTab.
 *										
 */

StosTab::StosTab ()
      : _top (0), _rozmiar (initStack)
{
      _tab = new int [initStack]; // utwórz tablicę (przydziel pamięć) na stosie
}

StosTab::~StosTab ()
{
      delete []_tab; // usuń tablicę z pamięci komputera (zwolnij pamięć)
}

void StosTab::Push (Wektor wek)
{
      for(int i=wek._wektor[0]; i >= 1; i--)
      {
		  assert (_top <= _rozmiar);
			if (_top == _rozmiar)
				Powieksz_Stos ();
		  _tab [_top] = wek._wektor[i];
		  ++_top;
	  }
}

void StosTab::Powieksz_Stos ()
{
      //cout << "Podwajanie stosu o rozmiarze: " << _rozmiar << ".\n";
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

void StosTab::Powieksz_Stos_dod1 ()
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

int StosTab::Pop ()
{
      assert (_top > 0);
      for(int i=0; i<=_top; i++)
      {
		  _tab[i]=_tab[i+1];
	  }
	  --_top;
	  return _tab [_top];      
}

bool StosTab::Is_Empty () const
{
      assert (_top >= 0); // sprawdzamy, czy zmienna _top spełnia kontrakt stosu
      return _top == 0;
}

void StosTab::Wypisz ()
{
	cout << "Stos tablicowy:"<<endl;
	for(int i=0; i<_top; i++)
	{
		cout << _tab[i] << endl;
	}
}

int StosTab::Size ()
{
	return _top;
}
