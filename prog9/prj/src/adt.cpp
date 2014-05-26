#include "adt.hh"

/*!
 * \file
 * \brief Modul zawierajacy definicje metod klasy Graf oraz funkcji Tworz.
 *										
 */

void Tworz()
{
	Graf g;
	clock_t start, stop;
	g.Nowy(50);
	
	srand(time(NULL));
	
	for (int i=0; i<50; i++)
		g.Dodaj_wierzcholek(i,1,1);//rand() %5,rand() %5);
	cout << "wierzch jest: " << g._ile_wierzcholkow << endl;
	
	for (int i=0; i<50; i++)
		g.Dodaj_krawedz(i,rand() %49,rand() %10);
		

	cout << "kraw jest: " << g._ile_krawedzi << endl; //<<"Lista: \n";
	/*
	g.Dodaj_wierzcholek(0, 1, 1);
	g.Dodaj_wierzcholek(1, 6, 2);
	g.Dodaj_wierzcholek(2, 3, 2);
	g.Dodaj_wierzcholek(3, 2, 5);
	g.Dodaj_wierzcholek(4, 9, 5);
	g.Dodaj_wierzcholek(5, 6, 5);
	g.Dodaj_wierzcholek(6, 10, 1);
	g.Dodaj_wierzcholek(7, 6, 9);
	g.Dodaj_wierzcholek(8, 9, 8);
	
	g.Dodaj_krawedz(0,2,1);
	g.Dodaj_krawedz(1,2,1);
	g.Dodaj_krawedz(3,2,3);
	g.Dodaj_krawedz(3,5,2);
	g.Dodaj_krawedz(1,5,8);
	g.Dodaj_krawedz(5,4,1);
	g.Dodaj_krawedz(4,7,6);
	g.Dodaj_krawedz(4,6,1);
	g.Dodaj_krawedz(6,7,3);
	g.Dodaj_krawedz(7,8,1);
	*/
	
	//g.Wyswietl();
	//cout<< "Heurystyka: "<<g.Heurystyka(1,6)<<endl<<endl;
	
	g.jest=false;
	
	int ile_powtorzen=1000;
	
	double czas=0;
	start=clock();
	for (int i=1; i<=ile_powtorzen; i++)
	{
		g.Astar(1,45);
		
	}
	if (g.jest==true)
			cout<<"znalazlem"<<endl;	
		
	stop=clock();
	czas=(double)(stop-start)/(double)(CLOCKS_PER_SEC);
	cout << "Czas wykonania algorytmu A*: " << czas << endl;
	cout << "Czas wykonania 1 algorytmu A*: " << czas/ile_powtorzen << endl<< endl;
	
	cout << "jestem po astar" << endl;
	
	
	czas=0;
	start=clock();
	for (int i=1; i<=ile_powtorzen; i++)
	{
		g.BFS(1,45);
		
	}	
	if (g.jest==true)
			cout<<"znalazlem"<<endl;	
	stop=clock();
	czas=(double)(stop-start)/(double)(CLOCKS_PER_SEC);
	cout << "Czas wykonania algorytmu BFS: " << czas << endl;
	cout << "Czas wykonania 1 algorytmu BFS: " << czas/ile_powtorzen << endl<< endl;
	
	
	czas=0;
	start=clock();
	for (int i=1; i<=ile_powtorzen; i++)
	{
		g.DFS(1,45);
		
	}	
	if (g.jest==true)
			cout<<"znalazlem"<<endl;		
	stop=clock();
	czas=(double)(stop-start)/(double)(CLOCKS_PER_SEC);
	cout << "Czas wykonania algorytmu DFS: " << czas << endl;
	cout << "Czas wykonania 1 algorytmu DFS*: " << czas/ile_powtorzen << endl<< endl;
	
	
	//g.Sasiedztwo(0);g.Sasiedztwo(1);g.Sasiedztwo(2);g.Sasiedztwo(3);g.Sasiedztwo(4);g.Sasiedztwo(5);
}

void Graf::Dodaj_wierzcholek(int v1, int x, int y)
{
	_ile_wierzcholkow++;
	//cout << _ile_miejsc_w_tab<< endl;
	//cout << v1 << endl;
	if (v1<_ile_miejsc_w_tab && _wekW[v1]._czyJest==false) 
	{
		_wekW[v1]._czyJest=1;
	}
	
	else
	{
		Wierzcholek w;
		w._wspx = x;
		w._wspy = y;
		w._indeksW=v1;
		w._czyJest=true;
		_wekW.push_back(w);
		_ile_miejsc_w_tab++;
	}
}

