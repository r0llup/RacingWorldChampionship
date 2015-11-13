#include "Person.h"
#include <fstream.h>

Person::Person(void)
{
	cout << "Constructeur par defaut (Person)" << endl;
	setNom("");
	setPrenom("");
	setNationalite("");
}

Person::Person(string nm)
{
	cout << "Constructeur d'initialisation (1) (Person)" << endl;
	setNom(nm);
	setPrenom("");
	setNationalite("");
}

Person::Person(string nm, string prn)
{
	cout << "Constructeur d'initialisation (2) (Person)" << endl;
	setNom(nm);
	setPrenom(prn);
	setNationalite("");
}

Person::Person(string nm, string prn, Date dateNaissance)
{
	cout << "Constructeur d'initialisation (3) (Person)" << endl;
	setNom(nm);
	setPrenom(prn);
	setDateNaissance(dateNaissance);
	setNationalite("");
}

Person::Person(string nm, string prn, Date dateNaissance, string nat)
{
	cout << "Constructeur d'initialisation (4) (Person)" << endl;
	setNom(nm);
	setPrenom(prn);
	setDateNaissance(dateNaissance);
	setNationalite(nat);
}

Person::Person(const Person &p)
{
	cout << "Constructeur de copie (Person)" << endl;
	setNom(p.getNom());
	setPrenom(p.getPrenom());
	setDateNaissance(p.getDateNaissance());
	setNationalite(p.getNationalite());
}

Person::~Person(void)
{
	cout << "Destructeur (Person)" << endl;
}

string Person::getNom(void) const
{
	return nom;
}

string Person::getPrenom(void) const
{
	return prenom;
}

Date Person::getDateNaissance(void) const
{
	return dateNaissance;
}

string Person::getNationalite(void) const
{
	return nationalite;
}

void Person::setNom(string n)
{
	nom = n;
}

void Person::setPrenom(string p)
{
	prenom = p;
}

void Person::setDateNaissance(Date d)
{
	dateNaissance = d;
}

void Person::setNationalite(string n)
{
	nationalite = n;
}

void Person::affiche(void)
{
	cout << *this;
}

string Person::getIdentification(void) const
{
	return getNom();
}

Person & Person::operator=(const Person &p)
{
	cout << "Operateur = (Person)" << endl;
	setNom(p.getNom());
	setPrenom(p.getPrenom());
	setDateNaissance(p.getDateNaissance());
	setNationalite(p.getNationalite());
	return *this;
}

bool Person::operator<(const Person &p)
{
	cout << "Operateur < (Person)" << endl;
	if(getNom() < p.getNom())
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Person::operator<=(const Person & p)
{
	cout << "Operateur <= (Person)" << endl;
	if(getNom() <= p.getNom())
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Person::operator==(const Person & p)
{
	cout << "Operateur == (Person)" << endl;
	if(getNom() == p.getNom())
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Person::operator>(const Person & p)
{
	cout << "Operateur > (Person)" << endl;
	if(getNom() > p.getNom())
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Person::operator>=(const Person & p)
{
	cout << "Operateur >= (Person)" << endl;
	if(getNom() >= p.getNom())
	{
		return true;
	}

	else
	{
		return false;
	}
}

istream & operator>>(istream & s, Person & p)
{
	cout << "Operateur >> (Person)" << endl;
	ifstream *tmp;
	tmp = dynamic_cast<ifstream *> (&s);

	if(tmp == 0)
	{
		cout << "Nom : ";
		s >> p.nom;
		cout << "Prenom : ";
		s >> p.prenom;
		cout << "Date de naissance : ";
		s >> p.dateNaissance;
		cout << "Nationalite : ";
		s >> p.nationalite;
	}

	else
	{
		*tmp >> p.nom;
		*tmp >> p.prenom;
		*tmp >> p.dateNaissance;
		*tmp >> p.nationalite;
	}

	return s;
}

ostream & operator<<(ostream & s, const Person & p)
{
	cout << "Operateur << (Person)" << endl;
	ofstream *tmp;
	tmp = dynamic_cast<ofstream *> (&s);

	if(tmp == 0)
	{
		s << "Nom : " << p.getNom() << endl;
		s << "Prenom : " << p.getPrenom() << endl;
		s << "Date de naissance : " << p.getDateNaissance();
		s << "Nationalite : " << p.getNationalite() << endl;
	}

	else
	{
		*tmp << p.nom << endl;
		*tmp << p.prenom << endl;
		*tmp << p.dateNaissance;
		*tmp << p.nationalite << endl;
	}

	return s;
}
