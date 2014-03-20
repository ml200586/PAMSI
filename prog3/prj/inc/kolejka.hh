#include "kolejka_list.hh"

/*!
 * \file
 * \brief Definicja klasy KolejkaTab, deklaracje metod klasy.
 * 
 * Plik zawiera definicje klasy KolejkaTab oraz deklaracje metod tej klasy.
 *  
*/

const int initKolejka = 1;
/*!
 *	\brief Klasa realizujaca strukture danych - kolejke - za pomoca tablicy.
 * 
 * Jej zadaniem jest wprowadzenie danych do kolejki oraz usuwanie ich. 
 * Umozliwia takze wypisywanie kolejki. 
 * 
*/
class KolejkaTab
{
private:
	
 /*!
 *\brief Podwajanie rozmiaru kolejki
 * 
 * Metoda umozliwia podwojenie wielkosci tablicy. Metoda wykorzystywana 
 * w funkcji Push, kiedy cale dostepne miejsce zostanie zapelnione.
 * 
 */
	void Powieksz_Kolejke ();
	
 /*!
 *\brief Powiekszanie rozmiaru kolejki o jeden
 * 
 * Metoda umozliwia powiekszenie wielkosci tablicy o jeden. Metoda 
 * wykorzystywana w funkcji Push, kiedy cale dostepne miejsce zostanie 
 * zapelnione.
 * 
 */
	void Powieksz_Kolejke_dod1 ();
	
 /*!
 *\brief Zmienna wskaznikowa - adres pierwszego elementu tablicy
 * 
 */
	int * _tab;
	
 /*!
 *\brief Zmienna reprezentujaca aktualny rozmiar tablicy
 * 
 */
	int   _rozmiar;
	
 /*!
 *\brief Zmienna reprezentujaca obecna ilosc elementow w kolejce
 * 
 */
	int _top;      
      

public:

/*!
 * \brief Konstruktor klasy KolejkaTab
 * 
 * Tworzy obiekt klasy KolejkaTab.
 */
	KolejkaTab ();
	
/*!
 * \brief Destruktor klasy KolejkaTab
 * 
 * Likwiduje obiekt klasy KolejkaTab z pamieci komputera.
 */
	~KolejkaTab ();
	
 /*!
 *\brief Dodawanie wektora do kolejki
 * 
 *\param Wektor wekt - wektor do umieszczenia w kolejce
 * 
 * Metoda odklada kolejno elementy wektora na koniec kolejki. W razie 
 * potrzeby powieksza tablice uzywajac funkcji Powieksz_Kolejke(podwaja 
 * rozmiar tablicy) lub Powieksz_Kolejke_dod1 (powieksza rozmiar tablicy 
 * o jeden)
 * 
 */
	void Enqueue (Wektor wek);
	
 /*!
 *\brief Zdejmowanie elementu z kolejki
 * 
 * Metoda usuwajaca element z poczatku kolejki.
 * 
 */
	int  Dequeue ();
	
 /*!
 *\brief Sprawdzanie czy kolejka jest pusta
 * 
 * Metoda, wykorzystujac zmienna _top (licznik elementow w kolejce), 
 * sprawdza, czy kolejka jest pusta. 
 * 
 *\return True - jesli kolejka jest pusta
 *\return False - jesli w kolejce cos sie znajduje 
 */
	bool Is_Empty () const;     // czy stos jest pusty?

 /*!
 *\brief Ilosc elementow kolejki
 * 
 * Metoda przekazuje informacje o tym, ile elementow aktualnie znajduje 
 * sie w kolejce.
 * 
 * \return _top - licznik elementow kolejki
 * 
 */
	int Size ();
	
 /*!
 *\brief Wypisywanie kolejki
 * 
 * Metoda umozliwia wyswietlenie kolejki.
 * 
 */
	void Wypisz ();
};
