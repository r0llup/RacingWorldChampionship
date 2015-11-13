#ifndef DATE_H
#define DATE_H
#include "InvalidDateException.h"

class Date
{
	friend istream & operator>>(istream & s, Date & d);
	friend ostream & operator<<(ostream & s, const Date & d);
	private:
		unsigned int jour;
		unsigned int mois;
		unsigned int annee;
	public:
		Date(void);
		Date(unsigned int j, unsigned int m, unsigned int a);
		Date(unsigned int j, unsigned int m);
		Date(unsigned int j);
		Date(char *d);
		Date(const Date &d);
		unsigned int getJour(void) const;
		unsigned int getMois(void) const;
		unsigned int getAnnee(void) const;
		void setJour(unsigned int j);
		void setMois(unsigned int m);
		void setAnnee(unsigned int a);
		void affiche(void);
		bool operator<(const Date & d);
		bool operator<=(const Date & d);
		bool operator==(const Date & d);
		bool operator>(const Date & d);
		bool operator>=(const Date & d);
};

#endif
