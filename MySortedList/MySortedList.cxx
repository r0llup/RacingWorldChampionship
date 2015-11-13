#include <stdlib.h>
#include <iostream.h>
#include <strings.h>
#include "MySortedList.h"
#include "Race.h"
#include "FederationAdmin.h"
#include "TeamMember.h"
#include "Competitor.h"

template <class type> void MySortedList<type>::insert(type n)
{
	if(getMode() == CROISSANT)
	{
		insertAsc(n);
	}

	else
	{
		insertDesc(n);
	}
}

template <class type> void MySortedList<type>::insertAsc(type n)
{
	if(MyList<type>::full())
	{
		return;
	}

	noeud<type> *nv = new noeud<type>(n, NULL);

	if(!nv)
	{
		return;
	}

	if(MyList<type>::empty()) // liste vide
	{
		MyList<type>::pList = nv;
		structure<type>::insert(n);
		return;
	}

	if(n <= MyList<type>::head()) // insertion au début
	{
		nv->setNext(MyList<type>::pList);
		MyList<type>::pList = nv;
		structure<type>::insert(n);
		return;
	}

	noeud<type> *cher(MyList<type>::pList), *pred(MyList<type>::pList);

	while(cher->next && n > cher->value)
	{
		pred = cher;
		cher = cher->next;
	}

	if (n > cher->value) // insertion à la fin
	{
		cher->setNext(nv);
	}

	else // insertion au milieu
	{
		pred->setNext(nv);
		nv->setNext(cher);
	}

	structure<type>::insert(n);
}

template <class type> void MySortedList<type>::insertDesc(type n)
{
	if(MyList<type>::full())
	{
		return;
	}

	noeud<type> *nv = new noeud<type>(n, NULL);

	if(!nv)
	{
		return;
	}

	if(MyList<type>::empty()) // liste vide
	{
		MyList<type>::pList = nv;
		structure<type>::insert(n);
		return;
	}

	if(n >= MyList<type>::head()) // insertion au début
	{
		nv->setNext(MyList<type>::pList);
		MyList<type>::pList = nv;
		structure<type>::insert(n);
		return;
	}

	noeud<type> *cher(MyList<type>::pList), *pred(MyList<type>::pList);

	while(cher->next && n < cher->value)
	{
		pred = cher;
		cher = cher->next;
	}

	if (n < cher->value) // insertion à la fin
	{
		cher->setNext(nv);
	}

	else // insertion au milieu
	{ 
		pred->setNext(nv);
		nv->setNext(cher);
	}

	structure<type>::insert(n);
}

template <class type> void MySortedList<type>::remove(type n)
{
	if(getMode() == CROISSANT)
	{
		removeAsc(n);
	}

	else
	{
		removeDesc(n);
	}
}

template <class type> void MySortedList<type>::removeAsc(type n)
{
	if(MyList<type>::empty())
	{
		return;
	}

	if(n == MyList<type>::head())
	{
		noeud<type> *tr = MyList<type>::pList;
		MyList<type>::pList = MyList<type>::pList->next;
		delete tr;
	}

	else
	{
		noeud<type> *cher(MyList<type>::pList), *pred(MyList<type>::pList);

		while(cher && n > cher->value)
		{
			pred = cher;
			cher = cher->next;
		}

		if(n == cher->value)
		{
			pred->setNext(cher->next);
			delete cher;
		}

		else
		{
			return;
		}
	}

	structure<type>::remove();
}

template <class type> void MySortedList<type>::removeDesc(type n)
{
	if(MyList<type>::empty())
	{
		return;
	}

	if(n == MyList<type>::head())
	{
		noeud<type> *tr = MyList<type>::pList;
		MyList<type>::pList = MyList<type>::pList->next;
		delete tr;
	}

	else
	{
		noeud<type> *cher(MyList<type>::pList), *pred(MyList<type>::pList);

		while(cher && n < cher->value)
		{
			pred = cher;
			cher = cher->next;
		}

		if(n == cher->value)
		{
			pred->setNext(cher->next);
			delete cher;
		}

		else
		{
			return;
		}
	}

	structure<type>::remove();
}

template <class type> void MySortedList<type>::setMode(int mod)
{
	if(mode == CROISSANT)
	{
		if(mod == DECROISSANT)
		{
			mode = mod;
		}
	}

	else
	{
		if(mod == CROISSANT)
		{
			mode = mod;
		}
	}
}

template class MySortedList<int>;
template class MySortedList<Race>;
template class MySortedList<FederationAdmin>;
template class MySortedList<TeamMember>;
template class MySortedList<Competitor>;
