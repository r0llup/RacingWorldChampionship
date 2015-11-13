#ifndef RACE_H
#define RACE_H
#include "Circuit.h"
#include "Date.h"
#include "InvalidRaceSizeException.h"
#include "MyVector.h"

class Race
{
	friend ostream & operator<<(ostream & s, Race & r);
	friend istream & operator>>(istream & s, Race & r);
	private:
		Circuit *circuit;
		Date date;
		int nbTours;
		MyVector<int> resultats;
	public:
		Race(void);
		Race(Circuit *c);
		Race(Circuit *c, Date d, int nbt);
		Race(const Race &r);
		~Race(void);
		Circuit *getCircuit(void) const;
		Date getDate(void) const;
		int getNbTours(void) const;
		float getRaceLength(void) const;
		inline MyVector<int> & getResultats(void) { return resultats; }
		void setCircuit(const Circuit *c);
		void setDate(Date d);
		void setNbTours(int ntc);
		void affiche(void) const;
		int verifierDossard(int dossard);
		void ajouterDossard(int dossard);
		Race & operator=(const Race & r);
		bool operator<(const Race & r);
		bool operator<=(const Race & r);
		bool operator==(const Race & r);
		bool operator>(const Race & r);
		bool operator>=(const Race & r);
};

#endif
