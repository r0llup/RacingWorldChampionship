#ifndef CIRCUIT_H
#define CIRCUIT_H
#include <iostream.h>

using namespace std;

class Circuit
{
	friend ostream & operator<<(ostream &s, const Circuit &c);
	friend istream & operator>>(istream &s, Circuit &c);
	private:
		string nom;
		string pays;
		float longueur;
		int compareLongueur(float l);
	public:
		static Circuit SPA_FRANCORCHAMPS;
		static Circuit SILVERSTONE;
		Circuit(void);
		Circuit(string n);
		Circuit(string n, string p);
		Circuit(string n, string p, float l);
		Circuit(const Circuit &c);
		string getNom(void) const;
		string getPays(void) const;
		float getLongueur(void) const;
		void setNom(string n);
		void setPays(string p);
		void setLongueur(float l);
		void affiche(void);
		void save(ofstream &file);
		void load(ifstream &file);
		Circuit & operator=(const Circuit &c);
		Circuit operator+(float l);
		Circuit operator+(Circuit &c);
		Circuit operator-(float l);
		float operator-(Circuit & c);
		int operator<(const Circuit &c);
		int operator>(const Circuit &c);
		int operator==(const Circuit &c);
		Circuit operator++(void);
		Circuit operator++(int);
};

#endif
