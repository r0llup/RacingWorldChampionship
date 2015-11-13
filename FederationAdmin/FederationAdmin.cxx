#include "FederationAdmin.h"
#include <fstream.h>

FederationAdmin::FederationAdmin(void) : AuthorisedPerson()
{
	cout << "Constructeur par defaut (FederationAdmin)" << endl;
	setNomCompetition("");
}

FederationAdmin::FederationAdmin(string nm, string prn, Date dateNaissance, string nat, \
	string nomComp) : AuthorisedPerson(nm, prn, dateNaissance, nat)
{
	cout << "Constructeur d'initialisation (FederationAdmin)" << endl;
	setNomCompetition(nomComp);
}

FederationAdmin::FederationAdmin(const FederationAdmin &fa) : AuthorisedPerson(fa)
{
	cout << "Constructeur de copie (FederationAdmin)" << endl;
	setNomCompetition(fa.getNomCompetition());
}

FederationAdmin::~FederationAdmin(void)
{
	cout << "Destructeur (FederationAdmin)" << endl;
}

string FederationAdmin::getNomCompetition(void) const
{
	return nomCompetition;
}

void FederationAdmin::setNomCompetition(string nomComp)
{
	nomCompetition = nomComp;
}

void FederationAdmin::affiche(void)
{
	cout << *this;
}

string FederationAdmin::getIdentification(void) const
{
	string tmp = getNomCompetition() + "#" + getNom();
	return tmp;
}

FederationAdmin & FederationAdmin::operator=(const FederationAdmin &fa)
{
	cout << "Operateur = (FederationAdmin)" << endl;
	*((FederationAdmin *) this) = (FederationAdmin &) fa;
	setNomCompetition(fa.getNomCompetition());
	return *this;
}

ostream & operator<<(ostream &s, const FederationAdmin &fa)
{
	cout << "Operateur << (FederationAdmin)" << endl;
	ofstream *tmp;
	tmp = dynamic_cast<ofstream *> (&s);

	if(tmp == 0)
	{
		s << (AuthorisedPerson &) fa;
		s << "Nom de la competition : " << fa.getNomCompetition() << endl;
	}

	else
	{
		*tmp << (AuthorisedPerson &) fa;
		*tmp << fa.getNomCompetition() << endl;
	}

	return s;
}

istream & operator>>(istream &s, FederationAdmin &fa)
{
	cout << "Operateur >> (FederationAdmin)" << endl;
	ifstream *tmp;
	tmp = dynamic_cast<ifstream *> (&s);

	if(tmp == 0)
	{
		s >> (AuthorisedPerson &) fa;
		cout << "Nom de la competition: ";
		s >> fa.nomCompetition;
	}

	else
	{
		*tmp  >> (AuthorisedPerson &) fa;
		*tmp >> fa.nomCompetition;
	}

	return s;
}
