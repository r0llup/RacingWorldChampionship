#ifndef MYLIST_H
#define MYLIST_H
#include "MyVector.h"

template <class type> struct noeud
{
	type value;
	type *pValue;
	noeud<type> *next;
	noeud(type n, noeud<type> *s) : value(n), pValue(&n), next(s) {};
	void setNext(noeud<type> *p) { next = p; }
};

template <class type> class IterList;

template <class type> class MyList : public structure<type>
{
	protected:
		noeud<type> *pList;
	public:
		MyList(void) : structure<type>(), pList(0) {};
		MyList(const MyList &l) { pList = l.pList; } 
		~MyList(void);
		int empty(void);
		type head(void)  { return pList->value; }
		type tail(void) ;
		void insertHead(type n);
		void insertTail(type n);
		type removeHead(void);
		type removeTail(void);
		int size(void) { return structure<type>::getNbreElem(); }
		void affiche(void) ;
		friend class IterList<type>;
		MyList & operator=(const MyList &l);
};

template <class type> class IterList
{
	private :
		MyList<type> &lis;
		noeud<type> *pCur;
	public :
		IterList(MyList<type>& l) : lis(l), pCur(l.pList) {};
		int end() { return pCur == 0; }
		void reset() { pCur = lis.pList; }
		int operator++();
		int operator++(int) { return operator++(); }
		operator type&()  { return pCur->value; }
};

#endif
