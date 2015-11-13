#include <stdlib.h>
#include <iostream.h>
#include <strings.h>
#include "MyVector.h"
#include "Race.h"
#include "Competitor.h"
#include "Circuit.h"
#include "TeamMember.h"
#include "FederationAdmin.h"

template <class type> int structure<type>::full(void)
{
	int *pTr = new int;

	if(!pTr)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

template <class type> int structure<type>::empty(void)
{
	if(nbreElem == 0)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

template <class type> MyVector<type>::MyVector(void) : structure<type>()
{
	cout << "Constructeur par defaut (MyVector)" << endl;
	tab = new type[10];
	occupe = new int [10];

	for(int i = 0; i < 10; i++)
	{
		occupe[i] = 0;
	}

	taille = 10;
}

template <class type> MyVector<type>::MyVector(int nb) : structure<type>()
{
	cout << "Constructeur d'initialisation (MyVector)" << endl;
	tab = new type[nb];
	occupe = new int [nb];

	for(int i = 0; i < nb; i++)
	{
		occupe[i] = 0;
	}

	taille = nb;
}

template <class type> MyVector<type>::~MyVector()
{
	cout << "Destructeur (MyVector)" << endl;
	delete [] tab;
}

template <class type> bool MyVector<type>::ajout(type n)
{
	int i;

	for(i = 0; i < taille; i++)
	{
		if(occupe[i] == 0)
		{
			*(tab+i) = n;
			occupe[i] = 1;
			structure<type>::insert(n);
			break;
		}
	}

	if(i < taille)
	{
		return true;
	}

	else
	{
		return false;
	}
}

template <class type> bool MyVector<type>::retrait(void)
{
	for(int i = taille - 1; i >= 0; i--)
	{
		if(occupe[i] == 1)
		{
			occupe[i] = 0;
			structure<type>::remove();
			return true;
		}
	}

	return false;
}

template <class type> type & MyVector<type>::operator[](int i)
{
	cout << "Operateur [] (MyVector)" << endl;
	return tab[i];
}

template <class type> MyVector<type> & MyVector<type>::operator=(const MyVector<type> &n)
{
	cout << "Operateur = (MyVector)" << endl;
	int i;

	structure<type>::nbreElem = n.nbreElem;

	for(i = 0; i < structure<type>::nbreElem; i++)
	{
		occupe[i] = n.occupe[i];
	}

	for(i = 0; i < structure<type>::nbreElem; i++)
	{
		tab[i] = n.tab[i];
	}

	return *this;
}

template <class type> void MyVector<type>::Affichage(void)
{
	if(structure<type>::nbreElem > 0)
	{
		for(int i = 0; i < taille; i++)
		{
			if(occupe[i] != 0)
			{
				cout << tab[i] << endl;	
			}
		}
	}

	else
	{
		cout << "Vecteur vide" << endl;
	}	
}

template class structure<int>;
template class structure<Race>;
template class structure<Competitor>;
template class structure<Circuit>;
template class structure<TeamMember>;
template class structure<FederationAdmin>;

template class MyVector<int>;
template class MyVector<Race>;
template class MyVector<Competitor>;
template class MyVector<Circuit>;

template class IterVector<int>;
template class IterVector<Race>;
template class IterVector<Competitor>;
template class IterVector<Circuit>;