void Graf::Dodaj_krawedz(int v1, int v2, int c)
{
	Krawedz k;
	_ile_krawedzi++;
	k._waga = c;

	k._w1=&_wekW[v1];
	k._w2=&_wekW[v2];
	_wekK.push_back(k);
	_A[v1].push_back(_wekW[v2]);
	if (v1 != v2) _A[v2].push_back(_wekW[v1]);
}

void Graf::Usun_krawedz(int v1, int v2, int c)
{
	for (unsigned int i=0; i<_wekK.size(); i++)
	{
		if (((_wekK[i]._w1->_indeksW == v1 && _wekK[i]._w2->_indeksW == v2)
				|| (_wekK[i]._w1->_indeksW == v2 && _wekK[i]._w2->_indeksW == v1)) 
				&& _wekK[i]._waga == c)
			_wekK.erase(_wekK.begin()+i);
	}
	int licznik=0;
	cout<<"Jestem przed usuwaniem z _A"<<endl;
	for (vector<Wierzcholek>::iterator iter = _A[v2].begin(); iter != _A[v2].end(); iter++) 
	{
		licznik++;
		cout<<"Jestem po raz "<<licznik<<endl;
		if (*iter == _wekW[v1]) 
		{
			_A[v2].erase(_A[v2].begin() + licznik -1);
			break;
		}
	}
	licznik=0;
	for (vector<Wierzcholek>::iterator iter = _A[v1].begin(); iter != _A[v1].end(); iter++) 
	{
		licznik++;
		cout<<"Jestem po raz "<<licznik<<endl;
		if (*iter == _wekW[v2]) 
		{
			_A[v1].erase(_A[v1].begin() + licznik -1);
			break;
		}
	}
}

void Graf::Usun_wierzcholek(int v1)
{
	_wekW[v1]._czyJest=false;
}
/*
vector<Graf::Wierzcholek> Graf::Sasiedztwo(int v1)
{
	vector<Wierzcholek> w;
	w.clear();
	if (_A[v1].empty()==1) 
	{
		//cout<<"Wierzcholek '"<<v1<<"' nie ma sasiadow.";
		return w;
	}
	else
	{
	//cout<<"Wierzcholek '"<<v1<<"' sasiaduje z: ";
	
	for (vector<Wierzcholek>::iterator iter = _A[v1].begin(); iter != _A[v1].end(); iter++) 
			w.push_back(*iter);
	//for (unsigned int i=0; i < w.size(); i++)
		//cout << setw(3) << w[i]._indeksW;
	return w;
	}
	cout<< endl << endl;
	
}*/

vector<int> Graf::Sasiedztwo(int v1)
{
	vector<int> w;
	w.clear();
	if (_A[v1].empty()==1) 
	{
		//cout<<"Wierzcholek '"<<v1<<"' nie ma sasiadow.";
		return w;
	}
	else
	{
	//cout<<"Wierzcholek '"<<v1<<"' sasiaduje z: ";
	
	for (vector<Wierzcholek>::iterator iter = _A[v1].begin(); iter != _A[v1].end(); iter++) 
			w.push_back(iter->_indeksW);
	//for (unsigned int i=0; i < w.size(); i++)
		//cout << setw(3) << w[i]._indeksW;
	return w;
	}
	//cout<< endl << endl;
	
}

void Graf::Czy_polaczone(int v1, int v2)
{
	vector<Wierzcholek> p;
	for (vector<Wierzcholek>::iterator iter = _A[v1].begin(); iter != _A[v1].end(); iter++) 
	{
		if (*iter == _wekW[v2]) p.push_back(_wekW[v2]);
	}
	if (p.empty()==1)cout << "Wierzcholki "<<v1<<" i "<<v2<<" nie sa polaczone."<<endl;
	else cout << "Wierzcholki "<<v1<<" i "<<v2<<" sa polaczone "<<p.size()<<" krawedziami."<<endl;
}

bool Graf::Polaczone(int v1, int v2)
{
	vector<Wierzcholek> p;
	for (vector<Wierzcholek>::iterator iter = _A[v1].begin(); iter != _A[v1].end(); iter++) 
	{
		if (*iter == _wekW[v2]) p.push_back(_wekW[v2]);
	}
	if (p.empty()==1) return false;
	else return true;
}

void Graf::Wyswietl()
{
	cout << endl;
	vector<Wierzcholek> w;
	for (unsigned int i=0; i < _wekW.size(); i++)
	{
		cout << setw(2) << i << ":";
		if (_wekW[i]._czyJest!=1) cout << "Brak tego wierzcholka ";
		else		
		{	
			for (vector<Wierzcholek>::iterator iter = _A[i].begin(); iter != _A[i].end(); iter++) 
				w.push_back(*iter);
		}
		for (unsigned int j=0; j < w.size(); j++)
			cout << setw(3) << w[j]._indeksW;	
			//cout << setw(3) << * iter;
		w.clear();	
		cout<< endl << endl;
	}
	
}

