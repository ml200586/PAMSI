#include <iostream>
#include <vector>

/*!
 * \file
 * \brief Definicja klasy TabAsoc oraz definicje funkcji  uzytych w programie.
 * 
 * Plik zawiera definicje klasy TabAsoc oraz definicje metod i przeciazen 
 * operatorow dla tej klasy.
 *  
*/
using namespace std;

 /*!
 *	\brief Klasa realizująca tablicę asocjacyjną.
 * 
 * Najważniejszym jej zadaniem jest przechowywanie w vectorze obiektów 
 * klasy Element oraz wykonywanie działań na tych obiektach.
*/
template <class V>
class TabAsoc
{
	
 /*!
 *	\brief Klasa przechowująca parę elementów tablicy asocjacyjnej.
 * 
 * Posiada dwa pola - jedno typu string, które jest kluczem/adresem 
 * wartości - drugiego pola tej klasy. Typ obiektu _value można zdefiniować 
 * w zależności od potrzeb, jest zrealizowany w postaci szablonu.
*/
	class Element
	{
		public:
		V _value;
		string _key;
	};

 /*!
 *	\brief Obiekt typu vector, stanowi strukturę tablicy asocjacyjnej.
*/
	vector<Element> _tablica;
	
 /*!
 *	\brief Obiekt typu int, służy do określenia położenia w tablicy.
*/
	int _punkt;	
		
public:
	
/*!
*\brief Funkcja określająca, ile elementów jest w tablicy
* 
* \return _tablica.size() - wbudowana funkcja z szablonu vector, określa 
* 							jego rozmiar
* 
*/
	long IleElementow()
	{
		return _tablica.size();
	}

/*!
*\brief Funkcja sprawdzająca, czy na tablicy jest element o zadanym kluczu
* 
* \param string klucz - klucz poszukiwanej wartości
* 
* Kolejno porównywane są elementy tablicy z zadanym, aż do momentu znalezienia
* identycznego, lub dotarcia do końca tablicy.
* 
* \return true lub false - w zależności, czy na tablicy znajduje się 
* 							poszukiwany element 
* 
*/
	bool CzyJest(string klucz)
	{
		for(int i=0; i<IleElementow(); i++)
		{
			if(_tablica[i]._key == klucz)
				return true;
		}
		return false;
	}
	
/*!
*\brief Funkcja dodająca element na koniec wektora
* 
* \param string klucz - adres dodawanej wartosci
* \param V wartosc - wartosc pozniej definiowanego typu
* 
* Najpierw jest sprawdzane, czy na tablicy znajduje sie juz wartosc 
* o zadanym kluczu, następnie tworzony jest Element o wartosciach 
* przekazanych w parametrach funkcji. Na koniec tablica jest sortowana, 
* jest to przydatne w później wykonywanym algorytmie wyszukiwania binarnego.
* 
* \return false - gdy na tablicy znajduje się już zadany element
* \return true - gdy element został dodany
* 							 
* 
*/	
	bool DodajElement(string klucz, V wartosc)
	{
		if(CzyJest(klucz))
			return false;
		Element war;
		war._key = klucz;
		war._value = wartosc;
		_tablica.push_back(war);
		Quicksort(0,IleElementow()-1);
		return true;
	}
	
/*!
*\brief Funkcja zamieniająca dwa elementy o zadanych indeksach
* 
* \param int i - numer pierwszego elementu
* \param int j - numer drugiego elementu
* 							 
* 
*/	
	void ZamienElementy(int i, int j)
	{
		V wart;
		string klu;
		klu=_tablica[i]._key;
		_tablica[i]._key=_tablica[j]._key;
		_tablica[j]._key=klu;
		wart=_tablica[i]._value;
		_tablica[i]._value=_tablica[j]._value;
		_tablica[j]._value=wart;
	}

/*!
*\brief Funkcja sortowania - Quicksort
* 
* \param int lewy - numer pierwszego elementu z zakresu do posortowania
* \param int prawy - numer ostatniego elementu z zakresu do posortowania
* 
* Funkcja realizuje algorytm sortowania szybkiego. Ustala srodkowy
* element, nastepnie od poczatku tablicy wyszukuje element wiekszy 
* od srodkowego, a od konca - mniejszy od niego. Jesli takie znajdzie 
* - zamienia je ze soba miejscami. Tak sie dzieje dopoki zmienna 
* służąca do wyszukiwania mniejszego nie bedzie wieksza od tej służącej 
* do wyszukiwania większego. Wtedy Quicksort zostaje wywolana ponownie 
* dla tablicy bedacej pierwsza polowa i drugie wywolanie dla tej bedacej 
* druga polowa poczatkowej tablicy do posortowania.
* 
*/	
	void Quicksort(int lewy, int prawy)
	{
		int i=lewy;
		int j=prawy;
		Element x=_tablica[(lewy+prawy)>>1];
		do
		{
			while (_tablica[i]._key<x._key) i++;
			while (_tablica[j]._key>x._key) j--;
			if (i<=j)
			{
				ZamienElementy(i,j);
				i++;
				j--;			
			}
		}
		while (i<=j);
		if(lewy<j) Quicksort(lewy,j);
		if(prawy>i) Quicksort(i,prawy);
	}

/*!
*\brief Funkcja wyszukująca zadany element
* 
* \param string szukanyklucz - adres poszukiwanej wartosci
* \param int lewy - indeks pierwszego elementu z zakresu do posortowania
* \param int prawy - indeks ostatniego elementu z zakresu do posortowania
* \param int &srodek - referencja na środek przedziału
* 
* Sprawdzane jest kolejno, czy poszukiwany element nie jest pierwszym, 
* ostatnim lub środkowym elementem tablicy, jeśli nie obszar poszukiwań 
* jest zawężany - dzielony na dwa i sprawdzany ponownie.
* 
* \return true - gdy poszukiwany element zostanie odnaleziony
* \return false - gdy elementu nie odnaleziono						 
* 
*/	
	bool ZnajdzElement(string szukanyklucz, int lewy, int prawy, int &srodek)
	{
		if(szukanyklucz==_tablica[lewy]._key)
		{
			_punkt=lewy;
			return true;
		}
		else if(szukanyklucz==_tablica[prawy]._key)
		{
			_punkt=prawy;
			return true;
		}
		srodek = (prawy + lewy) / 2 ;
		if(szukanyklucz==_tablica[srodek]._key)
		{
			_punkt=srodek;
			return true;
		}
		else if (szukanyklucz<_tablica[srodek]._key)
			ZnajdzElement(szukanyklucz,lewy,srodek,srodek);
		else if (szukanyklucz>_tablica[srodek]._key)
			ZnajdzElement(szukanyklucz,srodek,prawy,srodek);	
		return false;	
	}

/*!
*\brief Funkcja usuwająca element o zadanym kluczu
* 
* \param string klucz - adres wartosci do usunięcia
* 
* Jeśli udało się znaleźć zadany element, jest on usuwany za pomocą funkcji
* erase().
* 
* \return true - gdy element zostanie odnaleziony i usuniety
* \return false - gdy elementu nie odnaleziono						 
* 
*/		
	bool UsunElement(string klucz)
	{
		int sr;
		
		if (ZnajdzElement(klucz,0,IleElementow()-1,sr))
		{
			
			_tablica.erase(_tablica.begin()+_punkt);
			return true;
		}
		else
			return false;
	}

/*!
*\brief Przeciążenie operatora [], umożliwia dodawanie elementów do tablicy 
* 		asocjacyjnej
 * 
 *\param string klucz - zadany klucz wartości, która ma zostać dodana
 * 
 * 
* \return _tablica[i]._value - gdy klucz, taki jak podany, już istnieje
* \return _tablica[num]._value - gdy klucz, taki jak podany, wczesniej nie 
* 								istniał
* 
*/ 
	V& operator [] (string klucz)
	{
		for(int i=0; i<IleElementow(); i++)
		{
			if(_tablica[i]._key == klucz)
			return _tablica[i]._value;
		}
		long num = IleElementow();
		Element war;
		war._key = klucz;
		_tablica.push_back(war);
		return _tablica[num]._value;
	}

/*!
*\brief Wypisywanie na ekran tablicy asocjacyjnej
* 
* \param ostream & out - strumien wyjsciowy przekazywany przez referencje
* \param TabAsoc<V> & tab - zmienna typu TabAsoc, przekazywana na strumień 
* 							wyjściowy
*
* Przeciazenie operatora wyjscia. Funkcja odpowiada, za poprawne wypisanie
* na standardowe wyjście obiektu klasy TabAsoc, zadanego typu.
* 
* \return out - strumien wyjściowy
*/
	friend ostream & operator << ( ostream & out,  TabAsoc<V> & tab )
	{
		for (int i=0; i<tab.IleElementow(); i++)
			cout<<"\t"<<tab._tablica[i]._key<<"\t\t"<<tab._tablica[i]._value<<endl;
		return out;
	}

};
