#ifndef FEDERATIONADMIN_H
#define FEDERATIONADMIN_H
#include "AuthorisedPerson.h"

using namespace std;

class FederationAdmin : public AuthorisedPerson
{
	friend ostream & operator<<(ostream &s, const FederationAdmin &fa);
	friend istream & operator>>(istream &s, FederationAdmin &fa);
	private:
		string nomCompetition;
	public:
		FederationAdmin(void);
		FederationAdmin(string nm, string prn, Date dateNaissance, string nat, \
			string nomComp);
		FederationAdmin(const FederationAdmin &fa);
		~FederationAdmin(void);
		string getNomCompetition(void) const;
		void setNomCompetition(string nomComp);
		void affiche(void);
		string getIdentification(void) const;
		FederationAdmin & operator=(const FederationAdmin &fa);
};

#endif