Graf::Krawedz Graf::Znajdz_krawedz(int v1, int v2)
{
	
	for (unsigned int i=0; i<_wekK.size(); i++)
	{
		if ((_wekK[i]._w1->_indeksW == v1 && _wekK[i]._w2->_indeksW == v2)
				|| (_wekK[i]._w1->_indeksW == v2 && _wekK[i]._w2->_indeksW == v1)) 
			return _wekK[i];
	}
}

void Graf::DFS(int poczatek, int szukany)
{
	jest=false;
	//cout << "\nDFS\n";
	_stos.push(_wekW[poczatek]) ;
	//cout << "Przeszukano kolejno:\n";
	while(poczatek!=szukany)
	{
		poczatek=_stos.top()._indeksW;
		_stos.pop();
		if(!_wekW[poczatek]._czyOdwiedzony)
		{
			_wekW[poczatek]._czyOdwiedzony = true;
			for(vector<Wierzcholek>::iterator iter = _A[poczatek].begin(); iter != _A[poczatek].end(); iter++)
			if(!iter->_czyOdwiedzony) 
				_stos.push(*iter);

          // wypisujemy odwiedzony wierzchołek 
         // cout << poczatek << " ";
          }
          if(poczatek==szukany)
          {
			jest=true;
			//cout<<"Znalazlem"<<endl;
		}
	}
	for (unsigned int i=0; i<_wekW.size(); i++)
	{
		_wekW[i]._czyOdwiedzony=false;
	}
	//cout << endl;
}

void Graf::BFS(int poczatek, int szukany)
{
	jest=false;
	//cout << "\nBFS\n";
	_kolejka.push(_wekW[poczatek]) ;
	//cout << "Przeszukano kolejno:\n";
	while(poczatek!=szukany)
	{
		poczatek=_kolejka.front()._indeksW;
		_kolejka.pop();	
		if(!_wekW[poczatek]._czyOdwiedzony)
		{

			_wekW[poczatek]._czyOdwiedzony = true;
			for(vector<Wierzcholek>::iterator iter = _A[poczatek].begin(); iter != _A[poczatek].end(); iter++)
			if(!iter->_czyOdwiedzony) 
				_kolejka.push(*iter);

          // wypisujemy odwiedzony wierzchołek 
          //cout << poczatek << " ";
          }
          if(poczatek==szukany)
          {
			jest=true;
			//cout<<"Znalazlem"<<endl;
		}
	}
	for (unsigned int i=0; i<_wekW.size(); i++)
	{
		_wekW[i]._czyOdwiedzony=false;
	}
	//cout << endl;
}

double Graf::Heurystyka (int v1, int v2)
{
	Wierzcholek a, b;
	a = _wekW[v1];
	b = _wekW[v2];
	double heur = sqrt((a._wspx - b._wspx)*(a._wspx - b._wspx)+(a._wspy - b._wspy)*(a._wspy - b._wspy));
	//cout << "Heur dla : " << v1<<" i " <<v2<< " = " << heur << endl;
	return heur;
}

