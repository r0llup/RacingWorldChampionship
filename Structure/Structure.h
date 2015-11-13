#ifndef STRUCTURE_H
#define STRUCTURE_H

template <class type> class structure
{
	protected :
		int nbreElem;
	public :
		structure(void) { nbreElem = 0; }
		virtual ~structure(void);
		int getNbreElem(void);
		virtual type head(void) = 0; // fonction virtuelle pure
		virtual int empty(void);
		virtual int full(void);
		virtual void insert(type);
		void remove(void);
};