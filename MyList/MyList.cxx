#include <stdlib.h>
#include <iostream.h>
#include <string.h>
#include "MyList.h"
#include "Race.h"
#include "FederationAdmin.h"
#include "TeamMember.h"
#include "Competitor.h"

template <class type> MyList<type>::~MyList(void)
{
	cout << "Destructeur (MyList)" << endl;
	noeud<type> *pCur, *pPrec;
	pCur = pList;

	while(pCur != NULL)
	{
		pPrec = pCur;
		pCur = pCur->next;
		delete pPrec;
	}
}

template <class type> int MyList<type>::empty(void) 
{
	if(pList)
	{
		return 0;
	}

	return 1;
}

template <class type> type MyList<type>::tail(void) 
{
	if(!pList->next)
	{
		return pList->value;
	}

	noeud<type> *pWork = pList, *pPrec;

	while(pWork->next)
	{
		pPrec = pWork;
		pWork = pWork->next;
	}

	return pWork->value;
}

template <class type> void MyList<type>::insertHead(type n)
{
	pList = new noeud<type>(n, pList);
	structure<type>::insert(n);
}

template <class type> void MyList<type>::insertTail(type n)
{
	if(!pList->next)
	{
		pList->next = new noeud<type>(n, NULL);
		structure<type>::insert(n);
	}

	else
	{
		noeud<type> *pWork(pList), *pPrec;

		while(pWork->next)
		{
			pPrec = pWork;
			pWork = pWork->next;
		}

		pWork->next = new noeud<type>(n, NULL);
		structure<type>::insert(n);
	}
}

template <class type> type MyList<type>::removeHead(void)
{
	type ret;
	noeud<type> *pWork(pList);
	ret = pWork->value;
	pList = pList->next;
	delete pWork;
	structure<type>::remove();
	return ret;
}

template <class type> type MyList<type>::removeTail(void)
{
	type ret;

	if(!pList->next)
	{
		delete pList;
		pList = 0;
		structure<type>::remove();
	}

	noeud<type> *pWork(pList), *pPrec;

	while(pWork->next)
	{
		pPrec = pWork;
		pWork = pWork->next;
	}

	ret = pWork->value;
	delete pWork;
	pPrec->next = 0;
	structure<type>::remove();
	return ret;
}

template <class type> void MyList<type>::affiche(void)
{
	IterList<type> it(*this);

	if(empty()) 
	{
		cout << "Liste vide" << endl;
		return;
	}

	cout << "( ";

	while(!it.end())
	{
		type t = ((type) it);
		cout << t << " , ";
		it++;
	}

	cout << "\x8\x8)" << endl;
}

template <class type> MyList<type> & MyList<type>::operator=(const MyList &l)
{
	pList = l.pList;
	return (*this);
}

template <class type> int IterList<type>::operator++()
{
	if(pCur)
	{
		pCur = pCur->next;
		return 1;
	}

	return 0;
}

template class noeud<int>;
template class noeud<Race>;
template class noeud<FederationAdmin>;
template class noeud<TeamMember>;
template class noeud<Competitor>;

template class MyList<int>;
template class MyList<Race>;
template class MyList<FederationAdmin>;
template class MyList<TeamMember>;
template class MyList<Competitor>;

template class IterList<int>;
template class IterList<Race>;
template class IterList<FederationAdmin>;
template class IterList<TeamMember>;
template class IterList<Competitor>;
