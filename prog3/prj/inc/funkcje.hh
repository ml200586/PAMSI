#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
/*!
 * \file
 * \brief Definicja klasy Wektor, deklaracje funkcji uzytych w programie.
 * 
 * Plik zawiera definicje klasy Wektor oraz deklaracje metod i przeciazen 
 * operatorow dla tej klasy.
 * Znajdują się tu również deklaracje funkcji Start oraz Zapis_do_csv.
 *  
*/
 
 using namespace std;
 
 /*!
 *	\brief Klasa, której elementem jest obiekt typu vector<int>.
 * 
 * Najważniejszym jej zadaniem jest przechowywanie w vectorze liczb pobranych
 * z pliku, ktore zostana pozniej odpowiednio przetworzone i poddane dzialaniu
 * pewnego algorytmu.
*/
 class Wektor
 { 
	 public:
	 vector<int> _wektor; 

/*!
*\brief Porownanie dwoch wektorow
* 
* \param Wektor W1 - wektor do porownania	
*
* Przeciazenie operatora porownania. Jest to metoda typu bool, zwraca
* true w przypadku, gdy wektory sa jednakowe, lub false, gdy sie roznia.
* Jako, ze jest to metoda klasy Wektor, drugi wektor do porownania jest 
* domyslny.
* 
* \return true lub false
*/
	 bool operator == (Wektor W1);
	 
/*!
*\brief Przypisanie jednego wektora do drugiego
* 
* \param Wektor w1 - wektor, ktorego wartosci zostana przypisane innemu
* 					wektorowi
*
* Przeciazenie operatora przypisania. Jako, ze jest to metoda klasy Wektor, 
* drugi wektor jest domyslny.
* 
* \return wektor - obiekt typu Wektor, bedacy wynikiem operacji
*/
	 Wektor operator = (Wektor w1);
	 
/*!
*\brief Dodajnie elementow do wektora
 * 
 *\param Wektor w1 - wektor, ktorego elementy maja zostac dodane na koniec 
 * 					innego wektora
 * 
 * Przeciazenie operatora dodawania. Metoda realizujaca dodanie elementow 
 * jednego wektora na koniec innego wektora.
 * 
* \return wynik - obiekt typu Wektor, bedacy wynikiem operacji
*/ 
	 Wektor operator + (Wektor w1);
	 

 /*!
 *\brief Mnozenie wektora przez liczbe
 * 
 *\param Wektor wektor - wektor do pomnozenia
 *\param int czynnik - liczba, przez ktora ma byc pomnozony wektor
 * 
 * Metoda wykonujaca algorytm mnozenia wektora przez liczbe.
 * 
 *\return wektor - obiekt typu Wektor, bedacy wynikiem operacji
 */
	 Wektor Mnozenie (Wektor wektor, int czynnik);
	 
 /*!
 *\brief Zamiena elementow wektora
 * 
 *\param Wektor &wektor - wektor, ktorego elementy zostana zamienione, 
 * 						przekazywany przez referencje.
 *\param int numer1 - numer pierwszego elementu, ktory ma zostac zamieniony
 *\param int numer2 - numer drugiego elementu, ktory ma zostac zamieniony
 * 
 * Metoda realizujaca zamiane miejscami dwoch elementow tego samego wektora
 * 
 */
	 void Zamien_elementy (Wektor &wektor, int numer1, int numer2);
	 
 /*!
 *\brief Odwrocanie kolejnosci elementow wektora
 * 
 *\param Wektor &wektor - wektor, ktorego elementy maja zostac zapisane 
 * 						odwrotnie.
 * 
 * Metoda realizujaca odwrocenie kolejnosci zapisu elementow w obiekcie 
 * klasy Wektor.
 * 
 */
	 void Odwroc_kolejnosc (Wektor &wektor);
	 
 /*!
 *\brief Dodajnie elementu do wektora
 * 
 *\param Wektor &wektor - wektor, do ktorego ma zostac dopisany element
 *\param int element - wektor, ktory ma zostac dopisany do wektora
 * 
 * Metoda realizujaca dopisanie jednego elementu - jednej liczby na koniec 
 * zadanego wektora.
 * 
 */
	 void Dodaj_element (Wektor &wektor, int element);
	 
 /*!
 *\brief Dodajnie elementow do wektora
 * 
 *\param Wektor &wektor - wektor, do ktorego maja zostac dopisane elementy
 *\param Wektor wektor2 - wektor, ktorego zawartosc ma zostac dopisana 
 * 						do innego wektora
 * 
 * Metoda realizujaca dopisanie jednego lub wiecej elementu(bedacego wektorem)
 * na koniec innego wektora.
 * 
 */
	 void Dodaj_elementy (Wektor &wektor1, Wektor wektor2);
	 
 /*!
 *\brief Wczytywanie liczb z pliku do wektora
 * 
 *\param const char *nazwa_pliku - wskaznik na nazwe wczytywanego pliku
 * 
 * Metoda realizujaca wczytywanie danych z pliku do programu i wpisywanie
 * ich jako elementy wektora. Sprawdzana jest takze, poprawnosc otwarcia
 * pliku i wyswietlony zostaje stosowny komunikat.  
 * 
 *\return wektor - obiekt typu Wektor, bedacy wynikiem operacji
 */
	 Wektor Wczytywanie(const char *nazwa_pliku);
	 
/*!
*\brief Wyswietlanie wektorow
* 
* \param ostream &out - strumien wyjsciowy przekazywany przez referencje
* \param Wektor L - zmienna typu Wektor, pobrana ze strumienia
*
* Przeciazenie operatora wyjscia. Funkcja odpowiada, za poprawne wyswietlenie
* obiektu klasy Wektor.
* 
* Warunki koncowe: wyswietlenie wektora
* 
* \return in - strumien wejsciowy
*/
	 friend ostream& operator << (ostream &out, Wektor L); 
	 
/*!
*\brief Wczytywanie wektorow
* 
* \param istream &in - strumien wejsciowy przekazywany przez referencje
* \param Wektor& L - zmienna typu Wektor, pobrana ze strumienia
*
* Przeciazenie operatora wejscia. Funkcja odpowiada, za poprawne wczytanie
* do programu obiektu klasy Wektor.
* 
* Warunki poczatkowe: pobranie wektora ze strumienia
* 
* \return in - strumien wejsciowy
*/
	 friend istream& operator >> (istream &in, Wektor& L);
 };
 
