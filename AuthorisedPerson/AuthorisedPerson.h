#ifndef AUTHORISEDPERSON_H
#define AUTHORISEDPERSON_H
#include "Person.h"

using namespace std;

class AuthorisedPerson : public Person
{
	protected:
		string login;
	public:
		AuthorisedPerson(void);
		AuthorisedPerson(string nm, string prn, Date dateN, string nat);
		AuthorisedPerson(string nm, string prn, Date dateN, string nat, string log);
		AuthorisedPerson(const AuthorisedPerson &ap);
		~AuthorisedPerson(void);
		string getLogin(void) const;
		void setLogin(string log);
		string getIdentification(void) const = 0;
		void affiche();
		friend ostream & operator<<(ostream &s, const AuthorisedPerson &ap);
		friend istream & operator>>(istream &s, AuthorisedPerson &ap);
		AuthorisedPerson & operator=(AuthorisedPerson &ap);
};

#endif
