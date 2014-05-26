#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <ctime>
#include <time.h>
#include <stdlib.h>
/*!
 * \file
 * \brief Definicja klasy Graf, deklaracje jej metod. Definicje klas 
 * Krawędź i Wierzchołek oraz definicje przeciążeń operatorów dla Wierzchołka.
 *  
*/
using namespace std;
 /*!
 *	\brief Klasa, odpowiedzialna za reprezentację grafu.
 * 
 * Graf jest tutaj realizowany przy pomocy listy sąsiedztwa. Najważniejszym 
 * elementem klasy jest tablica wektorów, tworząca spis połączeń między 
 * wierzchołkami. Klasa zawiera dwie wewnętrzne struktury - reprezentujące 
 * wierzchołek oraz krawędź.
*/
class Graf
{
	

/*!
 * \brief Struktura reprezentująca wierzchołki grafu.
 * 
 * Struktura posiada 3 pola: 2 typu bool przechowujące informację, czy 
 * wierzchołek istnieje, oraz czy został już odwiedzony (wykorzystywane 
 * w algorytmach przeszukujących graf). Jest też pole typu int, informujące 
 * jaki jest indeks - numer wierzchołka.
 */ 		
	struct Wierzcholek
	{
		int _indeksW;
		bool _czyJest;
		bool _czyOdwiedzony;
		
		double _wspx;
		double _wspy;
		double _heur;
		double _trasa;
		double _suma;
		int _poprzedni;
		
/*!
*\brief Konstruktor elementu struktury Wierzcholek.
*
* Przy tworzeniu nowego elementu struktury Wierzcholek, jako początkową 
* wartość pola _czyJest zadajemy true, a _czyOdwiedzony - false.
*/	
		Wierzcholek()
		{
			_czyJest=true;
			_czyOdwiedzony=false;
			_heur = 0;
			_trasa = 0;
			_suma = 0;
			_poprzedni=0;
		};
		
				
/*!
*\brief Równość dwóch wierzchołków.
* 
* \param Wierzcholek w1 - wierzcholek do porownania	
*
* Przeciazenie operatora porównania. Jest to metoda typu bool, zwraca
* true w przypadku, gdy wierzchołki sa jednakowe, lub false, gdy się różnią.
* Sprawdzane jest to przez porównanie numerów indeksu wierzchołków. Jako, 
* że jest to metoda klasy Wierzcholek, drugi wierzcholek do porownania 
* jest domyslny. 
* 
* \return true lub false
*/
		bool operator == (Wierzcholek w1)
		{
			if (w1._indeksW==_indeksW) return true;
			else return false;
		};
		
/*!
*\brief Nierówność dwóch wierzchołków.
* 
* \param Wierzcholek w1 - wierzcholek do porownania	
*
* Przeciazenie operatora porównania. Jest to metoda typu bool, zwraca
* true w przypadku, gdy wierzchołki się różnią, lub false, gdy są jednakowe.
* Sprawdzane jest to przez porównanie numerów indeksu wierzchołków. Jako, 
* że jest to metoda klasy Wierzcholek, drugi wierzcholek do porownania 
* jest domyslny. 
* 
* \return true lub false
*/
		bool operator != (Wierzcholek w1)
		{
			if (w1._indeksW!=_indeksW) return true;
			else return false;
		};
		
/*!
*\brief Przypisanie wierzchołka.
* 
* \param Wierzcholek w1 - wierzchołek do przypisania
*
* Przeciazenie operatora przypisania. Jest to metoda typu Wierzcholek, zwraca
* . Jako, 
* że jest to metoda klasy Wierzcholek, drugi wierzcholek do przypisania 
* jest domyslny. 
* 
* \return true lub false
*/		
		Wierzcholek operator = (Wierzcholek w1)
		{
			_indeksW=w1._indeksW;
			_czyJest=w1._czyJest;
			_czyOdwiedzony=w1._czyOdwiedzony;
		
			_wspx=w1._wspx;
			_wspy=w1._wspy;
			_heur=w1._heur;
			_trasa=w1._trasa;
			_suma=w1._suma;
			_poprzedni=w1._poprzedni;
			return w1;
		};
		
	};

