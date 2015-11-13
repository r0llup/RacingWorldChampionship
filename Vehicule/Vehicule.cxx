#include "Vehicule.h"
#include <fstream.h>

Vehicule::Vehicule(void)
{
	cout << "Constructeur par defaut (Vehicule)" << endl;
	setType("default");
	setModele("default");
	setMoteur("default");
	setCylindre(0);
	setPneu("default");
}

Vehicule::Vehicule(const Vehicule &v)
{
	cout << "Constructeur de copie (Vehicule)" << endl;
	setType(v.getType());
	setModele(v.getModele());
	setMoteur(v.getMoteur());
	setCylindre(v.getCylindre());
	setPneu(v.getPneu());
}

Vehicule::~Vehicule(void)
{
	cout << "Destructeur (Vehicule)" << endl;
}

void Vehicule::setType(string t)
{
	type = t;
}

void Vehicule::setModele(string m)
{
	modele = m;
}

void Vehicule::setMoteur(string m)
{
	moteur = m;
}

void Vehicule::setCylindre(int c)
{
	cylindre = c;
}

void Vehicule::setPneu(string p)
{
	pneu = p;
}

string Vehicule::getType(void) const
{
	return type;
}

string Vehicule::getModele(void) const
{
	return modele;
}

string Vehicule::getMoteur(void) const
{
	return moteur;
}

int Vehicule::getCylindre(void) const
{
	return cylindre;
}

string Vehicule::getPneu(void) const
{
	return pneu;
}

ostream & operator<<(ostream &s, const Vehicule &v)
{
	cout << "Operateur << (Vehicule)" << endl;
	ofstream *tmp;
	tmp = dynamic_cast<ofstream *> (&s);

	if(tmp == 0)
	{
		cout << "Type : " << v.getType() << endl;
		cout << "Modele : " << v.getModele() << endl;
		cout << "Moteur : " << v.getMoteur() << endl;
		cout << "Cylindre : " << v.getCylindre() << endl;
		cout << "Pneu : " << v.getPneu() << endl;
	}

	else
	{
		*tmp << v.getType() << endl;
		*tmp << v.getModele() << endl;
		*tmp << v.getMoteur() << endl;
		*tmp << v.getCylindre() << endl;
		*tmp << v.getPneu() << endl;
	}

	return s;
}

istream & operator>>(istream &s, Vehicule &v)
{
	cout << "Operateur >> (Vehicule)" << endl;
	ifstream *tmp;
	tmp = dynamic_cast<ifstream *> (&s);

	if(tmp == 0)
	{
		cout << "Type : ";
		cin >> v.type;
		cout << "Modele : ";
		cin >> v.modele;
		cout << "Moteur : ";
		cin >> v.moteur;
		cout << "Cylindre : ";
		cin >> v.cylindre;
		cout << "Pneu : ";
		cin >> v.pneu;
	}

	else
	{
		*tmp >> v.type;
		*tmp >> v.modele;
		*tmp >> v.moteur;
		*tmp >> v.cylindre;
		*tmp >> v.pneu;
	}

	return s;
}
