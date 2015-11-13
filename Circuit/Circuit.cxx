#include "Circuit.h"
#include <fstream.h>

Circuit Circuit::SPA_FRANCORCHAMPS("Francorchamps", "Belgique", 7.004);

Circuit Circuit::SILVERSTONE("Silverstone", "Angleterre", 5.9);

int Circuit::compareLongueur(float l)
{
	if(getLongueur() < l)
	{
		return -1;
	}

	if(getLongueur() > l)
	{
		return 1;
	}

	return 0;
}

Circuit::Circuit(void)
{
	cout << "Constructeur par defaut (Circuit)" << endl;
	setNom("default");
	setPays("default");
	setLongueur(0);
}

Circuit::Circuit(string n)
{
	cout << "Constructeur d'initialisation (1) (Circuit)" << endl;
	setNom(n);
	setPays("default");
	setLongueur(0);
}

Circuit::Circuit(string n, string p)
{
	cout << "Constructeur d'intialisation (2) (Circuit)" << endl;
	setNom(n);
	setPays(p);
	setLongueur(0);
}

Circuit::Circuit(string n, string p, float l)
{
	cout << "Constructeur d'initialisation (3) (Circuit)" << endl;
	setNom(n);
	setPays(p);
	setLongueur(l);
}

Circuit::Circuit(const Circuit &c)
{
	cout << "Constructeur de copie (Circuit)" << endl;
	setNom(c.getNom());
	setPays(c.getPays());
	setLongueur(c.getLongueur());
}

string Circuit::getNom(void) const
{
	return nom;
}

string Circuit::getPays(void) const
{
	return pays;
}

float Circuit::getLongueur(void) const
{
	return longueur;
}

void Circuit::setNom(string n)
{
	nom = n;
}

void Circuit::setPays(string p)
{
	pays = p;
}

void Circuit::setLongueur(float l)
{
	longueur = l;
}

void Circuit::affiche(void)
{
	cout << "Nom du circuit : " << getNom() << endl;
	cout << "Pays du circuit : " << getPays() << endl;
	cout << "Longueur du circuit : " << getLongueur() << endl;
}

void Circuit::save(ofstream &file)
{
	file << *this;
}

void Circuit::load(ifstream &file)
{
	file >> *this;
}	

Circuit & Circuit::operator=(const Circuit &c)
{
	cout << "Operateur = (Circuit)" << endl;
	setNom(c.getNom());
	setPays(c.getPays());
	setLongueur(c.getLongueur());
	return *this;
}

Circuit Circuit::operator+(float l)
{
	cout << "Operateur + (Float) (Circuit)" << endl;
	Circuit c(*this);
	c.setLongueur(c.getLongueur() + l);
	return c;
}

Circuit Circuit::operator+(Circuit &c)
{
	cout << "Operateur + (Circuit) (Circuit)" << endl;
	Circuit nc(*this);
	nc.setLongueur(nc.getLongueur() + c.getLongueur());
	return nc;
}

Circuit Circuit::operator-(float l)
{
	cout << "Operateur - (Float) (Circuit)" << endl;
	Circuit c(*this);
	c.setLongueur(c.getLongueur() - l);
	return c;
}

float Circuit::operator-(Circuit &c)
{
	cout << "Operateur - (Circuit) (Circuit)" << endl;
	return getLongueur() - c.getLongueur();
}

ostream & operator<<(ostream &s, const Circuit &c)
{
	cout << "Operateur << (Circuit)" << endl;
	ofstream *tmp;
	tmp = dynamic_cast<ofstream *> (&s);

	if(tmp == 0)
	{
		s << c.getNom() << endl;
		s << c.getPays() << endl;
		s << c.getLongueur() << endl;
	}

	else
	{
		*tmp << c.getNom() << endl;
		*tmp << c.getPays() << endl;
		*tmp << c.getLongueur() << endl;
	}

	return s;
}

istream & operator>>(istream &s, Circuit &c)
{
	cout << "Operateur >> (Circuit)" << endl;
	ifstream *tmp;
	tmp = dynamic_cast<ifstream *> (&s);

	if(tmp == 0)
	{
		cout << "Nom : ";
		s >> c.nom;
		cout << "Pays : ";
		s >> c.pays;
		cout << "Longueur : ";
		s >> c.longueur;
	}

	else
	{
		*tmp >> c.nom;
		*tmp >> c.pays;
		*tmp >> c.longueur;
	}

	return s;
}

int Circuit::operator<(const Circuit &c)
{
	cout << "Operateur < (Circuit)" << endl;

	return compareLongueur(c.getLongueur()) == -1;
}

int Circuit::operator>(const Circuit &c)
{
	cout << "Operateur > (Circuit)" << endl;

	return compareLongueur(c.getLongueur()) == 1;
}

int Circuit::operator==(const Circuit &c)
{
	cout << "Operateur == (Circuit)" << endl;

	return compareLongueur(c.getLongueur()) == 0;
}

Circuit Circuit::operator++(void)
{
	cout << "Operateur pre ++ (Circuit)" << endl;

	setLongueur(getLongueur() + 0.01);

	return *this;
}

Circuit Circuit::operator++(int)
{
	cout << "Operateur post ++ (Circuit)" << endl;

	Circuit tmp(*this);
	(*this).setLongueur((*this).getLongueur() + 0.01);

	return tmp;
}
