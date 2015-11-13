#ifndef MYVECTOR_H
#define MYVECTOR_H

template <class type> class structure
{
	protected:
		int nbreElem;
	public:
		structure() { nbreElem = 0; }
		virtual ~structure() { };
		int getNbreElem(void) { return nbreElem; }
		virtual type head(void) = 0;
		virtual int empty(void);
		virtual int full(void);
		virtual void insert(type) { nbreElem++; }
		void remove(void) { nbreElem--; }
};

template <class type> class IterVector;

template<class type> class MyVector : public structure<type>
{
	private:
		int * occupe;
		type * tab;
		int taille;
	public:
		MyVector(void);
		MyVector(int nb);
		~MyVector();
		bool ajout(type n);
		bool retrait(void);
		bool retrait(int i);
		friend class IterVector<type>;
		type & operator[](int i);
		MyVector<type> & operator=(const MyVector<type> &n);
		void Affichage(void);
		int empty(void) { return structure<type>::getNbreElem() == 0; }
		type head(void) { return tab[0]; }
		type & GetElem(int i) { return tab[i]; }
};

template <class T> class IterVector
{
	private :
		T * pData;
		MyVector<T> & p;
	public :
		IterVector(MyVector<T>& s) : p(s)
		{
			pData = s.tab;
		}

		int end() const
		{
			if (pData - p.tab >= p.taille) return 1;
			else return 0;
		}

		void reset()
		{
			pData = p.tab;
		}

		int operator++()
		{
			if(!end())
			{
				pData++;
				return 1;
			}
			else return 0;
		}

		int operator++(int)
		{
			return operator++();
		}

		operator T &() const
		{
			return * pData;
		}
};

#endif
