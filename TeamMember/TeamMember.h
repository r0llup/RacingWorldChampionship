#ifndef TEAMMEMBER_H
#define TEAMMEMBER_H
#include "AuthorisedPerson.h"

using namespace std;

class TeamMember : public AuthorisedPerson
{
	friend ostream & operator<<(ostream &s, const TeamMember &tm);
	friend istream & operator>>(istream &s, TeamMember &tm);
	private:
		string fonctionEquipe;
		string nomEquipe;
	public:
		TeamMember(void);
		TeamMember(string nomP, string prnP, Date datNaisP, string natP, \
			string log, string fctE, string nomE);
		TeamMember(const TeamMember &tm);
		~TeamMember(void);
		string getFonctionEquipe(void) const;
		string getNomEquipe(void) const;
		void setFonctionEquipe(string fctE);
		void setNomEquipe(string nomE);
		void affiche(void);
		string getIdentification(void) const;
		TeamMember & operator=(const TeamMember &tm);
};

#endif
