#include "adt.hh"

/*!
 * \file
 * \brief Modul zawierajacy definicje metod klasy Graf oraz funkcji Tworz.
 *										
 */

void Tworz()
{
	Graf g;
	g.Nowy(13);
	for (int i=0; i < 13; i++)
		g.Dodaj_wierzcholek(i);
	cout << "wierzch jest: " << g._ile_wierzcholkow << endl;
	for (int i=1; i < 4; i++)
		g.Dodaj_krawedz(0,i,1);
	for (int i=4; i < 7; i++)
		g.Dodaj_krawedz(1,i,1);
	for (int i=10; i < 13; i++)
		g.Dodaj_krawedz(2,i,1);
	for (int i=7; i < 10; i++)
		g.Dodaj_krawedz(3,i,1);
	cout << "kraw jest: " << g._ile_krawedzi << endl<<"Lista: \n";
	g.Wyswietl();
	g.DFS(0);
	g.BFS(0);
	//g.Sasiedztwo(0);g.Sasiedztwo(1);g.Sasiedztwo(2);g.Sasiedztwo(3);g.Sasiedztwo(4);g.Sasiedztwo(5);
}

void Graf::Dodaj_wierzcholek(int v1)
{
	_ile_wierzcholkow++;
	cout << _ile_miejsc_w_tab<< endl;
	cout << v1 << endl;
	if (v1<_ile_miejsc_w_tab && _wekW[v1]._czyJest==false) 
	{
		_wekW[v1]._czyJest=1;
	}
	
	else
	{
		Wierzcholek w;
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
	if (_wekW[v1]._czyJest!=1)
		Dodaj_wierzcholek(v1);
	if (_wekW[v2]._czyJest!=1)
		Dodaj_wierzcholek(v2);
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

void Graf::Sasiedztwo(int v1)
{
	if (_A[v1].empty()==1) cout<<"Wierzcholek '"<<v1<<"' nie ma sasiadow.";
	else{
	cout<<"Wierzcholek '"<<v1<<"' sasiaduje z: ";
	vector<Wierzcholek> w;
	for (vector<Wierzcholek>::iterator iter = _A[v1].begin(); iter != _A[v1].end(); iter++) 
			w.push_back(*iter);
	for (unsigned int i=0; i < w.size(); i++)
		cout << setw(3) << w[i]._indeksW;
	}
	cout<< endl << endl;
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

void Graf::DFS(int poczatek)
{
	cout << "\nDFS\n";
	_stos.push(_wekW[poczatek]) ;
	cout << "Przeszukano kolejno:\n";
	while(!_stos.empty())
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
          cout << poczatek << " ";
          }
	}
	for (unsigned int i=0; i<_wekW.size(); i++)
	{
		_wekW[i]._czyOdwiedzony=false;
	}
	cout << endl;
}

void Graf::BFS(int poczatek)
{
	cout << "\nBFS\n";
	_kolejka.push(_wekW[poczatek]) ;
	cout << "Przeszukano kolejno:\n";
	while(!_kolejka.empty())
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
          cout << poczatek << " ";
          }
	}
	for (unsigned int i=0; i<_wekW.size(); i++)
	{
		_wekW[i]._czyOdwiedzony=false;
	}
	cout << endl;
}

