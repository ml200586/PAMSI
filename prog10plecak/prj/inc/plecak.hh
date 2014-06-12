#include <iostream>
#include <iomanip>
#include <vector>

/*!
 * \file
 * \brief Definicja klas Przedmiot oraz Plecak, deklaracje metod tych klas.
 *  
*/
using namespace std;

 /*!
 *	\brief Klasa Przedmiot, realizująca elementy znajdujące się w plecaku 
 * 			- przedmioty.
 * 
 * Posiada pola typu int: _indeks, _wartosc, _waga, opisujące atrybuty, 
 * jakie posiadają przedmioty w plecaku. Jest zaprzyjaźniona z klasą Plecak, 
 * aby możliwe było wzajemne korzystanie ze swoich pól.
*/
class Przedmiot
{
	int _indeks;
	int _wartosc;
	int _waga;
	
public:
	friend class Plecak;
	
/*!
*\brief Dodawanie nowych przedmiotów
* 
* \param int ind - indeks nowego przedmiotu
* \param int wart - wartość nowego przedmiotu
* \param int wag - waga nowego przedmiotu
*
* Funkcja odpowiedzialna za tworzenie nowych przedmiotów, przypisuje 
* elementowi klasy Przedmiot zadane atrybuty - indeks, wagę, wartość.
*/
	void DodajPrzedmiot (int ind, int wart, int wag);

};

 /*!
 *	\brief Klasa Plecak, realizująca trzon algorytmu - plecak z przedmiotami.
 * 
 * Posiada pola typu int: _pojemnosc, _ileelem, określające pojemność plecaka 
 * oraz ilość elementów, które się w nim znajdują. Jest zaprzyjaźniona z klasą 
 * Przedmiot, aby możliwe było wzajemne korzystanie ze swoich pól.
*/
class Plecak
{
	int _pojemnosc;
	int _ileelem;
	
/*!
 * \brief Struktura reprezentująca pola w _tablicy, znajdującej się w klasie Plecak.
 * 
 * Struktura posiada pole typu int: _suma, określające sumę wartości Elementow 
 * znajdującym się w danym polu _tablicy. Jest tu też vector<int> przechowujący 
 * indeksy wybranych elementów.
 */ 
	struct Elementy
	{
		int _suma;
		vector<int> _wybrane_elementy;
	};
	
/*!
 * \brief Tablica elementów.
 * 
 * Dwuwymiarowa tablica, w której polach znajdują się Elementy
 */ 
	Elementy _tablica [6][7];
	
public:

/*!
 * \brief Wektor Przedmiotów.
 * 
 * Tutaj przechowywane są przedmioty znajdujące się w plecaku.
 */
	vector<Przedmiot> _przedmioty;
	
/*!
*\brief Funkcja rozwiązująca problem plecakowy
* 
* \param int ilosc_elementow - ilość elementów znajdujących się w plecaku
* \param int pojemnosc_plecaka - maksymalna łączna waga przedmiotów, jaką 
* 								może pomieścić plecak
* 
* W funkcji realizowane jest rozwiązanie problemu plecakowego, z użyciem
* metody programowania dynamicznego
*/
	void ProblemPlecakowy(int ilosc_elementow, int pojemnosc_plecaka);
	
/*!
*\brief Funkcja obliczająca sumę wartości przedmiotów w danym polu
* 
* \param Elementy pole - elementy pola w _tablicy
* 
* W funkcji sumowane są wartości elementówznajdujących się w danym polu. 
* Odbywa się to z wykorzystaniem wektora indeksów przedmiotów.
* 
* \return wartosc - sumaryczna wartość przedmiotów
*/
	int ObliczWartosc(Elementy pole);


};

/*!
*\brief Funkcja tworząca przedmioty i plecak oraz wywołująca funkcję rozwiązującą 
* 		problem.
* 
* \param int ilosc_elementow - ilość elementów znajdujących się w plecaku
* \param int pojemnosc_plecaka - maksymalna łączna waga przedmiotów, jaką 
* 								może pomieścić plecak
* 
* Tutaj wywoływane są funkcje DodajPrzedmiot, aby stworzyć przedmioty dostępne 
* dla późniejszego algorytmu oraz ProblemPlecakowy, aby ten wcześniej zdefiniowany 
* problem plecakowy rozwiązać.
*/
void Tworz(int ilosc_elementow, int pojemnosc_plecaka);
