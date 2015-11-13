#ifndef MYSORTEDLIST_H
#define MYSORTEDLIST_H
#include "MyList.h"

template <class type> class MySortedList : public MyList<type>
{
	private:
		int mode;
	public:
		MySortedList() : MyList<type>() { mode = CROISSANT; }
		static const int CROISSANT = 1;
		static const int DECROISSANT = 2;
		void insert(type n);
		void insertAsc(type n);
		void insertDesc(type n);
		void remove(type n);
		void removeAsc(type n);
		void removeDesc(type n);
		void setMode(int mod);
		int getMode(void) { return mode; }
};

#endif
