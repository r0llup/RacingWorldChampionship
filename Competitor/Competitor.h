#ifndef COMPETITOR_H
#define COMPETITOR_H
#include "Person.h"

using namespace std;

class Competitor : public Person
{
	friend istream & operator>>(istream & s, Competitor & c);
	friend ostream & operator<<(ostream & s, const Competitor & c);
	private:
		int dossard;
		int score;
	public:
		Competitor(void);
		Competitor(string nm, string prn, Date dateNaissance, string nat, \
			int dossard, int score);
		Competitor(const Competitor &c);
		int getDossard(void) const;
		int getScore(void) const;
		void setDossard(int d);
		void setScore(int s);
		void affiche(void);
		string getIdentification();
		Competitor & operator=(const Competitor &c);
};

#endif