 /*!
 *	\brief Pole tworzące listę sąsiedztwa.
 * 
 * Tablica wskaźników na wektor. Wektory przechowują wierzchołki. Indeksy
 * tablicy odnoszą się do wierzchołków. Wektory zawarte w każdym z pól 
 * prezentują sąsiadów każdego z wierzchołków (o ile jakichś posiada).
*/
	vector<Wierzcholek> * _A;
/*!
 * \brief Struktura reprezentująca krawędzie grafu.
 * 
 * Struktura posiada 3 pola: 2 wskaźniki na Wierzcholek, odwołujące się
 * do wierzchołków, które krawędź łączy, oraz typu int przedstawiające, 
 * jaką wagę ma krawędź. 
 */ 
	struct Krawedz
	{
		Wierzcholek * _w1;
		Wierzcholek * _w2;
		double _waga;
	};
	
/*!
 * \brief Wektor wierzchołków.
 * 
 * Wektor elementów struktury Wierzcholek. W tym polu przechowywane są 
 * wszystkie wierzchołki tworzące graf.
 */
	vector<Wierzcholek> _wekW;
	
/*!
 * \brief Wektor krawędzi.
 * 
 * Wektor elementów struktury Krawedz. W tym polu przechowywane są wszystkie 
 * wierzchołki tworzące graf.
 */
	vector<Krawedz> _wekK;
	
/*!
 * \brief Stos elementów struktury Wierzcholek.
 * 
 * Pole to wykorzystywane jest do przeszukiwania grafu "najpierw w głąb".
 */
	stack<Wierzcholek> _stos;
	
/*!
 * \brief Kolejka elementów struktury Wierzcholek.
 * 
 * Pole to wykorzystywane jest do przeszukiwania grafu "najpierw w szerz".
 */
	queue<Wierzcholek> _kolejka;

public:
	bool jest;

