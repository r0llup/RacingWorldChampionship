#include "TeamMember.h"
#include <fstream.h>

TeamMember::TeamMember(void) : AuthorisedPerson()
{
	cout << "Constructeur par defaut (TeamMember)" << endl;
	setFonctionEquipe("");
	setNomEquipe("");
}

TeamMember::TeamMember(string nomP, string prnP, Date datNaisP, string natP, \
	string log, string fctE, string nomE) : AuthorisedPerson(nomP, prnP, datNaisP, natP, log)
{
	cout << "Constructeur d'initialisation (TeamMember)" << endl;
	setFonctionEquipe(fctE);
	setNomEquipe(nomE);
}

TeamMember::TeamMember(const TeamMember &tm) : AuthorisedPerson(tm)
{
	cout << "Constructeur de copie (TeamMember)" << endl;
	setFonctionEquipe(tm.getFonctionEquipe());
	setNomEquipe(tm.getNomEquipe());
}

TeamMember::~TeamMember(void)
{
	cout << "Destructeur (TeamMember)" << endl;
}

string TeamMember::getFonctionEquipe(void) const
{
	return fonctionEquipe;
}

string TeamMember::getNomEquipe(void) const
{
	return nomEquipe;
}

void TeamMember::setFonctionEquipe(string fctE)
{
	fonctionEquipe = fctE;
}

void TeamMember::setNomEquipe(string nomE)
{
	nomEquipe = nomE;
}

void TeamMember::affiche(void)
{
	cout << *this;
}

string TeamMember::getIdentification(void) const
{
	string tmp = getNom() + "#" + getNomEquipe() + "#" + getFonctionEquipe();
	return tmp;
}

ostream & operator<<(ostream &s, const TeamMember &tm)
{
	cout << "Operateur << (TeamMember)" << endl;
	ofstream *tmp;
	tmp = dynamic_cast<ofstream *> (&s);

	if(tmp == 0)
	{
		s << (AuthorisedPerson &) tm;
		s << "Nom de l'equipe : " << tm.getNomEquipe() << endl;
		s << "Fonction de l'equipe : " << tm.getFonctionEquipe() << endl;
	}

	else
	{
		*tmp << (AuthorisedPerson &) tm;
		*tmp << tm.nomEquipe << endl;
		*tmp << tm.fonctionEquipe << endl;
	}

	return s;
}

istream & operator>>(istream &s, TeamMember &tm)
{
	cout << "Operateur >> (TeamMember)" << endl;
	ifstream *tmp;
	tmp = dynamic_cast<ifstream *> (&s);

	if(tmp == 0)
	{
		s >> (AuthorisedPerson &) tm;
		cout << "Entrez le nom de l'equipe : ";
		s >> tm.nomEquipe;
		cout << "Entrez la fonction de l'equipe : ";
		s >> tm.fonctionEquipe;
	}

	else
	{
		*tmp >> (AuthorisedPerson &) tm;
		*tmp >> tm.nomEquipe;
		*tmp >> tm.fonctionEquipe;
	}

	return s;
}

TeamMember & TeamMember::operator=(const TeamMember &tm)
{
	cout << "Operateur = (TeamMember)" << endl;
	*((AuthorisedPerson *) this) = (AuthorisedPerson &) tm;
	setNomEquipe(tm.getNomEquipe());
	setFonctionEquipe(tm.getFonctionEquipe());
	return *this;
}
