#include "AuthorisedPerson.h"
#include <fstream.h>

AuthorisedPerson::AuthorisedPerson(void) : Person()
{
	cout << "Constructeur par defaut (AuthorisedPerson)" << endl;
	setLogin("");
}

AuthorisedPerson::AuthorisedPerson(string nm, string prn, Date dateN, string nat) : \
	Person(nm, prn, dateN, nat)
{
	cout << "Constructeur d'intialisation (1) (AuthorisedPerson)" << endl;
	setLogin("");
}	

AuthorisedPerson::AuthorisedPerson(string nm, string prn, Date dateN, string nat, \
	string log) : Person(nm, prn, dateN, nat)
{
	cout << "Constructeur d'initialisation (2) (AuthorisedPerson)" << endl;
	setLogin(log);
}

AuthorisedPerson::AuthorisedPerson(const AuthorisedPerson &ap)  : Person(ap)
{
	cout << "Constructeur de copie (AuthorisedPerson)" << endl;
	setLogin(ap.getLogin());
}

AuthorisedPerson::~AuthorisedPerson(void)
{
	cout << "Destructeur (AuthorisedPerson)" << endl;
}

string AuthorisedPerson::getLogin(void) const
{
	return login;
}

void AuthorisedPerson::setLogin(string log)
{
	login = log;
}

void AuthorisedPerson::affiche()
{
	cout << *this;
}

ostream & operator<<(ostream &s, const AuthorisedPerson &ap)
{
	cout << "Operateur << (AuthorisedPerson)" << endl;
	ofstream *tmp;
	tmp = dynamic_cast<ofstream *> (&s);

	if(tmp == 0)
	{
		s << (Person &) ap;
		s << "Login : " << ap.getLogin() << endl;
	}

	else
	{
		*tmp << (Person &) ap;
		*tmp << ap.getLogin() << endl;
	}

	return s;
}

istream & operator>>(istream &s, AuthorisedPerson &ap)
{
	cout << "Operateur >> (AuthorisedPerson)" << endl;
	ifstream *tmp;
	tmp = dynamic_cast<ifstream *> (&s);

	if(tmp == 0)
	{
		s >> (Person &) ap;
		cout << "Login : ";
		s >> ap.login;
	}

	else
	{
		*tmp >> (Person &) ap;
		*tmp >> ap.login;
	}

	return s;
}

AuthorisedPerson & AuthorisedPerson::operator=(AuthorisedPerson &ap)
{
	cout << "Operateur = (AuthorisedPerson)" << endl;
	*((Person *) this) = (Person &) ap;
	setLogin(ap.getLogin());
	return *this;
}
