#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include "funkcje.hh"

/*!
 * \file
 * \brief Definicja klasy StosTab, deklaracje metod klasy.
 * 
 * Plik zawiera definicje klasy StosTab oraz deklaracje metod tej klasy.
 *  
*/
const int initStack = 1;

/*!
 *\brief Klasa realizujaca strukture danych - stos - za pomoca tablicy.
 * 
 * Jej zadaniem jest wprowadzenie danych na stos oraz usuwanie ich. 
 * Umozliwia takze wypisywanie stosu. 
 * 
*/
class StosTab
{
	public:
	
/*!
 * \brief Konstruktor klasy StosTab
 * 
 * Tworzy obiekt klasy StosTab.
 */
	StosTab (); 
      
/*!
 * \brief Destruktor klasy StosTab
 * 
 * Likwiduje obiekt klasy StosTab z pamieci komputera.
 */
	~StosTab ();
      
 /*!
 *\brief Dodawanie wektora na stos
 * 
 *\param Wektor wekt - wektor do umieszczenia na stosie
 * 
 * Metoda odklada kolejno elementy wektora na wierzch stosu. W razie 
 * potrzeby powieksza tablice uzywajac funkcji Powieksz_Stos(podwaja 
 * rozmiar tablicy) lub Powieksz_Stos_dod1 (powieksza rozmiar tablicy 
 * o jeden)
 * 
 */
	void Push (Wektor wek);
      
 /*!
 *\brief Ilosc elementow stosu
 * 
 * Metoda przekazuje informacje o tym, ile elementow aktualnie znajduje 
 * sie na stosie.
 * 
 * \return _top - licznik elementow stosu
 * 
 */
	int Size ();
      
 /*!
 *\brief Zdejmowanie elementu ze stosu
 * 
 * Metoda usuwajaca element z gory stosu. 
 * 
 */
	int  Pop ();
	
 /*!
 *\brief Sprawdzanie czy stos jest pusty
 * 
 * Metoda, wykorzystujac zmienna _top (licznik elementow na stosie), 
 * sprawdza, czy stos jest pusty. 
 * 
 *\return True - jesli stos jest pusty
 *\return False - jesli na stosie cos sie znajduje 
 */
	bool Is_Empty () const;  
	
 /*!
 *\brief Wypisywanie stosu
 * 
 * Metoda umozliwia wyswietlenie stosu.
 * 
 */
	void Wypisz ();

private:

 /*!
 *\brief Podwajanie rozmiaru stosu
 * 
 * Metoda umozliwia podwojenie wielkosci tablicy. Metoda wykorzystywana 
 * w funkcji Push, kiedy cale dostepne miejsce zostanie zapelnione.
 * 
 */
	void Powieksz_Stos ();
	
 /*!
 *\brief Powiekszanie rozmiaru stosu o jeden
 * 
 * Metoda umozliwia powiekszenie wielkosci tablicy o jeden. Metoda 
 * wykorzystywana w funkcji Push, kiedy cale dostepne miejsce zostanie 
 * zapelnione.
 * 
 */
	void Powieksz_Stos_dod1 ();
	
 /*!
 *\brief Zmienna wskaznikowa - adres pierwszego elementu tablicy
 * 
 */
	int * _tab;

 /*!
 *\brief Zmienna reprezentujaca aktualny rozmiar tablicy
 * 
 */
	int _rozmiar;
	
 /*!
 *\brief Zmienna reprezentujaca obecna ilosc elementow na stosie
 * 
 */
	int _top;
    

};