	int _ile_wierzcholkow;
	int _ile_krawedzi;
	int _ile_miejsc_w_tab;

/*!
*\brief Konstruktor elementu klasy Graf.
*
* Przy tworzeniu nowego elementu klasy Graf, na zero ustawiamy wartości 
* pól: _ile_wierzcholkow, _ile_krawedzi, _ile_miejsc_w_tab, aby później
* móc odpowiednio zmieniać ich wartość w trakcie wykonywanie programu.
*/	
	Graf()
	{
		_ile_wierzcholkow=0;
		_ile_krawedzi=0;
		_ile_miejsc_w_tab=0;	
	};

/*!
*\brief Funkcja tworząca tablicę wektorów.
* 
* \param int ile - zmienna typu int, przez którą będziemy zadawać spodziewaną 
* 					ilość wierzchołków w grafie
* 
* Funkcja tworzy listę sąsiedztwa, za pomocą której reprezentujemy graf 
* w programie.
*/	
	void Nowy(int ile){_A = new vector<Wierzcholek> [ile];};
	
/*!
*\brief Funkcja sprawdzająca z czym łączy się zadany wierzchołek.
* 
* \param int v1 - indeks wierzchołka, którego sąsiadów chcemy sprawdzić
* 
* Funkcja najpierw wykorzystuje funkcję empty() - sprawdza czy dany wierzchołek
* posiada jakichkolwiek sąsiadów. Jeśli nie - wyświetla stosowny komunikat, 
* jeśli tak - przy pomocy iteratora przeszukuje jego wektor sąsiedztwa 
* i wyświetla indeksy wierzchołków, z którymi jest połączony.
*/	
	//vector<Graf::Wierzcholek> Sasiedztwo(int v1);
	vector<int> Sasiedztwo(int v1);
	
/*!
*\brief Funkcja wyświetlająca graf-  wypisująca na ekran jego listę sąsiedztwa.
* 
* Funkcja odwołuje się do po kolei do wszystkich wektorów w tablicy sąsiedztwa, 
* a następnie przy pomocy iteratora wyświetla jej zawartość.
*/	
	void Wyswietl();
	
/*!
*\brief Funkcja dodająca krawędź.
* 
* \param int v1 - indeks pierwszego wierzchołka, który chcemy połączyć krawędzią
* \param int v2 - indeks drugiego wierzchołka, który chcemy połączyć krawędzią
* \param int c - waga krawędzi
* 
* Funkcja odpowiada za przypisanie odpowiednich paremetrów nowej krawędzi 
* oraz za dodanie informacji o niej do tablicy sąsiedztwa. Jeśli jeden, lub oba,
* wierzchołki, między którymi chcemy dodać krawędź, nie istnieje, zostaje 
* dodany w tej funkcji.
*/	
	void Dodaj_krawedz(int v1, int v2, int c);
	
/*!
*\brief Funkcja usuwająca krawędź.
* 
* \param int v1 - indeks pierwszego wierzchołka, przy którym chcemy usunąć krawędź
* \param int v2 - indeks drugiego wierzchołka, przy którym chcemy usunąć krawędź
* \param int c - waga krawędzi
* 
* W funkcji, zadana krawędź zostaje usunięta z wektora krawędzi oraz z tablicy 
* sąsiedztwa.
*/	
	void Usun_krawedz(int v1, int v2, int c);
	
/*!
*\brief Funkcja sprawdzająca, czy zadane wierzchołki się łączą.
* 
* \param int v1 - indeks pierwszego wierzchołka do sprawdzenia
* \param int v2 - indeks drugiego wierzchołka do sprawdzenia
* 
* W funkcji przeszukiwana jest, przy pomocy iteratora, tablica sąsiedztwa.
* Wyświetlona zostaje informacja czy wierzchołki są połączone (a jeśli tak 
* to na ile sposobów), czy nie.
*/	
	void Czy_polaczone(int v1, int v2);
	
/*!
*\brief Funkcja usuwająca wierzchołek.
* 
* \param int v1 - indeks wierzchołka który chcemy usunąć
* 
* Wierzchołek jest usuwany przez nadanie jego polu _czyJest wartości false.
* Konsekwencją tego jest to, że nie wyświetli się już w tablicy sąsiedztwa 
* oraz na jego miejsce można dodać inny wierzchołek o tym samym indeksie.
*/
	void Usun_wierzcholek(int v1);
	
/*!
*\brief Funkcja dodająca wierzchołek.
* 
* \param int v1 - indeks wierzchołka, który chcemy dodać
* 
* Początkowo wierzchołki dodawane są pokolei, jeśli jakiś wierzchołek wcześniej
* usunięto, nowy można dodać na jego miejsce.
*/
	void Dodaj_wierzcholek(int v1, int x, int y);
	
/*!
*\brief Funkcja przechodząca graf w sposób "najpierw w głąb" .
* 
* \param int v1 - indeks wierzchołka, od którego chcemy zacząć przeszukiwanie
* 
* Funkcja wykorzystuje stos z szablonu stack. Odkłada na niego wierzchołki 
* do odwiedzenia i w ten sposób przechodzi cały graf. Potrzebne jest tu także 
* pole w wierzchołku "_czyOdwiedzony", aby uniknąć ponownego przechodzenia 
* tego samego wierzchołka. W łatwy sposób można tę funkcję wykorzystać 
* do wyszukiwania określonego elementu w grafie.
*/
	void DFS(int poczatek, int szukany);
	
/*!
*\brief Funkcja przechodząca graf w sposób "najpierw w szerz" .
* 
* \param int v1 - indeks wierzchołka, od którego chcemy zacząć przeszukiwanie
* 
* Funkcja wykorzystuje kolejkę z szablonu queue. Odkłada do niej wierzchołki 
* do odwiedzenia i w ten sposób przechodzi cały graf. Potrzebne jest tu także 
* pole w wierzchołku "_czyOdwiedzony", aby uniknąć ponownego przechodzenia 
* tego samego wierzchołka. W łatwy sposób można tę funkcję wykorzystać 
* do wyszukiwania określonego elementu w grafie.
*/
	void BFS(int poczatek, int szukany);
	
/*!
*\brief Funkcja sprawdzająca, czy zadane wierzchołki się łączą.
* 
* \param int v1 - indeks pierwszego wierzchołka do sprawdzenia
* \param int v2 - indeks drugiego wierzchołka do sprawdzenia
* 
* W funkcji przeszukiwana jest, przy pomocy iteratora, tablica sąsiedztwa.
* Wyświetlona zostaje informacja czy wierzchołki są połączone, czy nie.
* Jest to metoda typu bool, zwraca true w przypadku, gdy wierzchołki się 
* są połączone, lub false, jeśli nie.
* 
* \return true lub false
*/	
	bool Polaczone(int v1, int v2);
	
/*!
*\brief Funkcja wyszukująca krawędź.
* 
* \param int v1 - indeks wierzchołka, pierwszego końca końca krawędzi 
* \param int v2 - indeks wierzchołka, drugiego końca krawędzi
* 
* W funkcji, sprawdzane są kolejno elementy wektora krawędzi, aż do momentu 
* odnalezienia takiej krawędzi, która łączy zadane wierzchołki.
* 
* \return _wekK[i] - krawędź spełniająca zadane kryteria
*/	
	Graf::Krawedz Znajdz_krawedz(int v1, int v2);
	
/*!
*\brief Funkcja sprawdza występowanie elementu w wektorze.
* 
* \param vector<Wierzcholek> wektor - wektor wierzchołków, do przeszukania 
* \param Wierzcholek wi - poszukiwany wierzchołek
* 
* W funkcji, sprawdzane są przy pomocy iteratora kolejne elementy wektora 
* krawędzi, w poszukiwaniu identycznego z zadanym, jeśli taki zostanie 
* odnaleziony, funkcja zwraca true, jeśli nie - false.
* 
* \return true lub false
*/	
	bool Czy_w_wektorze(vector<int> wektor, int wi);
	
/*!
*\brief Funkcja licząca heurystykę.
* 
* \param int v1 - indeks pierwszego wierzchołka
* \param int v2 - indeks drugiego wierzchołka
* 
* W funkcji, wyliczana jest szacunkowa długość drogi między dwoma wierzchołkami. 
* Każdy wierzchołek posiada współrzędne, a heurystyką jest w programie 
* odległość w linii prostej między nimi.
* 
* \return heur - wartość heurystyki, typu double
*/	
	double Heurystyka (int v1, int v2);
	
/*!
*\brief Funkcja wypisująca kolejne wierzchołki przebyte po drodze do szukanego.
* 
* \param int poczatkowy - indeks początkowego wierzchołka
* \param int koncowy - indeks końcowego wierzchołka
* 
* W funkcji, poprzez wykorzystanie pola klasy Wierzchołek _poprzedni, które 
* jest wskaźnikiem na wcześniej odwiedzony element, odtwarzana jest ścieżka 
* przebyta od wierzchołka początkowego do końcowego.
* 
*/	
	void Pokaz_sciezke(int poczatkowy, int koncowy);
	
/*!
*\brief Funkcja heurystyczna wyszukiwania elementu w grafie.
* 
* \param int poczatkowy - indeks początkowego wierzchołka
* \param int koncowy - indeks końcowego wierzchołka
* 
* Funkcja odnajduje najkrótszą drogę pomiędzy dwoma wierzchołkami w grafie. 
* 
*/	
	void Astar (int poczatek, int cel);
};

/*!
*\brief Funkcja tworząca graf oraz uruchamiająca przeszukiwanie.
* 
* W funkcji dodawane są wierzchołki i krawędzie grafu, zostaje uruchomione 
* wyszukiwanie A*, DFS i BFS (z odpowiednimi parametrami), oraz mierzony 
* jest czas wykonania tych algorytmów.
* 
*/
void Tworz();