void Graf::Pokaz_sciezke(int poczatkowy, int koncowy)
{
	Wierzcholek w;
	vector<int> wek;
	w = _wekW[koncowy];
	wek.push_back(w._indeksW);
	cout<<w._indeksW<<endl;
	cout<<w._poprzedni<<endl;
	cout << "Sciezka: " <<endl;
	while(w._indeksW != poczatkowy)
	{
		wek.push_back(w._poprzedni);
		w=_wekW[w._poprzedni];
	}
	wek.push_back(w._indeksW);
	for(int i=wek.size()-2; i>=0; i--)
		cout<<wek[i]<<" ";
	cout<<endl;
}
void Graf::Astar (int poczatek, int cel)
{
	jest=false;
	int sasiad;
	vector<int> zamk;
	vector<int> otw;
	double min,koszt;
	otw.push_back(poczatek);

	_wekW[otw[0]]._trasa = 0;
	_wekW[otw[0]]._heur=Heurystyka(poczatek, cel);
	_wekW[otw[0]]._suma=_wekW[otw[0]]._trasa + _wekW[otw[0]]._heur;
	min=_wekW[otw[0]]._suma;

	while(!otw.empty())
	{
		int przetwarzany;
		przetwarzany = otw[0];
		
		min=_wekW[przetwarzany]._suma;
		
		for(unsigned int i=0; i<otw.size(); i++)
		{
			if(min > _wekW[otw[i]]._suma)
			{
				min=_wekW[otw[i]]._suma;
				przetwarzany = otw[i];
			}
		}
		if (przetwarzany == cel)
		{
			jest=true;
			//cout<<"Znalazlem"<<endl;
			//cout << "Znalazlem wierzcholek: " << przetwarzany._indeksW << " ."<<endl;
			//Pokaz_sciezke(poczatek, przetwarzany._indeksW);
			break;
		}
	/*	for (unsigned int i=0; i<otw.size(); i++)
		{
			if(otw[i]._indeksW==przetwarzany._indeksW)
				otw.erase(otw.begin()+i);
		}*/
		otw.erase(otw.begin());
		zamk.push_back(przetwarzany);
		
		for (unsigned int i=0; i<Sasiedztwo(przetwarzany).size(); i++) 
		{
			sasiad=Sasiedztwo(przetwarzany)[i];
			
			//????
			
			if(Czy_w_wektorze(zamk, sasiad)) //jesli na zamk - przejdz do nastepnego
				continue;
				
			koszt = _wekW[przetwarzany]._trasa + Znajdz_krawedz(przetwarzany, sasiad)._waga;
			
			if (!Czy_w_wektorze(otw,sasiad) || koszt < _wekW[sasiad]._trasa)
			{
				_wekW[sasiad]._trasa = Znajdz_krawedz(przetwarzany, sasiad)._waga + _wekW[przetwarzany]._trasa;
				//sasiad._trasa = koszt;
				_wekW[sasiad]._heur = Heurystyka(sasiad, cel);
				_wekW[sasiad]._suma = _wekW[sasiad]._trasa + _wekW[sasiad]._heur;
				_wekW[sasiad]._poprzedni = przetwarzany;
				//_wekW[sasiad._indeksW]=sasiad;
				if (!Czy_w_wektorze(otw,sasiad))
					otw.push_back(sasiad);
					
			}
		}
	}
	//cout << "Nie znaleziono." << endl;
}

/*
void Graf::Astar (int poczatek, int cel)
{
	jest=false;
	Wierzcholek sasiad;
	vector<Wierzcholek> zamk;
	vector<Wierzcholek> otw;
	double min,koszt;
	otw.push_back(_wekW[poczatek]);

	otw[0]._trasa = 0;
	otw[0]._heur=Heurystyka(poczatek, cel);
	otw[0]._suma=otw[0]._trasa + otw[0]._heur;
	min=otw[0]._suma;

	while(!otw.empty())
	{
		Wierzcholek przetwarzany;
		przetwarzany = otw[0];
		
		min=przetwarzany._suma;
		
		for(unsigned int i=0; i<otw.size(); i++)
		{
			if(min > otw[i]._suma)
			{
				min=otw[i]._suma;
				przetwarzany = otw[i];
			}
		}
		if (przetwarzany._indeksW == cel)
		{
			jest=true;
			//cout<<"Znalazlem"<<endl;
			//cout << "Znalazlem wierzcholek: " << przetwarzany._indeksW << " ."<<endl;
			//Pokaz_sciezke(poczatek, przetwarzany._indeksW);
			break;
		}
		for (unsigned int i=0; i<otw.size(); i++)
		{
			if(otw[i]._indeksW==przetwarzany._indeksW)
				otw.erase(otw.begin()+i);
		}*/
/*		otw.erase(otw.begin());
		zamk.push_back(przetwarzany);
		
		for (unsigned int i=0; i<Sasiedztwo(przetwarzany._indeksW).size(); i++) 
		{
			sasiad=_wekW[Sasiedztwo(przetwarzany._indeksW)[i]];
			
			//????
			
			if(Czy_w_wektorze(zamk, sasiad)) //jesli na zamk - przejdz do nastepnego
				continue;
				
			koszt = przetwarzany._trasa + Znajdz_krawedz(przetwarzany._indeksW, sasiad._indeksW)._waga;
			
			if (!Czy_w_wektorze(otw,sasiad) || koszt < sasiad._trasa)
			{
				sasiad._trasa = Znajdz_krawedz(przetwarzany._indeksW, sasiad._indeksW)._waga + przetwarzany._trasa;
				//sasiad._trasa = koszt;
				sasiad._heur = Heurystyka(sasiad._indeksW, cel);
				sasiad._suma = sasiad._trasa + sasiad._heur;
				sasiad._poprzedni = przetwarzany._indeksW;
				_wekW[sasiad._indeksW]=sasiad;
				if (!Czy_w_wektorze(otw,sasiad))
					otw.push_back(sasiad);
					
			}
		}
	}
	//cout << "Nie znaleziono." << endl;
}
*/
bool Graf::Czy_w_wektorze(vector<int> wektor, int wi)
{
	for (vector<int>::iterator iter = wektor.begin(); iter != wektor.end(); iter++) 
	{
		if (*iter==wi)
			return true;
	}
	return false;
}









