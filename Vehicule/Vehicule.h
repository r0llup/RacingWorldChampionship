#ifndef VEHICULE_H
#define VEHICULE_H
#include <iostream.h>

using namespace std;

class Vehicule
{
	friend ostream & operator<<(ostream &s, const Vehicule &v);
	friend istream & operator>>(istream &s, Vehicule &v);
	private:
		string type;
		string modele;
		string moteur;
		int cylindre;
		string pneu;
	public:
		Vehicule(void);
		Vehicule(const Vehicule &v);
		~Vehicule(void);
		void setType(string t);
		void setModele(string m);
		void setMoteur(string m);
		void setCylindre(int c);
		void setPneu(string p);
		string getType(void) const;
		string getModele(void) const;
		string getMoteur(void) const;
		int getCylindre(void) const;
		string getPneu(void) const;
};

#endif