/*!
*\brief Funkcja Start obslugujaca wywolanie algorytmu i mierzenie czasu 
* wykonania
* 
* \param int ile_powtorzen - obiekt typu int okreslajacy liczbe wykonan 
* 							algorytmu
* \param int ile_liczb - obiekt typu int okreslajacy liczbe danych, dla 
* 						ktorych zostanie wykonany algorytm
* \param Wektor dane - wektor danych, liczb, dla ktorych zostanie wykonany 
* 						algorytm
*
* Funkcja dopasowuje zadany wektor danych do parametrow wywolania, nastepnie
* wlacza zegar, wykonuje algorytm okreslona ilosc razy i wylacza zegar.
* Nastepnie sprawdza poprawnosc wykonania z wczytanym plikiem sprawdzenia.
* 
* \return czas - czas wykonania zadanej liczby algorytmow podany w sekundach
*/
 double Start (int ile_powtorzen, int ile_liczb, Wektor dane);
 
/*!
*\brief Zapisywanie danych do pliku .csv
* 
* \param double czas_sredni - sredni czas wykonania jednego algorytmu
* \param int ile_powtorzen - liczba powtorzen algorytmu
* \param int ile_liczb - liczba danych podanych do algorytmu
*
* Funkcja realizuje zapis danych otrzymanych z wykonania programu, do pliku
* .csv. W jednej kolumnie zapisywana jest liczba powtorzen algorytmu, 
* w drugiej liczba danych podanych do algorytmu, a w trzeciej - sredni 
* czas wykonania jednego algorytmu.
*/
 void Zapis_do_csv(double czas_sredni, int ile_powtorzen, int ile_liczb);








