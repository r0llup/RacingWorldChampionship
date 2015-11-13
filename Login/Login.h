#ifndef LOGIN_H
#define LOGIN_H
#include "FichierLog.h"
#include "FederationAdmin.h"
#include "TeamMember.h"
#include "../Fichier.ini"

using namespace std;

class Login
{
	private:
		string pseudo;
		string password;
		int typeCompte;
		bool logged;
		FichierLog log;
		FederationAdmin fa;
		TeamMember tm;
	public:
		Login(void);
		string getPseudo(void) const;
		string getPassword(void) const;
		int getTypeCompte(void);
		bool getLogged(void);
		string getNomCompetition(void) const;
		string getNomEquipe(void) const;
		void setPseudo(string p);
		void setPassword(string p);
		void setTypeCompte(int tc);
		void setLogged(bool l);
		int extractTypeCompte(void);
		string extractPseudo(string &ch);
		string extractPassword(string &ch);
		bool makeConnection(void);
		bool closeConnection(void);
};

#endif
