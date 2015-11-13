#include "Competitor.h"
#include <fstream.h>

Competitor::Competitor(void) : Person()
{
	cout << "Constructeur par defaut (Competitor)" << endl;
	setDossard(0);
	setScore(0);
}

Competitor::Competitor(string nm, string prn, Date dateNaissance, string nat, \
	int dossard, int score) : Person(nm, prn, dateNaissance, nat)
{
	cout << "Constructeur d'initialisation (Competitor)" << endl;
	setDossard(dossard);
	setScore(score);
}

Competitor::Competitor(const Competitor &c) : Person(c)
{
	cout << "Constructeur de copie (Competitor)" << endl;
	setDossard(c.getDossard());
	setScore(c.getScore());
}

int Competitor::getDossard(void) const
{
	return dossard;
}

int Competitor::getScore(void) const
{
	return score;
}

void Competitor::setDossard(int d)
{
	dossard = d;
}

void Competitor::setScore(int s)
{
	score = s;
}

void Competitor::affiche(void)
{
	cout << *this;
}

string Competitor::getIdentification()
{
	char temp[40];
	sprintf(temp, "%d#%d", getDossard(), getScore());
	string tmp = getNom() + "#" + temp;
	return tmp;
}

istream & operator>>(istream & s, Competitor & c)
{
	cout << "Operateur >> (Competitor)" << endl;
	ifstream *tmp;
	tmp = dynamic_cast<ifstream *> (&s);

	if(tmp == 0)
	{
		s >> (Person &) c;
		cout << "Numero de dossard : ";
		cin >> c.dossard;
		cout << "Score : ";
		cin >> c.score;
	}

	else
	{
		*tmp >> (Person &) c;
		*tmp >> c.dossard;
		*tmp >> c.score;
	}

	return s;
}

ostream & operator<<(ostream & s, const Competitor & c)
{
	cout << "Operateur << (Competitor)" << endl;
	ofstream *tmp;
	tmp = dynamic_cast<ofstream *> (&s);

	if(tmp == 0)
	{
		s << (Person &) c;
		s << "Numero de dossard : " << c.getDossard() << endl;
		s << "Score : " << c.getScore();
	}

	else
	{
		*tmp << (Person &) c;
		*tmp << c.getDossard() << endl;
		*tmp << c.getScore() << endl;
	}

	return s;
}

Competitor & Competitor::operator=(const Competitor &c)
{
	cout << "Operateur = (Competitor)" << endl;
	*((Person *) this) = (Person &) c;
	setDossard(c.getDossard());
	setScore(c.getScore());
	return *this;
}
