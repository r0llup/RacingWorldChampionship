#ifndef PERSON_H
#define PERSON_H
#include "Date.h"

using namespace std;

class Person
{
	friend istream & operator>>(istream & s, Person & p);
	friend ostream & operator<<(ostream & s, const Person & p);
	protected:
		string nom;
		string prenom;
		Date dateNaissance;
		string nationalite;
	public:
		Person(void);
		Person(string nm);
		Person(string nm, string prn);
		Person(string nm, string prn, Date dateNaissance);
		Person(string nm, string prn, Date dateNaissance, string nat);
		Person(const Person &p);
		virtual ~Person(void);
		string getNom(void) const;
		string getPrenom(void) const;
		Date getDateNaissance(void) const;
		string getNationalite(void) const;
		void setNom(string n);
		void setPrenom(string p);
		void setDateNaissance(Date d);
		void setNationalite(string n);
		void affiche(void);
		virtual string getIdentification(void) const;
		Person & operator=(const Person &p);
		bool operator<(const Person & p);
		bool operator<=(const Person & p);
		bool operator==(const Person & p);
		bool operator>(const Person & p);
		bool operator>=(const Person & p);
};

#endif
